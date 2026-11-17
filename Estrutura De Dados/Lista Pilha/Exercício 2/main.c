#include <stdio.h>
#include <stdlib.h>

typedef struct Nodo {
    int info;
    struct Nodo *proximo;
} TNodo;

int main() {
    TNodo *topo = NULL;
    int numero;

    for(int i=1; i <= 15; i++){
        printf("\nForneça um numero inteiro:");
        scanf("%d", &numero);

        if(numero % 2 == 0){
            TNodo *novo = malloc(sizeof(TNodo));
            if(novo == NULL)
                return 0;
                novo->info = numero;
                novo->proximo = topo;
                topo = novo;
        }
        else
            if(topo == NULL){
                TNodo *aux = topo;
                topo = aux->proximo;
                printf("\nRemovido: %d", aux->info);
                free(aux);

            }
    }

    printf("\n\nEsvaziando a pilha:");

    while(topo != NULL){
        TNodo *aux = topo;
        topo = aux->proximo;
        printf("\nRemovido: %d", aux->info);
        free(aux);
    }
    
    return 0;
}