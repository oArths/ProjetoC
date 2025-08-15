#ifndef MODELOS_H
#define MODELOS_H
//#include <windows.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sqlite3.h>

#define MAX_TITULO 20
#define MAX_TEXTO 200
#define MAX_TAG 20
#define MAX_NOME 40
#define MAX_SENHA 9999
#define MAX_ID 99999

typedef struct Tags {
  char tag[3][MAX_TAG + 1];
} Tags;

typedef struct Nota {
  int id;
  char titulo[MAX_TITULO + 1];
  char texto[MAX_TEXTO + 1];
  struct Tags tags;
  struct Nota *proximo;
} Nota;

typedef struct User {
  int id;
    char nome[MAX_NOME];   // Mude para um array de char
    char senha[MAX_SENHA];
  Nota *notas;
} User;

typedef struct {
  sqlite3 *db;
  char *err_msg;
  int banco_status;
  char *query;
  sqlite3_stmt *consultaPronta;

} Banco;
typedef struct Resultado {
  const char *query;
} Resultado;

typedef struct Resposta {
  bool error;
  const char *data;
} Resposta;

#endif
