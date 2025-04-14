#ifndef HELPS_H
#define HELPS_H
void limparBuffer() {
  int c;
  // Limpa o buffer de entrada até encontrar um '\n' ou EOF
  while ((c = getchar()) != '\n' && c != EOF);
}

int lerStringSegura(char *destino, int tamanho_max) {
  //* Verifica se o tamanho máximo é maior que 0
  if (fgets(destino, tamanho_max, stdin) == NULL) {
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
void Clear() {
#ifdef _WIN32
  system("cls");
  system("clear");
#endif
}
bool realizarlogin(char *nome, char *senha, User usuario) { return strcmp(nome, usuario.nome) == 0 && strcmp(senha, usuario.senha) == 0; }
#endif