// declara todas as funções que serão usadas no código.

#ifndef FUNCOES_H
#define FUNCOES_H
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

// aqui definimos as assinaturas das funções que usaremos
void menu_inicial();

cliente* cria_lista_clientes();
int cadastra_cliente(cliente *cabeca);
void listar_clientes(cliente *cabeca);
void liberar_lista_clientes(cliente *cabeca);
cliente* buscar_cliente(cliente *cabeca, char *cpf);
void atualizar_dados_cliente(cliente *cabeca, char *cpf);

produto* cria_lista();
void cadastra_produto(produto *cabeca);


#endif
