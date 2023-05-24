#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "funcionarios.h"
#include "validacoes.h"

void modulo_funcionarios(void) {
    char opcao;
    do {
        opcao = tela_funcionarios();
        switch (opcao) {
            case '1': adicionar_funcionario();
                      break;
            case '2': pesquisar_funcionario();
                      break;
            case '3': atualizar_funcionario();
                      break;
            case '4': excluir_funcionario();
                      break;
        }
    } while (opcao != '0');
}

void adicionar_funcionario(void) {
    Funcionario *fnc;

    fnc = tela_adicionar_funcionario();
    salvar_funcionario(fnc);

    free(fnc);
}

void pesquisar_funcionario(void) {
    Funcionario *fnc;
    char *cpf;

    cpf = tela_pesquisar_funcionario();
    fnc = buscar_funcionario(cpf);
    exibir_funcionario(fnc);

    free(fnc);
    free(cpf);
}

void atualizar_funcionario(void) {
    Funcionario *fnc;
	char* cpf;

	cpf = tela_atualizar_funcionario();
	fnc = buscar_funcionario(cpf);
	if (fnc == NULL) {
    	printf("\n>>>>> Funcionario não encontrado <<<<<\n");
  	} 
    else {
		  fnc = tela_adicionar_funcionario();
		  strcpy(fnc->cpf, cpf);
		  refazer_funcionario(fnc);
		  free(fnc);
	}
	free(cpf);
}

void excluir_funcionario(void) {
    Funcionario *fnc;
	char *cpf;

	cpf = tela_excluir_funcionario();
	fnc = (Funcionario*) malloc(sizeof(Funcionario));
	fnc = buscar_funcionario(cpf);
	if (fnc == NULL) {
    	printf("\n\nAluno não encontrado!\n\n");
  	} 
    else {
		  fnc->status = 0;
		  refazer_funcionario(fnc);
		  free(fnc);
	}
	free(cpf);
}


char tela_funcionarios(void) {
    char escolha;

    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                   >>>>>>  FUNCIONARIOS  <<<<<<                  ||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||        [ 1 ] Adicionar um novo funcionario                      ||\n");
    printf(" ||        [ 2 ] Pesquisar funcionario ja cadastrado                ||\n");
    printf(" ||        [ 3 ] Atualizar os dados de um funcionario               ||\n");
    printf(" ||        [ 4 ] Excluir funcionario do sistema                     ||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||        [ 0 ] Voltar ao Menu Principal                           ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf("       Digite o numero da sua escolha: ");
    scanf("%c", &escolha);
    getchar();

    return escolha;
}

Funcionario* tela_adicionar_funcionario(void) {
    Funcionario *fnc;

    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                 >>>>>     FUNCIONARIOS     <<<<<                ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                      ----- ADICIONAR -----                      ||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||           Obs.: Digite as informacoes com atencao               ||\n");
    printf(" ||                                                                 ||\n");
    fnc = (Funcionario*) malloc(sizeof(Funcionario));
    do {
        printf("         Nome completo: \n");
        printf("         => ");
        scanf("%[^\n]", fnc->nome);
        getchar();
    } while (!valida_nome(fnc->nome));
    printf("\n");
    do {
        printf("         CPF do Funcionario: \n");
        printf("         => ");
        scanf("%[^\n]", fnc->cpf);
        getchar();
    } while (!valida_cpf(fnc->cpf));
    printf("\n");
    do {
        printf("         Numero de celular: \n");
        printf("         => ");
        scanf("%[^\n]", fnc->celular);
        getchar();
    } while(!valida_cel(fnc->celular));
    printf("\n");
    do {
        printf("         Email:  \n");
        printf("         => ");
        scanf("%[^\n]", fnc->email);
        getchar();
    } while (!valida_email(fnc->email));
    printf("\n");
    do {
        printf("         Cargo/Funcao: \n");
        printf("         => ");
        scanf("%[^\n]", fnc->cargo);
        getchar();
    } while (!valida_nome(fnc->cargo));
    fnc->status = 1;
    printf("\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                     Funcionario cadastrado!                     ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar();
    return fnc;
}

char* tela_pesquisar_funcionario(void) {
    char *cpf;
    system("cls||clear");  
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                 >>>>>     FUNCIONARIOS     <<<<<                ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                      ----- PESQUISAR -----                      ||\n");
    printf(" ||                                                                 ||\n");
    cpf = (char*) malloc(12*sizeof(char));
    do {
        printf("         CPF do Funcionario (apenas digitos): \n");
        printf("         => ");
        scanf("%[^\n]", cpf);
        getchar();
    } while (!valida_cpf(cpf));

    return cpf;
}


char* tela_atualizar_funcionario(void) {
    char* cpf;
    
    cpf = (char*) malloc(12*sizeof(char));
    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                 >>>>>     FUNCIONARIOS     <<<<<                ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                     ----- ATUALIZACAO -----                     ||\n");
    printf(" ||                                                                 ||\n");
    do {
        printf("         CPF do Funcionario: \n");
        printf("         => ");
        scanf("%[^\n]", cpf);
        getchar();
    } while (!valida_cpf(cpf));
    return cpf;
}

   ////////// esta e as demais funcoes do mesmo tema editar
   ////////// por enquanto ficaram inutilizaveis e posteriormente
   ////////// sera encontrada uma forma de reutiliza-las 
char tela_editar_funcionario(void) {
    char editar;
    do {
        system("cls||clear");
        printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf(" ||                                                                 ||\n");
        printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
        printf(" ||                                                                 ||\n");
        printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf(" ||                 >>>>>     FUNCIONARIOS     <<<<<                ||\n");
        printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf(" ||                                                                 ||\n");
        printf(" ||                        ----- EDITAR -----                       ||\n");
        printf(" ||                                                                 ||\n");
        printf(" ||         [ 1 ] Nome                                              ||\n");
        printf(" ||         [ 2 ] CPF                                               ||\n");
        printf(" ||         [ 3 ] Email                                             ||\n");
        printf(" ||         [ 4 ] Celular                                           ||\n");
        printf(" ||         [ 5 ] Cargo                                             ||\n");
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
            case '1': tela_editar_nome();
                      break;
            case '2': tela_editar_cpf();
                      break;
            case '3': tela_editar_email();
                      break;
            case '4': tela_editar_cel();
                      break;
            case '5': tela_editar_cargo();
                      break;
        }
    } while (editar != '0');
}


void tela_editar_nome(void) {
    char nome[71];

    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                 >>>>>     FUNCIONARIOS     <<<<<                ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                        ----- EDITAR -----                       ||\n");
    printf(" ||                                                                 ||\n");
    do {
        printf("         Novo nome do funcionario: \n");
        printf("         => ");
        scanf("%[^\n]", nome);
        getchar();
    } while(!valida_nome(nome));
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||               ...... Atualizacao efetuada ......                ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar(); 
}


void tela_editar_cpf(void) {
    char cpf[12];

    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                 >>>>>     FUNCIONARIOS     <<<<<                ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                        ----- EDITAR -----                       ||\n");
    printf(" ||                                                                 ||\n");
    do {
        printf("         Novo CPF do Funcionario: \n");
        printf("         => ");
        scanf("%[^\n]", cpf);
        getchar();
    } while (!valida_cpf(cpf));
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||               ...... Atualizacao efetuada ......                ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar(); 
}

void tela_editar_cel(void) {
    char celular[12];

    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                 >>>>>     FUNCIONARIOS     <<<<<                ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                        ----- EDITAR -----                       ||\n");
    printf(" ||                                                                 ||\n");
    do {
        printf("         Novo numero de celular do funcionario: \n");
        printf("         => ");
        scanf("%[^\n]", celular);
        getchar();
    } while(!valida_cel(celular));
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||               ...... Atualizacao efetuada ......                ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar(); 
}

void tela_editar_email(void) {
    char email[51];

    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                 >>>>>     FUNCIONARIOS     <<<<<                ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                        ----- EDITAR -----                       ||\n");
    printf(" ||                                                                 ||\n");
    do {
        printf("         Novo email do funcionario: \n");
        printf("         => ");
        scanf("%[^\n]", email);
        getchar();
    } while (!valida_email(email));
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||               ...... Atualizacao efetuada ......                ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar(); 
}

void tela_editar_cargo(void) {
    char cargo[51];
    
    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                 >>>>>     FUNCIONARIOS     <<<<<                ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                        ----- EDITAR -----                       ||\n");
    printf(" ||                                                                 ||\n");
    do {
        printf("         Novo cargo do funcionario: \n");
        printf("         => ");
        scanf("%[^\n]", cargo);
        getchar();
    }  while(!valida_nome(cargo));
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||               ...... Atualizacao efetuada ......                ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar(); 
}


char* tela_excluir_funcionario(void) {
    char* cpf;

    cpf = (char*) malloc(12*sizeof(char));
    system("cls||clear");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                 >>>>>     FUNCIONARIOS     <<<<<                ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                       ----- EXCLUIR -----                       ||\n");
    printf(" ||                                                                 ||\n");
    do {
        printf("         CPF do Funcionario: \n");
        printf("         => ");
        scanf("%[^\n]", cpf);
        getchar();
    } while (!valida_cpf(cpf));
    printf(" ||                                                                 ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||                  ...... Acao realizada ......                   ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    getchar();
    return cpf;
}


void tela_erro(void) {
	system("cls||clear");
	printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
    printf(" ||       <<<<<<<<<<<       SOFTHOUSE CAICO       >>>>>>>>>>>       ||\n");
    printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	printf(" ||                                                                 ||\n");
	printf(" ||                   >>>>>>>>    ERRO    <<<<<<<                   ||\n");
	printf(" ||                                                                 ||\n");
    printf(" ||                 Não foi possível acessar o arquivo              ||\n");
	printf(" ||                                                                 ||\n");
    printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
    printf(" ||                                                                 ||\n");
	printf("     ------- Enter para continuar! --------");
	getchar();
}


/////////// FUNÇOES DE ARQUIVAMENTO ///////////
void salvar_funcionario(Funcionario* fnc) {
    FILE *fp;
    fp = fopen("funcionarios.dat", "ab");
    if (fp == NULL) {
        tela_erro();
    }
    fwrite(fnc, sizeof(Funcionario), 1, fp);
    fclose(fp);
}

Funcionario* buscar_funcionario(char* cpf) {
    FILE *fp;
    Funcionario* fnc;

    fnc = (Funcionario*) malloc(sizeof(Funcionario));
    fp = fopen("funcionarios.dat", "rb");
    if (fp == NULL) {
        tela_erro();
    }
    while (fread(fnc, sizeof(Funcionario), 1, fp)) {
        if ((strcmp(fnc->cpf, cpf) == 0) && (fnc->status == 1)) {
            fclose(fp);
            return fnc;
        }
    }   
    fclose(fp);
    return NULL;
}

void exibir_funcionario(Funcionario* fnc) {
	if (fnc == NULL) {
		printf("\n>>>>> Funcionario Inexistente <<<<<\n");
	} 
    else {
        printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
        printf(" ||                                                                 ||\n");
        printf(" ||               >>>>>> Funcionario Encontrado <<<<<<              ||\n");
        printf(" ||                                                                 ||\n");
        printf(" ||      Nome: %s         \n", fnc->nome);
        printf(" ||      Cargo/Funcao: %s \n", fnc->cargo);
        printf(" ||      Email: %s        \n", fnc->email);
        printf(" ||      Celular: %s      \n", fnc->celular);
        printf(" ||      CPF: %s          \n", fnc->cpf);
        printf(" ||      Status: %d       \n", fnc->status);
        printf(" ||                                                                 ||\n");
        printf(" |||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||||\n");
	}
	printf("\n      ------- Enter para continuar! --------");
	getchar();
}

void refazer_funcionario(Funcionario* fnc) {
	int achou;
	FILE* fp;
	Funcionario* fnc_lido;

	fnc_lido = (Funcionario*) malloc(sizeof(Funcionario));
	fp = fopen("funcionarios.dat", "r+b");
	if (fp == NULL) {
		tela_erro();
	}
	achou = 0;
	while (fread(fnc_lido, sizeof(Funcionario), 1, fp) && !achou) {
		if (strcmp(fnc_lido->cpf, fnc->cpf) == 0) {
			achou = 1;
			fseek(fp, -1*sizeof(Funcionario), SEEK_CUR);
        	fwrite(fnc, sizeof(Funcionario), 1, fp);
		}
	}
	fclose(fp);
	free(fnc_lido);
}