#ifndef INCLUDES_H
#define INCLUDES_H

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_TITULO 20
#define MAX_TEXTO 200
#define MAX_TAG 20
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
#endif  