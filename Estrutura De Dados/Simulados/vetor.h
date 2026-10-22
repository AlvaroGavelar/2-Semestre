#ifndef VETOR.H
#define VETOR.H

typedef struct TVetor *Vetor;

Vetor criarVetor(int capacidadeInicial);

void liberarVetor(Vetor *v);

int adicionar(Vetor v, int valor);

int obter(Vetor v, int indice);

int definir(Vetor v, int indice, int valor);

int remover(Vetor v, int indice);

int getQuantidade(Vetor v);

int getCapacidade(Vetor v);

#endif