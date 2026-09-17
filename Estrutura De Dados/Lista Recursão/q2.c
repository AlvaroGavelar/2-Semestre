#include <stdio.h>

int soma(int a, int b){
    if(b == 0)
        return a;
    return soma(a + 1, b - 1);
}

int main(){

    int valor = soma(5,8);
    printf("Valor: %d", valor);

    return 0;
}