#include <stdio.h>

int pesquisaBinaria(int vetor[], int inicio, int fim, int valor){
    if(inicio > fim)
        return -1;
    
    int meio = (inicio + fim) / 2;

    if(vetor[meio] == valor)
        return meio;

    if(valor < vetor[meio])
        return pesquisaBinaria(vetor, inicio, meio - 1, valor);
    
    return pesquisaBinaria(vetor, meio + 1, fim, valor);
}


int main(){
    int vetor[] = {2, 5, 8, 12, 17, 21, 30, 42, 50};


    int valor = pesquisaBinaria(vetor, 0, 8, 30);
    printf("Valor: %d", valor);

    return 0;
}