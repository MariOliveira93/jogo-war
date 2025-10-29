/*
* utils.c
 *
 * Implementação das funções utilitárias do projeto.
 */

#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "../include/utils.h"

/*
 * Implementação: limparBuffer
 *
 * Descarta caracteres residuais no buffer de entrada até encontrar
 * uma nova linha ou EOF.
 */
void limparBuffer(void) {
    int c;
    while ((c = getchar()) != '\n' && c != EOF);
}

/*
 * Implementação: exibirCabecalho
 *
 * Exibe a tela inicial do programa com informações sobre o sistema.
 */
void exibirCabecalho(void) {
    exibirSeparador();
    printf("     BEM-VINDO AO JOGO DE WAR - FASE 2       \n");
    printf("      Sistema de Batalhas e Territorios      \n");
    exibirSeparador();
}

/*
 * Implementação: exibirSeparador
 *
 * Imprime uma linha de separação visual.
 */
void exibirSeparador(void) {
    printf("=============================================\n");
}

/*
 * Implementação: pausar
 *
 * Aguarda o usuário pressionar Enter para continuar.
 * Assume que o buffer já foi limpo anteriormente.
 */
void pausar(void) {
    printf("\nPressione ENTER para continuar...");
    getchar();
}

/*
 * Implementação: inicializarAleatoriedade
 *
 * Configura a seed do gerador de números aleatórios com o tempo atual,
 * garantindo resultados diferentes a cada execução.
 */
void inicializarAleatoriedade(void) {
    srand(time(NULL));
}

/*
 * Implementação: exibirMenu
 *
 * Mostra as opções disponíveis para o jogador.
 */
void exibirMenu(void) {
    printf("\n");
    exibirSeparador();
    printf("                  MENU                       \n");
    exibirSeparador();
    printf("  1 - Realizar ataque\n");
    printf("  2 - Exibir territorios\n");
    printf("  3 - Sair\n");
    exibirSeparador();
    printf("Escolha uma opcao: ");
}