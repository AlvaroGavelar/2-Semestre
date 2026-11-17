#ifndef PILHA_H
#define PILHA_H

    typedef int TChave;

    typedef struct{
    TChave chave;
    /* demais componentes */
    }TElemento;

    typedef struct tPilha *TPilha; /* tipo opaco */

    TPilha pilha_cria(void);
    void pilha_termina(TPilha *pilha);
    int pilha_tamanho(TPilha pilha);
    int pilha_vazia(TPilha pilha);
    int pilha_push(TPilha pilha, TElemento elem);
    int pilha_pop(TPilha pilha, TElemento *elem);
    int busca_posicao(TPilha p, TChave chave);
    void transfere(TPilha p1, TPilha p2);
    void remove_vogais(TPilha p);

#endif
