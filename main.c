#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <locale.h>


// Fun��o para criptografar uma string (simples, apenas para exemplo)
void criptografar(char *texto) {
    int i;  // Declara��o fora do loop
    for (i = 0; texto[i] != '\0'; i++) {
        texto[i] += 3; // Ajusta cada caractere
    }
}

// Fun��o para descriptografar uma string
void descriptografar(char *texto) {
    int i;  // Declara��o fora do loop
    for (i = 0; texto[i] != '\0'; i++) {
        texto[i] -= 3; // Reverte o ajuste
    }
}

// Estrutura para usu�rio
typedef struct {
    char nome_usuario[20];
    char senha[20];
} Usuario;

// Fun��o para cadastrar um novo usu�rio
void cadastrarUsuario() {
    Usuario novoUsuario;
    FILE *arquivo = fopen("usuarios.txt", "a");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de usu�rios!\n");
        return;
    }

    printf("Informe o nome de usu�rio: ");
    scanf("%s", novoUsuario.nome_usuario);
    printf("Informe a senha: ");
    scanf("%s", novoUsuario.senha);
    
    // Criptografa a senha antes de salvar
    criptografar(novoUsuario.senha);
    
    // Salva o usu�rio no arquivo
    fprintf(arquivo, "%s %s\n", novoUsuario.nome_usuario, novoUsuario.senha);
    fclose(arquivo);
    
    printf("Usu�rio cadastrado com sucesso!\n");
}

// Fun��o para login de usu�rio
int login() {
    char usuario[20], senha[20];
    char usuarioArquivo[20], senhaArquivo[20];
    FILE *arquivo = fopen("usuarios.txt", "r");

    if (arquivo == NULL) {
        printf("Nenhum usu�rio cadastrado! Por favor, cadastre um usu�rio primeiro.\n");
        return 0;
    }

    printf("Usu�rio: ");
    scanf("%s", usuario);
    printf("Senha: ");
    scanf("%s", senha);
    
    // Criptografa a senha digitada para compara��o
    criptografar(senha);
    
    // Verifica cada linha do arquivo para encontrar o usu�rio e a senha
    while (fscanf(arquivo, "%s %s", usuarioArquivo, senhaArquivo) != EOF) {
        if (strcmp(usuario, usuarioArquivo) == 0 && strcmp(senha, senhaArquivo) == 0) {
            fclose(arquivo);
            printf("Login bem-sucedido!\n");
            return 1;
        }
    }

    fclose(arquivo);
    printf("Usu�rio ou senha incorretos!\n");
    return 0;
}

// Estrutura para armazenar informa��es da ind�stria
typedef struct {
    char nome_responsavel[50];
    char nome_empresa[50];
    char cnpj[20];
    char razao_social[50];
    char nome_fantasia[50];
    char telefone[15];
    char endereco[100];
    char cidade[30];
    char estado[3];
    char cep[10];
    char email[50];
    char data_abertura[11];
} Industria;

// Fun��o para cadastrar nova ind�stria
void cadastrarIndustria() {
    Industria novaIndustria;
    FILE *arquivo = fopen("industrias.txt", "a");
    
    if (arquivo == NULL) {
        printf("Erro ao abrir o arquivo de ind�strias!\n");
        return;
    }

    printf("Nome do respons�vel: ");
    scanf(" %[^\n]", novaIndustria.nome_responsavel);
    printf("Nome da empresa: ");
    scanf(" %[^\n]", novaIndustria.nome_empresa);
    printf("CNPJ: ");
    scanf("%s", novaIndustria.cnpj);
    printf("Raz�o social: ");
    scanf(" %[^\n]", novaIndustria.razao_social);
    printf("Nome fantasia: ");
    scanf(" %[^\n]", novaIndustria.nome_fantasia);
    printf("Telefone: ");
    scanf("%s", novaIndustria.telefone);
    printf("Endere�o: ");
    scanf(" %[^\n]", novaIndustria.endereco);
    printf("Cidade: ");
    scanf("%s", novaIndustria.cidade);
    printf("Estado (UF): ");
    scanf("%s", novaIndustria.estado);
    printf("CEP: ");
    scanf("%s", novaIndustria.cep);
    printf("Email: ");
    scanf("%s", novaIndustria.email);
    printf("Data de abertura (DD/MM/AAAA): ");
    scanf("%s", novaIndustria.data_abertura);
    
    // Grava no arquivo
    fprintf(arquivo, "%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s;%s\n", 
        novaIndustria.nome_responsavel, novaIndustria.nome_empresa, novaIndustria.cnpj,
        novaIndustria.razao_social, novaIndustria.nome_fantasia, novaIndustria.telefone,
        novaIndustria.endereco, novaIndustria.cidade, novaIndustria.estado,
        novaIndustria.cep, novaIndustria.email, novaIndustria.data_abertura);
        
    fclose(arquivo);
    printf("Ind�stria cadastrada com sucesso!\n");
}

int main() {
    int opcao;
    setlocale (LC_ALL, 	"portuguese");
    // Menu inicial
    do {
        printf("\nMenu Inicial:\n");
        printf("1. Login\n");
        printf("2. Cadastrar novo usu�rio\n");
        printf("3. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        
        if (opcao == 1) {
            if (login()) {
                break;  // Sai do loop se o login for bem-sucedido
            }
        } else if (opcao == 2) {
            cadastrarUsuario();
        } else if (opcao == 3) {
            printf("Saindo...\n");
            return 0;
        } else {
            printf("Op��o inv�lida!\n");
        }
    } while (opcao != 3);

    // Menu principal ap�s login
    do {
        printf("\nMenu Principal:\n");
        printf("1. Cadastrar ind�stria\n");
        printf("2. Sair\n");
        printf("Escolha uma op��o: ");
        scanf("%d", &opcao);
        
        switch (opcao) {
            case 1:
                cadastrarIndustria();
                break;
            case 2:
                printf("Saindo...\n");
                break;
            default:
                printf("Op��o inv�lida!\n");
        }
    } while (opcao != 2);
    
    return 0;
}

