#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define MAX_USUARIOS 1000

typedef struct Usuario {
    int id, vacina;
    char nome[100], endereco[100], email[100], sexo[15];
    double altura;
} Usuario;

void cadastro(Usuario usuarios[], int usuariosCount) {
    if (usuariosCount == MAX_USUARIOS) {
        printf("Limite de usuarios cadastrados atingido.\n");
        return;
    }

    usuarios[usuariosCount].id = rand() % 10000;

    printf("Insira o nome do usuario (Digite 'p' para parar): ");
    fgets(usuarios[usuariosCount].nome, 100, stdin);
    strtok(usuarios[usuariosCount].nome, "\n");

    if (strcmp(usuarios[usuariosCount].nome, "p") == 0) {
        printf("Cadastro interrompido.\n");
        return;
    }

    do {
        printf("Insira o email a ser usado: ");
        fgets(usuarios[usuariosCount].email, 100, stdin);
        strtok(usuarios[usuariosCount].email, "\n");
    } while (strchr(usuarios[usuariosCount].email, '@') == NULL);

    do {
        printf("Qual a altura do usuario? ");
        scanf("%lf", &usuarios[usuariosCount].altura);
        getchar();
    } while (usuarios[usuariosCount].altura <= 1 || usuarios[usuariosCount].altura >= 2);

    do {
        printf("O usuario e vacinado? (1 - Sim / 0 - Nao) ");
        scanf("%d", &usuarios[usuariosCount].vacina);
        getchar();
    } while (usuarios[usuariosCount].vacina != 1 && usuarios[usuariosCount].vacina != 0);

    do {
        printf("Qual o sexo do usuario? ");
        fgets(usuarios[usuariosCount].sexo, 15, stdin);
        strtok(usuarios[usuariosCount].sexo, "\n");
    } while (
        strcmp(usuarios[usuariosCount].sexo, "Masculino") != 0 &&
        strcmp(usuarios[usuariosCount].sexo, "Feminino") != 0 &&
        strcmp(usuarios[usuariosCount].sexo, "Indiferente") != 0
    );

    printf("Qual o endereco do usuario? ");
    fgets(usuarios[usuariosCount].endereco, 100, stdin);
    strtok(usuarios[usuariosCount].endereco, "\n");

    printf("Usuario cadastrado com sucesso!\n");
    printf("ID do usuario criado: %d\n", usuarios[usuariosCount].id);
}

void editarUsuario(Usuario usuarios[], int usuariosCount) {
    int idSearch;
    printf("Digite o ID do usuario a ser editado: ");
    scanf("%d", &idSearch);
    getchar();

    for (int i = 0; i < usuariosCount; i++) {
        if (usuarios[i].id == idSearch) {
            printf("Usuario encontrado!\n");
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Altura: %.2lf\n", usuarios[i].altura);
            printf("Vacinado: %s\n", usuarios[i].vacina ? "Sim" : "Nao");
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereco: %s\n", usuarios[i].endereco);

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
                getchar();

                switch (opcao) {
                    case 0:
                        printf("Saindo da edicao...\n");
                        break;
                    case 1:
                        printf("Novo Nome: ");
                        fgets(usuarios[i].nome, 100, stdin);
                        strtok(usuarios[i].nome, "\n");
                        break;
                    case 2:
                        printf("Novo Email: ");
                        fgets(usuarios[i].email, 100, stdin);
                        strtok(usuarios[i].email, "\n");
                        break;
                    case 3:
                        printf("Nova Altura: ");
                        scanf("%lf", &usuarios[i].altura);
                        getchar();
                        break;
                    case 4:
                        printf("Vacinado (1 - Sim / 0 - Nao): ");
                        scanf("%d", &usuarios[i].vacina);
                        getchar();
                        break;
                    case 5:
                        printf("Novo Sexo: ");
                        fgets(usuarios[i].sexo, 15, stdin);
                        strtok(usuarios[i].sexo, "\n");
                        break;
                    case 6:
                        printf("Novo Endereco: ");
                        fgets(usuarios[i].endereco, 100, stdin);
                        strtok(usuarios[i].endereco, "\n");
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

void excluirUsuario(Usuario usuarios[], int* usuariosCount) {
    int idSearch;
    printf("Digite o ID do usuario a ser excluido: ");
    scanf("%d", &idSearch);
    getchar();

    for (int i = 0; i < *usuariosCount; i++) {
        if (usuarios[i].id == idSearch) {
            for (int j = i; j < (*usuariosCount) - 1; j++) {
                usuarios[j] = usuarios[j + 1];
            }
            (*usuariosCount)--;
            printf("Usuario excluido com sucesso!\n");
            return;
        }
    }

    printf("Usuario nao encontrado.\n");
}

void buscarUsuarioPorEmail(const Usuario usuarios[], int usuariosCount) {
    char emailSearch[100];
    printf("Digite o email do usuario a ser buscado: ");
    fgets(emailSearch, 100, stdin);
    strtok(emailSearch, "\n");

    for (int i = 0; i < usuariosCount; i++) {
        if (strcmp(usuarios[i].email, emailSearch) == 0) {
            printf("Usuario encontrado!\n");
            printf("ID: %d\n", usuarios[i].id);
            printf("Nome: %s\n", usuarios[i].nome);
            printf("Email: %s\n", usuarios[i].email);
            printf("Altura: %.2lf\n", usuarios[i].altura);
            printf("Vacinado: %s\n", usuarios[i].vacina ? "Sim" : "Nao");
            printf("Sexo: %s\n", usuarios[i].sexo);
            printf("Endereco: %s\n", usuarios[i].endereco);
            return;
        }
    }

    printf("Usuario nao encontrado.\n");
}

void listarUsuarios(const Usuario usuarios[], int usuariosCount) {
    if (usuariosCount == 0) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    for (int i = 0; i < usuariosCount; i++) {
        printf("ID: %d\n", usuarios[i].id);
        printf("Nome: %s\n", usuarios[i].nome);
        printf("Email: %s\n", usuarios[i].email);
        printf("Altura: %.2lf\n", usuarios[i].altura);
        printf("Vacinado: %s\n", usuarios[i].vacina ? "Sim" : "Nao");
        printf("Sexo: %s\n", usuarios[i].sexo);
        printf("Endereco: %s\n", usuarios[i].endereco);
        printf("------------------------------\n");
    }
}

int main() {
    srand(time(NULL));

    int usuariosCount = 0;
    Usuario usuarios[MAX_USUARIOS];

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
        getchar();

        switch (opcao) {
            case 0:
                printf("Saindo do programa...\n");
                break;
            case 1:
                printf("\n=========================================\n");
                printf("          Cadastro de Usuario\n");
                printf("=========================================\n");
                cadastro(usuarios, &usuariosCount);
                break;
            case 2:
                printf("\n=========================================\n");
                printf("          Edicao de Usuario\n");
                printf("=========================================\n");
                editarUsuario(usuarios, usuariosCount);
                break;
            case 3:
                printf("\n=========================================\n");
                printf("          Exclusao de Usuario\n");
                printf("=========================================\n");
                excluirUsuario(usuarios, &usuariosCount);
                break;
            case 4:
                printf("\n=========================================\n");
                printf("          Busca de Usuario por Email\n");
                printf("=========================================\n");
                buscarUsuarioPorEmail(usuarios, usuariosCount);
                break;
            case 5:
                printf("\n=========================================\n");
                printf("          Lista de Usuarios\n");
                printf("=========================================\n");
                listarUsuarios(usuarios, usuariosCount);
                break;
            default:
                printf("Opcao invalida. Digite novamente.\n");
                break;
        }
    } while (opcao != 0);

    return 0;
}
