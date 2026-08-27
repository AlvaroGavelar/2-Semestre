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
    char matricula[10], nome[100];
    float salario;
    int sair;

    arq = fopen("dados.txt", "a+");

    if(arq == NULL){
        printf("\nErro na Abertura do Arquivo!\n");
        return 0;
    }

    // Posicionando no final do arquivo para escrever
    fseek(arq, 0, SEEK_END);

    do{

        printf("Forneca a Matricula: ");
        fgets(matricula, 10, stdin);

        int tam = strlen(matricula);

        if(tam > 0 && matricula[tam - 1] == '\n')
            matricula[tam - 1] = '\0';
        else
            limpaBuffer();

        printf("Forneca o Nome: ");
        fgets(nome, 100, stdin);

        tam = strlen(nome);

        if(tam > 0 && nome[tam - 1] == '\n')
            nome[tam - 1] = '\0';
        else
            limpaBuffer();

        printf("Forneca o Salario: ");
        scanf("%f", &salario);
        limpaBuffer();

        fprintf(arq, "%s;%s;%.2f\n",
                matricula, nome, salario);

        printf("Deseja sair? 1-Sim 2-Nao: ");
        scanf("%d", &sair);
        limpaBuffer();

    }while(sair != 1);

    // Posicionando no inicio do arquivo
    fseek(arq, 0, SEEK_SET);

    printf("\n\nDADOS CADASTRADOS\n\n");

    while(fscanf(arq, "%9[^;];%99[^;];%f\n",
                 matricula, nome, &salario) == 3){

        printf("%s\t\t%s\t\t%.2f\n",
               matricula, nome, salario);
    }

    fclose(arq);

    return 0;
}
