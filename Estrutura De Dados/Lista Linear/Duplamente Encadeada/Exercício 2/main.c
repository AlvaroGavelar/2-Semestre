#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    char nome[100];
}TElemento;

typedef struct Nodo{
    TElemento info;
    struct Nodo *prox, *ant;
}TNodo;

typedef struct {
    int tamanho;
    TNodo *inicio;
    TNodo *fim;
    TNodo *atual;
} TLista;

typedef TLista *tlista;

tlista listaCria(){
    tlista lista;
    lista = malloc(sizeof(TLista));

    if(lista == NULL)
        return NULL;

    lista->inicio = NULL;
    lista->tamanho = 0;
    lista->atual = NULL;
    lista->fim = NULL;

    return lista;
}

int insereListaInicio(tlista l, TElemento e){
    TNodo *novo = malloc(sizeof(TNodo));

    if(novo == NULL)
        return 0;

    strcpy(novo->info.nome , e.nome);

    if(l->tamanho == 0){
        novo->prox = novo;
        novo->ant = novo;
        l->inicio = novo;
        l->fim = novo;
        l->tamanho ++;
    }
    else{
        novo->ant = l->fim;
        novo->prox = l->inicio;
        l->inicio->ant = novo;
        l->fim->prox = novo;
        l->inicio = novo;
        l->tamanho ++;
    }

    return 1;
}

int insereListaFim(tlista l, TElemento e){
    if(l->tamanho == 0){
        insereListaInicio(l, e);
        return 1;
    }

    TNodo *novo = malloc(sizeof(TNodo));
    if(novo == NULL)
        return 0;

    strcpy(novo->info.nome , e.nome);

    novo->ant = l->fim;
    novo->prox = l->inicio;
    l->fim->prox = novo;
    l->inicio->ant = novo;
    l->fim = novo;
    l->tamanho ++;

    return 1;
}  

int acessarPagina(tlista l, TElemento e){
    TNodo *novo, *aux, *prox;
    novo = malloc(sizeof(TNodo));

    if(novo == NULL)
        return 0;

    strcpy(novo->info.nome, e.nome);

    novo->prox = NULL;
    novo->ant = NULL;

    if(l->inicio == NULL){
        l->inicio = novo;
        l->fim = novo;
        l->atual = novo;
        l->tamanho ++;

        return 1;
    }

    aux = l->atual->prox;

    while(aux != NULL){
        prox = aux->prox;
        free(aux);
        l->tamanho--;
        aux = prox;
    }
    
    l->fim = l->atual;
    l->atual->prox = NULL;

    novo->ant = l->atual;
    l->atual->prox = novo;

    l->atual = novo;
    l->fim = novo;
    l->tamanho++;

    return 1;
}

void voltarPagina(tlista l){
    if(l->atual->ant != NULL && l->atual != NULL){
        l->atual = l->atual->ant;
    }
}

void avancarPagina(tlista l){
    if(l->atual != NULL && l->atual->prox != NULL){
        l->atual = l->atual->prox;
    }
}

void imprimirHistorico(tlista l) {
    TNodo *aux = l->inicio;

    if (l->inicio == NULL) {
        printf("Historico vazio!\n");
        return;
    }

    while (aux != NULL) {
        if (aux == l->atual)
            printf("-> %s (ATUAL)\n", aux->info.nome);
        else
            printf("   %s\n", aux->info.nome);

        aux = aux->prox;
    }
}

void limparHistorico(tlista l) {
    TNodo *aux = l->inicio;
    TNodo *prox;

    while (aux != NULL) {
        prox = aux->prox;
        free(aux);
        aux = prox;
    }

    l->inicio = NULL;
    l->fim = NULL;
    l->atual = NULL;
    l->tamanho = 0;
}

int main() {
    tlista l = listaCria();
    int opcao;
    TElemento pagina;

    if (l == NULL)
        return 1;

    do {
        printf("\n===== HISTORICO DO NAVEGADOR =====\n");
        printf("1 - Acessar nova pagina\n");
        printf("2 - Voltar pagina\n");
        printf("3 - Avancar pagina\n");
        printf("4 - Exibir historico\n");
        printf("5 - Limpar historico\n");
        printf("0 - Sair\n");
        printf("Escolha: ");
        scanf("%d", &opcao);
        getchar();

        switch (opcao) {
            case 1:
                printf("Nome da pagina: ");
                fgets(pagina.nome, sizeof(pagina.nome), stdin);
                pagina.nome[strcspn(pagina.nome, "\n")] = '\0';

                if (acessarPagina(l, pagina))
                    printf("Pagina acessada!\n");
                else
                    printf("Erro ao acessar pagina.\n");
                break;

            case 2:
                voltarPagina(l);
                printf("Voltando pagina...\n");
                break;

            case 3:
                avancarPagina(l);
                printf("Avancando pagina...\n");
                break;

            case 4:
                imprimirHistorico(l);
                break;

            case 5:
                limparHistorico(l);
                printf("Historico limpo!\n");
                break;

            case 0:
                printf("Encerrando navegador...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while (opcao != 0);

    limparHistorico(l);
    free(l);

    return 0;
}
