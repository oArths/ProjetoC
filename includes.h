#ifndef INCLUDES_H
#define INCLUDES_H
#include <stdbool.h>
#include <locale.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define bool _Bool
#define true 1
#define false 0

#define MAX_TITULO 20
#define MAX_TEXTO 200
#define MAX_TAG 20
#define MAX_NOME 40
#define MAX_SENHA 8
typedef struct Tags {
  char tag[3][MAX_TAG + 1];
} Tags;

typedef struct {
  int id;
  char titulo[MAX_TITULO + 1];
  char texto[MAX_TEXTO + 1];
  struct Tags tags;
} listaNotas;

typedef struct User {
  int id;
  char nome[40];
  char senha[8];
} User;

void CriarNota(listaNotas novaNota);
void lerString(char *str, int tamanhoMax);
void EditarNota();
void ListarNota();
void limparBuffer();
void DeletarNota();
void Clear();
void Register();
void Login();
bool realizarlogin(char nome[], char senha[], User usuario);

#endif  