#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USUARIOS 1000

int id[MAX_USUARIOS];
char nome[MAX_USUARIOS][40];
char email[MAX_USUARIOS][40];
double altura[MAX_USUARIOS];
int vacina[MAX_USUARIOS];
char sexo[MAX_USUARIOS][20];
char endereco[MAX_USUARIOS][100];

void cadastrarUsuario(int contadorUsuarios) {
    if (contadorUsuarios == MAX_USUARIOS) {
        printf("Limite de usuarios cadastrados atingido.\n");
        return;
    }

    int novoUsuarioID = rand();
    id[contadorUsuarios] = novoUsuarioID;

    printf("Insira o nome do usuario em questao (Digite 'p' para parar): ");
    fgets(nome[contadorUsuarios], 40, stdin);
    fflush(stdin);
    getchar();

    if (nome[contadorUsuarios][0] == 'p') {
        system("cls");
        return;
    }

    do {
        printf("Informe o email a ser usado: ");
        fgets(email[contadorUsuarios], 40, stdin);
        fflush(stdin);
    } while (strchr(email[contadorUsuarios], '@') == NULL);

    do {
        printf("Qual a altura do usuario? ");
        scanf("%lf", &altura[contadorUsuarios]);
        fflush(stdin);
    } while (altura[contadorUsuarios] <= 1 || altura[contadorUsuarios] >= 2);

    do {
        printf("O usuario e vacinado? (1 - Sim) (0 - Nao) ");
        scanf("%d", &vacina[contadorUsuarios]);
        fflush(stdin);
    } while (vacina[contadorUsuarios] != 1 && vacina[contadorUsuarios] != 0);

    do {
        printf("Qual o sexo do usuario? ");
        fgets(sexo[contadorUsuarios], 20, stdin);
        fflush(stdin);
    } while (strcmp(sexo[contadorUsuarios], "Masculino\n") != 0 && strcmp(sexo[contadorUsuarios], "Feminino\n") != 0 && strcmp(sexo[contadorUsuarios], "Indiferente\n") != 0);

    printf("Qual o endereco do usuario? ");
    fgets(endereco[contadorUsuarios], 100, stdin);
    fflush(stdin);

    printf("Usuario cadastrado com sucesso!\n");
    printf("ID do usuario criado: %d\n", novoUsuarioID);
}
int main() {
    srand(time(NULL));

    int usuarioCount = 0;

    int opcao;
    do {
        printf("\n=========================================\n");
        printf("          Sistema de Cadastro\n");
        printf("=========================================\n");
        printf("Opcoes disponiveis:\n");
        printf("1. Cadastrar um novo usuario\n");
        printf("2. Editar informacoes de um usuario\n");
        printf("3. Excluir um usuario\n");
        printf("4. Buscar um usuario pelo email\n");
        printf("5. Listar todos os usuarios\n");
        printf("0. Sair do programa\n");
        printf("=========================================\n");

        printf("Digite o numero da opcao desejada: ");
        scanf("%d", &opcao);
        fflush(stdin);

        switch (opcao) {
            case 0:
                printf("Saindo do programa...\n");
                break;
            case 1:
                printf("\n=========================================\n");
                printf("          Cadastro de Usuario\n");
                printf("=========================================\n");
                cadastrarUsuario(usuarioCount);
                usuarioCount++;
                break;
            case 2:
                printf("\n=========================================\n");
                printf("          Edicao de Usuario\n");
                printf("=========================================\n");
                editarUsuario(usuarioCount);
                break;

            default:
                printf("Opcao invalida. Por favor, digite novamente.\n");
                break;
        }

        printf("\n");
    } while (opcao != 0);

    return 0;
}