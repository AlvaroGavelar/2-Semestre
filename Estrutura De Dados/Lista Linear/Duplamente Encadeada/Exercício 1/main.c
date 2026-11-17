#include <stdio.h>
#include "lista.h"

int main(){

    lista soldados = criarLista();

    inserirInicio(soldados, "Ana");
    inserirInicio(soldados, "Bruno");
    inserirFim(soldados, "Carlos");

    removerNome(soldados, "Carlo");

    printf("\nLista de soldados:\n");
    imprimirLista(soldados);

    trocaLista(soldados, 1,2);

    // josephus(soldados, 3);
    // josephus(soldados, 2);



    return 0;
}