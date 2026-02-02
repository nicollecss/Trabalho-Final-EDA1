// bibliotecas que usaremos
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include <windows.h>
#include "funcoes.h"
#include "structs.h"

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

void main_sistema() {
    // Inicializa as listas uma única vez através das funções de criação
    cliente *lista_clientes = cria_lista_clientes();
    produto *lista_produtos = cria_lista_produtos();
    carrinho *lista_carrinhos = cria_lista_carrinhos();

    int opcao_principal = -1;
    while(opcao_principal != 0) {
        printf("\n=== SISTEMA DA LOJA ===\n");
        printf("1- Clientes\n2- Produtos\n3- Modo Compra\n0- Sair\nEscolha: ");
        scanf("%d", &opcao_principal);

        switch(opcao_principal) {
            case 1: menu_clientes(lista_clientes); break; 
            case 2: menu_produtos(lista_produtos); break; 
            case 3: menu_compra(lista_carrinhos, lista_clientes, lista_produtos); break;
            case 0: printf("Encerrando o sistema...\n"); break;
            default: printf("Opcao invalida!\n"); break;
        }
    }

   
    liberar_lista_clientes(lista_clientes);
    libera_lista_produtos(lista_produtos);
    libera_lista_carrinhos(lista_carrinhos);
}

 //////////////////////////////////////////////   

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

void remover_cliente(cliente *cabeca, char *cpf) {
    cliente *ant = cabeca;
    cliente *atual = cabeca->prox;
    while (atual != NULL && strcmp(atual->cpf, cpf) != 0) {
        ant = atual;
        atual = atual->prox;
    }
    if (atual != NULL) {
        ant->prox = atual->prox;
        free(atual);
        printf("Cliente removido com sucesso!\n");
    } else {
        printf("Cliente nao encontrado.\n");
    }
}

void menu_clientes(cliente *cabeca) { 
    int i = -1;
    char cpf[50];

    while(i != 0) {
        printf("\n--- GERENCIAMENTO DE CLIENTES ---\n");
        printf("(1) Cadastrar novo cliente\n");
        printf("(2) Listar clientes\n");
        printf("(3) Buscar cliente pelo CPF\n");
        printf("(4) Atualizar dados de cliente\n");
        printf("(5) Remover cliente\n"); 
        printf("(0) Voltar ao menu principal\n");
        printf("Escolha uma opcao: ");
        
        if (scanf("%d", &i) != 1) {
            limpar_buffer();
            continue;
        }

        switch(i) {
            case 1:
                cadastra_cliente(cabeca);
                Sleep(1500);
                break;
            case 2:
                listar_clientes(cabeca);
                Sleep(3000);
                break;
            case 3:
                // Correção: Solicitando o CPF antes de buscar
                printf("Digite o CPF para buscar (somente numeros): ");
                scanf(" %[^\n]", cpf);
                
                cliente *c = buscar_cliente(cabeca, cpf);
                if(c != NULL) {
                    printf("\nCliente encontrado!\n");
                    printf("Nome: %s\n", c->nome);
                    printf("Email: %s\n", c->email);
                } else {
                    printf("\nCliente nao encontrado.\n");
                }
                Sleep(2000);
                break;
            case 4:
                printf("Digite o CPF para atualizar: ");
                scanf(" %[^\n]", cpf);
                atualizar_dados_cliente(cabeca, cpf);
                Sleep(2000);
                break;
            case 5:
                printf("Digite o CPF para remover: ");
                scanf(" %[^\n]", cpf);
                remover_cliente(cabeca, cpf);
                Sleep(2000);
                break;
            case 0:
                printf("Retornando...\n");
                Sleep(1000);
                break;
            default:
                printf("Opcao invalida!\n");
                Sleep(1000);
                break;
        }
    }
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

void limpar_buffer() {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

void cadastra_produto(produto *cabeca) {
    if (cabeca == NULL) return;

    char buffer[100];
    int codigo;

    printf(" \n\n");
    printf("---------------CADASTRO DO PRODUTO----------------\n");
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
    printf("---------------------------------------------\n");

    novo->prox = cabeca->prox;
    cabeca->prox = novo;

    printf("**Produto cadastrado com sucesso!**\n\n");
    Sleep(1500);
}

void lista_produtos(produto *cabeca){
    if (cabeca == NULL ||cabeca->prox ==NULL){
    printf("Nenhum produto cadastrado.\n");
    return;
    }

    produto *aux = cabeca->prox;

    printf(" \n");
    printf("----------LISTA DE PRODUTOS CADASTRADOS----------\n"); 
    while(aux != NULL){
        printf("-> Codigo: %d\n", aux->cod_unico);
        printf("-> Nome: %s\n", aux->nome);  
        printf("-> Preco unitario: R$ %.2f\n", aux->preco);  
        printf("-> Quantidade: %d\n", aux->quant);
        printf("-------------------------------------------------\n");
        printf(" \n");
        aux = aux->prox;
    }
    printf(" \n");
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

void edita_produto(produto *cabeca) {
    if (cabeca == NULL || cabeca->prox == NULL) {
        printf("Nenhum produto cadastrado.\n");
        return;
    }

    int codigo;
    char buffer[100];
    int opcao;

    printf("\nCodigo do produto que deseja editar: ");
    if (scanf("%d", &codigo) != 1) {
        printf("Codigo invalido.\n");
        limpar_buffer();
        return;
    }
    limpar_buffer();

    produto *p = buscar_produto(cabeca, codigo);

    if (p == NULL) {
        printf("Produto nao encontrado.\n");
        return;
    }

    do {
        printf("\n-------- EDITAR PRODUTO --------\n");
        printf("Codigo: %d\n", p->cod_unico);
        printf("Nome: %s\n", p->nome);
        printf("Preco: R$ %.2f\n", p->preco);
        printf("Quantidade: %d\n", p->quant);
        printf("--------------------------------\n");
        printf("(1) Alterar nome\n");
        printf("(2) Alterar preco\n");
        printf("(3) Alterar quantidade\n");
        printf("(0) Voltar\n");
        printf("Escolha: ");

        if (scanf("%d", &opcao) != 1) {
            limpar_buffer();
            printf("Opcao invalida.\n");
            continue;
        }
        limpar_buffer();

        switch (opcao) {
            case 1: {
                printf("Novo nome: ");
                scanf(" %99[^\n]", buffer);

                char *novo_nome = malloc(strlen(buffer) + 1);
                if (novo_nome == NULL) {
                    printf("Erro de memoria.\n");
                    return;
                }

                strcpy(novo_nome, buffer);
                free(p->nome);
                p->nome = novo_nome;

                printf("Nome atualizado com sucesso!\n");
                Sleep(1000);
                break;
            }

            case 2:
                printf("Novo preco: ");
                if (scanf("%f", &p->preco) != 1 || p->preco < 0) {
                    printf("Preco invalido.\n");
                    limpar_buffer();
                } else {
                    printf("Preco atualizado com sucesso!\n");
                }
                Sleep(1000);
                break;

            case 3:
                printf("Nova quantidade: ");
                if (scanf("%d", &p->quant) != 1 || p->quant < 0) {
                    printf("Quantidade invalida.\n");
                    limpar_buffer();
                } else {
                    printf("Quantidade atualizada com sucesso!\n");
                }
                Sleep(1000);
                break;

            case 0:
                printf("Retornando ao menu...\n");
                Sleep(1000);
                break;

            default:
                printf("Opcao invalida.\n");
        }

    } while (opcao != 0);
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
        printf("->Produto removido!\n\n");
    } else {
        printf("->Produto nao encontrado.\n\n\n");
    }
}

void menu_produtos(produto *lista) {
    int opcao=-1;

    while (opcao != 0) {
        printf("==========GERENCIAMENTO DE PRODUTOS==========\n\n");
        printf("->(1) Cadastrar produto\n");
        printf("->(2) Listar produtos cadastrados\n");
        printf("->(3) Buscar produto cadastrado\n");
        printf("->(4) Editar produto cadastrado\n");
        printf("->(5) Remover produto cadastrado\n");
        printf("->(0) Retorna ao menu principal (AINDA EM DESENVOLVIMENTO)\n\n");
        printf("=============================================\n");
        printf("Escolha a opcao: ");
        if (scanf("%d", &opcao) != 1) {
            limpar_buffer();
            continue;
        }

        switch (opcao) {
            case 1: 
                cadastra_produto(lista);
                break;
            case 2: 
                lista_produtos(lista);
                Sleep(2000);
                break;
            case 3: {
                int c;
                printf("\nCodigo a ser pesquisado: "); scanf("%d", &c);
                produto *p = buscar_produto(lista, c);
                if(p) printf("*Produto encontrado!\n->Nome do produto: %s\n\n", p->nome);
                else printf("*Produto nao encontrado.\n\n");
                Sleep(2000);
                break;
            }
            case 4:
                edita_produto(lista);
                break;
            case 5: {
                int c;
                printf("\n*Codigo para remocao: "); scanf("%d", &c);
                remove_produto(lista, c);
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

void adicionar_item_carrinho(carrinho *cabeca_carrinhos, cliente *cabeca_clientes, produto *cabeca_produtos, char *cpf_cliente) {
    int cod, qtd;
    
    // Busca o produto primeiro para saber se existe e tem estoque
    printf("Digite o codigo do produto: ");
    scanf("%d", &cod);
    produto *p = buscar_produto(cabeca_produtos, cod);

    if (p == NULL) {
        printf("[ERRO] Produto nao encontrado!\n");
        return;
    }

    printf("Digite a quantidade: ");
    scanf("%d", &qtd);

    if (p->quant < qtd) {
        printf("[ERRO] Estoque insuficiente! (Disponivel: %d)\n", p->quant);
        return;
    }

    // Busca o carrinho do cliente usando o CPF recebido pelo menu
    carrinho *c = cabeca_carrinhos->prox;
    carrinho *anterior = cabeca_carrinhos;
    while (c != NULL && strcmp(c->cpf, cpf_cliente) != 0) {
        anterior = c;
        c = c->prox;
    }

    // Se o cliente ainda não tem carrinho, cria um novo
    if (c == NULL) {
        c = (carrinho*)malloc(sizeof(carrinho));
        strcpy(c->cpf, cpf_cliente);
        c->itens = NULL;
        c->prox = NULL;
        anterior->prox = c;
    }

    // Adiciona o item na lista de itens do carrinho
    item_carrinho *novo_item = (item_carrinho*)malloc(sizeof(item_carrinho));
    novo_item->cod_unico = cod;
    novo_item->quantidade = qtd;
    novo_item->prox = c->itens;
    c->itens = novo_item;

    // Atualiza o estoque do produto
    p->quant -= qtd;
    printf("Item adicionado com sucesso!\n");
}

void listar_carrinho_cliente(carrinho *cabeca_carrinhos, produto *cabeca_produtos, char *cpf_cliente) {
    carrinho *c = cabeca_carrinhos->prox;
    while (c != NULL && strcmp(c->cpf, cpf_cliente) != 0) {
        c = c->prox;
    }

    if (c == NULL || c->itens == NULL) {
        printf("\nO carrinho do cliente %s esta vazio.\n", cpf_cliente);
        return;
    }

    float total_geral = 0;
    int total_itens = 0;
    printf("\n--- ITENS NO CARRINHO (CPF: %s) ---\n", cpf_cliente);
    
    item_carrinho *atual = c->itens;
    while (atual != NULL) {
        produto *p = buscar_produto(cabeca_produtos, atual->cod_unico);
        if (p != NULL) {
            float subtotal = p->preco * atual->quantidade;
            printf("Produto: %s | Qtd: %d | Preco Un: R$%.2f | Subtotal: R$%.2f\n", 
                    p->nome, atual->quantidade, p->preco, subtotal);
            total_geral += subtotal;
            total_itens += atual->quantidade;
        }
        atual = atual->prox;
    }
    printf("---------------------------------------------\n");
    printf("TOTAL DE ITENS: %d\n", total_itens);
    printf("VALOR TOTAL DA COMPRA: R$ %.2f\n", total_geral);
}

void remover_item_carrinho(carrinho *cabeca_carrinhos, produto *cabeca_produtos, char *cpf_cliente) {
    carrinho *c = cabeca_carrinhos->prox;
    while (c != NULL && strcmp(c->cpf, cpf_cliente) != 0) {
        c = c->prox;
    }

    if (c == NULL || c->itens == NULL) {
        printf("Carrinho vazio ou nao encontrado.\n");
        return;
    }

    int cod;
    printf("Digite o codigo do produto que deseja remover do carrinho: ");
    scanf("%d", &cod);

    item_carrinho *atual = c->itens;
    item_carrinho *anterior = NULL;

    while (atual != NULL && atual->cod_unico != cod) {
        anterior = atual;
        atual = atual->prox;
    }

    if (atual == NULL) {
        printf("Produto nao encontrado no carrinho.\n");
        return;
    }

    // Devolve ao estoque
    produto *p = buscar_produto(cabeca_produtos, cod);
    if (p != NULL) {
        p->quant += atual->quantidade;
    }

    // Remove da lista encadeada de itens
    if (anterior == NULL) {
        c->itens = atual->prox;
    } else {
        anterior->prox = atual->prox;
    }

    free(atual);
    printf("Produto removido e estoque atualizado com sucesso!\n");
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
    char cpf_atual[50];
    int escolha_usuario;
    int continuar_no_cpf;

    while (1) {
        printf("\n================ MODO COMPRA ================\n");
        printf("Digite o CPF do cliente para acessar o carrinho\n");
        printf("(ou digite '0' para voltar ao menu principal): ");
        scanf(" %[^\n]", cpf_atual);

        // Se digitar 0, sai do modo compra
        if (strcmp(cpf_atual, "0") == 0) {
            printf("Retornando ao menu principal...\n");
            Sleep(1000);
            break;
        }

        // Verifica se o cliente existe antes de prosseguir
        if (buscar_cliente(cabeca_clientes, cpf_atual) == NULL) {
            printf("\n[ERRO] Cliente nao cadastrado! Cadastre o cliente primeiro.\n");
            Sleep(2000);
            continue;
        }

        continuar_no_cpf = 1;
        while (continuar_no_cpf) {
            printf("\n--- CARRINHO DO CLIENTE: %s ---\n", cpf_atual);
            printf("(1) Incluir Produto\n");
            printf("(2) Listar Itens / Valor Total\n");
            printf("(3) Remover Produto\n");
            printf("(0) Sair deste carrinho (Trocar Cliente)\n");
            printf("Escolha: ");
            
            if (scanf("%d", &escolha_usuario) != 1) {
                limpar_buffer();
                continue;
            }

            switch (escolha_usuario) {
                case 1: 
                    adicionar_item_carrinho(cabeca_carrinhos, cabeca_clientes, cabeca_produtos, cpf_atual); 
                    Sleep(1500); 
                    break;
                case 2: 
                    listar_carrinho_cliente(cabeca_carrinhos, cabeca_produtos, cpf_atual); 
                    Sleep(3000); 
                    break;
                case 3: 
                    remover_item_carrinho(cabeca_carrinhos, cabeca_produtos, cpf_atual); 
                    Sleep(2000); 
                    break;
                case 0:
                    printf("Saindo do carrinho de %s...\n", cpf_atual);
                    continuar_no_cpf = 0; // Sai do loop interno e volta para o pedido de CPF
                    Sleep(1000);
                    break;
                default:
                    printf("Opcao invalida.\n");
                    Sleep(1000);
            }
        }
    }
}