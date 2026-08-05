/*
Faça um programa que leia um valor n e crie dinamicamente um vetor de n elementos e passe esse
vetor para uma função que vai ler os elementos desse vetor. Depois, no programa principal, o vetor
preenchido deve ser impresso. Além disso, antes de finalizar o programa, deve-se liberar a área de
memória alocada
*/

#include <stdio.h>
#include <stdlib.h>

void imprimeVetor(int *vetor, int n){
    int i;
    for(i=0;i<n;i++){
        printf("\nForneca um Numero:");
        scanf("%d", &vetor[i]);
    }
}

int main(){
    int *vetor, n, i;

    printf("\nForneca um Valor Inteiro:");
    scanf("%d", &n);

    vetor = (int*)malloc(sizeof(int)*n);

    imprimeVetor(vetor, n);

    for(i=0;i<n;i++){
        printf("\nImpressão: %d", vetor[i]);
    }

    free(vetor);
    return 0;
}