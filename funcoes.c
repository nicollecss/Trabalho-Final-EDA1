// bibliotecas que usaremos
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "funcoes.h"
#include "structs.h"


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

///////////////////////////////////////////////

produto* cria_lista() {
    produto *cabeca = calloc(1, sizeof(produto));
    if (cabeca == NULL) {
        printf("Erro de memoria.\n");
        return NULL;
    }

    cabeca->cod_unico = -1;
    cabeca->prox = NULL;
    cabeca->nome = NULL;

    return cabeca;
}

void cadastra_produto(produto *cabeca) {
    if (cabeca == NULL) return;

    char buffer[100];
    int codigo;

    printf("-----CADASTRO DO PRODUTO-----\n");
    printf("Codigo unico: ");
    if (scanf("%d", &codigo) != 1) {
        printf("Entrada invalida.\n");
        return;
    }

    produto *aux = cabeca->prox;
    while (aux != NULL) {
        if (aux->cod_unico == codigo) {
            printf("Erro: codigo ja cadastrado!\n");
            return;
        }
        aux = aux->prox;
    }

    produto *novo = calloc(1, sizeof(produto));
    if (novo == NULL) {
        printf("Erro de memoria.\n");
        return;
    }

    novo->cod_unico = codigo;

    printf("Nome: ");
    scanf(" %99[^\n]", buffer);

    novo->nome = malloc((strlen(buffer) + 1) * sizeof(char));
    if (novo->nome == NULL) {
        printf("Erro de memoria.\n");
        free(novo);
        return;
    }
    strcpy(novo->nome, buffer);

    printf("Preco: ");
    if (scanf("%f", &novo->preco) != 1) {
        printf("Entrada invalida.\n");
        free(novo->nome);
        free(novo);
        return;
    }

    printf("Quantidade: ");
    if (scanf("%d", &novo->quant) != 1) {
        printf("Entrada invalida.\n");
        free(novo->nome);
        free(novo);
        return;
    }

    novo->prox = cabeca->prox;
    cabeca->prox = novo;

    printf("Produto cadastrado com sucesso!\n");
    // adicionar um sleep e exit para ficar mais bonito
}
