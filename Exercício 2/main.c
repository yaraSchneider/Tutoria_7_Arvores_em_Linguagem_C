#include <stdio.h>
#include <stdlib.h>

/*
Exercicio 2 - Contando elementos da arvore binaria de busca
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

int contarNos(No *raiz) {
    if (raiz == NULL) {
        return 0;
    }

    return 1 + contarNos(raiz->esquerda) + contarNos(raiz->direita);
}

int contarFolhas(No *raiz) {
    if (raiz == NULL) {
        return 0;
    }

    if (raiz->esquerda == NULL && raiz->direita == NULL) {
        return 1;
    }

    return contarFolhas(raiz->esquerda) + contarFolhas(raiz->direita);
}

int contarNosComDoisFilhos(No *raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int contador = 0;

    if (raiz->esquerda != NULL && raiz->direita != NULL) {
        contador = 1;
    }

    return contador
           + contarNosComDoisFilhos(raiz->esquerda)
           + contarNosComDoisFilhos(raiz->direita);
}

int altura(No *raiz) {
    if (raiz == NULL) {
        return 0;
    }

    int alturaEsquerda = altura(raiz->esquerda);
    int alturaDireita = altura(raiz->direita);

    if (alturaEsquerda > alturaDireita) {
        return 1 + alturaEsquerda;
    }

    return 1 + alturaDireita;
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

    raiz = inserir(raiz, 50);
    raiz = inserir(raiz, 30);
    raiz = inserir(raiz, 70);
    raiz = inserir(raiz, 20);
    raiz = inserir(raiz, 40);
    raiz = inserir(raiz, 80);

    printf("Valores em ordem: ");
    imprimirEmOrdem(raiz);

    printf("\n\nTotal de nos: %d\n", contarNos(raiz));
    printf("Total de folhas: %d\n", contarFolhas(raiz));
    printf("Nos com dois filhos: %d\n", contarNosComDoisFilhos(raiz));
    printf("Altura: %d\n", altura(raiz));

    liberarArvore(raiz);

    return 0;
}