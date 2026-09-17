#include <stdio.h>

int arkerman(int m, int n){
    if(m == 0)
        return n + 1;

    if(n == 0)
        return arkerman(m-1, 1);

    return arkerman(m-1, arkerman(m, n-1));
}

int main(){

    int valor = arkerman(1,2);
    printf("Valor: %d", valor);

    return 0;
}