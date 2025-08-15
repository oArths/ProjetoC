#include "../includes/booting.h"

void booting() {
  // altera o nome da janela para o do projeto
 // SetConsoleTitle("ProjetoC - Gerenciador de Notas");
  // define a tela como o maximizada
// HWND hwnd = GetConsoleWindow();
//ShowWindow(hwnd, SW_MAXIMIZE);

  //* Definindo o locale para aceitar caracteres especiais como "Ç" e "ã"
  setlocale(LC_ALL, "pt_BR.UTF-8");
  // Rodar esses comando no terminal para que ele aceite "Ç"
  system("powershell -NoProfile -Command \"$OutputEncoding = [Console]::OutputEncoding = [System.Text.UTF8Encoding]::new()\"");
  // inicializa o banco
  Banco Banco;
  criarBanco(&Banco);
}
