#include <stdio.h>
#include <stdlib.h>

/*
Exercicio 5 - Comparando busca sequencial e busca em arvore
*/

typedef struct No {
    int valor;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(int valor) {
    No *novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    novo->valor = valor;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}

No* inserir(No *raiz, int valor) {
    if (raiz == NULL) {
        return criarNo(valor);
    }

    if (valor < raiz->valor) {
        raiz->esquerda = inserir(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = inserir(raiz->direita, valor);
    }

    return raiz;
}

int buscaSequencial(int vetor[], int tamanho, int valorBuscado, int *comparacoes) {
    int i;
    *comparacoes = 0;

    for (i = 0; i < tamanho; i++) {
        (*comparacoes)++;

        if (vetor[i] == valorBuscado) {
            return 1;
        }
    }

    return 0;
}

int buscaNaArvore(No *raiz, int valorBuscado, int *comparacoes) {
    *comparacoes = 0;

    while (raiz != NULL) {
        (*comparacoes)++;

        if (valorBuscado == raiz->valor) {
            return 1;
        }

        if (valorBuscado < raiz->valor) {
            raiz = raiz->esquerda;
        } else {
            raiz = raiz->direita;
        }
    }

    return 0;
}

void liberarArvore(No *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    int vetor[] = {
        50, 30, 70, 20, 40, 60, 80, 10, 25, 35,
        45, 55, 65, 75, 85, 5, 15, 27, 33, 90
    };

    int tamanho = sizeof(vetor) / sizeof(vetor[0]);
    int valorBuscado = 75;
    int comparacoesSequencial;
    int comparacoesArvore;
    int encontradoSequencial;
    int encontradoArvore;
    int i;

    No *raiz = NULL;

    for (i = 0; i < tamanho; i++) {
        raiz = inserir(raiz, vetor[i]);
    }

    encontradoSequencial = buscaSequencial(vetor, tamanho, valorBuscado, &comparacoesSequencial);
    encontradoArvore = buscaNaArvore(raiz, valorBuscado, &comparacoesArvore);

    printf("Valor buscado: %d\n", valorBuscado);

    printf("\nBusca sequencial:\n");
    if (encontradoSequencial) {
        printf("Encontrado.\n");
    } else {
        printf("Nao encontrado.\n");
    }
    printf("Comparacoes: %d\n", comparacoesSequencial);

    printf("\nBusca na arvore:\n");
    if (encontradoArvore) {
        printf("Encontrado.\n");
    } else {
        printf("Nao encontrado.\n");
    }
    printf("Comparacoes: %d\n", comparacoesArvore);

    liberarArvore(raiz);

    return 0;
}