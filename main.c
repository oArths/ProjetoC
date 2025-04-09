
#include <locale.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define MAX_TITULO 20
#define MAX_TEXTO 200
#define MAX_TAG 20
typedef struct Tags
{
    char tag[3][MAX_TAG + 1];
} Tags;

typedef struct
{
    int id;
    char titulo[MAX_TITULO + 1];
    char texto[MAX_TEXTO + 1];
    struct Tags tags;
} listaNotas;

typedef struct User
{
    int id;
    char nome[40];
    char senha[8];
} User;
// Rodar esses comando no terminal para que ele aceite "C"
//$OutputEncoding = [Console]::OutputEncoding =[System.Text.UTF8Encoding]::new()
// chcp 65001

void CriarNota(listaNotas novaNota);
void lerString(char *str, int tamanhoMax);
void EditarNota();
void ListarNota();
void limparBuffer();
void DeletarNota();
void Clear();

listaNotas *Listas = NULL;
int tamanho = 0;

void limparBuffer()
{
    int c;
    while ((c = getchar()) != '\n' && c != EOF)
        ;
}

int lerStringSegura(char *destino, int tamanho_max)
{
    if (fgets(destino, tamanho_max, stdin) == NULL)
    {
        return 0; // Falha na leitura (Ctrl+D/Ctrl+C)
    }

    size_t len = strlen(destino);
    if (len > 0 && destino[len - 1] == '\n')
    {
        destino[len - 1] = '\0'; // Remove newline
        return 1;                // Leitura bem-sucedida, dentro do limite
    }
    else
    {
        limparBuffer(); // Limpa excesso de caracteres
        return 2;       // Leitura com truncamento
    }
}

int main()
{
    setlocale(LC_ALL, "pt_BR.UTF-8");

    int op;
    do
    {
        printf("\nBem vindo ao C-Note\n");
        printf(
            "\n Escolha umas das opC'C5es:\n 1 - Criar Nota\n 2 - Editar uma Nota\n 3 "
            "- Listar Notas\n 4 - Excluir uma Nota\n\n ");

        scanf("%d", &op);
        getchar();
        listaNotas novaNota;

        switch (op)
        {
        case 1:

            printf("Adicione um titulo a sua nota: 40 Char Max \n");
            int status_titulo = lerStringSegura(titulo, MAX_TITULO + 1);
            if (status_titulo == 0)
            {
                printf("Entrada cancelada pelo usuário\n");
                return 1;
            }

            printf("Adicione um texto a sua nota: 200 Char Max \n");
            int status_texto = lerStringSegura(texto, MAX_TEXTO + 1);
            if (status_texto == 0)
            {
                printf("Entrada cancelada pelo usuário\n");
                return 1;
            }

            for (int i = 0; i < 3; i++)
            {
                printf("Adicione uma tag a sua nota: 20 Char Max \n");
                int status_tag = lerStringSegura(tag, MAX_TAG + 1);
                if (status_tag == 0)
                {
                    printf("Entrada cancelada pelo usuário\n");
                    return 1;
                }
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
            printf("Escolha uma opC'C#o valida!");
            break;
        }
    } while (1);

    return 0;
}
void ListarNota()
{
    // divide o tamanho total da Lista pela do primeiro item
    // int tamanho = sizeof(Listas) / sizeof(Listas[0]);

    if (tamanho == 0)
    {
        printf("Nenhuma nota cadastrada!\n");
        return;
    }

    // loop para ler todas as tags armazenadas no array
    for (int i = 0; i < tamanho; i++)
    {
        // funC'C#o que verifica se a nota nC#o esta vazia antes de imprimir

        printf("---------------------\n");
        // acessando o indice de acordo com
        printf("Id: %i\n", Listas[i].id);
        printf("Titulo: %s\n", Listas[i].titulo);
        printf("Texto: %s\n", Listas[i].texto);
        printf("Tags: ");
        for (int j = 0; j < 3; j++)
        {
            // verificando se a tag nC#o C) vazia ja que se for vazia ela vai conter apenas'\n'
            if (Listas[i].tags.tag[j][0] != '\0')
            {
                printf("%s ", Listas[i].tags.tag[j]);
            }
        }
        printf("\n---------------------");
    }
}

void CriarNota(listaNotas novaNota)
{
    // incrementando o contador  por estar criando uma nova nota
    tamanho++;
    // verificamos se existe espaC'o de memoria em Listas pra guarda a nova nota com o realloc, caso nC#o tenha
    //  ele retorna null, com isso pra evitar perder os dados ao tentar realocar os dados atribuimos o realloc
    //  ao um ponteiro que guarda o endereC'o "*temp" de memoria dos dados da listas, caso  de certo ele "temp" passa os dados pra Listas
    void *temp = realloc(Listas, tamanho * sizeof(listaNotas));

    if (temp == NULL)
    {
        printf("Erro ao alocar memC3ria!\n");
        exit(1);
    }

    Listas = temp;

    Listas[tamanho - 1].id = novaNota.id;
    // strncpy(destino , origem, remover o ultimo caracter) C) responsavel por transferir um dado de uma variavel para outra
    strncpy(Listas[tamanho - 1].titulo, novaNota.titulo, sizeof(Listas[tamanho - 1].titulo) - 1);

    strncpy(Listas[tamanho - 1].texto, novaNota.texto, sizeof(Listas[tamanho - 1].texto) - 1);

    for (int i = 0; i < 3; i++)
    {
        strncpy(Listas[tamanho - 1].tags.tag[i], novaNota.tags.tag[i], sizeof(Listas[tamanho - 1].tags.tag[i]) - 1);
    }
    printf("Nota Salva com sucesso!!\n");
}
void EditarNota()
{
    printf("foi 2");
}
void DeletarNota()
{
    printf("foi 2");
}
