#include <stdio.h>
#include <stdlib.h>

/*
Exercicio 3 - Menor e maior valor da arvore
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

int menorValor(No *raiz) {
    if (raiz == NULL) {
        printf("A arvore esta vazia.\n");
        exit(1);
    }

    while (raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }

    return raiz->valor;
}

int maiorValor(No *raiz) {
    if (raiz == NULL) {
        printf("A arvore esta vazia.\n");
        exit(1);
    }

    while (raiz->direita != NULL) {
        raiz = raiz->direita;
    }

    return raiz->valor;
}

void imprimirEmOrdem(No *raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d ", raiz->valor);
        imprimirEmOrdem(raiz->direita);
    }
}

void liberarArvore(No *raiz) {
    if (raiz != NULL) {
        liberarArvore(raiz->esquerda);
        liberarArvore(raiz->direita);
        free(raiz);
    }
}

int main() {
    No *raiz = NULL;
    int valores[] = {50, 30, 70, 20, 40, 60, 80, 10, 35, 90};
    int quantidade = sizeof(valores) / sizeof(valores[0]);
    int i;

    for (i = 0; i < quantidade; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    printf("Valores em ordem: ");
    imprimirEmOrdem(raiz);

    printf("\n\nMenor valor da arvore: %d\n", menorValor(raiz));
    printf("Maior valor da arvore: %d\n", maiorValor(raiz));

    liberarArvore(raiz);

    return 0;
}