#include <stdio.h>
#include <string.h>

typedef struct {
    int dia;
    int mes;
    int ano;
} Data;

typedef struct {
    int id;
    char nome[50];
    char fabricante[50];
    char modelo[50];
    int anoFabricacao;
    char localizacao[100];
    int emManutencao;
} Equipamento;

typedef struct {
    int id;
    int idEquipamento;
    Data dataAbertura;
    Data dataConclusao;
    char descricaoProblema[200];
    char descricaoSolucao[200];
    float custo;
    char tecnicoResponsavel[100];
    int prioridade;
} Manutencao;

typedef struct {
    int id;
    char nome[100];
    char especialidade[50];
    int disponivel;
} Tecnico;

void limpaBuffer() {
    int ch;

    do {
        ch = getchar();
    } while(ch != '\n' && ch != EOF);
}

void cadastrarEquipamento() {
    FILE *arq;
    Equipamento equipamento;

    arq = fopen("equipamentos.dat", "ab");

    if(arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    printf("ID: ");
    scanf("%d", &equipamento.id);

    limpaBuffer();

    printf("Nome: ");
    fgets(equipamento.nome, 50, stdin);
    equipamento.nome[strcspn(equipamento.nome, "\n")] = '\0';

    printf("Fabricante: ");
    fgets(equipamento.fabricante, 50, stdin);
    equipamento.fabricante[strcspn(equipamento.fabricante, "\n")] = '\0';

    printf("Modelo: ");
    fgets(equipamento.modelo, 50, stdin);
    equipamento.modelo[strcspn(equipamento.modelo, "\n")] = '\0';

    printf("Ano de fabricacao: ");
    scanf("%d", &equipamento.anoFabricacao);

    limpaBuffer();

    printf("Localizacao: ");
    fgets(equipamento.localizacao, 100, stdin);
    equipamento.localizacao[strcspn(equipamento.localizacao, "\n")] = '\0';

    equipamento.emManutencao = 0;

    fwrite(&equipamento, sizeof(equipamento), 1, arq);

    fclose(arq);

    printf("Equipamento cadastrado!\n");
}

void cadastrarTecnico() {
    FILE *arq;
    Tecnico tecnico;

    arq = fopen("tecnicos.dat", "ab");

    if(arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    printf("ID: ");
    scanf("%d", &tecnico.id);

    limpaBuffer();

    printf("Nome: ");
    fgets(tecnico.nome, 100, stdin);
    tecnico.nome[strcspn(tecnico.nome, "\n")] = '\0';

    printf("Especialidade: ");
    fgets(tecnico.especialidade, 50, stdin);
    tecnico.especialidade[strcspn(tecnico.especialidade, "\n")] = '\0';

    tecnico.disponivel = 1;

    fwrite(&tecnico, sizeof(tecnico), 1, arq);

    fclose(arq);

    printf("Tecnico cadastrado!\n");
}

int buscarEquipamento(int id, Equipamento *equipamento) {
    FILE *arq;

    arq = fopen("equipamentos.dat", "rb");

    if(arq == NULL)
        return 0;

    while(fread(equipamento, sizeof(*equipamento), 1, arq) == 1) {

        if(equipamento->id == id) {
            fclose(arq);
            return 1;
        }
    }

    fclose(arq);

    return 0;
}

int buscarTecnico(int id, Tecnico *tecnico) {
    FILE *arq;

    arq = fopen("tecnicos.dat", "rb");

    if(arq == NULL)
        return 0;

    while(fread(tecnico, sizeof(*tecnico), 1, arq) == 1) {

        if(tecnico->id == id) {
            fclose(arq);
            return 1;
        }
    }

    fclose(arq);

    return 0;
}

void abrirManutencao() {
    FILE *arq;

    Equipamento equipamento;
    Tecnico tecnico;
    Manutencao manutencao;

    int idEquipamento;
    int idTecnico;

    printf("ID do equipamento: ");
    scanf("%d", &idEquipamento);

    if(!buscarEquipamento(idEquipamento, &equipamento)) {
        printf("Equipamento nao encontrado!\n");
        return;
    }

    if(equipamento.emManutencao == 1) {
        printf("Equipamento ja esta em manutencao!\n");
        return;
    }

    printf("ID do tecnico: ");
    scanf("%d", &idTecnico);

    if(!buscarTecnico(idTecnico, &tecnico)) {
        printf("Tecnico nao encontrado!\n");
        return;
    }

    if(tecnico.disponivel == 0) {
        printf("Tecnico indisponivel!\n");
        return;
    }

    manutencao.idEquipamento = idEquipamento;

    printf("ID da manutencao: ");
    scanf("%d", &manutencao.id);

    printf("Data de abertura (dia mes ano): ");
    scanf("%d %d %d",
          &manutencao.dataAbertura.dia,
          &manutencao.dataAbertura.mes,
          &manutencao.dataAbertura.ano);

    manutencao.dataConclusao.dia = 0;
    manutencao.dataConclusao.mes = 0;
    manutencao.dataConclusao.ano = 0;

    limpaBuffer();

    printf("Descricao do problema: ");
    fgets(manutencao.descricaoProblema, 200, stdin);
    manutencao.descricaoProblema[
        strcspn(manutencao.descricaoProblema, "\n")
    ] = '\0';

    manutencao.descricaoSolucao[0] = '\0';

    printf("Custo: ");
    scanf("%f", &manutencao.custo);

    limpaBuffer();

    printf("Tecnico responsavel: ");
    fgets(manutencao.tecnicoResponsavel, 100, stdin);
    manutencao.tecnicoResponsavel[
        strcspn(manutencao.tecnicoResponsavel, "\n")
    ] = '\0';

    printf("Prioridade (1-Baixa 2-Media 3-Alta 4-Critica): ");
    scanf("%d", &manutencao.prioridade);

    arq = fopen("manutencoes.dat", "ab");

    if(arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    fwrite(&manutencao, sizeof(manutencao), 1, arq);

    fclose(arq);

    equipamento.emManutencao = 1;

    arq = fopen("equipamentos.dat", "rb+");

    if(arq != NULL) {

        Equipamento temp;

        while(fread(&temp, sizeof(temp), 1, arq) == 1) {

            if(temp.id == idEquipamento) {

                fseek(arq, -(long)sizeof(temp), SEEK_CUR);

                fwrite(&equipamento, sizeof(equipamento), 1, arq);

                break;
            }
        }

        fclose(arq);
    }

    tecnico.disponivel = 0;

    arq = fopen("tecnicos.dat", "rb+");

    if(arq != NULL) {

        Tecnico temp;

        while(fread(&temp, sizeof(temp), 1, arq) == 1) {

            if(temp.id == idTecnico) {

                fseek(arq, -(long)sizeof(temp), SEEK_CUR);

                fwrite(&tecnico, sizeof(tecnico), 1, arq);

                break;
            }
        }

        fclose(arq);
    }

    printf("Manutencao aberta!\n");
}

void concluirManutencao() {
    FILE *arq;

    Manutencao manutencao;
    Equipamento equipamento;
    Tecnico tecnico;

    int idManutencao;
    int idTecnico;

    printf("ID da manutencao: ");
    scanf("%d", &idManutencao);

    arq = fopen("manutencoes.dat", "rb+");

    if(arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    int encontrou = 0;

    while(fread(&manutencao, sizeof(manutencao), 1, arq) == 1) {

        if(manutencao.id == idManutencao) {

            encontrou = 1;

            printf("Data de conclusao (dia mes ano): ");
            scanf("%d %d %d",
                  &manutencao.dataConclusao.dia,
                  &manutencao.dataConclusao.mes,
                  &manutencao.dataConclusao.ano);

            limpaBuffer();

            printf("Descricao da solucao: ");
            fgets(manutencao.descricaoSolucao, 200, stdin);
            manutencao.descricaoSolucao[
                strcspn(manutencao.descricaoSolucao, "\n")
            ] = '\0';

            printf("Custo final: ");
            scanf("%f", &manutencao.custo);

            printf("ID do tecnico: ");
            scanf("%d", &idTecnico);

            fseek(arq, -(long)sizeof(manutencao), SEEK_CUR);

            fwrite(&manutencao, sizeof(manutencao), 1, arq);

            break;
        }
    }

    fclose(arq);

    if(!encontrou) {
        printf("Manutencao nao encontrada!\n");
        return;
    }

    if(buscarEquipamento(manutencao.idEquipamento, &equipamento)) {

        equipamento.emManutencao = 0;

        arq = fopen("equipamentos.dat", "rb+");

        if(arq != NULL) {

            Equipamento temp;

            while(fread(&temp, sizeof(temp), 1, arq) == 1) {

                if(temp.id == equipamento.id) {

                    fseek(arq, -(long)sizeof(temp), SEEK_CUR);

                    fwrite(&equipamento, sizeof(equipamento), 1, arq);

                    break;
                }
            }

            fclose(arq);
        }
    }

    if(buscarTecnico(idTecnico, &tecnico)) {

        tecnico.disponivel = 1;

        arq = fopen("tecnicos.dat", "rb+");

        if(arq != NULL) {

            Tecnico temp;

            while(fread(&temp, sizeof(temp), 1, arq) == 1) {

                if(temp.id == tecnico.id) {

                    fseek(arq, -(long)sizeof(temp), SEEK_CUR);

                    fwrite(&tecnico, sizeof(tecnico), 1, arq);

                    break;
                }
            }

            fclose(arq);
        }
    }

    printf("Manutencao concluida!\n");
}

void listarEmManutencao() {
    FILE *arq;
    Equipamento equipamento;

    arq = fopen("equipamentos.dat", "rb");

    if(arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    while(fread(&equipamento, sizeof(equipamento), 1, arq) == 1) {

        if(equipamento.emManutencao == 1) {

            printf("\nID: %d", equipamento.id);
            printf("\nNome: %s", equipamento.nome);
            printf("\nFabricante: %s", equipamento.fabricante);
            printf("\nModelo: %s", equipamento.modelo);
            printf("\nLocalizacao: %s\n", equipamento.localizacao);
        }
    }

    fclose(arq);
}

void historicoManutencoes() {
    FILE *arq;
    Manutencao manutencao;

    int idEquipamento;

    printf("ID do equipamento: ");
    scanf("%d", &idEquipamento);

    arq = fopen("manutencoes.dat", "rb");

    if(arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    while(fread(&manutencao, sizeof(manutencao), 1, arq) == 1) {

        if(manutencao.idEquipamento == idEquipamento) {

            printf("\nID manutencao: %d", manutencao.id);
            printf("\nProblema: %s", manutencao.descricaoProblema);
            printf("\nSolucao: %s", manutencao.descricaoSolucao);
            printf("\nCusto: %.2f", manutencao.custo);
            printf("\nTecnico: %s", manutencao.tecnicoResponsavel);
            printf("\nPrioridade: %d", manutencao.prioridade);

            printf("\nData abertura: %02d/%02d/%d",
                   manutencao.dataAbertura.dia,
                   manutencao.dataAbertura.mes,
                   manutencao.dataAbertura.ano);

            printf("\nData conclusao: %02d/%02d/%d\n",
                   manutencao.dataConclusao.dia,
                   manutencao.dataConclusao.mes,
                   manutencao.dataConclusao.ano);
        }
    }

    fclose(arq);
}

void relatorioCustos() {
    FILE *arq;
    Manutencao manutencao;

    int idEquipamento;
    float total = 0;

    printf("ID do equipamento: ");
    scanf("%d", &idEquipamento);

    arq = fopen("manutencoes.dat", "rb");

    if(arq == NULL) {
        printf("Erro ao abrir arquivo!\n");
        return;
    }

    while(fread(&manutencao, sizeof(manutencao), 1, arq) == 1) {

        if(manutencao.idEquipamento == idEquipamento) {
            total += manutencao.custo;
        }
    }

    fclose(arq);

    printf("Custo total: %.2f\n", total);
}

void equipamentosMaisManutencoes() {
    FILE *arqEquipamento;
    FILE *arqManutencao;

    Equipamento equipamento;
    Manutencao manutencao;

    int maior = 0;
    int quantidade;

    arqEquipamento = fopen("equipamentos.dat", "rb");

    if(arqEquipamento == NULL) {
        printf("Erro ao abrir equipamentos!\n");
        return;
    }

    while(fread(&equipamento, sizeof(equipamento), 1,
                arqEquipamento) == 1) {

        quantidade = 0;

        arqManutencao = fopen("manutencoes.dat", "rb");

        if(arqManutencao != NULL) {

            while(fread(&manutencao, sizeof(manutencao), 1,
                        arqManutencao) == 1) {

                if(manutencao.idEquipamento == equipamento.id) {
                    quantidade++;
                }
            }

            fclose(arqManutencao);
        }

        if(quantidade > maior) {
            maior = quantidade;
        }
    }

    fclose(arqEquipamento);

    printf("Maior quantidade de manutencoes: %d\n", maior);

    arqEquipamento = fopen("equipamentos.dat", "rb");

    if(arqEquipamento == NULL)
        return;

    while(fread(&equipamento, sizeof(equipamento), 1,
                arqEquipamento) == 1) {

        quantidade = 0;

        arqManutencao = fopen("manutencoes.dat", "rb");

        if(arqManutencao != NULL) {

            while(fread(&manutencao, sizeof(manutencao), 1,
                        arqManutencao) == 1) {

                if(manutencao.idEquipamento == equipamento.id) {
                    quantidade++;
                }
            }

            fclose(arqManutencao);
        }

        if(quantidade == maior) {

            printf("\nID: %d", equipamento.id);
            printf("\nNome: %s", equipamento.nome);
            printf("\nManutencoes: %d\n", quantidade);
        }
    }

    fclose(arqEquipamento);
}

int main() {
    int opcao;

    do {
        printf("\n\n--- MANUTENCAO ---");
        printf("\n1 - Cadastrar equipamento");
        printf("\n2 - Cadastrar tecnico");
        printf("\n3 - Abrir chamado");
        printf("\n4 - Concluir manutencao");
        printf("\n5 - Listar equipamentos em manutencao");
        printf("\n6 - Historico de manutencoes");
        printf("\n7 - Relatorio de custos");
        printf("\n8 - Equipamentos com mais manutencoes");
        printf("\n0 - Sair");
        printf("\nOpcao: ");

        scanf("%d", &opcao);

        switch(opcao) {

            case 1:
                cadastrarEquipamento();
                break;

            case 2:
                cadastrarTecnico();
                break;

            case 3:
                abrirManutencao();
                break;

            case 4:
                concluirManutencao();
                break;

            case 5:
                listarEmManutencao();
                break;

            case 6:
                historicoManutencoes();
                break;

            case 7:
                relatorioCustos();
                break;

            case 8:
                equipamentosMaisManutencoes();
                break;

            case 0:
                printf("Encerrando...\n");
                break;

            default:
                printf("Opcao invalida!\n");
        }

    } while(opcao != 0);

    return 0;
}