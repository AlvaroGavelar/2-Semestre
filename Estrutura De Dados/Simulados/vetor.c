/*
===========================================================
QUESTÃO 1 — TAD VETOR DINÂMICO DE INTEIROS
===========================================================

Implemente o TAD Vetor, responsável por armazenar uma
quantidade variável de números inteiros.

No arquivo vetor.h, foi declarado:

typedef struct TVetor *Vetor;

A estrutura TVetor deverá ser definida SOMENTE no arquivo
vetor.c.

O vetor deverá armazenar:
- os valores inteiros;
- a quantidade atual de elementos;
- a capacidade atual do vetor.

Implemente as seguintes funções:

Vetor criarVetor(int capacidadeInicial);

void liberarVetor(Vetor *v);

int adicionar(Vetor v, int valor);

int obter(Vetor v, int indice);

int definir(Vetor v, int indice, int valor);

int remover(Vetor v, int indice);

int getQuantidade(Vetor v);

int getCapacidade(Vetor v);


REGRAS:

1. criarVetor
- Deve alocar dinamicamente a estrutura.
- Deve alocar espaço para capacidadeInicial inteiros.
- A quantidade inicial deve ser 0.
- Caso ocorra erro de alocação, retornar NULL.

2. adicionar
- Adiciona um elemento ao final do vetor.
- Caso o vetor esteja cheio, deve aumentar sua capacidade
  utilizando realloc.
- A quantidade deve ser incrementada após a inserção.

3. obter
- Recebe um índice e retorna o elemento daquela posição.
- Deve verificar se o índice é válido.

4. definir
- Recebe um índice e um valor.
- Altera o elemento daquela posição.
- Deve verificar se o índice é válido.

5. remover
- Remove o elemento da posição indicada.
- Os elementos à direita devem ser deslocados uma posição
  para a esquerda.
- A quantidade deve ser decrementada.

Exemplo:

[10, 20, 30, 40, 50]

remover índice 2

[10, 20, 40, 50]

6. getQuantidade
- Retorna a quantidade atual de elementos.

7. getCapacidade
- Retorna a capacidade atualmente alocada.

8. liberarVetor
- Deve liberar toda a memória utilizada pelo TAD.

IMPORTANTE:
- Implementar somente o TAD.
- NÃO fazer main.
- A estrutura TVetor deve ficar escondida no vetor.c.
===========================================================
*/

#include <stdio.h>
#include <stdlib.h>
#include "vetor.h"

struct TVetor{
    int *vetor;
    int capacidade;
    int tamanho;
};

// 1. criarVetor
// - Deve alocar dinamicamente a estrutura.
// - Deve alocar espaço para capacidadeInicial inteiros.
// - A quantidade inicial deve ser 0.
// - Caso ocorra erro de alocação, retornar NULL.
Vetor criarVetor(int capacidadeInicial){
  Vetor v;

  if(capacidadeInicial <= 0)
      return NULL;

  //Aloca Struct
  v = malloc(sizeof(struct TVetor));

  if(v == NULL) 
    return NULL;

  //Aloca Vetor
  v->vetor = malloc(capacidadeInicial * sizeof(int));

  if(v->vetor == NULL){
    free(v);
    return NULL;
  }

  v->capacidade = capacidadeInicial;
  v->tamanho = 0;
  
  return v;
}

void liberarVetor(Vetor *v){
  if(v == NULL)
    return;

  if(*v == NULL)
    return;

  free((*v)->vetor);
  free(*v);

  *v = NULL;
}

// 2. adicionar
// - Adiciona um elemento ao final do vetor.
// - Caso o vetor esteja cheio, deve aumentar sua capacidade
//   utilizando realloc.
// - A quantidade deve ser incrementada após a inserção.
int adicionar(Vetor v, int valor){
  int *aux;

  if(v == NULL)
    return 0;

  if(v->tamanho == v->capacidade){
    aux = realloc(v->vetor, (v->capacidade * 2) * sizeof(int));

    if(aux == NULL)
      return 0;

      v->vetor = aux;
      v->capacidade = v->capacidade * 2;
  }

  v->vetor[v->tamanho] = valor;
  v->tamanho ++;

  return 1;
}

// 3. obter
// - Recebe um índice e retorna o elemento daquela posição.
// - Deve verificar se o índice é válido.
int obter(Vetor v, int indice){
  if(v == NULL)
    return 0;

  if(indice >= v->tamanho || indice < 0)
    return 0;

  return v->vetor[indice];
}

// 4. definir
// - Recebe um índice e um valor.
// - Altera o elemento daquela posição.
// - Deve verificar se o índice é válido.
int definir(Vetor v, int indice, int valor){
  if(v == NULL)
    return 0;

  if(indice >= v->tamanho || indice < 0)
    return 0;

  v->vetor[indice] = valor;

  return 1;
}

// 5. remover
// - Remove o elemento da posição indicada.
// - Os elementos à direita devem ser deslocados uma posição
//   para a esquerda.
// - A quantidade deve ser decrementada
int remover(Vetor v, int indice){
  int i;

  if(v == NULL)
    return 0;

  if(indice >= v->tamanho || indice < 0)
    return 0;

  //i + 1, sempre i < algo - 1
  for(i=indice; i < v->tamanho - 1; i++){
    v->vetor[i] = v->vetor[i+1];
  }
  v->tamanho--;

  return 1;
}


// 6. getQuantidade
// - Retorna a quantidade atual de elementos.
int getQuantidade(Vetor v){
  if(v == NULL)
    return 0;

  return v->tamanho;
}

// 7. getCapacidade
// - Retorna a capacidade atualmente alocada.
int getCapacidade(Vetor v){
  if(v == NULL)
    return 0;

  return v->capacidade;
}