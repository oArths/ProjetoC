#ifndef DB_H
#define DB_H

bool realizarLogin(char *nome, char *senha);
bool criarBanco(Banco *banco);
bool conectarBanco(Banco *banco);
bool executarQuery(Banco *banco, Resultado *resultado);

bool conectarBanco(Banco *banco) {
  banco->banco_status = sqlite3_open("C:\\Users\\Arthur\\Documents\\code\\ProjetoC\\db\\banco.db", &banco->db);

  if (banco->banco_status != SQLITE_OK) {
    printf("Erro %d ao abrir o banco: %s\n", banco->banco_status, sqlite3_errmsg(banco->db));
    perror("perror");

    sqlite3_free(banco->err_msg);
    sqlite3_close(banco->db);
    return false;
  }
  return true;
}
bool executarQuery(Banco *banco, Resultado *resultado) {
  banco->banco_status = sqlite3_prepare_v2(banco->db, banco->query, -1, &banco->consultaPronta, 0);
  if (banco->banco_status != SQLITE_OK) {
    printf("Erro na execução da consulta: %s\n", sqlite3_errmsg(banco->db));
    return false;
  }

  if (sqlite3_step(banco->consultaPronta) == SQLITE_ROW) {
    resultado->query = (const char *)sqlite3_column_text(banco->consultaPronta, 0);
  }

  sqlite3_finalize(banco->consultaPronta);
  return true;
}

bool criarBanco(Banco *banco) {
  Resultado resultado;
  if (!conectarBanco(banco)) return false;
  sqlite3_exec(banco->db, "PRAGMA foreign_keys = ON;", 0, 0, 0);

  banco->query = "CREATE TABLE IF NOT EXISTS User (Id INTEGER PRIMARY KEY, User TEXT NOT NULL, Senha TEXT NOT NULL);";
  if (!executarQuery(banco, &resultado)) return false;

  banco->query = "CREATE TABLE IF NOT EXISTS Notas (Id INTEGER PRIMARY KEY, Titulo TEXT NOT NULL, Texto TEXT NOT NULL, Data DATETIME NOT NULL);";
  if (!executarQuery(banco, &resultado)) return false;

  banco->query =
      "CREATE TABLE IF NOT EXISTS UserNotas (NotaId INTEGER, UserId INTEGER, "
      "FOREIGN KEY (NotaId) REFERENCES Notas(Id), "
      "FOREIGN KEY (UserId) REFERENCES User(Id), "
      "PRIMARY KEY (NotaId, UserId));";
  if (!executarQuery(banco, &resultado)) return false;

  banco->query = "CREATE TABLE IF NOT EXISTS Tags (Id INTEGER PRIMARY KEY, Tag TEXT UNIQUE);";
  if (!executarQuery(banco, &resultado)) return false;

  banco->query =
      "CREATE TABLE IF NOT EXISTS NotaTags (NotaId INTEGER, TagId INTEGER, "
      "FOREIGN KEY (NotaId) REFERENCES Notas(Id), "
      "FOREIGN KEY (TagId) REFERENCES Tags(Id), "
      "PRIMARY KEY (NotaId, TagId));";
  if (!executarQuery(banco, &resultado)) return false;

  sqlite3_close(banco->db);
  return true;
}
bool criarUsuario(Banco *banco, const char *user, const char *senha) {
  Resultado resultado;
  if (!conectarBanco(banco)) return false;

  sprintf(banco->query, "SELECT * FROM User WHERE User = '%s' AND Senha = '%s'", user, senha);

  if (!executarQuery(banco, &resultado)) return false;

  return true;
}
bool realizarLogin(char *nome, char *senha) {
  return true;
}
#endif