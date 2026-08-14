/*
Implemente um programa que permita ao usuário cadastrar quantos números inteiros desejar, sem
que o tamanho do vetor seja previamente conhecido. Para isso, utilize a função realloc para
expandir o vetor a cada nova inserção. O processo de inserção continua indefinidamente até que o
usuário digite o valor -1, que deve ser tratado como sentinela de parada (não deve ser armazenado
no vetor). Ao final, exiba todos os números cadastrados na ordem em que foram inseridos e libere a
memória alocada.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int valor, i;
    int qtd = 0;
    int *vetor = NULL;

    printf("\nForneca um numero ou -1 para sair\n");

    while(1){
        printf("Numero:");
        scanf("%d", &valor);

        if(valor == -1){
            printf("\nSaindo\n");
            break;
        }

            int *aux;

            aux = realloc(vetor,sizeof(int) * (qtd + 1));

            if(aux == NULL){
                printf("Erro ao alocar memoria.\n");
                free(vetor);
                return 1;
            }

            vetor = aux;
        
        vetor[qtd] = valor;
        qtd++;
    }

    for(i = 0; i < qtd; i++){
        printf("\nValor na Posicao %d: %d", i + 1, vetor[i]);
    }

    free(vetor);

    return 0;
}