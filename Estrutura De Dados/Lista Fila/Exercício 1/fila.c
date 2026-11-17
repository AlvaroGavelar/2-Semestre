
#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct Nodo {
    TElemento info;
    struct Nodo *prox;
} TNodo;

struct tFila {
    TNodo *inicio, *fim;
    int tamanho;
};

TFila fila_cria(void) {
    TFila f = malloc(sizeof(struct tFila));

    if (f) {
        f->inicio = NULL;
        f->fim = NULL;
        f->tamanho = 0;
    }

    return f;
}

int fila_vazia(TFila f) {
    return f->inicio == NULL;
}

int fila_insere(TFila f, TElemento e) {
    TNodo *ptr = malloc(sizeof(TNodo));

    if (ptr == NULL)
        return 0;

    ptr->info = e;
    ptr->prox = NULL;

    if (fila_vazia(f))
        f->inicio = ptr;
    else
        f->fim->prox = ptr;

    f->fim = ptr;
    f->tamanho++;

    return 1;
}

int fila_retira(TFila f, TElemento *e) {
    TNodo *ptr;

    if (fila_vazia(f))
        return 0;

    ptr = f->inicio;
    f->inicio = f->inicio->prox;

    *e = ptr->info;

    f->tamanho--;

    free(ptr);

    if (f->inicio == NULL)
        f->fim = NULL;

    return 1;
}

void fila_imprime(TFila f) {
    TNodo *aux = f->inicio;

    printf("\nFila de impressao:\n");

    while (aux != NULL) {
        printf("[Doc %d - %d linhas] -> ",
               aux->info.id, aux->info.linhas);

        aux = aux->prox;
    }

    printf("NULL\n");
}

void fila_libera(TFila f) {
    TElemento e;

    while (fila_retira(f, &e));

    free(f);
}
