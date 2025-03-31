#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Rodar esses comando no terminal para que ele aceite "Ç"
//$OutputEncoding = [Console]::OutputEncoding =[System.Text.UTF8Encoding]::new()
// chcp 65001

void CriarNota();
void EditarNota();
void ListarNota();
void DeletarNota();

typedef struct Tags {
  char tag[3][20];
} Tags;

typedef struct {
  char titulo[20];
  char texto[200];
  struct Tags tags;
} listaNotas;

typedef struct User {
  int id;
  char nome[40];
  char senha[8];
} User;
listaNotas* Lista = NULL;
int tamanho = 0;
// listaNotas Lista[3] = {{.titulo = "titilo1", .texto = "texto muito grande", .tags = {{"tag1", "tag1", "tag1"}}},
//                        {.titulo = "titilo2", .texto = "texto muito grande", .tags = {{"tag2", "tag2", "tag2"}}},
//                        {.titulo = "titilo3", .texto = "texto muito grande", .tags = {{"tag3", "tag3", "tag3"}}}};

int main() {
  setlocale(LC_ALL, "pt_BR.UTF-8");

  int op;
  printf("Bem vindo ao C-Note\n");
  printf(
      "\n Escolha umas das opções:\n 1 - Criar Nota\n 2 - Editar uma Nota\n 3 "
      "- Listar Notas\n 4 - Excluir uma Nota\n ");

  scanf("%d", &op);
  char titulo1[40];
  char texto1[200];
  switch (op) {
    case 1:

      printf("Adicione um titulo a sua nota: 40 Char Max \n");
      scanf("%s", titulo1);
      printf("%s", titulo1);
      CriarNota();
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

  return 0;
}
void ListarNota() {
  // divide o tamanho total da Lista pela do primeiro item
  int tamanho = sizeof(Lista) / sizeof(Lista[0]);

  // loop para ler todas as tags armazenadas no array
  for (int i = 0; i <= tamanho; i++) {
    // função que verifica se a nota não esta vazia antes de imprimir
   
    printf("---------------------\n");
    // acessando o indice de acordo com
    printf("Titulo: %s\n", Lista[i].titulo);
    printf("Texto: %s\n", Lista[i].texto);
    printf("Tags: ");
    for (int j = 0; j < 3; j++) {
      // verificando se a tag não é vazia ja que se for vazia ela vai conter apenas'\n'
      if (Lista[i].tags.tag[j][0] != '\0') {
        printf("%s ", Lista[i].tags.tag[j]);
      }
    }
    printf("\n---------------------");
  }
}

void CriarNota(const char* titulo, const char* texto, const char tags[3][20]) {
  // incrementando o contador  por estar criando uma nova nota
  tamanho++;
  // verificamos se existe espaço de memoria em Lista pra guarda a nova nota com o realloc, caso não tenha
  //  ele retorna null, com isso pra evitar perder os dados ao tentar realocar os dados atribuimos o realloc
  //  ao um ponteiro que guarda o endereço "*temp" de memoria dos dados da lista, caso  de certo ele "temp" passa os dados pra Lista
  void *temp = realloc(Lista, tamanho * sizeof(listaNotas));

  if (temp == NULL) {
    printf("Erro ao alocar memória!\n");
    exit(1);
  }

  Lista = temp;
  // strncpy(destino , origem, remover o ultimo caracter) é responsavel por transferir um dado de uma variavel para outra
  strncpy(Lista[tamanho - 1].titulo, titulo, sizeof(Lista[tamanho - 1].titulo) - 1);
  // garantindo que a string termine em '\0' para evitar erros
  Lista[tamanho - 1].titulo[sizeof(Lista[tamanho - 1].titulo) - 1] = '\0';

  strncpy(Lista[tamanho - 1].texto, texto, sizeof(Lista[tamanho - 1].texto) - 1);
  Lista[tamanho - 1].texto[sizeof(Lista[tamanho - 1].texto) - 1] = '\0';

  for (int i = 0; i < 3; i++) {
    strncpy(Lista[tamanho - 1].tags.tag[i], tags[i], sizeof(Lista[tamanho - 1].tags.tag[i]) - 1);
    Lista[tamanho - 1].tags.tag[i][sizeof(Lista[tamanho - 1].tags.tag[i]) - 1] = '\0';
  }

  printf("Nota Salva com sucesso!!");
}
void EditarNota() { printf("foi 2"); }
void DeletarNota() { printf("foi 2"); }