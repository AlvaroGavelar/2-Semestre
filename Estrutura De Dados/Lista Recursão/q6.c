#include <stdio.h>
#include <string.h>

int parenteses(char str[], int pos, int contador){
    if(str[pos] == '\0')
        return contador == 0;
    
    if(str[pos] == '(')
        contador++;
    else if(str[pos] == ')')
        contador--;

    if(contador < 0)
        return 0;

    return parenteses(str, pos+1, contador);
}

int main() {
    char str[] = "(())";

    if (parenteses(str, 0, 0))
        printf("Bem formada");
    else
        printf("Nao e bem formada");

    return 0;
}