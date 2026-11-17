#include <stdio.h>
#include <stdlib.h>
#include "pilha.h"
typedef struct Nodo{
    TElemento info;
    struct Nodo *proximo;
}TNodo;

struct tPilha{
    TNodo *topo;
    int tamanho;
};

TPilha pilha_cria(){
    TPilha pilha;
    pilha = (TPilha)malloc(sizeof(struct tPilha));
    if(pilha){
        pilha->topo = NULL;
        pilha->tamanho =0;
    }
    return pilha;
}

void pilha_termina(TPilha *pilha){
    TNodo *ptr;
    while((*pilha)->topo!=NULL){
        ptr = (*pilha)->topo;
        (*pilha)->topo=(*pilha)->topo->proximo;
        free(ptr);
    }
    free(*pilha);
    *pilha = NULL;
}

int pilha_tamanho(TPilha pilha){
    return pilha->tamanho;
}
int pilha_vazia(TPilha pilha){
    return pilha->tamanho==0;
}

int pilha_pop(TPilha pilha, TElemento *elem){
    TNodo *ptr;
    //verificando se a pilha éstá vazia
    if(pilha->tamanho==0)
        return 0;
    
    ptr = pilha->topo;
    pilha->topo = pilha->topo->proximo;
    //pilha->topo = ptr->proximo;
    *elem = ptr->info;
    free(ptr);
    pilha->tamanho--;
    return 1;
}

//inserindo um elemento na pilha
int pilha_push(TPilha pilha, TElemento elem){
     TNodo *ptr;
    ptr = (TNodo*)malloc(sizeof(TNodo));
    
    if(ptr==NULL)
        return 0;
    
    ptr->info = elem;
    ptr->proximo = pilha->topo;
    pilha->topo = ptr;
    pilha->tamanho++;
    return 1;
}