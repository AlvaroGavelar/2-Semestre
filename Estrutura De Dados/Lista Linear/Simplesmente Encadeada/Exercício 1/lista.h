#ifndef LISTA_H
#define LISTA_H

typedef struct {
    char descricao[100];
    int prioridade;
    float tempo;
} Tarefa;

typedef struct Nodo {
    Tarefa info;
    struct Nodo *prox;
} TNodo;

typedef struct {
    TNodo *inicio;
    int tamanho;
} TLista;

typedef TLista* lista;

lista criarLista();
int inserirTarefa(lista l, Tarefa tarefa);
void removerTarefa(lista l);
void listarTarefas(lista l);
int atualizarPrioridade(lista l, char descricao[], int novaPrioridade);
void liberarLista(lista l);

#endif