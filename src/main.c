/*
 * main.c
 *
 * Arquivo principal do programa de cadastro e batalhas de territórios do jogo War.
 *
 * Este programa permite:
 * - Alocação dinâmica de territórios
 * - Cadastro de territórios com suas respectivas informações
 * - Simulação de ataques entre territórios
 * - Atualização dinâmica dos dados após batalhas
 *
 * Autor: [Seu Nome]
 * Data: [Data Atual]
 * Versão: 2.0 - Fase Aventureiro
 */

#include <stdio.h>
#include <stdlib.h>
#include "../include/territorio.h"
#include "../include/utils.h"

/*
 * Função: realizarAtaque
 *
 * Gerencia o processo de seleção e execução de um ataque entre territórios.
 *
 * Parâmetros:
 *   - territorios: ponteiro para o array de territórios
 *   - quantidade: número de territórios disponíveis
 *
 * Retorno: void
 */
void realizarAtaque(Territorio *territorios, int quantidade) {
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
        return;
    }

    // Seleciona território defensor
    printf("Escolha o territorio DEFENSOR (1-%d): ", quantidade);
    scanf("%d", &indiceDefensor);
    indiceDefensor--; // Ajusta para índice do array (0-based)

    // Valida índice do defensor
    if (indiceDefensor < 0 || indiceDefensor >= quantidade) {
        printf("Erro: Territorio invalido!\n");
        limparBuffer();
        return;
    }

    // Verifica se não está atacando o mesmo território
    if (indiceAtacante == indiceDefensor) {
        printf("Erro: Um territorio nao pode atacar a si mesmo!\n");
        limparBuffer();
        return;
    }

    limparBuffer();

    // Realiza o ataque usando ponteiros
    atacar(&territorios[indiceAtacante], &territorios[indiceDefensor]);
}

/*
 * Função Principal
 *
 * Gerencia o fluxo de execução do programa:
 * 1. Inicializa o gerador de números aleatórios
 * 2. Aloca memória dinamicamente para os territórios
 * 3. Realiza o cadastro de todos os territórios
 * 4. Apresenta menu interativo para batalhas
 * 5. Libera a memória alocada ao finalizar
 */
int main(void) {
    int quantidadeTerritórios;
    Territorio *territorios = NULL;
    int opcao = 0;

    // Inicializa o gerador de números aleatórios
    inicializarAleatoriedade();

    // Exibe o cabeçalho do programa
    exibirCabecalho();

    // Solicita quantidade de territórios
    printf("\nQuantos territorios deseja cadastrar? ");
    scanf("%d", &quantidadeTerritórios);
    limparBuffer();

    // Valida quantidade
    if (quantidadeTerritórios <= 0) {
        printf("Erro: Quantidade invalida!\n");
        return 1;
    }

    // Aloca memória dinamicamente para os territórios
    territorios = alocarTerritorios(quantidadeTerritórios);

    // Verifica se a alocação foi bem-sucedida
    if (territorios == NULL) {
        printf("Erro: Nao foi possivel alocar memoria para os territorios.\n");
        return 1;
    }

    printf("\nMemoria alocada com sucesso para %d territorios!\n", quantidadeTerritórios);

    // Laço de entrada: cadastro dos territórios usando ponteiros
    for (int i = 0; i < quantidadeTerritórios; i++) {
        // Passa o ponteiro para cada território usando aritmética de ponteiros
        cadastrarTerritorio(territorios + i, i + 1);
    }

    // Exibição inicial de todos os territórios cadastrados
    exibirTodosTerritórios(territorios, quantidadeTerritórios);

    // Loop principal do jogo
    while (opcao != 3) {
        exibirMenu();
        scanf("%d", &opcao);
        limparBuffer();

        switch (opcao) {
            case 1:
                // Realizar ataque
                realizarAtaque(territorios, quantidadeTerritórios);
                pausar();
                break;

            case 2:
                // Exibir territórios
                exibirTodosTerritórios(territorios, quantidadeTerritórios);
                pausar();
                break;

            case 3:
                // Sair
                printf("\nEncerrando o jogo...\n");
                break;

            default:
                printf("\nOpcao invalida! Tente novamente.\n");
                pausar();
                break;
        }
    }

    // Libera a memória alocada antes de encerrar
    liberarMemoria(territorios);

    printf("\nObrigado por jogar WAR!\n");
    exibirSeparador();

    return 0;
}