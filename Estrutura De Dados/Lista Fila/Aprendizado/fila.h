#ifndef FILA_H
#define FILA_H
typedef int TChave;
typedef struct{
 TChave chave;
 /* demais componentes */
}TElemento;
typedef struct tFila *TFila; /* tipo opaco */
TFila fila_cria(void);
void fila_termina(TFila f);
int fila_insere(TFila f, TElemento e);
int fila_retira(TFila f, TElemento *e);
int fila_tamanho(TFila f);
int fila_cheia(TFila f);
int fila_vazia(TFila f);
#endif