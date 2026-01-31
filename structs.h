// define structs usadas durante o trabalho.
#ifndef STRUCTS_H
#define STRUCTS_H

typedef struct Cliente {
    char nome[100];
    char cpf[50];
    char email[50];
    char telefone[15];
    char data_nascimento[15];
}cliente;

typedef struct Produto{
    int cod_unico;
    char *nome;
    float preco;
    int quant;
    struct Produto *prox;
} produto;

#endif


