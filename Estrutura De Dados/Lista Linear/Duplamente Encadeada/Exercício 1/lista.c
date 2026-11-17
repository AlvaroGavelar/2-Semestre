#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

struct Nodo {
    char nome[50];
    struct Nodo *next;
    struct Nodo *prev;
};

struct TLista {
    TNodo *inicio;
    TNodo *fim;
    int tamanho;
};

lista criarLista(){
    lista ptr = malloc(sizeof(lista));

    if(ptr == NULL)
        return NULL;

    ptr->inicio = NULL;
    ptr->fim = NULL;
    ptr->tamanho = 0;

    return ptr;
}

void inserirInicio(lista l, char nome[]){
    TNodo *novo = malloc(sizeof(TNodo));

    if(novo == NULL)
        return;

    strcpy(novo->nome, nome);

    //LISTA VAZIA
    if(l->tamanho == 0){
        novo->next = novo;
        novo->prev = novo;
        l->inicio = novo;
        l->fim = novo;
        l->tamanho++;
    }
    else{
        novo->next = l->inicio;
        novo->prev = l->fim;
        l->inicio->prev = novo;
        l->fim->next = novo;
        l->inicio = novo;
        l->tamanho++;
    }
}

void inserirFim(lista l, char nome[]){

    if(l->tamanho == 0){
        inserirInicio(l, nome);
        return;
    }

    TNodo *novo = malloc(sizeof(TNodo));

    if(novo == NULL)
        return;
    
    strcpy(novo->nome, nome);

    novo->prev = l->fim;
    novo->next = l->inicio;
    l->fim->next = novo;
    l->inicio->prev = novo;
    l->fim = novo;
    l->tamanho ++;
}

void imprimirLista(lista l) {
    if (l->tamanho == 0)
        return;

    TNodo *aux = l->inicio;

    do {
        printf("Nome: %s\n", aux->nome);
        aux = aux->next;
    } while (aux != l->inicio);
}

void removerNome(lista l, char nome[]){
    if(l->tamanho == 0)
        return;

    if(l->tamanho == 1){
        TNodo *aux = l->inicio;
        free(aux);

        l->inicio = NULL;
        l->fim = NULL;
        l->tamanho = 0;
        return;
    }

    TNodo *aux = l->inicio;

    do {
        if(strcmp(nome, aux->nome) == 0){

            if (aux == l->inicio)
                l->inicio = aux->next;

            if (aux == l->fim)
                l->fim = aux->prev;

            aux->prev->next = aux->next;
            aux->next->prev = aux->prev;

            l->inicio->prev = l->fim;
            l->fim->next = l->inicio;

            free(aux);
            l->tamanho--;
            printf("\nSoldado Removido: %s", nome);

            return;
        }
        aux = aux->next;
    } while (aux != l->inicio);
}

int tamanhoLista(lista l){
    return l->tamanho;
}

void josephus(lista l, int numero){
    if (l->tamanho == 0 || numero <= 0)
        return;

    TNodo *atual = l->inicio;

    while(l->tamanho > 1){
        int contador = 1;
        
        while (contador < numero) {
            atual = atual->next;
            contador++;
        }

        TNodo *proximo = atual->next;

        printf("\nEliminado: %s\n", atual->nome);

        removerNome(l, atual->nome);

        atual = proximo;

        printf("\nSoldados restantes:\n");
        imprimirLista(l);
    }

    printf("\nSobrevivente: %s\n", l->inicio->nome);
}

void trocaLista(lista l, int n1, int n2) {
    if (n1 == n2)
        return;

    if (n1 < 1 || n2 < 1 ||
        n1 > l->tamanho || n2 > l->tamanho)
        return;

    TNodo *nu1 = NULL;
    TNodo *nu2 = NULL;
    TNodo *aux = l->inicio;

    int contador = 1;

    // Encontrar os dois nós
    while (aux != NULL) {
        if (contador == n1)
            nu1 = aux;

        if (contador == n2)
            nu2 = aux;

        aux = aux->next;
        contador++;
    }

    // Garantir que nu1 esteja antes de nu2
    if (n1 > n2) {
        TNodo *temp = nu1;
        nu1 = nu2;
        nu2 = temp;
    }

    // Guardar os vizinhos
    TNodo *ant1 = nu1->prev;
    TNodo *prox1 = nu1->next;
    TNodo *ant2 = nu2->prev;
    TNodo *prox2 = nu2->next;

    // Caso 1: nós vizinhos
    if (prox1 == nu2) {
        if (ant1 != NULL)
            ant1->next = nu2;
        else
            l->inicio = nu2;

        if (prox2 != NULL)
            prox2->prev = nu1;
        else
            l->fim = nu1;

        nu2->prev = ant1;
        nu2->next = nu1;
        nu1->prev = nu2;
        nu1->next = prox2;
    }

    // Caso 2: nós não vizinhos
    else {
        if (ant1 != NULL)
            ant1->next = nu2;
        else
            l->inicio = nu2;

        if (prox1 != NULL)
            prox1->prev = nu2;

        if (ant2 != NULL)
            ant2->next = nu1;
        else
            l->inicio = nu1;

        if (prox2 != NULL)
            prox2->prev = nu1;
        else
            l->fim = nu1;

        nu1->prev = ant2;
        nu1->next = prox2;

        nu2->prev = ant1;
        nu2->next = prox1;
    }
}
