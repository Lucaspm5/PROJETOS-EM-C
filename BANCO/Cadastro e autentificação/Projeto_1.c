#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_USUARIOS 100

struct usuario 
{
    char nome[100];
    char cpf[12];
    char numero_conta[10];
    char senha[20];
    float saldo;
};

struct usuario lista_usuarios[MAX_USUARIOS];

int num_usuarios = 0;

int cadastrar_usuario(char nome[], char cpf[], char numero_conta[], char senha[]) 
{
    if(num_usuarios >= MAX_USUARIOS) 
    {
        printf("Erro: o limite de usuários foi atingido.\n");
        return 0;
    }

    for(int i = 0; i < num_usuarios; i++){
        if(strcmp(cpf, lista_usuarios[i].cpf) == 0) 
        {
            printf("Erro: o CPF já foi cadastrado.\n");
            return 0;
        }
        if(strcmp(numero_conta, lista_usuarios[i].numero_conta) == 0){
            printf("Erro: o número da conta já foi cadastrado.\n");
            return 0;
        }
        if(strcmp(nome, lista_usuarios[i].nome) == 0)
        {
            printf("Erro: o nome do úsuario ainda já foi cadastrado.\n");
            return 0;
        }
    }

    struct usuario novo_usuario;
    
    strcpy(novo_usuario.nome, nome);
    strcpy(novo_usuario.cpf, cpf);
    strcpy(novo_usuario.numero_conta, numero_conta);
    strcpy(novo_usuario.senha, senha);
    
    novo_usuario.saldo = 0;


    lista_usuarios[num_usuarios++] = novo_usuario;


    printf("Usuário cadastrado com sucesso!\n");
    return 1;
}

int autenticar_usuario(char numero_conta[], char senha[]) 
{
    for(int i = 0; i < num_usuarios; i++){
        if(strcmp(numero_conta, lista_usuarios[i].numero_conta) == 0 && strcmp(senha, lista_usuarios[i].senha) == 0){
            printf("Usuário autenticado com sucesso!\n");
            return 1;
        }
    }
    printf("Erro: usuário ou senha inválidos.\n");
    return 0;
}

int main(int argc, char const **argv) 
{
    int opcao;
    char nome[100], cpf[12], numero_conta[10], senha[20];

    do {
        printf("\nBem-vindo ao banco!\n");
        printf("Escolha uma opção:\n");
        printf("1 - Cadastrar usuário\n");
        printf("2 - Autenticar usuário\n");
        printf("3 - Sair\n");
        scanf("%d", &opcao);

        switch (opcao) 
        {
            case 1:
                printf("Informe o nome do usuário: ");
                scanf(" %[^\n]s", nome);
                printf("Informe o CPF do usuário: ");
                scanf("%s", cpf);
                printf("Informe o número da conta do usuário: ");
                scanf("%s", numero_conta);
                printf("Informe a senha do usuário: ");
                scanf("%s", senha);
                cadastrar_usuario(nome, cpf, numero_conta, senha);
                break;
            case 2:
                printf("Informe o número da conta do usuário: ");
                scanf("%s", numero_conta);
                printf("Informe a senha do usuário: ");
                scanf("%s", senha);
                autenticar_usuario(numero_conta, senha);
                break;
            case 3:
                printf("Obrigado por utilizar o banco!\n");
                break;
            default:
                printf("Opção inválida. Tente novamente.\n");
                break;
        }

    }while(opcao != 3);

    return 0;
}
