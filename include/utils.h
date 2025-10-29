/*
 * utils.h
 *
 * Header file contendo funções utilitárias para o projeto.
 */

#ifndef UTILS_H
#define UTILS_H

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

/*
 * Função: inicializarAleatoriedade
 *
 * Inicializa o gerador de números aleatórios usando o tempo atual.
 * Deve ser chamada uma vez no início do programa.
 *
 * Retorno: void
 */
void inicializarAleatoriedade(void);

/*
 * Função: exibirMenu
 *
 * Exibe o menu principal do jogo com as opções disponíveis.
 *
 * Retorno: void
 */
void exibirMenu(void);

#endif // UTILS_H