#include <stdio.h>
#include <locale.h>

void CriarNota();
void EditarNota();
void ListarNota();
void DeletarNota();

typedef struct Tags
{
    char tag[3][20];
} Tags;

typedef struct
{
    char titulo[20];
    char texto[200];
    struct Tags tags;
} listaNotas;

typedef struct User
{
    int id;
    char nome[40];
    char senha[8];
} User;

listaNotas Lista[3] = {
    {.titulo = "titilo1", .texto = "texto muito grande", .tags = {{"tag1", "tag1", "tag1"}}},
    {.titulo = "titilo2", .texto = "texto muito grande", .tags = {{"tag2", "tag2", "tag2"}}},
    {.titulo = "titilo3", .texto = "texto muito grande", .tags = {{"tag3", "tag3", "tag3"}}}};

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int op;
    printf("Bem vindo ao C-Note\n");
    printf("\n Escolha umas das opções:\n 1 - Criar Nota\n 2 - Editar uma Nota\n 3 - Listar Notas\n 4 - Excluir uma Nota\n ");

    scanf("%d", &op);
    switch (op)
    {
    case 1:
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
void ListarNota()
{

    for (int i = 0; i <= 2; i++){
        printf("---------------------\n");
        printf("Titulo: %s\n", Lista[i].titulo);
        printf("Texto: %s\n", Lista[i].texto);
        printf("Tags: ");
        for (int j = 0; j < 3; j++)
        {
            if (Lista[i].tags.tag[j][0] != '\0'){ 
                printf("%s ", Lista[i].tags.tag[j]);
            }
        }
        printf("\n---------------------");
    }


}

void CriarNota()
{
    printf("foi 1");
}
void EditarNota()
{
    printf("foi 2");
}
void DeletarNota()
{
    printf("foi 2");
}