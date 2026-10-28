#include <stdio.h>
#include "modulo.h"

// ============================================
// CARREGAR CARTEIRA DO ARQUIVO
// ============================================

int carregarCarteira(Ativo ativos[], int limite) {

    FILE *arquivo = fopen(ARQUIVO_CARTEIRA, "r");

    int total = 0;

    // Verifica se o arquivo existe
    if (arquivo == NULL) {
        printf("\nArquivo %s nao encontrado.\n",
               ARQUIVO_CARTEIRA);

        printf("Carteira iniciada vazia.\n");

        return 0;
    }

    // Le os ativos armazenados
    while (total < limite) {

        Ativo novo;

        int lidos = fscanf(
            arquivo,
            "%49s %29s %lf %lf %lf",
            novo.nome,
            novo.categoria,
            &novo.quantidade,
            &novo.precoCompra,
            &novo.precoAtual
        );

        // Final do arquivo
        if (lidos == EOF) {
            break;
        }

        // Verifica se o registro esta completo
        if (lidos != 5) {
            printf("Registro invalido no arquivo.\n");
            printf("Leitura interrompida.\n");
            break;
        }

        // Verifica valores invalidos
        if (novo.quantidade <= 0 ||
            novo.precoCompra <= 0 ||
            novo.precoAtual < 0) {

            printf("Ativo invalido ignorado: %s\n",
                   novo.nome);
            continue;
        }

        // Adiciona o ativo ao vetor
        ativos[total] = novo;

        total++;
    }

    if (total == limite) {
        printf("Limite de %d ativos atingido.\n",
               limite);
    }

    // Fecha o arquivo
    fclose(arquivo);

    printf("\n%d ativo(s) carregado(s) de %s.\n",
           total, ARQUIVO_CARTEIRA);

    return total;
}

// ============================================
// SALVAR CARTEIRA NO ARQUIVO
// ============================================

int salvarCarteira(const Ativo ativos[], int total) {

    FILE *arquivo = fopen(ARQUIVO_CARTEIRA, "w");

    int i;

    // Verifica se o arquivo abriu corretamente
    if (arquivo == NULL) {
        perror("Erro ao abrir carteira.txt para gravacao");
        return 0;
    }

    // Grava os ativos no arquivo texto
    for (i = 0; i < total; i++) {

        if (fprintf(
            arquivo,
            "%s %s %.6f %.6f %.6f\n",
            ativos[i].nome,
            ativos[i].categoria,
            ativos[i].quantidade,
            ativos[i].precoCompra,
            ativos[i].precoAtual
        ) < 0) {

            perror("Erro ao gravar carteira.txt");

            fclose(arquivo);

            return 0;
        }
    }

    // Fecha o arquivo e verifica possiveis erros
    if (fclose(arquivo) != 0) {
        perror("Erro ao fechar carteira.txt");
        return 0;
    }

    return 1;
}