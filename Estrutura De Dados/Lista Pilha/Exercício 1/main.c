#include <stdio.h>
#include "pilha.h"

int main(){
    TPilha pi;
    TElemento el;
    int i;

    pi = pilha_cria();
    if(pi!=NULL){
        for(i=1;i<=5;i++){
            el.chave=i;
            if(pilha_push(pi,el)==0){
                printf("\nErro naa Inserção do elemento na pilha\n");
                break;
            }
        }
        printf("\nNúmero de Elementos na pilha = %d\n",pilha_tamanho(pi));
        
        if(pilha_pop(pi,&el)==1){
            printf("\nO elemento = %d foi retirado da pilha\n",el.chave);
            printf("\nNúmero de Elementos na pilha = %d\n",pilha_tamanho(pi));
        }

        el.chave=300;
        if(pilha_push(pi,el)==1){
            printf("\nA chave %d foi inserida na pilha\n",el.chave);
            printf("\nNúmero de Elementos na pilha = %d\n",pilha_tamanho(pi));
        }
        else
            printf("\nErro na Inserção na Pilha!!!\n");

        printf("\nElementos da pilha\n");
        while(pilha_pop(pi,&el)==1)
            printf("%d\n",el.chave);
        
        pilha_termina(&pi);
    }
    else
        printf("\nErro na Criação da Pilha!!!\n");
    return 0;
}