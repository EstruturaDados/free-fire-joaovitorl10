#include <stdio.h>
#include <string.h>

#define MAX_ITENS 10

// Struct para representar um item da mochila
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Função para adicionar um item ao vetor
int inserirItem(Item mochila[], int *total) {
    if (*total >= MAX_ITENS) {
        printf("Mochila cheia!\n");
        return 0;
    }
    printf("Digite o nome do item: ");
    scanf("%29s", mochila[*total].nome);
    printf("Digite o tipo do item: ");
    scanf("%19s", mochila[*total].tipo);
    printf("Digite a quantidade: ");
    scanf("%d", &mochila[*total].quantidade);
    (*total)++;
    printf("Item adicionado com sucesso!\n");
    return 1;
}

// Função para remover um item pelo nome
int removerItem(Item mochila[], int *total) {
    char nome[30];
    printf("Digite o nome do item a remover: ");
    scanf("%29s", nome);
    for (int i = 0; i < *total; i++) {
        if (strcmp(mochila[i].nome, nome) == 0) {
            for (int j = i; j < *total - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            (*total)--;
            printf("Item removido com sucesso!\n");
            return 1;
        }
    }
    printf("Item não encontrado!\n");
    return 0;
}

// Função para listar todos os itens
void listarItens(Item mochila[], int total) {
    printf("\nItens na mochila:\n");
    printf("---------------------------------------------\n");
    printf("| %-28s | %-18s | %-10s |\n", "Nome", "Tipo", "Quantidade");
    printf("---------------------------------------------\n");
    for (int i = 0; i < total; i++) {
        printf("| %-28s | %-18s | %-10d |\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
    }
    printf("---------------------------------------------\n");
}

// Função para buscar item por nome (sequencial)
void buscarItem(Item mochila[], int total) {
    char nome[30];
    int encontrado = 0, comparacoes = 0;
    printf("Digite o nome do item a buscar: ");
    scanf("%29s", nome);
    for (int i = 0; i < total; i++) {
        comparacoes++;
        if (strcmp(mochila[i].nome, nome) == 0) {
            printf("Item encontrado!\n");
            printf("Nome: %s\nTipo: %s\nQuantidade: %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Item não encontrado!\n");
    }
    printf("Comparações realizadas: %d\n", comparacoes);
}

int main() {
    Item mochila[MAX_ITENS];
    int total = 0;
    int opcao;
    do {
        printf("\n===== Menu Mochila =====\n");
        printf("1. Adicionar item\n");
        printf("2. Remover item\n");
        printf("3. Listar itens\n");
        printf("4. Buscar item por nome\n");
        printf("0. Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);
        switch (opcao) {
            case 1:
                inserirItem(mochila, &total);
                break;
            case 2:
                removerItem(mochila, &total);
                break;
            case 3:
                listarItens(mochila, total);
                break;
            case 4:
                buscarItem(mochila, total);
                break;
            case 0:
                printf("Saindo...\n");
                break;
            default:
                printf("Opção inválida!\n");
        }
    } while (opcao != 0);
    return 0;
}
