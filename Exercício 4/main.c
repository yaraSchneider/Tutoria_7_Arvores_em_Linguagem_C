#include <stdio.h>
#include <stdlib.h>

/*
Exercicio 4 - Removendo um valor da arvore binaria de busca
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

No* encontrarMenorNo(No *raiz) {
    while (raiz != NULL && raiz->esquerda != NULL) {
        raiz = raiz->esquerda;
    }

    return raiz;
}

No* remover(No *raiz, int valor) {
    if (raiz == NULL) {
        return NULL;
    }

    if (valor < raiz->valor) {
        raiz->esquerda = remover(raiz->esquerda, valor);
    } else if (valor > raiz->valor) {
        raiz->direita = remover(raiz->direita, valor);
    } else {
        // Caso 1: no folha
        if (raiz->esquerda == NULL && raiz->direita == NULL) {
            free(raiz);
            return NULL;
        }

        // Caso 2: no com apenas filho direito
        if (raiz->esquerda == NULL) {
            No *temporario = raiz->direita;
            free(raiz);
            return temporario;
        }

        // Caso 2: no com apenas filho esquerdo
        if (raiz->direita == NULL) {
            No *temporario = raiz->esquerda;
            free(raiz);
            return temporario;
        }

        // Caso 3: no com dois filhos
        // Usa o sucessor: menor valor da subarvore direita
        No *sucessor = encontrarMenorNo(raiz->direita);
        raiz->valor = sucessor->valor;
        raiz->direita = remover(raiz->direita, sucessor->valor);
    }

    return raiz;
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
    int valores[] = {50, 30, 70, 20, 40, 60, 80};
    int quantidade = sizeof(valores) / sizeof(valores[0]);
    int i;

    for (i = 0; i < quantidade; i++) {
        raiz = inserir(raiz, valores[i]);
    }

    printf("Arvore inicial em ordem:\n");
    imprimirEmOrdem(raiz);

    printf("\n\nRemovendo 20 - no folha:\n");
    raiz = remover(raiz, 20);
    imprimirEmOrdem(raiz);

    printf("\n\nRemovendo 30 - no com filho(s):\n");
    raiz = remover(raiz, 30);
    imprimirEmOrdem(raiz);

    printf("\n\nRemovendo 50 - raiz com dois filhos:\n");
    raiz = remover(raiz, 50);
    imprimirEmOrdem(raiz);

    printf("\n");

    liberarArvore(raiz);

    return 0;
}