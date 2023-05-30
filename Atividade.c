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

void cadastrarUsuario(int usuarioCount) {
    if (usuarioCount == MAX_USUARIOS) {
        printf("Limite de usuarios cadastrados atingido.\n");
        return;
    }

    int novoUsuarioID = rand();
    id[usuarioCount] = novoUsuarioID;

    printf("Insira o nome do usuario em questao (Digite 'p' para parar): ");
    fgets(nome[usuarioCount], 40, stdin);
    fflush(stdin);
    getchar();

    if (nome[usuarioCount][0] == 'p') {
        system("cls");
        return;
    }

    do {
        printf("Informe o email a ser usado: ");
        fgets(email[usuarioCount], 40, stdin);
        fflush(stdin);
    } while (strchr(email[usuarioCount], '@') == NULL);

    do {
        printf("Qual a altura do usuario? ");
        scanf("%lf", &altura[usuarioCount]);
        fflush(stdin);
    } while (altura[usuarioCount] <= 1 || altura[usuarioCount] >= 2);

    do {
        printf("O usuario e vacinado? (1 - Sim) (0 - Nao) ");
        scanf("%d", &vacina[usuarioCount]);
        fflush(stdin);
    } while (vacina[usuarioCount] != 1 && vacina[usuarioCount] != 0);

    do {
        printf("Qual o sexo do usuario? ");
        fgets(sexo[usuarioCount], 20, stdin);
        fflush(stdin);
    } while (strcmp(sexo[usuarioCount], "Masculino\n") != 0 && strcmp(sexo[usuarioCount], "Feminino\n") != 0 && strcmp(sexo[usuarioCount], "Indiferente\n") != 0);

    printf("Qual o endereco do usuario? ");
    fgets(endereco[usuarioCount], 100, stdin);
    fflush(stdin);

    printf("Usuario cadastrado com sucesso!\n");
    printf("ID do usuario criado: %d\n", novoUsuarioID);
}

void editarUsuario(int usuarioCount) {
    int idSearch;
    printf("Digite o ID do usuario a ser editado: ");
    scanf("%d", &idSearch);

    for (int i = 0; i < usuarioCount; i++) {
        if (id[i] == idSearch) {
            printf("Usuario encontrado!\n");
            printf("Nome: %s\n", nome[i]);
            printf("Email: %s\n", email[i]);
            printf("Altura: %.2lf\n", altura[i]);
            printf("Vacinado: %s\n", vacina[i] ? "Sim" : "Nao");
            printf("Sexo: %s\n", sexo[i]);
            printf("Endereco: %s\n", endereco[i]);

            printf("\nDigite os novos dados do usuario:\n");

            int opcao;
            do {
                printf("Opcoes de edicao:\n");
                printf("1. Nome\n");
                printf("2. Email\n");
                printf("3. Altura\n");
                printf("4. Vacinado\n");
                printf("5. Sexo\n");
                printf("6. Endereco\n");
                printf("0. Sair\n");

                printf("Digite a opcao desejada: ");
                scanf("%d", &opcao);

                switch (opcao) {
                    case 0:
                        printf("Saindo da edicao...\n");
                        break;
                    case 1:
                        printf("Novo Nome: ");
                        getchar();
                        fgets(nome[i], 40, stdin);
                        break;
                    case 2:
                        printf("Novo Email: ");
                        getchar();
                        fgets(email[i], 40, stdin);
                        break;
                    case 3:
                        printf("Nova Altura: ");
                        scanf("%lf", &altura[i]);
                        break;
                    case 4:
                        printf("Vacinado (1 - Sim / 0 - Nao): ");
                        scanf("%d", &vacina[i]);
                        break;
                    case 5:
                        printf("Novo Sexo: ");
                        getchar();
                        fgets(sexo[i], 20, stdin);
                        break;
                    case 6:
                        printf("Novo Endereco: ");
                        getchar();
                        fgets(endereco[i], 100, stdin);
                        break;
                    default:
                        printf("Opcao invalida. Digite novamente.\n");
                        break;
                }
            } while (opcao != 0);

            printf("Usuario editado com sucesso!\n");

            return;
        }
    }

    printf("Usuario nao encontrado.\n");
}

void excluirUsuario(int *usuarioCount) {
    int idSearch;
    printf("Digite o ID do usuario a ser excluido: ");
    scanf("%d", &idSearch);

    for (int i = 0; i < *usuarioCount; i++) {
        if (id[i] == idSearch) {
            for (int j = i; j < (*usuarioCount) - 1; j++) {
                id[j] = id[j + 1];
                strcpy(nome[j], nome[j + 1]);
                strcpy(email[j], email[j + 1]);
                altura[j] = altura[j + 1];
                vacina[j] = vacina[j + 1];
                strcpy(sexo[j], sexo[j + 1]);
                strcpy(endereco[j], endereco[j + 1]);
            }
            (*usuarioCount)--;
            printf("Usuario excluido com sucesso!\n");
            return;
        }
    }

    printf("Usuario nao encontrado.\n");
}

void buscarUsuarioPorEmail(int usuarioCount) {
    char emailSearch[40];
    printf("Digite o email do usuario a ser buscado: ");
    fgets(emailSearch, 40, stdin);

    for (int i = 0; i < usuarioCount; i++) {
        if (strcmp(email[i], emailSearch) == 0) {
            printf("Usuario encontrado!\n");
            printf("ID: %d\n", id[i]);
            printf("Nome: %s\n", nome[i]);
            printf("Email: %s\n", email[i]);
            printf("Altura: %.2lf\n", altura[i]);
            printf("Vacinado: %s\n", vacina[i] ? "Sim" : "Nao");
            printf("Sexo: %s\n", sexo[i]);
            printf("Endereco: %s\n", endereco[i]);
            return;
        }
    }

    printf("Usuario nao encontrado.\n");
}

void listarUsuarios(int usuarioCount) {
    if (usuarioCount == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    for (int i = 0; i < usuarioCount; i++) {
        printf("ID: %d\n", id[i]);
        printf("Nome: %s\n", nome[i]);
        printf("Email: %s\n", email[i]);
        printf("Altura: %.2lf\n", altura[i]);
        printf("Vacinado: %s\n", vacina[i] ? "Sim" : "Nao");
        printf("Sexo: %s\n", sexo[i]);
        printf("Endereco: %s\n", endereco[i]);
        printf("------------------------------\n");
    }
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
            case 3:
                printf("\n=========================================\n");
                printf("          Exclusao de Usuario\n");
                printf("=========================================\n");
                excluirUsuario(&usuarioCount);
                break;
            case 4:
                printf("\n=========================================\n");
                printf("          Busca de Usuario por Email\n");
                printf("=========================================\n");
                buscarUsuarioPorEmail(usuarioCount);
                break;
            case 5:
                printf("\n=========================================\n");
                printf("          Lista de Usuarios Cadastrados\n");
                printf("=========================================\n");
                listarUsuarios(usuarioCount);
                break;
            default:
                printf("Opcao invalida. Por favor, digite novamente.\n");
                break;
        }

        printf("\n");
    } while (opcao != 0);

    return 0;
}

