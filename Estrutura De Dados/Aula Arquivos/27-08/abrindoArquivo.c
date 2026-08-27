#include <stdio.h>
#include <string.h>

void limpaBuffer(){
    int ch;
    do{
        ch = getchar();
    }while(ch != '\n' && ch != EOF);
}

int main(){
    FILE *arq;
    char matricula[10],nome[100];
    int sair;
    float salario;

    arq = fopen("dados.txt", "a");

    if(arq != NULL){

        do{
            
            printf("Forneca a Matricula:");
            fgets(matricula, 10, stdin);

            int tam;

            tam = strlen(matricula);
            if(matricula[tam - 1] == '\n')
                matricula[tam - 1] = '\0';
            else
                limpaBuffer();

            printf("Forneca o Nome:");
            fgets(nome, 100, stdin);

            tam = strlen(nome);
            if(nome[tam - 1] == '\n')
                nome[tam - 1] = '\0';
            else
                limpaBuffer();

            printf("Forneca o Salario:");
            scanf("%f", &salario);

            fprintf(arq, "%s;%s;%.2f\n", matricula, nome, salario);

            printf("!Deseja sair? 1-Sim 2-Nao");
            scanf("%d", &sair);

        }while(sair != 1);

        fclose(arq);
    }
    else
        printf("\nErro na Abertura do Arquivo!\n");

    return 0;
}