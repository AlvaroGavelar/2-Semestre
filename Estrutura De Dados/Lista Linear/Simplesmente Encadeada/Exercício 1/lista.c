#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

lista criarLista() {
    lista l = malloc(sizeof(TLista));

    if (l == NULL)
        return NULL;

    l->inicio = NULL;
    l->tamanho = 0;

    return l;
}

int inserirTarefa(lista l, Tarefa tarefa) {
    TNodo *novo = malloc(sizeof(TNodo));

    if (novo == NULL)
        return 0;

    novo->info = tarefa;
    novo->prox = NULL;

    if (l->inicio == NULL ||
        tarefa.prioridade > l->inicio->info.prioridade) {

        novo->prox = l->inicio;
        l->inicio = novo;
    }
    else {
        TNodo *aux = l->inicio;

        while (aux->prox != NULL &&
               aux->prox->info.prioridade >= tarefa.prioridade) {

            aux = aux->prox;
        }

        novo->prox = aux->prox;
        aux->prox = novo;
    }

    l->tamanho++;

    return 1;
}

void removerTarefa(lista l) {
    if (l->inicio == NULL)
        return;

    TNodo *aux = l->inicio;

    l->inicio = aux->prox;

    free(aux);

    l->tamanho--;
}

void listarTarefas(lista l) {
    if (l->inicio == NULL) {
        printf("\nNenhuma tarefa pendente.\n");
        return;
    }

    TNodo *aux = l->inicio;

    while (aux != NULL) {
        printf("\nDescricao: %s", aux->info.descricao);
        printf("\nPrioridade: %d", aux->info.prioridade);
        printf("\nTempo estimado: %.2f horas\n", aux->info.tempo);

        aux = aux->prox;
    }
}

int atualizarPrioridade(lista l, char descricao[], int novaPrioridade) {
    TNodo *aux = l->inicio;
    TNodo *ant = NULL;

    while (aux != NULL &&
           strcmp(aux->info.descricao, descricao) != 0) {

        ant = aux;
        aux = aux->prox;
    }

    if (aux == NULL)
        return 0;

    Tarefa tarefa = aux->info;

    if (ant == NULL)
        l->inicio = aux->prox;
    else
        ant->prox = aux->prox;

    free(aux);

    tarefa.prioridade = novaPrioridade;

    if (!inserirTarefa(l, tarefa))
        return 0;

    return 1;
}

void liberarLista(lista l) {
    if (l == NULL)
        return;

    TNodo *aux = l->inicio;
    TNodo *prox;

    while (aux != NULL) {
        prox = aux->prox;
        free(aux);
        aux = prox;
    }

    free(l);
}