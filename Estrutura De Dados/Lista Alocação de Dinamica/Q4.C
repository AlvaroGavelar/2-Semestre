/*
Faça um laço de entrada de dados, onde o usuário deve digitar uma sequência de números, sem
limite de quantidade de dados a ser fornecida. O usuário irá digitar os números um a um, sendo que
caso ele deseje encerrar a entrada de dados, ele irá digitar o número Zero. No final, todos os dados
digitados deverão ser salvos em um arquivo texto em disco. Atenção: os dados devem ser
armazenados na memória deste modo... faça com que o programa inicie criando um ponteiro para
um bloco (vetor) de 10 valores inteiros, e alocando dinamicamente espaço em memória para este
bloco; após, caso o vetor alocado esteja cheio; aloque um novo vetor do tamanho do vetor anterior
adicionado com espaço para mais 10 valores (tamanho N+10, onde N inicia com 10), copie os
valores já digitados da área inicial para esta área maior e libere a memória da área inicial; repita
este procedimento de expandir dinamicamente com mais 10 valores o vetor alocado cada vez que o
mesmo estiver cheio. Assim o vetor irá ser “expandido” de 10 em 10 valores. Usar a função
malloc para alocar memória de forma dinâmica.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int capacidade = 10;
    int total = 0;
    int valor;

    int *vetor = (int*)malloc(sizeof(int) * capacidade);

        if(vetor == NULL){
            printf("Erro de alocacao inicial na memoria!\n");
            return NULL;
        }

    printf("\nForneca um Numero Inteiro: (Ou 0 Para Sair)");

    while(1){

        printf("\nValor:");
        scanf("%d", &valor);

            if(valor == 0){
                break;
            }

        if(total == capacidade){
            int novaCapacidade = capacidade + 10;

            int *aux = (int*)realloc(vetor, novaCapacidade * sizeof(int));

            if(aux == NULL){
                printf("\nErro de Alocacao!\n");
                break;
            }

            vetor = aux;
            capacidade = novaCapacidade;

            printf("\nMemoria Expandida Com Sucesso!!\n");

        }
        
        vetor[total] = valor;
        total++;

    }

    FILE *arquivo = fopen("dados.txt", "w");

    if (arquivo == NULL) {
        printf("\nErro ao criar/abrir o arquivo para gravacao!\n");
        free(vetor);
        return 1;
    }

    for (int i = 0; i < total; i++) {
        fprintf(arquivo, "%d\n", vetor[i]);
    }

    fclose(arquivo);
    printf("\nSucesso! %d numero(s) salvos no arquivo 'dados.txt'.\n", total);

    free(vetor);

    return 0;
}