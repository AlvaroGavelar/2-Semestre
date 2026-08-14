/*
Implemente um programa que leia dois números inteiros, m e n, representando, respectivamente, o
número de linhas e de colunas de uma matriz. Em seguida, aloque dinamicamente uma matriz de
inteiros com m linhas e n colunas. Solicite que o usuário preencha todos os elementos da matriz. Após o
preenchimento, exiba o conteúdo em formato tabular (semelhante a uma tabela).
Ao final, libere corretamente toda a memória alocada.
*/

#include <stdio.h>
#include <stdlib.h>

int main(){
    int m; //Linha
    int n; //Coluna
    int i, j;

    int **matriz;

    printf("Numero De Linhas:");
    scanf("%d", &m);
    printf("Numero de Colunas:");
    scanf("%d", &n);
    
    matriz = (int**)malloc(sizeof(int) * m);

    if(matriz){
        for(i = 0; i < m; i++){
        matriz[i] = (int*)malloc(sizeof(int*) * n);
            if(matriz[i] == NULL){
                printf("\nErro de Alocacao!\n");

                for(j = 0; j < m; j++){
                    free(matriz[i]);
                }

                free(matriz);
                return 0;
            }
        }
    }
    else{
        free(matriz);
        return 0;
    }

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("Valor da Posicao [%d][%d]:", i, j);
            scanf("%d", &matriz[i][j]);
        }
    }

    for(i = 0; i < m; i++){
        for(j = 0; j < n; j++){
            printf("[%d]\t",matriz[i][j]);
        }
        printf("\n");
    }

    for(i = 0; i < m; i++){
        free(matriz[i]);
    }
    free(matriz);

    return 0;
}