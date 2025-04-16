#ifndef INCLUDES_H
#define INCLUDES_H
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
#define MAX_SENHA 20

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
  char nome[40];
  char senha[8];
  Nota *notas;
} User;

void Login();
void Register();
void Conta(User *user);
void CriarNota(User *user);
void EditarNota(User *user);
void ListarNota(User *user);
void DeletarNota(User *user);

void limparBuffer();
void Clear();
void lerString(char *str, int tamanhoMax);
bool realizarlogin(char nome[], char senha[], User usuario);
#include "helps.h"

#endif