#include <stdio.h>

int mdc(int x, int y){
    if(x % y == 0)
        return y;

    if(y > x)
        return mdc(y,x);

    return mdc(y, x % y);
}

int main(){

    int valor = mdc(48, 18);
    printf("Valor: %d", valor);

    return 0;
}