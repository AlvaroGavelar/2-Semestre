#include <stdio.h>
#include <stdlib.h>
#include "fila.h"

typedef struct Nodo{
    TElemento info;
    struct Nodo *prox;
}TNodo;
struct tFila{
    TNodo *inicio, *fim;
    int tamanho;
};

TFila fila_cria(void){
    TFila f = (TFila)malloc(sizeof(struct tFila));
    if(f){
        f->inicio = NULL;
        f->fim = NULL;
        f->tamanho = 0;
    }
    return f;
}

int fila_insere(TFila f, TElemento e){
    TNodo *ptr = malloc(sizeof(TNodo));
    if(ptr == NULL)
        return 0;

    ptr->info = e;
    ptr->prox = NULL;

    if(f->inicio == NULL)
        f->inicio = ptr;
    else
        f->fim->prox = ptr;

    f->fim = ptr;
    f->tamanho++;

    return 1;
}

int fila_retira(TFila f, TElemento *e){
    TNodo *ptr;

    if(f->inicio == NULL)
        return 0;

    ptr = f->inicio;
    f->inicio = f->inicio->prox;
    *e = ptr->info;
    f->tamanho--;
    free(ptr);
    if(f->inicio == NULL)
        f->fim = NULL;

    return 1;
}