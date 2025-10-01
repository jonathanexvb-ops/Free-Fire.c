#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Definição da struct que representa cada item do inventário
typedef struct {
    char nome[30];
    char tipo[20];
    int quantidade;
} Item;

// Capacidade máxima do inventário
#define MAX_ITENS 10

// Vetor que armazena os itens e variável que indica a quantidade atual
Item mochila[MAX_ITENS];
int totalItens = 0;

// Função para listar todos os itens cadastrados
void listarItens() {
    printf("\nItens na mochila:\n");
    if (totalItens == 0) {
        printf("A mochila está vazia.\n");
    } else {
        for (int i = 0; i < totalItens; i++) {
            printf("Nome: %s | Tipo: %s | Quantidade: %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
        }
    }
}

// Função para cadastrar um novo item na mochila
void inserirItem() {
    if (totalItens >= MAX_ITENS) {
        printf("A mochila está cheia. Remova um item antes de adicionar outro.\n");
        return;
    }

    Item novoItem;
    printf("Digite o nome do item: ");
    scanf(" %29[^\n]", novoItem.nome);
    printf("Digite o tipo do item (arma/munição/cura): ");
    scanf(" %19[^\n]", novoItem.tipo);
    printf("Digite a quantidade: ");
    scanf("%d", &novoItem.quantidade);

    mochila[totalItens++] = novoItem;
    printf("Item adicionado com sucesso!\n");
    listarItens();
}

// Função para remover um item pelo nome
void removerItem() {
    if (totalItens == 0) {
        printf("A mochila está vazia. Não há itens para remover.\n");
        return;
    }

    char nomeRemover[30];
    printf("Digite o nome do item a remover: ");
    scanf(" %29[^\n]", nomeRemover);

    int encontrado = 0;
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeRemover) == 0) {
            // Desloca os itens seguintes para preencher o espaço
            for (int j = i; j < totalItens - 1; j++) {
                mochila[j] = mochila[j + 1];
            }
            totalItens--;
            encontrado = 1;
            printf("Item removido com sucesso!\n");
            break;
        }
    }
    if (!encontrado) {
        printf("Item não encontrado na mochila.\n");
    }
    listarItens();
}

// Função para buscar um item pelo nome
void buscarItem() {
    if (totalItens == 0) {
        printf("A mochila está vazia. Não há itens para buscar.\n");
        return;
    }

    char nomeBuscar[30];
    printf("Digite o nome do item a buscar: ");
    scanf(" %29[^\n]", nomeBuscar);

    int encontrado = 0;
    for (int i = 0; i < totalItens; i++) {
        if (strcmp(mochila[i].nome, nomeBuscar) == 0) {
            printf("Item encontrado: Nome: %s | Tipo: %s | Quantidade: %d\n", mochila[i].nome, mochila[i].tipo, mochila[i].quantidade);
            encontrado = 1;
            break;
        }
    }
    if (!encontrado) {
        printf("Item não encontrado na mochila.\n");
    }
}

int main() {
    int opcao;

    do {
        printf("\n=== Sistema de Inventário ===\n");
        printf("1 - Adicionar item\n");
        printf("2 - Remover item\n");
        printf("3 - Listar itens\n");
        printf("4 - Buscar item\n");
        printf("0 - Sair\n");
        printf("Escolha uma opção: ");
        scanf("%d", &opcao);

        switch(opcao) {
            case 1: inserirItem(); break;
            case 2: removerItem(); break;
            case 3: listarItens(); break;
            case 4: buscarItem(); break;
            case 0: printf("Saindo do sistema...\n"); break;
            default: printf("Opção inválida!\n");
        }
    } while(opcao != 0);

    return 0;
}
