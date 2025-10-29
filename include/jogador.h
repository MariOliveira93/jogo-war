/*
 * jogador.h
 *
 * Header file contendo as definições da estrutura Jogador
 * e as declarações das funções relacionadas ao gerenciamento de jogadores.
 */

#ifndef JOGADOR_H
#define JOGADOR_H

#define TAM_NOME_JOGADOR 50
#define TAM_MISSAO 200

/*
 * Struct: Jogador
 *
 * Estrutura que representa um jogador no jogo War.
 *
 * Campos:
 *   - nome: nome do jogador (até 50 caracteres)
 *   - cor: cor do exército do jogador (até 10 caracteres)
 *   - missao: ponteiro para string contendo a missão do jogador
 *   - missaoCumprida: flag indicando se a missão foi cumprida (0 ou 1)
 */
typedef struct {
    char nome[TAM_NOME_JOGADOR];
    char cor[10];
    char *missao;
    int missaoCumprida;
} Jogador;

/*
 * Função: alocarJogadores
 *
 * Aloca dinamicamente memória para um vetor de jogadores.
 *
 * Parâmetros:
 *   - quantidade: número de jogadores a serem alocados
 *
 * Retorno: ponteiro para o vetor de jogadores alocado ou NULL em caso de erro
 */
Jogador* alocarJogadores(int quantidade);

/*
 * Função: liberarJogadores
 *
 * Libera a memória alocada dinamicamente para os jogadores,
 * incluindo as missões de cada jogador.
 *
 * Parâmetros:
 *   - jogadores: ponteiro para o vetor de jogadores
 *   - quantidade: número de jogadores
 *
 * Retorno: void
 */
void liberarJogadores(Jogador *jogadores, int quantidade);

/*
 * Função: cadastrarJogador
 *
 * Realiza o cadastro de um jogador através da entrada do usuário.
 *
 * Parâmetros:
 *   - jogador: ponteiro para a struct Jogador que será preenchida
 *   - numero: número do jogador sendo cadastrado (para exibição)
 *
 * Retorno: void
 */
void cadastrarJogador(Jogador *jogador, int numero);

/*
 * Função: exibirJogador
 *
 * Exibe as informações de um jogador de forma formatada.
 * A missão é passada por valor para exibição (não será modificada).
 *
 * Parâmetros:
 *   - jogador: ponteiro constante para a struct Jogador
 *   - numero: número do jogador para identificação
 *
 * Retorno: void
 */
void exibirJogador(const Jogador *jogador, int numero);

/*
 * Função: exibirTodosJogadores
 *
 * Exibe todos os jogadores cadastrados.
 *
 * Parâmetros:
 *   - jogadores: ponteiro para o array de jogadores
 *   - quantidade: número de jogadores
 *
 * Retorno: void
 */
void exibirTodosJogadores(const Jogador *jogadores, int quantidade);

#endif // JOGADOR_H