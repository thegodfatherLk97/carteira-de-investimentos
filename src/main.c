#include <stdio.h>
#include "funcoes.h"

// ============================================
// PROGRAMA PRINCIPAL
// ============================================

int main(void) {

    // Vetor de structs que representa a carteira
    Ativo carteira[MAX_ATIVOS];

    // Carrega os ativos salvos anteriormente
    int total = carregarCarteira(
        carteira,
        MAX_ATIVOS
    );

    int opcao = 0;
    int totalAnterior;

    double valorInvestido;
    double valorAtual;

    // ========================================
    // MENU PRINCIPAL
    // ========================================

    do {

        exibirMenu();

        // Verifica se a entrada e numerica
        if (scanf("%d", &opcao) != 1) {

            if (feof(stdin)) {
                printf("\nEntrada encerrada.\n");
                break;
            }

            limparEntrada();

            printf("\nOpcao invalida.\n");
            printf("Digite um numero de 1 a 5.\n");

            continue;
        }

        limparEntrada();

        switch (opcao) {

            // =================================
            // 1 - CADASTRAR ATIVO
            // =================================

            case 1:

                totalAnterior = total;

                total = cadastrarAtivo(
                    carteira,
                    total
                );

                // Salva somente quando ha novo cadastro
                if (total > totalAnterior) {

                    if (salvarCarteira(carteira, total)) {

                        printf(
                            "Carteira salva em %s.\n",
                            ARQUIVO_CARTEIRA
                        );

                    } else {

                        printf(
                            "Aviso: cadastro em memoria, "
                            "mas nao foi possivel salvar.\n"
                        );
                    }
                }

                break;

            // =================================
            // 2 - LISTAR ATIVOS
            // =================================

            case 2:

                listarAtivos(
                    carteira,
                    total
                );

                break;

            // =================================
            // 3 - VALOR TOTAL DA CARTEIRA
            // =================================

            case 3:

                printf(
                    "\nValor total atual da carteira: "
                    "R$ %.2f\n",
                    calcularValorTotal(carteira, total)
                );

                break;

            // =================================
            // 4 - RENTABILIDADE GERAL
            // =================================

            case 4:

                if (total == 0) {

                    printf(
                        "\nNenhum ativo cadastrado "
                        "para calcular rentabilidade.\n"
                    );

                } else {

                    valorInvestido = calcularValorInvestido(
                        carteira,
                        total
                    );

                    valorAtual = calcularValorTotal(
                        carteira,
                        total
                    );

                    printf(
                        "\nValor investido: R$ %.2f\n",
                        valorInvestido
                    );

                    printf(
                        "Valor atual: R$ %.2f\n",
                        valorAtual
                    );

                    printf(
                        "Lucro/prejuizo: R$ %.2f\n",
                        valorAtual - valorInvestido
                    );

                    printf(
                        "Rentabilidade geral: %.2f%%\n",
                        calcularRentabilidadeGeral(
                            carteira,
                            total
                        )
                    );
                }

                break;

            // =================================
            // 5 - SAIR
            // =================================

            case 5:

                // Garante a gravacao ao encerrar
                if (!salvarCarteira(carteira, total)) {

                    printf(
                        "Aviso: nao foi possivel "
                        "salvar a carteira ao sair.\n"
                    );
                }

                printf("\nPrograma encerrado.\n");

                break;

            // =================================
            // OPCAO INVALIDA
            // =================================

            default:

                printf("\nOpcao invalida.\n");
                printf("Digite um numero de 1 a 5.\n");

                break;
        }

    } while (opcao != 5);

    return 0;
}