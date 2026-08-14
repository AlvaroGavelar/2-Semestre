/*
Construa um programa (main) que aloque em tempo de execução (dinamicamente) uma matriz de
ordem m x n (linha por coluna), usando 1+m chamadas a função malloc. Agora, aproveite este
programa para construir uma função que recebendo os parâmetros m e n aloque uma matriz de
ordem m x n e retorne um ponteiro para esta matriz alocada. Crie ainda uma função para liberar a
área de memória alocada pela matriz. Finalmente, crie um novo programa (main) que teste/use as
duas funções criadas acima.
*/

#include <stdio.h>
#include <stdlib.h>

int **alocaMatriz(int l, int c){
    int **matriz;

    matriz = (int**)malloc(sizeof(int) * l);
    
    int i;

    if(matriz){
        for(i = 0; i < l; i++){
            matriz[i] = (int*)malloc(sizeof(int) * c);
        }
    }

    return matriz;
}

int liberamatriz(int **matriz, int l){
    int i;

    for(i = 0; i < l; i++){
        free(matriz[i]);
    }
    free(matriz);

    printf("\nLiberado Com Sucesso!!\n");
}

int main(){
    int l, c, i, j;

    printf("\nNumero de Linhas:");
    scanf("%d", &l);
    printf("\nNumero de Colunas:");
    scanf("%d", &c);

    int **matriz;

    matriz = alocaMatriz(l, c);

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("Digite matriz[%d][%d]: ", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    printf("\nMatriz:\n");

    for (int i = 0; i < l; i++) {
        for (int j = 0; j < c; j++) {
            printf("%d ", matriz[i][j]);
        }
        printf("\n");
    }

    liberamatriz(matriz, l);

    return 0;
}