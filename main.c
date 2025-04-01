#include "includes.h"

// Rodar esses comando no terminal para que ele aceite "Ç"
//$OutputEncoding = [Console]::OutputEncoding =[System.Text.UTF8Encoding]::new()
// chcp 65001

void CriarNota(listaNotas novaNota);
void EditarNota();
void ListarNota();
void DeletarNota();
void Clear();

#define MAX_TITULO 40
#define MAX_TEXTO 200
#define MAX_TAG 20

listaNotas* Listas = NULL;
int tamanho = 0;

int main() {
  setlocale(LC_ALL, "pt_BR.UTF-8");

  int op;
  do {
    printf("\nBem vindo ao C-Note\n");
    printf(
        "\n Escolha umas das opções:\n 1 - Criar Nota\n 2 - Editar uma Nota\n 3 "
        "- Listar Notas\n 4 - Excluir uma Nota\n\n ");

    scanf("%d", &op);
    getchar();
    listaNotas novaNota;

    switch (op) {
      case 1:

        printf("Adicione um titulo a sua nota: 40 Char Max \n");
        fgets(novaNota.titulo, MAX_TITULO, stdin);
        Clear();
        novaNota.titulo[strcspn(novaNota.titulo, "\n")] = '\0';

        printf("Adicione um texto a sua nota: 200 Char Max \n");
        fgets(novaNota.texto, MAX_TEXTO, stdin);
        Clear();
        novaNota.texto[strcspn(novaNota.texto, "\n")] = '\0';

        for (int i = 0; i < 3; i++) {
          printf("Adicione uma tag a sua nota: 20 Char Max \n");
          fgets(novaNota.tags.tag[i], MAX_TAG, stdin);
          Clear();
          novaNota.tags.tag[i][strcspn(novaNota.tags.tag[i], "\n")] = '\0';
        }
        novaNota.id = tamanho + 1;
        CriarNota(novaNota);
        break;
      case 2:
        EditarNota();
        break;
      case 3:
        ListarNota();
        break;
      case 4:
        DeletarNota();
        break;
      default:
        printf("Escolha uma opção valida!");
        break;
    }
  } while (1);

  return 0;
}
void ListarNota() {
  // divide o tamanho total da Lista pela do primeiro item
  // int tamanho = sizeof(Listas) / sizeof(Listas[0]);

  if (tamanho == 0) {
    printf("Nenhuma nota cadastrada!\n");
    return;
  }

  // loop para ler todas as tags armazenadas no array
  for (int i = 0; i < tamanho; i++) {
    // função que verifica se a nota não esta vazia antes de imprimir

    printf("---------------------\n");
    // acessando o indice de acordo com
    printf("Id: %i\n", Listas[i].id);
    printf("Titulo: %s\n", Listas[i].titulo);
    printf("Texto: %s\n", Listas[i].texto);
    printf("Tags: ");
    for (int j = 0; j < 3; j++) {
      // verificando se a tag não é vazia ja que se for vazia ela vai conter apenas'\n'
      if (Listas[i].tags.tag[j][0] != '\0') {
        printf("%s ", Listas[i].tags.tag[j]);
      }
    }
    printf("\n---------------------");
  }
}

void CriarNota(listaNotas novaNota) {
  // incrementando o contador  por estar criando uma nova nota
  tamanho++;
  // verificamos se existe espaço de memoria em Listas pra guarda a nova nota com o realloc, caso não tenha
  //  ele retorna null, com isso pra evitar perder os dados ao tentar realocar os dados atribuimos o realloc
  //  ao um ponteiro que guarda o endereço "*temp" de memoria dos dados da listas, caso  de certo ele "temp" passa os dados pra Listas
  void* temp = realloc(Listas, tamanho * sizeof(listaNotas));

  if (temp == NULL) {
    printf("Erro ao alocar memória!\n");
    exit(1);
  }

  Listas = temp;

  Listas[tamanho - 1].id = novaNota.id;
  // strncpy(destino , origem, remover o ultimo caracter) é responsavel por transferir um dado de uma variavel para outra
  strncpy(Listas[tamanho - 1].titulo, novaNota.titulo, sizeof(Listas[tamanho - 1].titulo) - 1);

  strncpy(Listas[tamanho - 1].texto, novaNota.texto, sizeof(Listas[tamanho - 1].texto) - 1);

  for (int i = 0; i < 3; i++) {
    strncpy(Listas[tamanho - 1].tags.tag[i], novaNota.tags.tag[i], sizeof(Listas[tamanho - 1].tags.tag[i]) - 1);
  }
  printf("Nota Salva com sucesso!!\n");
}
void EditarNota() { printf("foi 2"); }
void DeletarNota() { printf("foi 2"); }
void Clear() {
    int ch;
    do {
        ch = fgetc(stdin);  // Lê o próximo caractere
    } while (ch != EOF && ch != '\n'); 
}