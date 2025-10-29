/*
 * missao.h
 *
 * Header file contendo as declarações das funções relacionadas
 * ao sistema de missões estratégicas do jogo.
 */

#ifndef MISSAO_H
#define MISSAO_H

#include "jogador.h"
#include "territorio.h"

// Número de missões disponíveis
#define TOTAL_MISSOES 7

/*
 * Função: obterMissoes
 *
 * Retorna um ponteiro para o array de strings contendo as missões disponíveis.
 *
 * Retorno: ponteiro para array de strings com as missões
 */
const char** obterMissoes(void);

/*
 * Função: atribuirMissao
 *
 * Sorteia e atribui uma missão aleatória para um jogador.
 * Utiliza malloc para alocar memória para a string da missão.
 * A missão é copiada por referência para o jogador.
 *
 * Parâmetros:
 *   - jogador: ponteiro para o jogador que receberá a missão (passagem por referência)
 *   - missoes: array de strings contendo as missões disponíveis
 *   - totalMissoes: número total de missões disponíveis
 *
 * Retorno: void
 */
void atribuirMissao(Jogador *jogador, const char *missoes[], int totalMissoes);

/*
 * Função: exibirMissao
 *
 * Exibe a missão de um jogador específico.
 * A missão é passada por valor (apenas leitura).
 *
 * Parâmetros:
 *   - missao: string contendo a missão (passagem por valor)
 *   - nomeJogador: nome do jogador
 *
 * Retorno: void
 */
void exibirMissao(const char *missao, const char *nomeJogador);

/*
 * Função: verificarMissao
 *
 * Verifica se a missão de um jogador foi cumprida analisando o mapa.
 * A verificação é feita silenciosamente durante o jogo.
 *
 * Parâmetros:
 *   - jogador: ponteiro para o jogador (passagem por referência para atualizar flag)
 *   - mapa: ponteiro para o array de territórios
 *   - tamanho: número de territórios no mapa
 *
 * Retorno: 1 se a missão foi cumprida, 0 caso contrário
 */
int verificarMissao(Jogador *jogador, const Territorio *mapa, int tamanho);

/*
 * Função: verificarTodosMissoes
 *
 * Verifica as missões de todos os jogadores e retorna o índice do vencedor.
 *
 * Parâmetros:
 *   - jogadores: ponteiro para o array de jogadores
 *   - quantidadeJogadores: número de jogadores
 *   - mapa: ponteiro para o array de territórios
 *   - tamanhoMapa: número de territórios
 *
 * Retorno: índice do jogador vencedor ou -1 se ninguém venceu ainda
 */
int verificarTodasMissoes(Jogador *jogadores, int quantidadeJogadores,
                          const Territorio *mapa, int tamanhoMapa);

#endif // MISSAO_H