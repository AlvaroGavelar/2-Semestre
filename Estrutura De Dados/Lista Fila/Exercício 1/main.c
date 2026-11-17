
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "fila.h"

int main() {
    TFila fila = fila_cria();

    if (fila == NULL)
        return 1;

    srand(time(NULL));

    int id = 1;
    int ciclo = 1;
    int opcao;

    do {
        printf("\n========== CICLO %d ==========\n", ciclo);

        // Se a fila estiver vazia, gera documentos
        if (rand() % 2 == 0 || fila == NULL) {

            int quantidade = rand() % 4 + 1;

            printf("Gerando %d documentos...\n", quantidade);

            for (int i = 0; i < quantidade; i++) {
                TElemento doc;

                doc.id = id++;
                doc.linhas = rand() % 500 + 1;

                fila_insere(fila, doc);

                printf("Doc %d: %d linhas\n",
                       doc.id, doc.linhas);
            }

        } else {

            TElemento doc;

            fila_retira(fila, &doc);

            printf("Imprimindo documento %d...\n", doc.id);

            if (doc.linhas > 100) {

                doc.linhas -= 100;

                printf("100 linhas impressas.\n");
                printf("Restam %d linhas.\n", doc.linhas);

                // Documento incompleto volta para o início
                // para continuar sendo atendido
                // (não é o comportamento FIFO correto
                // se outros documentos já estiverem na fila)

                // Para manter o documento na frente,
                // precisamos de uma operação diferente.
                
                fila_insere(fila, doc);

            } else {

                printf("%d linhas impressas.\n", doc.linhas);
                printf("Documento concluido!\n");

            }
        }

        fila_imprime(fila);

        printf("\nContinuar? (1-Sim / 0-Nao): ");
        scanf("%d", &opcao);

        ciclo++;

    } while (opcao == 1);

    fila_libera(fila);

    return 0;
}
