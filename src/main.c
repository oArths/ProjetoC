#include "../includes/includes.h"

void Login();
void Register();
void Conta(User *user);
void CriarNota(User *user);
void EditarNota(User *user);
void ListarNota(User *user);
void DeletarNota(User *user);

User *usuarios = NULL;
User *userLogado = NULL;
int totalUser = 0;

int main() {

//CRIAR UM INICIALIZADOR COM TODOS OS CODIGOS DE CONFIGURAÇÃO/BANCO DE DADOS ANTES DE INICIAR

  //* Definindo o locale para aceitar caracteres especiais como "Ç" e "ã"
HWND hwnd = GetConsoleWindow();
ShowWindow(hwnd, SW_MAXIMIZE);


setlocale(LC_ALL, "pt_BR.UTF-8");
// Rodar esses comando no terminal para que ele aceite "Ç"
system("powershell -NoProfile -Command \"$OutputEncoding = [Console]::OutputEncoding = [System.Text.UTF8Encoding]::new()\"");
Banco Banco;
criarBanco(&Banco);
int op;

do {
  printf("\nBem vindo ao C-Note\n");
  printf("\n Escolha umas das opçôes:\n 1 - Login\n 2 - Registar\n 3 - Sair\n\n ");
  scanf("%d", &op);
  getchar();

  switch (op) {
    case 1:
      Login();
      break;
    case 2:
      Register();
      break;
    case 3:
      printf("Saindo do programa...\n");
      exit(0);
      break;
    default:
      printf("Escolha uma opção invalida!");
      break;
  }
  } while (op != 4);
  // Liberar a memória alocada para usuários ao sair
  for (int i = 0; i < totalUser; i++) {
    Nota *atual = usuarios[i].notas;
    while (atual != NULL) {
      Nota *proximo = atual->proximo;
      free(atual);
      atual = proximo;
    }
  }
  free(usuarios);
  return 0;
}

void Register() {
  char nome[MAX_NOME], senha[MAX_SENHA];
  while (1) {
    printf("Digite seu usuario: min 3 char\n");
    lerStringSegura(nome, MAX_NOME);
    if (strlen(nome) < 3) {
      printf("Digite um nome valido\n");
    }
    break;
  }
  while (1) {
    printf("Digite sua senha: min 4 char\n");
    lerStringSegura(senha, MAX_SENHA);
    if (strlen(senha) < 4) {
      printf("Digite uma senha deve ter no minimo 4 caracteres");
    }
    break;
  }
  

  // totalUser++;
  // usuarios = (User *)realloc(usuarios, totalUser * sizeof(User));
  // if (usuarios == NULL) {
  //   printf("Erro ao alocar memória para novo usuário!\n");
  //   exit(1);
  // }
  // usuarios[totalUser - 1].id = totalUser;
  // strncpy(usuarios[totalUser - 1].nome, nome, MAX_NOME);
  // usuarios[totalUser - 1].nome[MAX_NOME] = '\0';
  // strncpy(usuarios[totalUser - 1].senha, senha, MAX_SENHA);
  // usuarios[totalUser - 1].senha[MAX_SENHA] = '\0';
  // usuarios[totalUser - 1].notas = NULL;  // Inicializa a lista de notas do novo usuário como vazia
  printf("Usuário cadastrado com Sucesso!\n");
  Login();
}

void Login() {
  int tentativa = 0;
  char nome[MAX_NOME], senha[MAX_SENHA];
  while (tentativa != 3) {
    printf("\nBem vindo ao C-Note\n\n");
    printf("Informar seu dados para Logar\n");
    printf("Digite seu nome de usuario:\n ");
    lerStringSegura(nome, MAX_NOME);
    printf("Digite sua senha:\n ");
    lerStringSegura(senha, MAX_SENHA);

    for (int i = 0; i < totalUser; i++) {
      if (realizarLogin(nome, senha)) {
        printf("Login realzado com sucesso!!\n");
        printf("\n iniciando seção..");
        userLogado = &usuarios[i];
        Conta(userLogado);
        return;
      }
    }
    tentativa++;
    printf("Login falhou. Tentativa %d de 3.\n", tentativa);
  }
  printf("Número máximo de tentativas alcançado. Encerrando...\n");
}

void Conta(User *user) {
  int op;
  do {
    printf("\nBem vindo ao C-Note\n");
    printf(
        "\n Escolha umas das opçôes:\n 1 - Criar Nota\n 2 - Editar uma Nota\n 3 "
        "- Listar Notas\n 4 - Excluir uma Nota\n 5 - Sair\n\n ");

    scanf("%d", &op);
    getchar();

    switch (op) {
      case 1:
        CriarNota(user);
        break;
      case 2:
        EditarNota(user);
        break;
      case 3:
        ListarNota(user);

        break;
      case 4:
        DeletarNota(user);
        break;
      case 5:
        printf("Saindo do programa...\n");
        exit(0);
        break;
      default:
        printf("Escolha uma opção invalida!");
        break;
    }
  } while (op != 6);

  return;
}
void CriarNota(User *user) {
  Nota *novaNota = (Nota *)malloc(sizeof(Nota));
  if (novaNota == NULL) {
    printf("Erro ao alocar memória para a nova nota!\n");
    return;
  }
  printf("Adicione um titulo a sua nota: 40 Char Max \n");
  int status_titulo = lerStringSegura(novaNota->titulo, MAX_TITULO + 1);
  if (status_titulo == 0) {
    printf("Entrada cancelada pelo usuário\n");
    free(novaNota);
    return;
  }

  printf("Adicione um texto a sua nota: 200 Char Max \n");
  int status_texto = lerStringSegura(novaNota->texto, MAX_TEXTO + 1);
  if (status_texto == 0) {
    printf("Entrada cancelada pelo usuário\n");
    free(novaNota);
    return;
  }

  for (int i = 0; i < 3; i++) {
    printf("Adicione uma tag a sua nota: 20 Char Max \n");
    int status_tag = lerStringSegura(novaNota->tags.tag[i], MAX_TAG + 1);
    if (status_tag == 0) {
      printf("Entrada cancelada pelo usuário\n");
      free(novaNota);
      return;
    }
  }
  int nextId = 1;
  if (user->notas != NULL) {
    Nota *atual = user->notas;
    while (atual->proximo != NULL) {
      atual = atual->proximo;
    }
    nextId = atual->id + 1;
  }
  novaNota->id = nextId;
  novaNota->proximo = user->notas;  // Nova nota aponta para a antiga primeira nota
  user->notas = novaNota;           // Atualiza o ponteiro da lista de notas do usuário

  printf("Nota Salva com sucesso!!\n");
}
void ListarNota(User *user) {
  // divide o tamanho total da Lista pela do primeiro item
  if (user->notas == NULL) {
    printf("Nenhuma nota cadastrada para este usuário!\n");
    return;
  }

  printf("\n----- Suas Notas -----\n");
  Nota *atual = user->notas;

  // loop para ler todas as tags armazenadas no array
  while (atual != NULL) {
    printf("---------------------\n");
    printf("Id: %i\n", atual->id);
    printf("Titulo: %s\n", atual->titulo);
    printf("Texto: %s\n", atual->texto);
    printf("Tags: ");
    for (int j = 0; j < 3; j++) {
      if (atual->tags.tag[j][0] != '\0') {
        printf("%s ", atual->tags.tag[j]);
      }
    }
    printf("\n---------------------\n");
    atual = atual->proximo;
  }
}
void EditarNota(User *user) {
  char idSolicitado[MAX_ID];
  do {
    printf("Digite o id da Nota que deseja editar:\n");
    lerStringSegura(idSolicitado, MAX_ID);

    if (strspn(idSolicitado, "0123456789") != strlen(idSolicitado)) {
      printf("Entrada inválida! Digite apenas números.\n");
    }
  } while (strspn(idSolicitado, "0123456789") != strlen(idSolicitado));

  if (user->notas == NULL) {
    printf("Nenhuma nota cadastrada para este usuário!\n");
    return;
  }
  Nota *atual = user->notas;
  Nota CopiaAtual, EdicaoAtual;
  int idSolicitadoInt = atoi(idSolicitado);

  while (atual != NULL) {
    if (atual->id == idSolicitadoInt) {
      CopiaAtual.id = atual->id;
      strcpy(CopiaAtual.titulo, atual->titulo);
      strcpy(CopiaAtual.texto, atual->texto);
      for (int i = 0; i < 3; i++) {
        strcpy(CopiaAtual.tags.tag[i], atual->tags.tag[i]);
      }
      break;
    } else {
      atual = atual->proximo;
    }
  }
  printf("\n Modo de Edição?\n");
  printf("Digite o novo valor (ou pressione Enter para manter o valor atual)\n");
  printf("Titulo atual: %s\n", CopiaAtual.titulo);
  printf("Novo Titulo: ");
  lerStringSegura(EdicaoAtual.titulo, MAX_TITULO);
  printf("Texto atual: %s\n", CopiaAtual.texto);
  if (EdicaoAtual.titulo[0] != '\0') {
    strcpy(CopiaAtual.titulo, EdicaoAtual.titulo);
  }
  printf("Novo Texto: ");
  lerStringSegura(EdicaoAtual.texto, MAX_TEXTO);
  if (EdicaoAtual.texto[0] != '\0') {
    strcpy(CopiaAtual.texto, EdicaoAtual.texto);
  }
  for (int j = 0; j < 3; j++) {
    if (atual->tags.tag[j][0] != '\0') {
      printf("Tag %d°: %s\n", j, atual->tags.tag[j]);
      printf("Nova Tag %d°: ");
      lerStringSegura(EdicaoAtual.tags.tag[j], MAX_TAG);

      if (EdicaoAtual.tags.tag[j][0] != '\0') {
        strcpy(CopiaAtual.tags.tag[j], EdicaoAtual.tags.tag[j]);
      }
    }
  }
  atual->id = CopiaAtual.id;
  strcpy(atual->titulo, CopiaAtual.titulo);
  strcpy(atual->texto, CopiaAtual.texto);
  for (int i = 0; i < 3; i++) {
    strcpy(atual->tags.tag[i], CopiaAtual.tags.tag[i]);
  }
  printf("\nNota atualizada com sucesso!\n");
}
void DeletarNota(User *user) { printf("foi 3"); }
