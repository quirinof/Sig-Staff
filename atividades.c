#include <stdio.h>
#include <stdlib.h>
#include "atividades.h"
#include "validacoes.h"


void modulo_atividades(void) {
    char opcao;
    do {
        opcao = tela_atividades();
        switch (opcao) {
            case '1': tela_adicionar_atividade();
                      break;
            case '2': tela_pesquisar_atividade();
                      break;
            case '3': tela_atualizar_atividade();
                      break;
            case '4': tela_excluir_atividade();
                      break;
        }
    } while (opcao != '0');
}

char tela_atividades(void) {

    char escolha;

    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                   >>>>>>  ATIVIDADES  <<<<<<                    ||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||         [ 1 ] Adicionar nova atividade                          ||\n");
    printf(" ||         [ 2 ] Pesquisar atividade existente                     ||\n");
    printf(" ||         [ 3 ] Atualizar uma atividade em andamento              ||\n");
    printf(" ||         [ 4 ] Excluir atividade                                 ||\n");
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


void tela_adicionar_atividade(void) {

    char titulo_atividade[51];
    char id_atividade[6];
    char id_projeto[6];
    char cpf_atividade[12];
    char data_atividade[11];

    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                  >>>>>     ATIVIDADES     <<<<<                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                      ----- ADICIONAR -----                      ||\n");
    printf(" ||                                                                 ||\n");
    printf("            Titulo/Nome da atividade: \n");
    printf("            => ");
    scanf("%[A-ZÁÀÃÂÉÈÊÍÌÎÓÒÕÔÚÙÛ a-záàãâéèêíìîóòõôúùûÇç]", titulo_atividade);
    getchar();
    printf("\n");
    while (!valida_id(id_atividade, 5)) {
        printf("            ID da Atividade: \n");
        printf("            => ");
        scanf("%s", id_atividade);
        valida_id(id_atividade, 5);
        getchar();
    }
    printf("\n");
    while (!valida_id(id_projeto, 5)) {
        printf("            ID do Projeto relacionado: \n");
        printf("            => ");
        scanf("%s", id_projeto);
        valida_id(id_projeto, 5);
        getchar();
    }
    printf("\n");
    while (!valida_cpf(cpf_atividade)) {
        printf("         CPF do Funcionario atribuido (apenas digitos): \n");
        printf("         => ");
        scanf("%s", cpf_atividade);
        getchar();
        valida_cpf(cpf_atividade);
    }       
    printf("\n");
    printf("            Data de entrega da atividade (dd/mm/aaaa): \n");
    printf("            => ");
    scanf("%[^\n]", data_atividade);
    getchar();
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                ...... Atividade incluida ......                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar();
}


void tela_pesquisar_atividade(void) {

    char id_atividade[6];

    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                  >>>>>     ATIVIDADES     <<<<<                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                      ----- PESQUISAR -----                      ||\n");
    printf(" ||                                                                 ||\n");
    while (!valida_id(id_atividade, 5)) {
        printf("            Digite o ID da Atividade: \n");
        printf("            => ");
        scanf("%s", id_atividade);
        valida_id(id_atividade, 5);
        getchar();
    }
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                ...... Atividade encontrada ......               ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar();
}


void tela_atualizar_atividade(void) {

    char id_atividade[6];
    char editar; 

    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                  >>>>>     ATIVIDADES     <<<<<                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                      ----- ATUALIZAR -----                      ||\n");
    printf(" ||                                                                 ||\n");
    while (!valida_id(id_atividade, 5)) {
        printf("            Digite o ID da Atividade: \n");
        printf("            => ");
        scanf("%s", id_atividade);
        valida_id(id_atividade, 5);
        getchar();
    }
    printf("\n");
    do {
        system("cls || clear");
        printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf(" ||                                                                 ||\n");
        printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
        printf(" ||                                                                 ||\n");
        printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf(" ||                  >>>>>     ATIVIDADES     <<<<<                 ||\n");
        printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf(" ||                                                                 ||\n");
        printf(" ||                          __ EDITAR __                           ||\n");
        printf(" ||                                                                 ||\n");
        printf(" ||         [ 1 ] Titulo                                            ||\n");
        printf(" ||         [ 2 ] CPF do funcionario                                ||\n");
        printf(" ||         [ 3 ] Data de entrega                                   ||\n");
        printf(" ||         [ 4 ] ID do Projeto atribuido                           ||\n");
        printf(" ||         [ 5 ] ID da Atividade                                   ||\n");
        printf(" ||                                                                 ||\n");
        printf(" ||         [ 0 ] Sair                                              ||\n");
        printf(" ||                                                                 ||\n");
        printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf(" ||                                                                 ||\n");
        printf("           Digite sua escolha: ");
        scanf("%c", &editar);
        getchar();
        printf("\n");
        switch (editar) {
            case '1': tela_editar_titulo_atividade();
                      break;
            case '2': tela_editar_cpf_atividade();
                      break;
            case '3': tela_editar_data_atividade();
                      break;
            case '4': tela_editar_id_atribuido();
                      break;
            case '5': tela_editar_id_atividade();
                      break;
        }          
    } while (editar != '0');
}

void tela_editar_titulo_atividade(void) {
    char titulo_atividade[51];

    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                  >>>>>     ATIVIDADES     <<<<<                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                          __ EDITAR __                           ||\n");
    printf(" ||                                                                 ||\n");
    printf("         Novo titulo de atividade: \n");
    printf("         => ");
    scanf("%[A-ZÁÀÃÂÉÈÊÍÌÎÓÒÕÔÚÙÛ a-záàãâéèêíìîóòõôúùûÇç]", titulo_atividade);
    getchar();
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                       Informacao atualizada!                    ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar(); 
}

void tela_editar_cpf_atividade(void) {
    char cpf_atividade[12];

    system("cls || clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                  >>>>>     ATIVIDADES     <<<<<                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                          __ EDITAR __                           ||\n");
    printf(" ||                                                                 ||\n");
    while (!valida_cpf(cpf_atividade)) {
        printf("         Novo CPF do Funcionario atribuido a Atividade (apenas digitos): \n");
        printf("         => ");
        scanf("%s", cpf_atividade);
        getchar();
        valida_cpf(cpf_atividade);
    }
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                       Informacao atualizada!                    ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar(); 
}

void tela_editar_data_atividade(void) {
    char data_atividade[11];

    system("cls || clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                  >>>>>     ATIVIDADES     <<<<<                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                          __ EDITAR __                           ||\n");
    printf(" ||                                                                 ||\n");
    printf("         Nova Data de entrega da atividade (dd/mm/aaaa): \n");
    printf("         => ");
    scanf("%[0-9/]", data_atividade);
    getchar();
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                       Informacao atualizada!                    ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar(); 
}

void tela_editar_id_atribuido(void) {
    char id_projeto[6];

    system("cls || clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                  >>>>>     ATIVIDADES     <<<<<                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                          __ EDITAR __                           ||\n");
    printf(" ||                                                                 ||\n");
    while (!valida_id(id_projeto, 5)) {
        printf("            Novo ID do projeto atribuido a Atividade: \n");
        printf("            => ");
        scanf("%s", id_projeto);
        valida_id(id_projeto, 5);
        getchar();
    }
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                       Informacao atualizada!                    ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar(); 
}

void tela_editar_id_atividade(void) {
    char id_atividade[6];

    system("cls || clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                  >>>>>     ATIVIDADES     <<<<<                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                          __ EDITAR __                           ||\n");
    printf(" ||                                                                 ||\n");
    while (!valida_id(id_atividade, 5)) {
        printf("            Novo ID da Atividade: \n");
        printf("            => ");
        scanf("%s", id_atividade);
        valida_id(id_atividade, 5);
        getchar();
    }
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                       Informacao atualizada!                    ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar(); 
}

void tela_excluir_atividade(void) {

    char id_atividade[6];

    system("cls || clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                  >>>>>     ATIVIDADES     <<<<<                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                       ----- EXCLUIR -----                       ||\n");
    printf(" ||                                                                 ||\n");
    while (!valida_id(id_atividade, 5)) {
        printf("            Digite o ID da Atividade: \n");
        printf("            => ");
        scanf("%s", id_atividade);
        valida_id(id_atividade, 5);
        getchar();
    }
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                  ...... Atividade deletada ......               ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar();
}