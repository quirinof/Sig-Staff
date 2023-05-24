typedef struct funcionario Funcionario;
struct funcionario {
    char nome[71];
    char cpf[12];
    char celular[12];
    char email[51];
    char cargo[61];
    int status;
};

void adicionar_funcionario(void);
void pesquisar_funcionario(void);
void atualizar_funcionario(void);
void excluir_funcionario(void);

void modulo_funcionarios(void);
char tela_funcionarios(void);
Funcionario* tela_adicionar_funcionario(void);
char* tela_pesquisar_funcionario(void);
char* tela_atualizar_funcionario(void);
char tela_editar_funcionario(void);
void tela_editar_nome(void);
void tela_editar_cpf(void);
void tela_editar_cel(void);
void tela_editar_email(void);
void tela_editar_cargo(void);
char* tela_excluir_funcionario(void);
void tela_erro(void);

void salvar_funcionario(Funcionario*);
Funcionario* buscar_funcionario(char*);
void exibir_funcionario(Funcionario*);
void refazer_funcionario(Funcionario*);