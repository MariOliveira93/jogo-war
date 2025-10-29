/*
* main.c
 *
 * Arquivo principal do programa de cadastro de territórios do jogo War.
 *
 * Este programa permite o cadastro de territórios com suas respectivas
 * informações (nome, cor do exército e número de tropas) e exibe
 * os dados cadastrados ao final.
 *
 * Autor: [Seu Nome]
 * Data: [Data Atual]
 * Versão: 1.0
 */

#include <stdio.h>
#include "../include/territorio.h"
#include "../include/utils.h"

/*
 * Função Principal
 *
 * Gerencia o fluxo de execução do programa:
 * 1. Exibe o cabeçalho
 * 2. Realiza o cadastro de todos os territórios
 * 3. Exibe os territórios cadastrados
 */
int main(void) {
    // Declaração do vetor de structs para armazenar os territórios
    Territorio territorios[TOTAL_TERRITORIOS];

    // Exibe o cabeçalho do programa
    exibirCabecalho();

    printf("\nVoce cadastrara %d territorios.\n", TOTAL_TERRITORIOS);

    // Laço de entrada: cadastro dos territórios
    for (int i = 0; i < TOTAL_TERRITORIOS; i++) {
        cadastrarTerritorio(&territorios[i], i + 1);
    }

    // Exibição de todos os territórios cadastrados
    exibirTodosTerritórios(territorios, TOTAL_TERRITORIOS);

    printf("\nCadastro concluido com sucesso!\n");

    return 0;
}