/*
 * jogador.c
 *
 * Implementação das funções relacionadas ao gerenciamento de jogadores.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/jogador.h"
#include "../include/utils.h"

/*
 * Implementação: alocarJogadores
 *
 * Utiliza calloc para alocar memória inicializada com zeros para os jogadores.
 */
Jogador* alocarJogadores(int quantidade) {
    Jogador *jogadores = (Jogador*) calloc(quantidade, sizeof(Jogador));

    if (jogadores == NULL) {
        printf("Erro: Falha na alocacao de memoria para jogadores!\n");
        return NULL;
    }

    // Inicializa as missões como NULL
    for (int i = 0; i < quantidade; i++) {
        jogadores[i].missao = NULL;
        jogadores[i].missaoCumprida = 0;
    }

    return jogadores;
}

/*
 * Implementação: liberarJogadores
 *
 * Libera a memória alocada para os jogadores e suas missões.
 */
void liberarJogadores(Jogador *jogadores, int quantidade) {
    if (jogadores != NULL) {
        // Libera cada missão individualmente
        for (int i = 0; i < quantidade; i++) {
            if (jogadores[i].missao != NULL) {
                free(jogadores[i].missao);
            }
        }
        // Libera o vetor de jogadores
        free(jogadores);
        printf("Memoria dos jogadores liberada com sucesso!\n");
    }
}

/*
 * Implementação: cadastrarJogador
 *
 * Solicita ao usuário as informações do jogador.
 */
void cadastrarJogador(Jogador *jogador, int numero) {
    printf("\n=== Cadastro do Jogador %d ===\n", numero);

    // Leitura do nome do jogador
    printf("Digite o nome do jogador: ");
    scanf(" %[^\n]", jogador->nome);

    // Leitura da cor do exército
    printf("Digite a cor do exercito: ");
    scanf(" %[^\n]", jogador->cor);

    // Inicializa flags
    jogador->missaoCumprida = 0;

    limparBuffer();
}

/*
 * Implementação: exibirJogador
 *
 * Exibe as informações de um jogador, incluindo sua missão (passada por valor).
 */
void exibirJogador(const Jogador *jogador, int numero) {
    printf("\nJogador %d:\n", numero);
    printf("  Nome: %s\n", jogador->nome);
    printf("  Cor: %s\n", jogador->cor);

    if (jogador->missao != NULL) {
        printf("  Missao: %s\n", jogador->missao);
    } else {
        printf("  Missao: Nao atribuida\n");
    }

    printf("  Status: %s\n", jogador->missaoCumprida ? "MISSAO CUMPRIDA!" : "Em jogo");
}

/*
 * Implementação: exibirTodosJogadores
 *
 * Exibe todos os jogadores cadastrados.
 */
void exibirTodosJogadores(const Jogador *jogadores, int quantidade) {
    printf("\n");
    exibirSeparador();
    printf("           JOGADORES CADASTRADOS             \n");
    exibirSeparador();

    for (int i = 0; i < quantidade; i++) {
        exibirJogador(jogadores + i, i + 1);
    }

    printf("\n");
    exibirSeparador();
}