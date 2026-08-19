/*
Escreva um programa que leia um número inteiro n, correspondente ao tamanho de um vetor. Em
seguida, aloque dinamicamente um vetor de n posições e preencha-o com números inteiros fornecidos
pelo usuário. O programa deve então remover todas as ocorrências de valores repetidos, de modo que
cada número apareça apenas uma vez. Para isso, reorganize o vetor e use a função realloc para
reduzir seu tamanho ao mínimo necessário. Por fim, exiba o vetor resultante, contendo apenas os
elementos únicos. 
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int n;
    int *vetor = NULL;

    printf("Tamanho do Vetor:");
    scanf("%d", &n);

    vetor = malloc(n * sizeof(int));

    if(vetor){
        for(int i = 0; i < n; i++){
            printf("Forneca um numero inteiro para a Posicao %d:", i + 1);
            scanf("%d", &vetor[i]);
        }

        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n;){
                if(vetor[i] == vetor[j]){
                    for(int k = j; k < n - 1; k++){
                        vetor[k] = vetor[k + 1];
                    }
                    n--;
                }
                else
                    j++;
            }
        }

        int *aux;

        aux = realloc(vetor, sizeof(int) * n);
        if(aux){
            vetor = aux;
        }
        else{
            free(vetor);
            return 1;
        }    

        for(int i = 0; i < n; i++){
            printf("Posicao %d: %d\n", i + 1, vetor[i]);
        }
    }   
    else{
        printf("\n!Erro de Alocacao!\n");
        return 1;
    }

    free(vetor);

    return 0;
}