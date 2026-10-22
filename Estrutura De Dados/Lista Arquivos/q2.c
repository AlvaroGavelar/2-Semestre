/*
Crie um programa para controlar produtos.
Cada produto possui:
• código;
• nome;
• preço;
• quantidade em estoque.
O sistema deve possuir o menu:
1 - Cadastrar produto
2 - Listar produtos
3 - Buscar produto por código
4 - Registrar entrada no estoque
5 - Registrar venda
6 - Mostrar valor total do estoque
0 - Sair
A venda só pode ser realizada se houver quantidade suficiente em estoque.
*/

#include <stdio.h>
#include <string.h>

typedef struct{
    int codigo;
    char nome[100];
    float preco;
    int qtd_produto;
}Produto;

void limpaBuffer(){
    int ch;
    do{
        ch = getchar();
    }while(ch != '\n' && ch != EOF);
}

void mostrarProduto(Produto produto){
    printf("-- Produto --");
    printf("\nCodigo: %d", produto.codigo);
    printf("\nNome: %s", produto.nome);
    printf("\nPreco: %.2f", produto.preco);
    printf("\nQuantidade: %d", produto.qtd_produto);
    printf("\n-----------");
}

void cadastroProduto(char *arq_produto, Produto Produto){
    FILE *arq;
    int codigo, tam;
    char nome[100];

    printf("Codigo:");
    scanf("%d", &codigo);

    arq = fopen(arq_produto, "rb");

    if(arq != NULL){

        while(fread(&Produto, sizeof(Produto), 1, arq) == 1){
            if(Produto.codigo == codigo){
                printf("Produto ja Cadastrado");
                fclose(arq);
                return;
            }
        }
        fclose(arq);
    }

    arq = fopen(arq_produto, "ab");

    if(arq == NULL){
        printf("Problema para abrir o arquivo");
        return;
    }

    Produto.codigo = codigo;

    limpaBuffer();
    printf("Nome:");
    fgets(nome, 100, stdin);
    tam = strlen(nome);
    if(nome[tam-1] == '\n')
        nome[tam-1] = '\0';
    else
        limpaBuffer();

    strcpy(Produto.nome, nome);

    printf("Preco:");
    scanf("%f", &Produto.preco);

    printf("Quantidade:");
    scanf("%d", &Produto.qtd_produto);

    fwrite(&Produto, sizeof(Produto), 1, arq);
    fclose(arq);

    printf("\nProduto Cadastrado\n");

}

void listarProdutos(char *arq_produto, Produto produto){
    FILE *arq;

    arq = fopen(arq_produto, "rb");

    if(arq == NULL){
        printf("Problema para abrir o arquivo");
        return;
    }
    
    while(fread(&produto, sizeof(produto), 1, arq) == 1){
        mostrarProduto(produto);
    }

    fclose(arq);
}

void buscarProduto(char *arq_produto, Produto Produto){
    FILE *arq;
    int codigo, encontrou = 0;

    arq = fopen(arq_produto, "rb");

    if(arq == NULL){
        printf("Problema para abrir o arquivo");
        return;
    }

    printf("Codigo:");
    scanf("%d", &codigo);

    while(fread(&Produto, sizeof(Produto), 1, arq) == 1){
        if(Produto.codigo == codigo){
            mostrarProduto(Produto);
            encontrou = 1;
        }
    }
    if(!encontrou)
        printf("Codigo Nao Encontrado");

    fclose(arq);
}

void registraEntrada(char *arq_produto, Produto Produto){
    FILE *arq;
    int qtd, codigo, encontrou = 0;

    arq = fopen(arq_produto, "rb+");

    if(arq == NULL){
        printf("Problema para abrir o arquivo");
        return;
    }

    printf("Codigo do Produto:");
    scanf("%d", &codigo);
    
    while(fread(&Produto, sizeof(Produto), 1, arq) == 1){
        if(Produto.codigo == codigo){
            printf("Quantidade a ser adicionada:");
            scanf("%d", &qtd);
            Produto.qtd_produto += qtd;
            fseek(arq, -(long)sizeof(Produto), SEEK_CUR);
        fwrite(&Produto, sizeof(Produto), 1, arq);
            printf("Estoque Aumentado");
            encontrou = 1;
            break;
        }
    }
    
    if(!encontrou)
        printf("Codigo Nao Encontrado!");
        
    fclose(arq);
}

void registraSaida(char *arq_produto, Produto Produto){
    FILE *arq;
    int qtd, codigo, encontrou = 0;

    arq = fopen(arq_produto, "rb+");

    if(arq == NULL){
        printf("Problema para abrir o arquivo");
        return;
    }

    printf("Codigo do Produto:");
    scanf("%d", &codigo);
        
    while(fread(&Produto, sizeof(Produto), 1, arq) == 1){
        if(Produto.codigo == codigo){
            printf("Quantidade a ser Vendida:");
            scanf("%d", &qtd);

        if(qtd > Produto.qtd_produto){
            printf("Venda Nao Finalizada!");
            return;
        }
        else
            Produto.qtd_produto -= qtd;
            fseek(arq, -(long)sizeof(Produto), SEEK_CUR);
            fwrite(&Produto, sizeof(Produto), 1, arq);
            printf("Produto Vendido");
            encontrou = 1;
            break;
        }
    }
    
    if(!encontrou)
        printf("Codigo Nao Encontrado!");

    fclose(arq);
}

void valorEstoque(char *arq_produto, Produto Produto){
    FILE *arq;
    float soma = 0;

    arq = fopen(arq_produto, "rb");

    if(arq == NULL){
        printf("Problema para abrir o arquivo");
        return;
    }

    while(fread(&Produto, sizeof(Produto), 1, arq) == 1){
        soma += Produto.qtd_produto * Produto.preco;
    }

    fclose(arq);

    printf("Soma: %.2f", soma);
}

int main(){
    int menu;
    Produto produto;
    char *arq_produto = "produtos.dat";

    do{
        printf("\n-- Menu --");
        printf("\n1 - Cadastro");
        printf("\n2 - Listar");
        printf("\n3 - Buscar");
        printf("\n4 - Registra Entrada");
        printf("\n5 - Registrar Venda");
        printf("\n6 - Total Estoque");
        printf("\n0 - Sair");
        printf("\n----------\n");
        printf("\nEscolha:");
        scanf("%d", &menu);

        switch(menu){
            case 1:
                cadastroProduto(arq_produto, produto);
                break;
            case 2:
                listarProdutos(arq_produto, produto);
                break;
            case 3:
                buscarProduto(arq_produto, produto);
                break;
            case 4:
                registraEntrada(arq_produto, produto);
                break;
            case 5:
                registraSaida(arq_produto, produto);
                break;
            case 6:
                valorEstoque(arq_produto, produto);
                break;
            case 0:
                printf("\nEncerrando...");
                break;
            default:
                printf("\nOpcao Errada!\n");
        }

    }while(menu!=0);

    return 0;
}