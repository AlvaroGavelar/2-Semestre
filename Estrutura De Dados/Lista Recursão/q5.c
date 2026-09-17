#include <stdio.h>

int fatorial(int n){
    if(n == 1)
        return 1;

    return n * fatorial(n - 1);
}

float serie(int n){
    if(n == 1)
        return 1;
    
    return serie(n - 1) + 1.0 / fatorial(n);
}

int main(){

    printf("%.7f", serie(4));

    return 0;
}