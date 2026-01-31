//bibliotecas que usaremos
//...
#include "funcoes.h"
#include "structs.h"
#include <stdlib.h>
#include <stdio.h>


cliente *cadastra_cliente(){
    cliente *c1 = (cliente*)malloc(sizeof(cliente));
    printf("-----CADASTRO DO CLIENTE-----\n");
    printf("Nome: ");
    scanf(" %[^\n]",c1->nome);
    printf("CPF: ");
    getchar();
    scanf(" %[^\n]",c1->cpf);
    printf("E-mail: ");
    scanf(" %[^\n]",c1->email);
    printf("Telefone: ");
    scanf(" %[^\n]",c1->telefone);
    printf("Data de nascimento: ");
    //getchar();
    scanf(" %[^\n]",c1->data_nascimento);
    printf("Cliente cadastrado com sucesso!\n\n\n");
    return c1;
}

void menu_inicial(){
    //system("clear");
    int n;
    printf("-----MENU INICIAL-----\n");
    printf("(1) Cadastrar cliente\n");
    scanf("%d",&n);
    switch(n){
        case 1:
            getchar();
            cliente *cliente1;
            cliente1 = cadastra_cliente();
            printf("Nome: %s\nCPF: %s\nTelefone: %s\nE-mail: %s\n",cliente1->nome,cliente1->cpf,cliente1->telefone,cliente1->email);
    }
}