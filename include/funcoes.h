#ifndef FUNCOES_H
#define FUNCOES_H

#include "modulo.h"

// Menu principal
void exibirMenu(void);

// Limpeza do buffer de entrada
void limparEntrada(void);

// Cadastro de um novo ativo
int cadastrarAtivo(Ativo ativos[], int total);

// Listagem dos ativos cadastrados
void listarAtivos(const Ativo ativos[], int total);

// Calcula o valor total investido
double calcularValorInvestido(
    const Ativo ativos[],
    int total
);

// Calcula o valor atual da carteira
double calcularValorTotal(
    const Ativo ativos[],
    int total
);

// Calcula a rentabilidade geral em percentual
double calcularRentabilidadeGeral(
    const Ativo ativos[],
    int total
);

#endif