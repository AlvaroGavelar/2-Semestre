/*
Criar uma estrutura , contendo nome, data de nascimento e CPF. Crie uma variável que é um
ponteiro para esta estrutura (no programa principal). Depois crie uma função que receba este
ponteiro e preencha os dados da estrutura e também uma uma função que receba este ponteiro e
imprima os dados da estrutura. Finalmente, faça a chamada a esta função na função principal.

Idem a questão acima, mas construa as funções usando referências (&).

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[100];
    char data[11];
    char cpf[12];
}TPerfil;

void limpaBuffer(){
    int c;
    do{
        c = getchar();
    }while(c != '\n' && c != EOF);
}

void preencheStruct(TPerfil *p){

    int tam;

    printf("\nNome:");
    fgets(p->nome, 100, stdin);
        tam = strlen(p->nome);
        if(p->nome[tam - 1] == '\n')
            p->nome[tam - 1] = '\0';
        else
            limpaBuffer();
    printf("\nData:");
    fgets(p->data, 11, stdin);
        tam = strlen(p->data);
        if(p->data[tam - 1] == '\n')
            p->data[tam - 1] = '\0';
        else
            limpaBuffer();
    printf("\nCpf:");
    fgets(p->cpf, 12, stdin);
        tam = strlen(p->cpf);
        if(p->cpf[tam - 1] == '\n')
            p->cpf[tam - 1] = '\0';
        else
            limpaBuffer();
}

void imprimiStruct(TPerfil *p){
    printf("\nNome: %s", p->nome);
    printf("\nData: %s", p->data);
    printf("\nCpf: %s", p->cpf);
}

int main(){
    TPerfil p;

    preencheStruct(&p);
    imprimiStruct(&p);


    return 0;
}