// declara todas as funções que serão usadas no código.

#ifndef FUNCOES_H
#define FUNCOES_H
#include <stdio.h>
#include <stdlib.h>
#include "structs.h"

// aqui definimos as assinaturas das funções que usaremos
void menu_inicial();
cliente *cadastra_cliente();

produto *cria_lista();
void cadastra_produto(produto *cabeca);

#endif
