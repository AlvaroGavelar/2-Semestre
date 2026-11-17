
#ifndef FILA_H
#define FILA_H

typedef struct {
    int id;
    int linhas;
} TElemento;

typedef struct tFila *TFila;

TFila fila_cria(void);
int fila_insere(TFila f, TElemento e);
int fila_retira(TFila f, TElemento *e);
int fila_vazia(TFila f);
void fila_imprime(TFila f);
void fila_libera(TFila f);

#endif
