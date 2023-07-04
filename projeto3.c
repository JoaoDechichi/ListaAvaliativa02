#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_NOME_LENGTH 50
#define MAX_EMAIL_LENGTH 50
#define MAX_ENDERECO_LENGTH 100

struct Pessoa {
    int id;
    char nome[MAX_NOME_LENGTH];
    char email[MAX_EMAIL_LENGTH];
    char sexo[MAX_NOME_LENGTH];
    char endereco[MAX_ENDERECO_LENGTH];
    double altura;
    int vacina;
    struct Pessoa* proximo;
};

typedef struct Pessoa Pessoa;

Pessoa* criarPessoa(int id) {
    Pessoa* pessoa = (Pessoa*)malloc(sizeof(Pessoa));
    pessoa->id = id;
    pessoa->proximo = NULL;
    return pessoa;
}

void cadastrar(Pessoa* pessoa) {
    printf("Digite o nome completo: ");
    fgets(pessoa->nome, MAX_NOME_LENGTH, stdin);
    pessoa->nome[strcspn(pessoa->nome, "\n")] = '\0';

    printf("Digite o email: ");
    fgets(pessoa->email, MAX_EMAIL_LENGTH, stdin);
    pessoa->email[strcspn(pessoa->email, "\n")] = '\0';

    printf("Digite o sexo (Masculino, Feminino, Indefinido): ");
    fgets(pessoa->sexo, MAX_NOME_LENGTH, stdin);
    pessoa->sexo[strcspn(pessoa->sexo, "\n")] = '\0';

    printf("Digite o endereco: ");
    fgets(pessoa->endereco, MAX_ENDERECO_LENGTH, stdin);
    pessoa->endereco[strcspn(pessoa->endereco, "\n")] = '\0';

    printf("Digite a altura: ");
    scanf("%lf", &pessoa->altura);
    getchar();

    printf("Digite a vacina (0 - Nao, 1 - Sim): ");
    scanf("%d", &pessoa->vacina);
    getchar();
}

void editarUsuario(Pessoa* lista, int usuariosCount) {
    int id;

    printf("Digite o ID do usuario a ser editado: ");
    scanf("%d", &id);
    getchar();

    Pessoa* atual = lista;
    int encontrado = 0;

    while (atual != NULL) {
        if (atual->id == id) {
            printf("\n=========================================\n");
            printf("          Edicao de Usuario\n");
            printf("=========================================\n");
            printf("Usuario encontrado:\n");
            printf("ID: %d\n", atual->id);
            printf("Nome: %s\n", atual->nome);
            printf("Email: %s\n", atual->email);
            printf("Sexo: %s\n", atual->sexo);
            printf("Endereco: %s\n", atual->endereco);
            printf("Altura: %.2lf\n", atual->altura);
            printf("Vacina: %d\n", atual->vacina);

            printf("\nDigite as novas informacoes:\n");
            cadastrar(atual);
            encontrado = 1;
            break;
        }
        atual = atual->proximo;
    }

    if (!encontrado) {
        printf("Nenhum usuario encontrado com o ID %d\n", id);
    }
}

void excluirUsuario(Pessoa** lista, int* usuariosCount) {
    int id;

    printf("Digite o ID do usuario a ser excluido: ");
    scanf("%d", &id);
    getchar();

    Pessoa* atual = *lista;
    Pessoa* anterior = NULL;
    int encontrado = 0;

    while (atual != NULL) {
        if (atual->id == id) {
            if (anterior == NULL) {
                *lista = atual->proximo;
            } else {
                anterior->proximo = atual->proximo;
            }
            free(atual);
            encontrado = 1;
            (*usuariosCount)--;
            printf("Usuario com o ID %d foi excluido com sucesso.\n", id);
            break;
        }
        anterior = atual;
        atual = atual->proximo;
    }

    if (!encontrado) {
        printf("Nenhum usuario encontrado com o ID %d\n", id);
    }
}

void buscarPessoaPorEmail(Pessoa* lista, const char* emailBusca) {
    Pessoa* atual = lista;
    int encontrado = 0;

    while (atual != NULL) {
        if (strcmp(atual->email, emailBusca) == 0) {
            printf("\n=========================================\n");
            printf("          Busca de Usuario por Email\n");
            printf("=========================================\n");
            printf("Usuario encontrado:\n");
            printf("ID: %d\n", atual->id);
            printf("Nome: %s\n", atual->nome);
            printf("Email: %s\n", atual->email);
            printf("Sexo: %s\n", atual->sexo);
            printf("Endereco: %s\n", atual->endereco);
            printf("Altura: %.2lf\n", atual->altura);
            printf("Vacina: %d\n", atual->vacina);
            encontrado = 1;
            break;
        }
        atual = atual->proximo;
    }

    if (!encontrado) {
        printf("Nenhum usuario encontrado com o email %s\n", emailBusca);
    }
}


void listarUsuarios(Pessoa* lista) {
    if (lista == NULL) {
        printf("Nenhum usuario cadastrado.\n");
        return;
    }

    printf("Lista de Usuarios:\n");

    Pessoa* atual = lista;

    while (atual != NULL) {
        printf("-----------------------------\n");
        printf("ID: %d\n", atual->id);
        printf("Nome: %s\n", atual->nome);
        printf("Email: %s\n", atual->email);
        printf("Sexo: %s\n", atual->sexo);
        printf("Endereco: %s\n", atual->endereco);
        printf("Altura: %.2lf\n", atual->altura);
        printf("Vacina: %d\n", atual->vacina);
        printf("-----------------------------\n");
        atual = atual->proximo;
    }
}

void liberarLista(Pessoa* lista) {
    Pessoa* atual = lista;
    Pessoa* proximo;

    while (atual != NULL) {
        proximo = atual->proximo;
        free(atual);
        atual = proximo;
    }
}

int main() {
    int opcao, usuariosCount = 0;
    Pessoa* lista = NULL;
    char emailBusca[MAX_EMAIL_LENGTH];

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
                usuariosCount++;
                Pessoa* novaPessoa = criarPessoa(usuariosCount);
                cadastrar(novaPessoa);
                if (lista == NULL) {
                    lista = novaPessoa;
                } else {
                    Pessoa* atual = lista;
                    while (atual->proximo != NULL) {
                        atual = atual->proximo;
                    }
                    atual->proximo = novaPessoa;
                }
                break;
            case 2:
                printf("\n=========================================\n");
                printf("          Edicao de Usuario\n");
                printf("=========================================\n");
                editarUsuario(lista, usuariosCount);
                break;
            case 3:
                printf("\n=========================================\n");
                printf("          Exclusao de Usuario\n");
                printf("=========================================\n");
                excluirUsuario(&lista, &usuariosCount);
                break;
            case 4:
                printf("\n=========================================\n");
                printf("          Busca de Usuario por Email\n");
                printf("=========================================\n");
                printf("Digite o email a ser buscado: ");
                fgets(emailBusca, MAX_EMAIL_LENGTH, stdin);
                emailBusca[strcspn(emailBusca, "\n")] = '\0';
                buscarPessoaPorEmail(lista, emailBusca);
                break;
            case 5:
                printf("\n=========================================\n");
                printf("          Lista de Usuarios\n");
                printf("=========================================\n");
                listarUsuarios(lista);
                break;
            default:
                printf("Opcao invalida. Digite novamente.\n");
                break;
        }
    } while (opcao != 0);

    liberarLista(lista);

    return 0;
}
