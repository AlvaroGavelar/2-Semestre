#ifndef LISTA_H
#define LISTA_H

typedef struct Nodo TNodo;
typedef struct TLista TLista;

typedef TLista* lista;

lista criarLista();
void inserirInicio(lista l, char nome[]);
void inserirFim(lista l, char nome[]);
void imprimirLista(lista l);
void removerNome(lista l, char nome[]);
int tamanhoLista(lista l);
void josephus(lista l, int numero);
void trocaLista(lista l, int n1, int n2);

#endif