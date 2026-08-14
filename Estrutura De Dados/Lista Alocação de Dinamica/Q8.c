/*
Faça um programa que leia um número inteiro n, representando a quantidade de elementos que
serão armazenados. Em seguida, aloque dinamicamente um vetor capaz de armazenar n inteiros.
O programa deve solicitar que o usuário digite os valores um a um, preenchendo todo o vetor. Após
a leitura, exiba todos os elementos armazenados na tela, na mesma ordem em que foram digitados.
Por fim, libere corretamente a memória alocada
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int qtd;

    printf("\nForneca um Numero Inteiro para a Quantiadade:");
    scanf("%d", &qtd);

    int *vetor = (int*)malloc(sizeof(int) * qtd);

     if (vetor == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 0;
     }

    for(int i = 0; i < qtd; i++){
        printf("Valor da Posicao %d: ", i + 1);
        scanf("%d", &vetor[i]);
    }

    printf("\nElementos armazenados:\n");

    for (int i = 0; i < qtd; i++) {
        printf("%d ", vetor[i]);
    }

    printf("\n");

    free(vetor);

    return 0;
}