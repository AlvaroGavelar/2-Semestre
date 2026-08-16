/*
Escreva um programa que aloque dinamicamente um vetor de n inteiros. Após o preenchimento do
vetor, permita que o usuário escolha uma posição para remover um elemento.
Após a remoção, reorganize os elementos para que não fiquem “buracos” no vetor, e utilize realloc
para ajustar o tamanho da área de memória.Exiba o vetor resultante e, ao final, libere a memória. 
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(){
    int n;
    int m;
    int *vetor = NULL;

    while(1){
        printf("Quantidade De Posicoes:");
        scanf("%d", &n);

        if(n > 0){
            break;
        }
        printf("Valor invalido! Digite novamente.\n");
    }

    vetor = (int*)malloc(sizeof(int) * n);

    if(vetor){

        //Preenche
        for(int i = 0; i < n; i++){
            printf("Forneca um Numero:");
            scanf("%d", &vetor[i]);
        }

        //Procura
        while(1){
        printf("Posicao a Ser Deletada:");
        scanf("%d", &m);

            if(m >= 0 && m <= n){
                break;
            }
        printf("Valor invalido! Digite novamente.\n");
        }

        for(int i = m; i < n - 1; i++){
            vetor[i] = vetor[i + 1];
            }

            
            int *aux = realloc(vetor, sizeof(int) * (n - 1));
            
            if(aux){
                vetor = aux;
            }
            else{
                free(vetor);
                return 0;
            }

            n--;
    }
    else{
        free(vetor);
        return 0;
    }
    
    for(int i = 0; i < n; i++){
        printf("Posicao %d: [%d]\n", i+1, vetor[i]);
    }

    free(vetor);

    return 0;
}