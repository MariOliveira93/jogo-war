/*
 * main.c
 *
 * Arquivo principal do programa de cadastro e batalhas de territórios do jogo War.
 *
 * Este programa permite:
 * - Alocação dinâmica de territórios e jogadores
 * - Cadastro de territórios e jogadores com suas respectivas informações
 * - Sistema de missões estratégicas com sorteio aleatório
 * - Simulação de ataques entre territórios
 * - Verificação automática de vitória por cumprimento de missão
 *
 * Autor: [Seu Nome]
 * Data: [Data Atual]
 * Versão: 3.0 - Fase Mestre
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/territorio.h"
#include "../include/jogador.h"
#include "../include/missao.h"
#include "../include/utils.h"

/*
 * Função: realizarAtaque
 *
 * Gerencia o processo de seleção e execução de um ataque entre territórios.
 *
 * Parâmetros:
 *   - territorios: ponteiro para o array de territórios
 *   - quantidade: número de territórios disponíveis
 *   - jogadores: ponteiro para o array de jogadores
 *   - quantidadeJogadores: número de jogadores
 *
 * Retorno: índice do jogador vencedor ou -1 se ninguém venceu
 */
int realizarAtaque(Territorio *territorios, int quantidade,
                   Jogador *jogadores, int quantidadeJogadores) {
    int indiceAtacante, indiceDefensor;

    printf("\n");
    exibirSeparador();
    printf("           SELECAO DE ATAQUE                 \n");
    exibirSeparador();

    // Exibe territórios disponíveis
    printf("\nTerritorios disponiveis:\n");
    for (int i = 0; i < quantidade; i++) {
        printf("  [%d] %s (%s) - %d tropas\n",
               i + 1, territorios[i].nome, territorios[i].cor, territorios[i].tropas);
    }

    // Seleciona território atacante
    printf("\nEscolha o territorio ATACANTE (1-%d): ", quantidade);
    scanf("%d", &indiceAtacante);
    indiceAtacante--; // Ajusta para índice do array (0-based)

    // Valida índice do atacante
    if (indiceAtacante < 0 || indiceAtacante >= quantidade) {
        printf("Erro: Territorio invalido!\n");
        limparBuffer();
        return -1;
    }

    // Seleciona território defensor
    printf("Escolha o territorio DEFENSOR (1-%d): ", quantidade);
    scanf("%d", &indiceDefensor);
    indiceDefensor--; // Ajusta para índice do array (0-based)

    // Valida índice do defensor
    if (indiceDefensor < 0 || indiceDefensor >= quantidade) {
        printf("Erro: Territorio invalido!\n");
        limparBuffer();
        return -1;
    }

    // Verifica se não está atacando o mesmo território
    if (indiceAtacante == indiceDefensor) {
        printf("Erro: Um territorio nao pode atacar a si mesmo!\n");
        limparBuffer();
        return -1;
    }

    limparBuffer();

    // Realiza o ataque usando ponteiros
    atacar(&territorios[indiceAtacante], &territorios[indiceDefensor]);

    // Verifica se algum jogador cumpriu sua missão após o ataque
    int vencedor = verificarTodasMissoes(jogadores, quantidadeJogadores,
                                         territorios, quantidade);

    return vencedor;
}

/*
 * Função Principal
 *
 * Gerencia o fluxo de execução do programa:
 * 1. Inicializa o gerador de números aleatórios
 * 2. Aloca memória dinamicamente para territórios e jogadores
 * 3. Realiza o cadastro de territórios e jogadores
 * 4. Atribui missões aleatórias para cada jogador
 * 5. Apresenta menu interativo para batalhas
 * 6. Verifica condições de vitória após cada turno
 * 7. Libera toda a memória alocada ao finalizar
 */
int main(void) {
    int quantidadeTerritórios, quantidadeJogadores;
    Territorio *territorios = NULL;
    Jogador *jogadores = NULL;
    int opcao = 0;
    int jogoAtivo = 1;

    // Inicializa o gerador de números aleatórios
    inicializarAleatoriedade();

    // Exibe o cabeçalho do programa
    exibirCabecalho();

    // ========== CONFIGURAÇÃO DO JOGO ==========

    // Solicita quantidade de jogadores
    printf("\nQuantos jogadores participarao? ");
    scanf("%d", &quantidadeJogadores);
    limparBuffer();

    if (quantidadeJogadores <= 0) {
        printf("Erro: Quantidade invalida de jogadores!\n");
        return 1;
    }

    // Aloca memória para os jogadores
    jogadores = alocarJogadores(quantidadeJogadores);
    if (jogadores == NULL) {
        printf("Erro: Nao foi possivel alocar memoria para os jogadores.\n");
        return 1;
    }

    // Cadastra os jogadores
    printf("\n=== CADASTRO DE JOGADORES ===\n");
    for (int i = 0; i < quantidadeJogadores; i++) {
        cadastrarJogador(&jogadores[i], i + 1);
    }

    // Solicita quantidade de territórios
    printf("\nQuantos territorios deseja cadastrar? ");
    scanf("%d", &quantidadeTerritórios);
    limparBuffer();

    if (quantidadeTerritórios <= 0) {
        printf("Erro: Quantidade invalida de territorios!\n");
        liberarJogadores(jogadores, quantidadeJogadores);
        return 1;
    }

    // Aloca memória dinamicamente para os territórios
    territorios = alocarTerritorios(quantidadeTerritórios);
    if (territorios == NULL) {
        printf("Erro: Nao foi possivel alocar memoria para os territorios.\n");
        liberarJogadores(jogadores, quantidadeJogadores);
        return 1;
    }

    printf("\nMemoria alocada com sucesso!\n");

    // Cadastra os territórios
    printf("\n=== CADASTRO DE TERRITORIOS ===\n");
    for (int i = 0; i < quantidadeTerritórios; i++) {
        cadastrarTerritorio(territorios + i, i + 1);
    }

    // ========== ATRIBUIÇÃO DE MISSÕES ==========

    printf("\n");
    exibirSeparador();
    printf("       ATRIBUINDO MISSOES ESTRATEGICAS       \n");
    exibirSeparador();
    printf("\n");

    const char **missoes = obterMissoes();

    // Atribui missões para cada jogador (passagem por referência)
    for (int i = 0; i < quantidadeJogadores; i++) {
        atribuirMissao(&jogadores[i], missoes, TOTAL_MISSOES);
    }

    printf("\n");
    pausar();

    // Exibe as missões de cada jogador (passagem por valor para leitura)
    for (int i = 0; i < quantidadeJogadores; i++) {
        exibirMissao(jogadores[i].missao, jogadores[i].nome);
    }

    pausar();

    // Exibição inicial de todos os territórios
    exibirTodosTerritórios(territorios, quantidadeTerritórios);

    // ========== LOOP PRINCIPAL DO JOGO ==========

    while (opcao != 4 && jogoAtivo) {
        exibirMenu();
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1: {
                // Realizar ataque e verificar vitória
                int vencedor = realizarAtaque(territorios, quantidadeTerritórios,
                                             jogadores, quantidadeJogadores);

                if (vencedor >= 0) {
                    printf("\n");
                    exibirSeparador();
                    printf("          >>> TEMOS UM VENCEDOR! <<<         \n");
                    exibirSeparador();
                    printf("\n");
                    printf("Parabens, %s!\n", jogadores[vencedor].nome);
                    printf("Voce cumpriu sua missao:\n%s\n", jogadores[vencedor].missao);
                    exibirSeparador();
                    jogoAtivo = 0;
                }

                pausar();
                break;
            }

            case 2:
                // Exibir territórios
                exibirTodosTerritórios(territorios, quantidadeTerritórios);
                pausar();
                break;

            case 3:
                // Exibir jogadores e missões
                exibirTodosJogadores(jogadores, quantidadeJogadores);
                pausar();
                break;

            case 4:
                // Sair
                printf("\nEncerrando o jogo...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                pausar();
                break;
        }
    }

    // ========== LIBERAÇÃO DE MEMÓRIA ==========

    // Libera a memória alocada antes de encerrar
    liberarMemoria(territorios);
    liberarJogadores(jogadores, quantidadeJogadores);

    printf("\nObrigado por jogar WAR!\n");
    exibirSeparador();

    return 0;
}