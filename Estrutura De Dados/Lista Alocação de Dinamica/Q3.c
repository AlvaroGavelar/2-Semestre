/*
Faça uma função que receba um valor n e crie dinamicamente um vetor de n elementos e
retorneum ponteiro. Crie uma função que receba um ponteiro para um vetor e um valor n e imprima
os n elementos desse vetor. Construa também uma função que receba um ponteiro para um vetor e
libere esta área de memória. Ao final, crie uma função principal que leia um valor n e chame a
função criada acima. Depois, a função principal deve ler os n elementos desse vetor. Então, a
função principal deve chamar a função de impressão dos n elementos do vetor criado e, finalmente,
liberara memória alocada através da função criada para liberação
*/

#include <stdio.h>
#include <stdlib.h>

int *criaVetor(int n){
    int *vetor; 
    
    *vetor = (int*)malloc(n*sizeof(int));
    if(vetor == NULL)
        return 0;

    return vetor;
}

void imprimiVetor(int *vetor, int n){
    int i;
    printf("\nImpressao\n");
    for(i=0;i<n;i++){
        printf("\n%d", vetor[i]);
    }
}

void liberaVetor(int *vetor){
    free(vetor);
}

int main(){
    int n, *vetor;

    printf("\nForneca um Valor Inteiro:");
    scanf("%d", &n);

    *vetor = criaVetor(n);

    for(int i=0;i<n;i++){
        printf("\n%d. Numero:", i+1);
        scanf("%d", &vetor[i]);
    }

    imprimiVetor(vetor,n);
    liberaVetor(vetor);

    return 0;
}