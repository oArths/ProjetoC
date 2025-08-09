#ifndef DB_H
#define DB_H
#include "modelos.h"

bool realizarLogin(char *nome, char *senha);
bool criarBanco(Banco *banco);
bool conectarBanco(Banco *banco);
bool executarQuery(Banco *banco, Resultado *resultado);
Resposta criarUsuario(Banco *banco, User *user);
void desconectarBanco(Banco *banco);
#endif