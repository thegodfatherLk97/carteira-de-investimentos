#include <stdio.h>
#include "funcoes.h"

// ============================================
// MENU PRINCIPAL
// ============================================

void exibirMenu(void) {
    printf("\n===== CARTEIRA DE INVESTIMENTOS - CP2 =====\n");
    printf("1. Cadastrar ativo\n");
    printf("2. Listar ativos\n");
    printf("3. Calcular valor total da carteira\n");
    printf("4. Calcular rentabilidade geral\n");
    printf("5. Sair\n");
    printf("Escolha uma opcao: ");
}

// ============================================
// LIMPEZA DO BUFFER
// ============================================

void limparEntrada(void) {
    int caractere;

    while ((caractere = getchar()) != '\n' &&
           caractere != EOF) {
    }
}

// ============================================
// CADASTRO DE ATIVOS
// ============================================

int cadastrarAtivo(Ativo ativos[], int total) {
    Ativo novo;

    if (total >= MAX_ATIVOS) {
        printf("\nCarteira cheia. Limite de %d ativos.\n",
               MAX_ATIVOS);
        return total;
    }

    printf("\n===== CADASTRO DE ATIVO =====\n");

    printf("Nome (sem espacos): ");
    if (scanf("%49s", novo.nome) != 1) {
        limparEntrada();
        return total;
    }
    limparEntrada();

    printf("Categoria (sem espacos): ");
    if (scanf("%29s", novo.categoria) != 1) {
        limparEntrada();
        return total;
    }
    limparEntrada();

    printf("Quantidade: ");
    if (scanf("%lf", &novo.quantidade) != 1) {
        limparEntrada();
        printf("Quantidade invalida. Cadastro cancelado.\n");
        return total;
    }
    limparEntrada();

    printf("Preco de compra (use ponto decimal): ");
    if (scanf("%lf", &novo.precoCompra) != 1) {
        limparEntrada();
        printf("Preco de compra invalido. Cadastro cancelado.\n");
        return total;
    }
    limparEntrada();

    printf("Preco atual (use ponto decimal): ");
    if (scanf("%lf", &novo.precoAtual) != 1) {
        limparEntrada();
        printf("Preco atual invalido. Cadastro cancelado.\n");
        return total;
    }
    limparEntrada();

    // Validacao dos valores informados
    if (novo.quantidade <= 0 ||
        novo.precoCompra <= 0 ||
        novo.precoAtual < 0) {

        printf("Dados invalidos. Cadastro cancelado.\n");
        return total;
    }

    // Adiciona o ativo ao vetor
    ativos[total] = novo;

    printf("\nAtivo cadastrado com sucesso!\n");

    return total + 1;
}

// ============================================
// LISTAGEM DE ATIVOS
// ============================================

void listarAtivos(const Ativo ativos[], int total) {
    int i;

    if (total == 0) {
        printf("\nNenhum ativo cadastrado.\n");
        return;
    }

    printf("\n===== ATIVOS CADASTRADOS =====\n");

    for (i = 0; i < total; i++) {
        printf("\nAtivo %d\n", i + 1);
        printf("Nome: %s\n", ativos[i].nome);
        printf("Categoria: %s\n", ativos[i].categoria);
        printf("Quantidade: %.4f\n", ativos[i].quantidade);
        printf("Preco de compra: R$ %.2f\n",
               ativos[i].precoCompra);
        printf("Preco atual: R$ %.2f\n",
               ativos[i].precoAtual);
    }
}

// ============================================
// CALCULO DO VALOR INVESTIDO
// ============================================

double calcularValorInvestido(
    const Ativo ativos[],
    int total
) {
    double soma = 0.0;
    int i;

    for (i = 0; i < total; i++) {
        soma += ativos[i].quantidade *
                ativos[i].precoCompra;
    }

    return soma;
}

// ============================================
// CALCULO DO VALOR ATUAL DA CARTEIRA
// ============================================

double calcularValorTotal(
    const Ativo ativos[],
    int total
) {
    double soma = 0.0;
    int i;

    for (i = 0; i < total; i++) {
        soma += ativos[i].quantidade *
                ativos[i].precoAtual;
    }

    return soma;
}

// ============================================
// CALCULO DA RENTABILIDADE GERAL
// ============================================

double calcularRentabilidadeGeral(
    const Ativo ativos[],
    int total
) {
    double investido = calcularValorInvestido(
        ativos, total
    );

    double atual = calcularValorTotal(
        ativos, total
    );

    // Evita divisao por zero
    if (investido <= 0.0) {
        return 0.0;
    }

    return ((atual - investido) / investido) * 100.0;
}