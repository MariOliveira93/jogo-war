/*
* utils.c
 *
 * Implementação das funções utilitárias do projeto.
 */

#include <stdio.h>
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
    printf("     BEM-VINDO AO JOGO DE WAR - FASE 1       \n");
    printf("     Sistema de Cadastro de Territorios      \n");
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
 */
void pausar(void) {
    printf("\nPressione ENTER para continuar...");
    limparBuffer();
    getchar();
}