#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "atividades.h"
#include "funcionarios.h"
#include "projetos.h"
#include "relatorios.h"
#include "validacoes.h"


void modulo_relatorios(void) {
    char opcao;
    do {
        opcao = tela_relatorios();
        switch(opcao) {
            case '1': listar_funcionarios();
                      break;
            case '2': listar_projetos();
                      break;
            case '3': listar_atividades();
                      break;
            case '4': atividades_por_funcionario();
                      break;
            case '5': atividades_por_projeto();
                      break;
            case '6': funcionarios_por_projeto();
                      break;
        }
    } while (opcao != '0');
}

void atividades_por_funcionario(void) {
    char *cpf;
    cpf = tela_atividades_por_funcionario();
    relatorio_atv_por_fnc(cpf);
    free(cpf);
}

void atividades_por_projeto(void) {
    tela_atividades_por_projeto();
}

void funcionarios_por_projeto(void) {
    tela_funcionarios_por_projeto();
}

char tela_relatorios(void) {
    char escolha;

    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                 >>>>>>     RELATORIOS     <<<<<<                ||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||         Relatorio completo:                         ||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||         [ 1 ] Funcionarios                                      ||\n");
    printf(" ||         [ 2 ] Projetos                                          ||\n");
    printf(" ||         [ 3 ] Atividades                                        ||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||         Relatorio Especifico:                                   ||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||         [ 4 ] Atividades por Funcionario                        ||\n");
    printf(" ||         [ 5 ] Atividades por Projeto                            ||\n");
    printf(" ||         [ 6 ] Funcionarios por Projeto                          ||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||         [ 0 ] Voltar ao Menu Principal                          ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n"); 
    printf(" ||                                                                 ||\n");
    printf("       Digite sua escolha: ");
    scanf("%c", &escolha);
    getchar();
    
    return escolha;
}


char* tela_atividades_por_funcionario(void) {
    char *cpf;
    cpf = (char*) malloc(12*sizeof(char));

    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                 >>>>>>     RELATORIOS     <<<<<<                ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||              ----- Atividades por Funcionario -----             ||\n");
    printf(" ||                                                                 ||\n");
    do {
    printf(" ||         CPF do Funcionario:                                     ||\n");
    printf(" ||         => ");
    scanf("%[^\n]", cpf);
    getchar();
    } while (!valida_cpf(cpf));
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar();

    return cpf;
}

void tela_atividades_por_projeto(void) {
    char id_pjt[6];

    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                 >>>>>>     RELATORIOS     <<<<<<                ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                ----- Atividades por Projeto -----               ||\n");
    printf(" ||                                                                 ||\n");
    do {
    printf(" ||         ID do Projeto:                                          ||\n");
    printf(" ||         => ");
    scanf("%[^\n]", id_pjt);
    getchar();
    } while (!valida_id(id_pjt, 5));
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar();
}

void tela_funcionarios_por_projeto(void) {
    char id_pjt[6];

    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                 >>>>>>     RELATORIOS     <<<<<<                ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                ----- Funcionarios por Projeto -----             ||\n");
    printf(" ||                                                                 ||\n");
    do {
    printf(" ||         ID do Projeto:                                          ||\n");
    printf(" ||         => ");
    scanf("%[^\n]", id_pjt);
    getchar();
    } while (!valida_id(id_pjt, 5));
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar();
}

void listar_funcionarios(void) {
    FILE *fp;
    Funcionario *fnc;
    fnc = (Funcionario*) malloc(sizeof(Funcionario));
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        tela_erro();
    }
    while (fread(fnc, sizeof(Funcionario), 1, fp)) {
        exibir_funcionario(fnc);
    }
    fclose(fp);
    free(fnc);
}

void listar_projetos(void) {
    FILE *fp;
    Projeto *pjt;
    pjt = (Projeto*) malloc(sizeof(Projeto));
    fp = fopen("projetos.dat", "rb");
    if (fp == NULL) {
        tela_erro_pjt();
    }
    while (fread(pjt, sizeof(Projeto), 1, fp)) {
        exibir_projeto(pjt);
    }
    fclose(fp);
    free(pjt);
}

void listar_atividades(void) {
    FILE *fp;
    Atividade *atv;
    atv = (Atividade*) malloc(sizeof(Atividade));
    fp = fopen("atividades.dat", "rb");
    if (fp == NULL) {
        tela_erro_atv();
    }
    while (fread(atv, sizeof(Atividade), 1, fp)) {
        exibir_atividade(atv);
    }
    fclose(fp);
    free(atv);
}