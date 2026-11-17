#ifndef LISTA_H
#define LISTA_H

    typedef int TChave;
    typedef struct telemento *TElemento; /* opaco */

    TElemento elemento_cria(void);
    void elemento_destroi(TElemento *elemento);
    TChave elemento_getChave(TElemento elemento);
    void elemento_setChave(TElemento elemento, TChave novaChave);
    int elemento_compara(TElemento e1, TElemento e2);

    typedef struct tlista *TLista; /* opaco */
    TLista lista_cria(void);
    void lista_destroi(TLista *lista);
    int lista_getTamanho(TLista lista);
    int lista_vazia(TLista lista);
    int lista_cheia(TLista lista);
    TElemento lista_getElemento(TLista lista, int indice);
    TElemento lista_buscaChave(TLista lista, TChave ch);
    int lista_insereFinal(TLista lista, TElemento elem);
    int lista_insereInicio(TLista lista, TElemento elem);
    int lista_inserePosicao(TLista lista, TElemento elem, int indice);
    int lista_iniciaCorrente(TLista lista);
    TElemento lista_getCorrente(TLista lista);
    int lista_remove(TLista lista, TChave ch, TElemento *elem);



#endif
