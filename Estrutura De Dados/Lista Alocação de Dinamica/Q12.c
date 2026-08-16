/*
Faça um programa que permita ao usuário cadastrar vários nomes de pessoas.
Cada nome deve ser armazenado em uma área de memória alocada dinamicamente, de forma que o
espaço utilizado seja exatamente o necessário para guardar o nome. Além disso, mantenha todos os
ponteiros para os nomes em um vetor dinâmico de ponteiros, que também deve crescer conforme novos
nomes forem adicionados. Ao término do cadastro (por exemplo, quando o usuário digitar a palavra
"fim"), exiba todos os nomes cadastrados e, em seguida, libere a memória utilizada.
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
    int qtd = 0, tamanho;
    char nome[100];
    char** vetor = NULL;

    while(1){
        printf("\nNome:");
        fgets(nome, 100, stdin);

        
        tamanho = strlen(nome);
        if(nome[tamanho - 1] == '\n'){
            nome[tamanho - 1] = '\0';
        }
        else
        limpaBuffer();
        
        if(strcmp(nome,"fim") == 0){
            break;
        }
        
        vetor = realloc(vetor, (qtd + 1) * sizeof(char*));

        if(vetor){
            vetor[qtd] = malloc((tamanho + 1) * sizeof(char));

            if(vetor[qtd]){
                strcpy(vetor[qtd],nome);
            }
            else
                free(vetor[qtd]);

            qtd++;
        }
        else
            free(vetor);

        
    }

    printf("\nNomes cadastrados:\n");

    for (int i = 0; i < qtd; i++) {
        printf("%s\n", vetor[i]);
    }

    for(int i = 0; i < qtd; i++){
        free(vetor[i]);
    }

    free(vetor);
        

    return 0;
}