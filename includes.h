#ifndef INCLUDES_H
#define INCLUDES_H

#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct Tags {
    char tag[3][20];
  } Tags;
  
  typedef struct {
    int id;
    char titulo[20];
    char texto[200];
    struct Tags tags;
  } listaNotas;
  
  typedef struct User {
    int id;
    char nome[40];
    char senha[8];
} User;

#endif  