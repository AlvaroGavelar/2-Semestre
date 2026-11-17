#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
#define CAPACIDADE 100

typedef struct Nodo{
    TElemento info;
    struct Nodo *proximo;
}TNodo;

struct tPilha{
    int topo;
    TElemento elementos[CAPACIDADE];
};

TPilha pilha_cria(){
    TPilha pilha;
    pilha = (TPilha)malloc(sizeof(struct tPilha));
    if(pilha){
        pilha->topo = -1;
    }
    return pilha;
}

void pilha_termina(TPilha *pilha){
    free(*pilha);
    *pilha = NULL;
}

int pilha_tamanho(TPilha pilha){
    return pilha->topo + 1;
}
int pilha_vazia(TPilha pilha){
    return pilha->topo == -1;
}

int pilha_pop(TPilha pilha, TElemento *elem){
    TNodo *ptr;
    //verificando se a pilha éstá vazia
    if(pilha->topo == -1)
        return 0;
 
    *elem = pilha->elementos[pilha->topo];
    pilha->topo --;
}

//inserindo um elemento na pilha
int pilha_push(TPilha pilha, TElemento elem){
    
    if(pilha->topo = CAPACIDADE - 1)
        return 0;
    
    pilha->topo++;
    pilha->elementos[pilha->topo] = elem;

    return 1;
}

int busca_posicao(TPilha p, TChave chave){
    TNodo *atual = p->topo;
    int posicao = 1;

    while(atual != NULL){
        if(atual->info.chave == chave)
            return posicao;

        atual = atual->proximo;
        posicao ++;
    }
    return 0;
}

void transfere(TPilha p1, TPilha p2){
    TPilha *aux = malloc(sizeof(TPilha));
    TElemento elem;

    if(aux == NULL)
        return NULL;

    while(!pilha_vazia(p1)){
        pilha_pop(p1, &elem);
        pilha_push(aux, elem);
    }

    while(!pilha_vazia(p2)){
        pilha_pop(aux, &elem);
        pilha_push(p2, elem);
    }
}

void remove_vogais(TPilha p) {
    TPilha aux = pilha_cria();
    TElemento elem;

    while (!pilha_vazia(p)) {
        pilha_pop(p, &elem);

        if (elem.chave != 'a' && elem.chave != 'e' &&
            elem.chave != 'i' && elem.chave != 'o' &&
            elem.chave != 'u' && elem.chave != 'A' &&
            elem.chave != 'E' && elem.chave != 'I' &&
            elem.chave != 'O' && elem.chave != 'U') {

            pilha_push(aux, elem);
        }
    }

    while (!pilha_vazia(aux)) {
        pilha_pop(aux, &elem);
        pilha_push(p, elem);
    }

    pilha_termina(&aux);
}

void remove_menores(TPilha p, TChave x){
    TPilha aux = pilha_cria();
    TElemento elem;

    while(!pilha_vazia(p)){
        pilha_pop(p, &elem);
        if(elem.chave >= x)
            pilha_push(aux, elem);
    }

    while(!pilha_vazia(aux)){
        pilha_pop(aux, &elem);
        pilha_push(p, elem);    
    }

    pilha_termina(&aux);
}