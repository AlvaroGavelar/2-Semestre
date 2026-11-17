#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"

int main() {
    lista l = criarLista();

    if (l == NULL)
        return 1;

    int opcao;
    Tarefa tarefa;
    char descricao[100];
    int novaPrioridade;

    do {
        printf("\n===== GERENCIADOR DE TAREFAS =====\n");
        printf("1 - Inserir tarefa\n");
        printf("2 - Remover tarefa concluida\n");
        printf("3 - Listar tarefas pendentes\n");
        printf("4 - Atualizar prioridade\n");
        printf("0 - Sair\n");
        printf("Opcao: ");

        scanf("%d", &opcao);
        getchar();

        switch (opcao) {

            case 1:
                printf("\nDescricao: ");
                fgets(tarefa.descricao, 100, stdin);

                tarefa.descricao[
                    strcspn(tarefa.descricao, "\n")
                ] = '\0';

                printf("Prioridade: ");
                scanf("%d", &tarefa.prioridade);

                printf("Tempo estimado (horas): ");
                scanf("%f", &tarefa.tempo);

                if (inserirTarefa(l, tarefa))
                    printf("\nTarefa inserida!\n");
                else
                    printf("\nErro ao inserir tarefa.\n");

                break;

            case 2:
                if (l->tamanho > 0) {
                    removerTarefa(l);
                    printf("\nTarefa de maior prioridade removida!\n");
                }
                else {
                    printf("\nNao existem tarefas.\n");
                }

                break;

            case 3:
                listarTarefas(l);
                break;

            case 4:
                printf("\nDescricao da tarefa: ");
                fgets(descricao, 100, stdin);

                descricao[
                    strcspn(descricao, "\n")
                ] = '\0';

                printf("Nova prioridade: ");
                scanf("%d", &novaPrioridade);

                if (atualizarPrioridade(l, descricao, novaPrioridade))
                    printf("\nPrioridade atualizada!\n");
                else
                    printf("\nTarefa nao encontrada ou erro de memoria.\n");

                break;

            case 0:
                printf("\nEncerrando programa...\n");
                break;

            default:
                printf("\nOpcao invalida!\n");
        }

    } while (opcao != 0);

    liberarLista(l);

    return 0;
}