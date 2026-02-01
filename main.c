#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"
#include "structs.h"

int main() {
    
   menu_inicial();
   
    cliente *lista_clientes = cria_lista_clientes();
    produto *lista_produtos = cria_lista_produtos();
    carrinho *lista_carrinhos = cria_lista_carrinhos();

    int opcao_principal = -1;
    while(opcao_principal != 0) {
        printf("\n=== SISTEMA DE LOJA ===\n");
        printf("1- Clientes\n2- Produtos\n3- Modo Compra\n0- Sair\nEscolha: ");
        scanf("%d", &opcao_principal);

        switch(opcao_principal) {
            case 1: menu_inicial(lista_clientes); break;
            case 2: menu_produtos(lista_produtos); break;
            case 3: menu_compra(lista_carrinhos, lista_clientes, lista_produtos); break;
        }
    }

    // Liberação final
    liberar_lista_clientes(lista_clientes);
    libera_lista_produtos(lista_produtos);
    libera_lista_carrinhos(lista_carrinhos);

return 0;
}
