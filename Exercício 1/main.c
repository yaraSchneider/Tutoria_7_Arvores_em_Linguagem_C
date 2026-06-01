#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/*
Exercicio 1 - Cadastro de alunos com arvore binaria de busca
A arvore e organizada pela matricula do aluno.
*/

typedef struct Aluno {
    int matricula;
    char nome[50];
    float nota;
} Aluno;

typedef struct No {
    Aluno aluno;
    struct No *esquerda;
    struct No *direita;
} No;

No* criarNo(int matricula, const char nome[], float nota) {
    No *novo = (No*) malloc(sizeof(No));

    if (novo == NULL) {
        printf("Erro ao alocar memoria.\n");
        exit(1);
    }

    novo->aluno.matricula = matricula;
    strcpy(novo->aluno.nome, nome);
    novo->aluno.nota = nota;
    novo->esquerda = NULL;
    novo->direita = NULL;

    return novo;
}

No* inserir(No *raiz, int matricula, const char nome[], float nota) {
    if (raiz == NULL) {
        printf("Inserindo aluno %d - %s\n", matricula, nome);
        return criarNo(matricula, nome, nota);
    }

    if (matricula < raiz->aluno.matricula) {
        raiz->esquerda = inserir(raiz->esquerda, matricula, nome, nota);
    } else if (matricula > raiz->aluno.matricula) {
        raiz->direita = inserir(raiz->direita, matricula, nome, nota);
    } else {
        printf("Matricula %d ja cadastrada.\n", matricula);
    }

    return raiz;
}

No* buscar(No *raiz, int matricula) {
    if (raiz == NULL) {
        return NULL;
    }

    if (matricula == raiz->aluno.matricula) {
        return raiz;
    }

    if (matricula < raiz->aluno.matricula) {
        return buscar(raiz->esquerda, matricula);
    }

    return buscar(raiz->direita, matricula);
}

void imprimirEmOrdem(No *raiz) {
    if (raiz != NULL) {
        imprimirEmOrdem(raiz->esquerda);
        printf("%d - %s - Nota: %.1f\n",
               raiz->aluno.matricula,
               raiz->aluno.nome,
               raiz->aluno.nota);
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
    No *resultado;
    int matriculaBusca = 102;
    int matriculaNaoEncontrada = 999;

    raiz = inserir(raiz, 102, "Ana", 9.0);
    raiz = inserir(raiz, 55, "Bruno", 8.5);
    raiz = inserir(raiz, 180, "Carla", 7.5);

    printf("\nAlunos em ordem:\n");
    imprimirEmOrdem(raiz);

    printf("\nBuscar matricula %d:\n", matriculaBusca);
    resultado = buscar(raiz, matriculaBusca);

    if (resultado != NULL) {
        printf("Aluno encontrado: %s\n", resultado->aluno.nome);
    } else {
        printf("Matricula %d nao encontrada.\n", matriculaBusca);
    }

    printf("\nBuscar matricula %d:\n", matriculaNaoEncontrada);
    resultado = buscar(raiz, matriculaNaoEncontrada);

    if (resultado != NULL) {
        printf("Aluno encontrado: %s\n", resultado->aluno.nome);
    } else {
        printf("Matricula %d nao encontrada.\n", matriculaNaoEncontrada);
    }

    liberarArvore(raiz);

    return 0;
}