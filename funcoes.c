// bibliotecas que usaremos
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "funcoes.h"
#include "structs.h"

void menu_inicial(){
    /*
    cliente *cabeca = cria_lista_clientes();
    char cpf[12];
    int x = cadastra_cliente(cabeca);
    x = cadastra_cliente(cabeca);
    listar_clientes(cabeca);
    printf("Digite o cpf a ser buscado (digite apenas numeros): ");
    scanf(" %[^\n]", cpf);

    cliente *c = buscar_cliente(cabeca, cpf);
    if(c!=NULL) printf("cliente encontrado: %s\n", c->nome);
    else printf("cliente nao encontrado!\n");

    liberar_lista_clientes(cabeca);
    */
    
    cliente *cabeca = cria_lista_clientes();
    int i=-1;
    char cpf[12];

    printf("CLIENTES\n(1) Cadastrar novo cliente\n(2) Listar clientes\n(3) Buscar cliente pelo CPF\n(4) Atualizar dados de cliente\n(0) Encerrar o programa\n");
    scanf("%d",&i);

    while(i!=0){
        switch(i){
            case 1:
                int x = cadastra_cliente(cabeca);
                break;

            case 2:
                listar_clientes(cabeca);
                break;

            case 3:
                printf("Digite o cpf a ser buscado (somente numeros): ");
                scanf(" %[^\n]",cpf);

                cliente *c = buscar_cliente(cabeca, cpf);
                if(c!=NULL) printf("cliente encontrado: %s\n", c->nome);
                else printf("cliente nao encontrado!\n");
                break;

            case 4:
                printf("Digite o cpf do cliente que voce deseja atualizar os dados (somente numeros): ");
                scanf(" %[^\n]",cpf);

                atualizar_dados_cliente(cabeca, cpf);
                break;

            case 0:
                liberar_lista_clientes(cabeca);
                return;
        }

        printf("\nCLIENTES\n(1) Cadastrar novo cliente\n(2) Listar clientes\n(3) Buscar cliente pelo CPF\n(4) Atualizar dados de cliente\n(0) Encerrar o programa\n");
        scanf("%d",&i);
    }
}

cliente* cria_lista_clientes(){
    cliente *cabeca = calloc(1, sizeof(cliente));

    if(cabeca==NULL){
        printf("Erro de memoria (lista de clientes)");
    }

    cabeca->prox = NULL;

    return cabeca;
}

int cadastra_cliente(cliente *cabeca){
    cliente *novo = calloc(1, sizeof(cliente));
    if(novo == NULL){
        printf("erro na alocacao de memoria para cadastro de novo cliente");
        return 0;
    }
    //nome, cpf, email, telefone, data nasc

    printf("\nDigite o nome do cliente: ");
    scanf(" %[^\n]", novo->nome);

    printf("Digite o CPF do cliente (digite somente numeros): ");
    scanf(" %[^\n]", novo->cpf);

    printf("Digite o e-mail do cliente: ");
    scanf(" %[^\n]", novo->email);

    printf("Digite o telefone do cliente: ");
    scanf(" %[^\n]", novo->telefone);

    printf("Digite a data de nascimento do cliente (formato DD/MM/YYYY): ");
    scanf(" %[^\n]", novo->data_nasc);

    cliente *aux = cabeca;

    while(aux->prox != NULL){
        aux = aux->prox;
    }

    aux->prox = novo;

    printf("Cliente cadastrado com sucesso!\n");
    return 1;
}

void listar_clientes(cliente *cabeca){
    cliente *aux = cabeca->prox;

    printf("LISTA DE CLIENTES:\n");

    while(aux!=NULL){
        printf("CPF: %s | Nome: %s\n", aux->cpf, aux->nome);
        aux = aux->prox;
    }

    printf("----------------\n");
}

cliente* buscar_cliente(cliente *cabeca, char *cpf){
    cliente *aux = cabeca->prox;

    while(aux!=NULL){
        if(strcmp(aux->cpf,cpf)==0){
            return aux;
        }
        aux=aux->prox;
    }

    return NULL;
}

void liberar_lista_clientes(cliente *cabeca){
    cliente *aux = cabeca->prox;
    cliente *temp;

    while(aux!=NULL){
        temp = aux;
        aux = aux->prox;
        free(temp);
    }

    free(cabeca);
}

void atualizar_dados_cliente(cliente *cabeca, char *cpf){
    cliente *c = buscar_cliente(cabeca, cpf);
    char i;

    if(c==NULL){
        printf("cliente nao encontrado\n");
        return;
    }

    printf("Cliente encontrado\n");
    printf("Nome: %s\n",c->nome);
    printf("CPF: %s\n",c->cpf);
    printf("E-mail: %s\n",c->email);
    printf("Telefone: %s\n",c->telefone);
    printf("Data de nascimento: %s\n",c->data_nasc);
    
    printf("Deseja alterar o nome? (s/n) ");
    scanf(" %c]",&i);
    if(i=='s'){
        printf("Digite o novo nome: ");
        scanf(" %[^\n]",c->nome);
    }

    printf("Deseja alterar o CPF? (s/n) ");
    scanf(" %c",&i);
    if(i=='s'){
        printf("Digite o novo CPF: ");
        scanf(" %[^\n]",c->cpf);
    }

    printf("Deseja alterar o e-mail? (s/n) ");
    scanf(" %c",&i);
    if(i=='s'){
        printf("Digite o novo e-mail: ");
        scanf(" %[^\n]",c->email);
    }

    printf("Deseja alterar o telefone? (s/n) ");
    scanf(" %c",&i);
    if(i=='s'){
        printf("Digite o novo telefone (apenas numeros): ");
        scanf(" %[^\n]",c->telefone);
    }

    printf("Deseja alterar a data de nascimento? (s/n) ");
    scanf(" %c",&i);
    if(i=='s'){
        printf("Digite a nova data de nascimento (formato DD/MM/YYYY): ");
        scanf(" %[^\n]",c->data_nasc);
    }

    printf("Dados atualizados com sucesso! Novos dados:\n");
    printf("Nome: %s\n", c->nome);
    printf("CPF: %s\n", c->cpf);
    printf("E-mail: %s\n", c->email);
    printf("Telefone: %s\n", c->telefone);
    printf("Data de nascimento: %s\n", c->data_nasc);

    return;
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
