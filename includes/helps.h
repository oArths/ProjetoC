#ifndef HELPS_H
#define HELPS_H
void limparBuffer() {
  int c;
  // Limpa o buffer de entrada até encontrar um '\n' ou EOF
  while ((c = getchar()) != '\n' && c != EOF);
}

int lerStringSegura(char *destino, int tamanhoMax) {
  //* Verifica se o tamanho máximo é maior que 0
  if (fgets(destino, tamanhoMax, stdin) == NULL) {
    return 0;
  }
  //* Remove o caractere de nova linha, se presente
  size_t len = strlen(destino);
  //* Verifica se o último caractere é '\n' e o substitui por '\0'
  if (len > 0 && destino[len - 1] == '\n') {
    //* Substitui o '\n' por '\0' para finalizar a string corretamente
    destino[len - 1] = '\0';
    return 1;
  } else {
    //* Se o tamanho máximo foi atingido, remove o restante da linha
    limparBuffer();
    return 2;
  }
}
bool realizarlogin(char *nome, char *senha, User usuario) {
  return strcmp(nome, usuario.nome) == 0 && strcmp(senha, usuario.senha) == 0;
}

bool criarBanco() {
  sqlite3 *db;
  char *err_msg = 0;

  int banco = sqlite3_open("./db/banco.db", &db);
  sqlite3_exec(db, "PRAGMA foreign_keys = ON;", 0, 0, 0);

  if (banco != SQLITE_OK) {
    printf("Erro ao abrir o banco de dados: %s\n", sqlite3_errmsg(db));
    return 1;
  }

  // Comando SQL para criar uma tabela
  const char *sql =
      "CREATE TABLE IF NOT EXISTS User (Id INTEGER PRIMARY KEY, User TEXT NOT NULL, Senha TEXT NOT NULL);"
      "CREATE TABLE IF NOT EXISTS Notas (Id INTEGER PRIMARY KEY, Titulo TEXT NOT NULL, Texto TEXT NOT NULL, Data DATETIME NOT NULL);"
      "CREATE TABLE IF NOT EXISTS UserNotas (NotaId INTEGER, UserId INTEGER, "
      "FOREIGN KEY (NotaId) REFERENCES Notas(Id), "
      "FOREIGN KEY (UserId) REFERENCES User(Id), "
      "PRIMARY KEY (NotaId, UserId));"
      "CREATE TABLE IF NOT EXISTS Tags (Id INTEGER PRIMARY KEY, Tag TEXT UNIQUE);"
      "CREATE TABLE IF NOT EXISTS NotaTags (NotaId INTEGER, TagId INTEGER, "
      "FOREIGN KEY (NotaId) REFERENCES Notas(Id), "
      "FOREIGN KEY (TagId) REFERENCES Tags(Id), "
      "PRIMARY KEY (NotaId, TagId));";

  banco = sqlite3_exec(db, sql, 0, 0, &err_msg);

  if (banco != SQLITE_OK) {
    printf("Erro SQL: %s\n", err_msg);
    sqlite3_free(err_msg);
    return false;
  } else {
    printf("Tabela criada com sucesso!\n");
    return true;
  }

  sqlite3_close(db);
}
#endif