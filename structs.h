// define structs usadas durante o trabalho.
#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct Cliente {
    char nome[100];
    char cpf[50];
    char email[50];
    char telefone[15];
    char data_nasc[15];
    struct Cliente *prox;
}cliente;

typedef struct Produto{
    int cod_unico;
    char *nome;
    float preco;
    int quant;
    struct Produto *prox;
} produto;

typedef struct ItemCarrinho {
    int cod_produto;
    int quantidade;
    struct ItemCarrinho *prox;
} item_carrinho;

typedef struct Carrinho {
    char cpf_cliente[50];
    item_carrinho *itens; // Cabeça da lista de itens deste carrinho
    struct Carrinho *prox;
} carrinho;

#endif


