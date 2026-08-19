/*
Faça um programa que leia duas palavras fornecidas pelo usuário. Aloque dinamicamente uma nova
área de memória com tamanho suficiente para armazenar a concatenação das duas strings (incluindo o
caractere '\0'). Construa a string resultante, exiba-a na tela e libere a memória.
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void limpaBuffer(){
    int c;
    do{
        c = getchar();
    }while(c != '\n' && c != EOF);
}

int main(){
    char nome1[100];
    char nome2[100];
    char *resultado;
    int tamanho;

    printf("Nome 1:");
    fgets(nome1, 100, stdin);

    tamanho = strlen(nome1);
        if(nome1[tamanho - 1] == '\n'){
            nome1[tamanho - 1] = '\0';
        }
    else
        limpaBuffer();

    printf("Nome 2:");
    fgets(nome2, 100, stdin);

    tamanho = strlen(nome2);
    if(nome2[tamanho - 1] == '\n'){
            nome2[tamanho - 1] = '\0';
        }
    else
        limpaBuffer();

    resultado = malloc((strlen(nome1) + strlen(nome2) + 1) * sizeof(char));

    if (resultado == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
}

    strcpy(resultado, nome1);
    strcat(resultado, nome2);

    printf("Juncao: %s", resultado);

    free(resultado);

        return 0;
}