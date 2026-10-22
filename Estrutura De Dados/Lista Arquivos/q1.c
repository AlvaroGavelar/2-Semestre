/*Crie uma estrutura Aluno com:
    matricula;
    nome;
    tres notas;
    media;
    situacao.
O programa deve apresentar um menu:
1 - Cadastrar aluno
2 - Listar alunos
3 - Consultar aluno por matricula
4 - Exibir aprovados
5 - Exibir reprovados
0 - Sair
A media deve ser calculada automaticamente. Considere aprovacao com media maior ou igual a 60. */

#include <stdio.h>
#include <string.h>

void limpaBuffer(){
    int ch;
    do{
        ch = getchar();
    }while(ch != '\n' && ch != EOF);
}

typedef struct{
    int matricula;
    char nome[100];
    float n1,n2,n3;
    float media;
    char situacao[20];
}TAluno;

float mediaNotas(float n1, float n2, float n3){
    return (n1 + n2 + n3) / 3;
}

void situacaoAluno(TAluno *a){
    if(a->media >= 60)
        strcpy(a->situacao, "Aprovado");
    else
        strcpy(a->situacao, "Reprovado");
}

void cadastroAluno(FILE *arquivo, TAluno a){
    int tam;
    char Tnome[50];
    arquivo = fopen("alunos.dat", "ab");
    if(arquivo == NULL){
        printf("Erro ao Abrir o Arquivo");
        return;
    }

    printf("Matricula:");
    scanf("%d", &a.matricula);
    limpaBuffer();

    printf("Nome:");
    fgets(Tnome, 50, stdin);
    tam = strlen(Tnome);
    if(Tnome[tam - 1] == '\n')
        Tnome[tam - 1] = '\0';
    else    
        limpaBuffer();
    
    strcpy(a.nome, Tnome);


    printf("Nota 1: ");
    scanf("%f", &a.n1);

    printf("Nota 2: ");
    scanf("%f", &a.n2);

    printf("Nota 3: ");
    scanf("%f", &a.n3);

    a.media = mediaNotas(a.n1, a.n2, a.n3);

    situacaoAluno(&a);

    fwrite(&a, sizeof(a), 1, arquivo);

    fclose(arquivo);
    printf("\nAluno Cadastrado\n");
}

void mostrarAluno(TAluno aluno){
    printf("\n-------------------------\n");
    printf("Matricula: %d\n", aluno.matricula);
    printf("Nome: %s\n", aluno.nome);
    printf("Nota 1: %.2f\n", aluno.n1);
    printf("Nota 2: %.2f\n", aluno.n2);
    printf("Nota 3: %.2f\n", aluno.n3);
    printf("Media: %.2f\n", aluno.media);
    printf("Situacao: %s\n", aluno.situacao);
}

void listar(FILE *arquivo, TAluno aluno){
    arquivo = fopen("alunos.dat", "rb");

    if(arquivo == NULL){
        printf("Erro ao Abrir o Arquivo");
        return;
    }

    while(fread(&aluno, sizeof(aluno), 1, arquivo) == 1){
        mostrarAluno(aluno);
    }

    fclose(arquivo);
}

void consultaMatricula(FILE *arquivo, TAluno aluno){
    int matricula, encontrou = 0;

    arquivo = fopen("alunos.dat", "rb");

    if(arquivo == NULL){
        printf("Erro ao Abrir o Arquivo");
        return;
    }

    printf("Forneca a matricula:");
    scanf("%d", &matricula);

    while(fread(&aluno, sizeof(aluno), 1, arquivo) == 1){
        if(aluno.matricula == matricula){
            mostrarAluno(aluno);
            encontrou = 1;
        }
    }

    if(!encontrou)
        printf("Aluno Nao Encontrado!\n");

    fclose(arquivo);
}

void exibirAprovado(FILE *arquivo, TAluno aluno){
    arquivo = fopen("alunos.dat", "rb");

    if(arquivo == NULL){
        printf("Erro ao Abrir o Arquivo");
        return;
    }

    printf("--- Alunos Aprovados ---");
    while(fread(&aluno, sizeof(aluno), 1, arquivo) == 1){
        if(aluno.media >= 60){
            mostrarAluno(aluno);
        }
    }

    fclose(arquivo);
}

void exibirReprovado(FILE *arquivo, TAluno aluno){
    arquivo = fopen("alunos.dat", "rb");

    if(arquivo == NULL){
        printf("Erro ao Abrir o Arquivo");
        return;
    }

    printf("--- Alunos Reprovado ---");
    while(fread(&aluno, sizeof(aluno), 1, arquivo) == 1){
        if(aluno.media < 60){
            mostrarAluno(aluno);
        }
    }

    fclose(arquivo);
}


int main(){
    int menu;
    FILE *arquivo;
    TAluno a;
    int matricula;

    do{
        printf("\n===== SISTEMA ESCOLAR =====\n");
        printf("1 - Cadastrar aluno\n");
        printf("2 - Listar alunos\n");
        printf("3 - Consultar aluno por matricula\n");
        printf("4 - Exibir aprovados\n");
        printf("5 - Exibir reprovados\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                cadastroAluno(arquivo,a);
                break;
            case 2:
                listar(arquivo, a);
                break;
            case 3:
                consultaMatricula(arquivo, a);
                break;
            case 4:
                exibirAprovado(arquivo, a);
                break;
            case 5:
                exibirReprovado(arquivo, a);
                break;
            case 0:
                printf("Encerrando...\n");
                break;
            default:
                printf("Opcao invalida.\n");
        }
    }while(menu != 0);

    return 0;
}

