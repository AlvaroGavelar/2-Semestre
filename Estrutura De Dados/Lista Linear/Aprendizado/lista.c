#include <stdio.h>
#include <stdlib.h>
#include "lista.h"

//Simples Encadeada

// typedef struct nodo{
//     TElemento info; /* o elemento */
//     struct nodo *prox;
//     }TNodo;
// struct tlista{
//     TNodo *inicio, *fim;
//     int tamanho;
//     TNodo *corrente; /* cursor */
// };

// TLista lista_cria(void){
//     TLista lista = (TLista) malloc(sizeof(struct tlista));
//     if(lista){
//         lista->inicio = NULL;
//         lista->fim = NULL;
//         lista->tamanho = 0;
//         lista->corrente = NULL;
//     }
//     return lista;
// }

// int lista_insereFinal(TLista lista, TElemento elem){
//     TNodo *ptr = (TNodo*) malloc(sizeof(TNodo));
//     /* sem memória: a lista original não é alterada */
//     if(ptr == NULL)
//         return 0;
//     ptr->info = elem; /* ① */
//     ptr->prox = NULL;
//     if(lista->inicio == NULL) /* ② lista vazia */
//         lista->inicio = ptr;
//     else
//         lista->fim->prox = ptr; /* ② caso geral */
//     lista->fim = ptr; /* ③ */
//     lista->tamanho++;
//     return 1;
// }

// int lista_insereInicio(TLista lista, TElemento elem){
//     TNodo *ptr = (TNodo*) malloc(sizeof(TNodo));
//     /* sem memória: a lista original não é alterada */
//     if(ptr == NULL)
//         return 0;
//     ptr->info = elem;
//     ptr->prox = lista->inicio; /* ① */
//     lista->inicio = ptr; /* ② */
//     if(lista->fim == NULL) /* lista estava vazia */
//         lista->fim = ptr;
//     lista->tamanho++;
//     return 1;
// }

// int lista_inserePosicao(TLista lista, TElemento elem, int indice){
//     TNodo *ant, *ptr;
//     int i;
//     if(indice <= 0 || indice > lista->tamanho + 1)
//         return 0;
//     if(indice == 1)
//         return lista_insereInicio(lista, elem);
//     if(indice == lista->tamanho + 1)
//         return lista_insereFinal(lista, elem);
//     ptr = (TNodo*) malloc(sizeof(TNodo));
//     if(ptr == NULL)
//         return 0;
//     ant = lista->inicio; /* anda até a posição indice-1 */
//     for(i = 1; i < indice - 1; i++)
//         ant = ant->prox;
//     ptr->info = elem;
//     ptr->prox = ant->prox; /* ① */
//     ant->prox = ptr; /* ② */
//     lista->tamanho++;
//     return 1;
// }

// TElemento lista_getElemento(TLista lista, int indice){
//     TNodo *ptr;
//     int i;
//     if(indice <= 0 || indice > lista->tamanho)
//         return NULL;
//     ptr = lista->inicio;
//     for(i = 1; i < indice; i++) /* anda indice-1 nós */
//         ptr = ptr->prox;
//     return ptr->info;
// }

// TElemento lista_buscaChave(TLista lista, TChave ch){
//     TNodo *ptr;
//     for(ptr = lista->inicio; ptr != NULL; ptr = ptr->prox)
//         if(elemento_getChave(ptr->info) == ch)
//     return ptr->info;
//     return NULL;
// }

// int lista_iniciaCorrente(TLista lista){
//     lista->corrente = lista->inicio;
//         return lista->tamanho != 0;
//     }
//     TElemento lista_getCorrente(TLista lista){
//     TElemento elem;
//     if(lista->corrente == NULL) /* passou do fim */
//         return NULL;
//     elem = lista->corrente->info;
//     lista->corrente = lista->corrente->prox;
//     return elem;
// }

// int lista_remove(TLista lista, TChave ch, TElemento *elem){
//     TNodo *ant = NULL, *ptr = lista->inicio;
//     while(ptr != NULL && elemento_getChave(ptr->info) != ch){
//         ant = ptr;
//         ptr = ptr->prox;
//     }
//     /* não achou: a lista original não é alterada */
//     if(ptr == NULL)
//         return 0;
//     if(ant == NULL) /* era o primeiro */
//         lista->inicio = ptr->prox;
//     else
//         ant->prox = ptr->prox; /* ① */
//     if(ptr == lista->fim) /* era o último */
//         lista->fim = ant;
//     if(ptr == lista->corrente) /* corrente não fica em nó liberado */
//         lista->corrente = ptr->prox;
//     *elem = ptr->info; /* ② posse passa ao cliente */
//     free(ptr);
//     lista->tamanho--;
//     return 1;
// }

// void lista_destroi(TLista *lista){
//     TNodo *ptr;
//     while((*lista)->inicio != NULL){
//     ptr = (*lista)->inicio;
//     (*lista)->inicio = ptr->prox;
//     elemento_destroi(&ptr->info);
//     free(ptr);
//     }
//     free(*lista);
//     *lista = NULL;
// }

// Duplamente
typedef struct Nodo{
    TElemento info; /* o elemento */
    struct Nodo *proximo, *anterior;
    }TNodo;

struct tlista{
    TNodo *inicio,
    *corrente; /* cursor */
    int tamanho;
    int posicaoCorrente;
};

TLista lista_cria(void){
    TLista lista;
    lista = (TLista) malloc(sizeof(struct tlista));
    if(lista){
        lista->tamanho = 0;
        lista->inicio = NULL;
        lista->corrente = NULL;
        lista->posicaoCorrente = 0;
    }
    return lista;
}

int lista_insereInicio(TLista lista, TElemento elem){
    TNodo *ptr;
    ptr = (TNodo*) malloc(sizeof(TNodo));
    /* sem memória: a lista original não é alterada */
    if(ptr == NULL)
        return 0;
    ptr->info = elem;
    if(lista->inicio == NULL){ /* primeiro nó */
        ptr->anterior = ptr;
        ptr->proximo = ptr;
    }
    else{
        ptr->proximo = lista->inicio; /* ① */
        ptr->anterior = lista->inicio->anterior; /* ② */
        lista->inicio->anterior->proximo = ptr; /* ③ */
        lista->inicio->anterior = ptr; /* ④ */
    }
    lista->inicio = ptr; /* ⑤ */
    lista->tamanho++;
    return 1;
}

lista_insereInicio(TLista lista, TElemento elem){
    TNodo *ptr;
    ptr = (TNodo*) malloc(sizeof(TNodo));
    /* sem memória: a lista original não é alterada */
    if(ptr == NULL)
        return 0;
    ptr->info = elem;
    if(lista->inicio == NULL){ /* primeiro nó */
        ptr->anterior = ptr;
        ptr->proximo = ptr;
    }
    else{
        ptr->proximo = lista->inicio; /* ① */
        ptr->anterior = lista->inicio->anterior; /* ② */
        lista->inicio->anterior->proximo = ptr; /* ③ */
        lista->inicio->anterior = ptr; /* ④ */
    }
    lista->inicio = ptr; /* ⑤ */
    lista->tamanho++;
    return 1;
}

int lista_insereFinal(TLista lista, TElemento elem){
    int inseriu;
    inseriu = lista_insereInicio(lista, elem);
    if(inseriu == 1)
        lista->inicio = lista->inicio->proximo;
    return inseriu;
}

TElemento lista_getElemento(TLista lista, int indice){
    TNodo *ptr;
    int i;
    if(indice <= 0 || indice > lista->tamanho)
        return NULL;
    ptr = lista->inicio;
    if(indice <= lista->tamanho/2) /* para frente */
        for(i = 1; i < indice; i++)
            ptr = ptr->proximo;
    else /* para trás */
        for(i = lista->tamanho; i >= indice; i--)
            ptr = ptr->anterior;
    return ptr->info;
}

