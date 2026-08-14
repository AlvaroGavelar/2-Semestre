/*
Escreva um programa que leia do usuário uma palavra (sem espaços). Após a leitura, aloque
dinamicamente uma área de memória com o tamanho exato necessário para armazenar a palavra,
incluindo o caractere terminador '\0'. Copie o conteúdo da string para essa nova área e exiba a
palavra copiada. Libere a memória ao final. 
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
    char palavra[100];
    char *novaPalavra;
    int tam;

    printf("\nPalavra:");
    fgets(palavra,100,stdin);

    tam = strlen(palavra);
    if(palavra[tam - 1] == '\n')
        palavra[tam - 1] = '\0';
    else
        limpaBuffer();   

    novaPalavra = (char*)malloc(sizeof(char) * (strlen(palavra) + 1));

    if(novaPalavra == NULL){
        return 0;
    }

    strcpy(novaPalavra, palavra);

    printf("\nCopia: %s\n", novaPalavra);

    free(novaPalavra);

    return 0;
}