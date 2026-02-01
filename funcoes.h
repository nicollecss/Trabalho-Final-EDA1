// declara todas as funções que serão usadas no código.

#ifndef FUNCOES_H
#define FUNCOES_H
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

void menu_inicial();

cliente* cria_lista_clientes();
int cadastra_cliente(cliente *cabeca);
void listar_clientes(cliente *cabeca);
void liberar_lista_clientes(cliente *cabeca);
cliente* buscar_cliente(cliente *cabeca, char *cpf);
void atualizar_dados_cliente(cliente *cabeca, char *cpf);

produto* cria_lista_produtos();
void limpar_buffer();
void cadastra_produto(produto *cabeca);
void lista_produtos(produto *cabeca);
void libera_lista_produtos(produto *cabeca);
produto* buscar_produto(produto *cabeca, int codigo);
void remove_produto(produto *cabeca, int codigo);
void menu_produtos(produto *cabeca);

carrinho* cria_lista_carrinhos();
void menu_compra(carrinho *cabeca_c, cliente *cabeca_cli, produto *cabeca_p);
carrinho* buscar_carrinho(carrinho *cabeca, char *cpf);
void adicionar_item(carrinho *cabeca_c, cliente *cabeca_cli, produto *cabeca_p);
void listar_carrinho_cliente(carrinho *cabeca_c, produto *cabeca_p);
void remover_item_carrinho(carrinho *cabeca_c, produto *cabeca_p);
void libera_lista_carrinhos(carrinho *cabeca);
#endif