/*
 * utils.h
 *
 * Header file contendo funções utilitárias para o projeto.
 */

#ifndef UTILS_H
#define UTILS_H

// Constante para o total de territórios do jogo
#define TOTAL_TERRITORIOS 5

/*
 * Função: limparBuffer
 *
 * Limpa o buffer de entrada para evitar problemas com scanf.
 *
 * Retorno: void
 */
void limparBuffer(void);

/*
 * Função: exibirCabecalho
 *
 * Exibe o cabeçalho inicial do programa.
 *
 * Retorno: void
 */
void exibirCabecalho(void);

/*
 * Função: exibirSeparador
 *
 * Exibe uma linha separadora para melhor formatação da saída.
 *
 * Retorno: void
 */
void exibirSeparador(void);

/*
 * Função: pausar
 *
 * Pausa a execução aguardando o usuário pressionar Enter.
 *
 * Retorno: void
 */
void pausar(void);

#endif // UTILS_H