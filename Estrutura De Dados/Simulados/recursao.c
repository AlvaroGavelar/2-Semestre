/*
===========================================================
QUESTÃO 2 — RECURSÃO
===========================================================
Implemente uma função recursiva que receba um vetor de
inteiros e a quantidade de elementos e verifique se o vetor
está em ordem não decrescente.
Um vetor está em ordem não decrescente quando cada elemento
é menor ou igual ao próximo.
Exemplos:
[1, 2, 3, 4, 5] → 1
[1, 2, 2, 5, 8] → 1
[1, 3, 2, 4]     → 0
[5]              → 1
A função deve retornar:
1 → vetor está ordenado
0 → vetor não está ordenado
RESTRIÇÕES:
- Deve ser obrigatoriamente recursiva.
- Não pode utilizar for, while ou do while.
DICA:
A comparação principal deve ser entre dois elementos
consecutivos:
v[0] <= v[1]
Depois, a função deve continuar verificando o restante
do vetor.
===========================================================
*/

#include <stdio.h>

int listaDecrescente(int valor[], int n){
  if(n <= 1)
        return 1;

    // Se o elemento atual for maior que o próximo,
    // o vetor não está em ordem
    if(valor[0] > valor[1])
        return 0;

    // Verifica o restante do vetor
    return listaDecrescente(valor + 1, n - 1);
}


int main() {

    int v[] = {1, 2, 3, 4, 5};
    int n = 5;

    printf("%d\n", listaDecrescente(v, n));

    return 0;
}