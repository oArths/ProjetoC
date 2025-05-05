#include "../includes/helps.h"

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
  size_t tamanho = strlen(destino);
  //* Verifica se o último caractere é '\n' e o substitui por '\0'
  if (tamanho > 0 && destino[tamanho - 1] == '\n') {
    //* Substitui o '\n' por '\0' para finalizar a string corretamente
    destino[tamanho - 1] = '\0';
    return 1;
  } else {
    //* Se o tamanho máximo foi atingido, remove o restante da linha
    limparBuffer();
    return 2;
  }
}