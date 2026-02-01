// bibliotecas que usaremos
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
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
            case 1:{
                int x = cadastra_cliente(cabeca);
                break;
            }
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

produto* cria_lista_produtos() {
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

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastra_produto(produto *cabeca) {
    if (cabeca == NULL) return;

    char buffer[100];
    int codigo;

    printf(" \n");
    printf("-----CADASTRO DO PRODUTO-----\n");
    printf("Codigo unico: ");
    if (scanf("%d", &codigo) != 1) {
        printf("Entrada invalida.\n");
        limpar_buffer();
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

    printf("Preco unitario: ");
    if (scanf("%f", &novo->preco) != 1) {
        printf("Entrada invalida.\n");
        limpar_buffer();
        free(novo->nome);
        free(novo);
        return;
    }

    printf("Quantidade: ");
    if (scanf("%d", &novo->quant) != 1) {
        printf("Entrada invalida.\n");
        limpar_buffer();
        free(novo->nome);
        free(novo);
        return;
    }
    printf("----------------\n");

    novo->prox = cabeca->prox;
    cabeca->prox = novo;

    printf("**Produto cadastrado com sucesso!**\n");
    Sleep(1500);
}


void lista_produtos(produto *cabeca){
    if (cabeca == NULL ||cabeca->prox ==NULL){
    printf("Nenhum produto cadastrado.\n");
    return;
    }

    produto *aux = cabeca->prox;

    printf(" \n");
    printf("----LISTA DE PRODUTOS CADASTRADOS----\n"); //arrumar
    while(aux != NULL){
        printf("-> Codigo: %d\n", aux->cod_unico);
        printf("-> Nome: %s\n", aux->nome);  
        printf("-> Preco unitario: R$ %.2f\n", aux->preco);  
        printf("-> Quantidade: %d\n", aux->quant);
        printf("----------------------------\n"); //arrumar
        printf(" \n");
        aux = aux->prox;
    }
}


void libera_lista_produtos(produto *cabeca) {
    if (cabeca == NULL) return;

    produto *aux = cabeca;
    while (aux != NULL) {
        produto *temp = aux;
        aux = aux->prox;

        if (temp->nome != NULL) {
            free(temp->nome);
        }

        free(temp);
    }
}


produto* buscar_produto(produto *cabeca, int codigo) {
    if (cabeca == NULL) return NULL;

    produto *aux = cabeca->prox;

    while (aux != NULL) {
        if (aux->cod_unico == codigo) {
            return aux;
        }
        aux = aux->prox;
    }

    return NULL;
}


void remove_produto(produto *cabeca, int codigo) {
    produto *ant = cabeca;
    produto *atual = cabeca->prox;

    while (atual != NULL && atual->cod_unico != codigo) {
        ant = atual;
        atual = atual->prox;
    }

    if (atual != NULL) {
        ant->prox = atual->prox;
        free(atual->nome);
        free(atual);
        printf("Produto removido!\n");
    } else {
        printf("Produto nao encontrado.\n");
    }
}


void menu_produtos(produto *cabeca_produtos) { 
    int opcao = -1;

    while (opcao != 0) {
        printf("\n1-Cadastrar 2-Listar 3-Buscar 4-Remover 0-Sair: ");
        if (scanf("%d", &opcao) != 1) {
            limpar_buffer();
            continue;
        }

        switch (opcao) {
            case 1: cadastra_produto(cabeca_produtos); break;
            case 2: lista_produtos(cabeca_produtos); break;
            case 3: {
                int c;
                printf("Cod: "); scanf("%d", &c);
                produto *p = buscar_produto(cabeca_produtos, c);
                if(p) printf("Achou: %s\n", p->nome);
                else printf("Nao achou.\n");
                break;
            }
            case 4: {
                int c;
                printf("Cod p/ remover: "); scanf("%d", &c);
                remove_produto(cabeca_produtos, c);
                break;
            }
        }
    }
}

///////////////////////////////////////////////
carrinho* cria_lista_carrinhos() {
    carrinho *cabeca_carrinhos = calloc(1, sizeof(carrinho));
    if(cabeca_carrinhos == NULL) return NULL;
    cabeca_carrinhos->prox = NULL;
    return cabeca_carrinhos;
}

void adicionar_item_carrinho(carrinho *cabeca_carrinhos, cliente *cabeca_clientes, produto *cabeca_produtos) {
    char cpf_busca[50];
    int codigo_busca, quantidade_desejada;

    printf("Digite o CPF do cliente: ");
    scanf(" %[^\n]", cpf_busca);

    if (buscar_cliente(cabeca_clientes, cpf_busca) == NULL) {
        printf("Erro: Cliente nao encontrado!\n");
        return;
    }

    printf("Digite o codigo unico do produto: ");
    scanf("%d", &codigo_busca);
    produto *produto_alvo = buscar_produto(cabeca_produtos, codigo_busca);

    if (produto_alvo == NULL) {
        printf("Erro: Produto nao encontrado!\n");
        return;
    }

    printf("Quantidade: ");
    scanf("%d", &quantidade_desejada);

    if (quantidade_desejada > produto_alvo->quant) {
        printf("Erro: Estoque insuficiente! (Disponivel: %d)\n", produto_alvo->quant);
        return;
    }

    carrinho *navegador_carrinhos = cabeca_carrinhos->prox;
    carrinho *carrinho_do_cliente = NULL;

    while(navegador_carrinhos != NULL) {
        if(strcmp(navegador_carrinhos->cpf, cpf_busca) == 0) {
            carrinho_do_cliente = navegador_carrinhos;
            break;
        }
        navegador_carrinhos = navegador_carrinhos->prox;
    }

    if (carrinho_do_cliente == NULL) {
        carrinho_do_cliente = calloc(1, sizeof(carrinho));
        strcpy(carrinho_do_cliente->cpf, cpf_busca);
        carrinho_do_cliente->prox = cabeca_carrinhos->prox;
        cabeca_carrinhos->prox = carrinho_do_cliente;
    }

    item_carrinho *novo_item = calloc(1, sizeof(item_carrinho));
    novo_item->cod_unico = codigo_busca;
    novo_item->quantidade = quantidade_desejada;
    novo_item->prox = carrinho_do_cliente->itens;
    carrinho_do_cliente->itens = novo_item;

    produto_alvo->quant -= quantidade_desejada; // Baixa no estoque
    printf("Item adicionado com sucesso!\n");
}

void listar_carrinho_cliente(carrinho *cabeca_carrinhos, produto *cabeca_produtos) {
    char cpf_busca[50];
    printf("Digite o CPF para consultar o carrinho: ");
    scanf(" %[^\n]", cpf_busca);

    carrinho *atual_carrinho = cabeca_carrinhos->prox;
    while(atual_carrinho != NULL && strcmp(atual_carrinho->cpf, cpf_busca) != 0) {
        atual_carrinho = atual_carrinho->prox;
    }

    if (atual_carrinho == NULL || atual_carrinho->itens == NULL) {
        printf("Carrinho vazio para este cliente.\n");
        return;
    }

    float valor_total_compra = 0;
    int total_itens = 0;
    item_carrinho *item_navegador = atual_carrinho->itens;

    printf("\n--- CARRINHO DO CPF: %s ---\n", cpf_busca);
    while(item_navegador != NULL) {
        produto *info_produto = buscar_produto(cabeca_produtos, item_navegador->cod_unico);
        if(info_produto != NULL) {
            float subtotal = info_produto->preco * item_navegador->quantidade;
            printf("Cod: %d | Produto: %s | Qtd: %d | Subtotal: R$ %.2f\n", 
                    info_produto->cod_unico, info_produto->nome, item_navegador->quantidade, subtotal);
            valor_total_compra += subtotal;
            total_itens += item_navegador->quantidade;
        }
        item_navegador = item_navegador->prox;
    }
    printf("TOTAL DE ITENS: %d | VALOR TOTAL: R$ %.2f\n--------------------------\n", total_itens, valor_total_compra);
}

void remover_item_carrinho(carrinho *cabeca_carrinhos, produto *cabeca_produtos) {
    char cpf_busca[50];
    int codigo_remover;

    printf("CPF do cliente: ");
    scanf(" %[^\n]", cpf_busca);

    carrinho *atual_carrinho = cabeca_carrinhos->prox;
    while(atual_carrinho != NULL && strcmp(atual_carrinho->cpf, cpf_busca) != 0) {
        atual_carrinho = atual_carrinho->prox;
    }

    if (atual_carrinho == NULL || atual_carrinho->itens == NULL) {
        printf("Nenhum item encontrado no carrinho deste cliente.\n");
        return;
    }

    printf("Digite o codigo do produto para remover: ");
    scanf("%d", &codigo_remover);

    item_carrinho *anterior_item = NULL;
    item_carrinho *atual_item = atual_carrinho->itens;

    while (atual_item != NULL && atual_item->cod_unico != codigo_remover) {
        anterior_item = atual_item;
        atual_item = atual_item->prox;
    }

    if (atual_item == NULL) {
        printf("Produto nao esta no carrinho.\n");
        return;
    }

    // Devolve a quantidade ao estoque antes de deletar
    produto *produto_estoque = buscar_produto(cabeca_produtos, atual_item->cod_unico);
    if (produto_estoque != NULL) {
        produto_estoque->quant += atual_item->quantidade;
    }

    // Ajusta os ponteiros da lista interna de itens
    if (anterior_item == NULL) {
        atual_carrinho->itens = atual_item->prox;
    } else {
        anterior_item->prox = atual_item->prox;
    }

    free(atual_item);
    printf("Produto removido e estoque atualizado!\n");
}

void libera_lista_carrinhos(carrinho *cabeca_carrinhos) {
    carrinho *carrinho_auxiliar = cabeca_carrinhos;
    while(carrinho_auxiliar != NULL) {
        item_carrinho *item_auxiliar = carrinho_auxiliar->itens;
        while(item_auxiliar != NULL) {
            item_carrinho *item_para_liberar = item_auxiliar;
            item_auxiliar = item_auxiliar->prox;
            free(item_para_liberar);
        }
        carrinho *carrinho_para_liberar = carrinho_auxiliar;
        carrinho_auxiliar = carrinho_auxiliar->prox;
        free(carrinho_para_liberar);
    }
}

void menu_compra(carrinho *cabeca_carrinhos, cliente *cabeca_clientes, produto *cabeca_produtos) {
    int escolha_usuario = -1;
    while(escolha_usuario != 0) {
        printf("\n--- MODO COMPRA ---\n(1) Incluir no Carrinho\n(2) Listar Carrinho\n(3) Remover do Carrinho\n(0) Voltar\nEscolha: ");
        scanf("%d", &escolha_usuario);

        switch(escolha_usuario) {
            case 1: adicionar_item_carrinho(cabeca_carrinhos, cabeca_clientes, cabeca_produtos); break;
            case 2: listar_carrinho_cliente(cabeca_carrinhos, cabeca_produtos); break;
            case 3: remover_item_carrinho(cabeca_carrinhos, cabeca_produtos); break;
            case 0: break;
            default: printf("Opcao invalida.\n");
        }
    }
}