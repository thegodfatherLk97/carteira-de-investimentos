#ifndef MODULO_H
#define MODULO_H

#define MAX_ATIVOS 100
#define ARQUIVO_CARTEIRA "data/carteira.txt"

// Estrutura que representa um ativo financeiro
typedef struct {
    char nome[50];
    char categoria[30];
    double quantidade;
    double precoCompra;
    double precoAtual;
} Ativo;

// Carrega os ativos salvos no arquivo texto
int carregarCarteira(Ativo ativos[], int limite);

// Salva os ativos no arquivo texto
int salvarCarteira(const Ativo ativos[], int total);

#endif