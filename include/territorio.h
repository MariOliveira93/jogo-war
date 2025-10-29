/*
 * territorio.h
 *
 * Header file contendo as definições da estrutura Territorio
 * e as declarações das funções relacionadas ao gerenciamento de territórios.
 */

#ifndef TERRITORIO_H
#define TERRITORIO_H

// Constantes relacionadas aos territórios
#define TAM_NOME 30
#define TAM_COR 10

/*
 * Struct: Territorio
 *
 * Estrutura que representa um território no jogo War.
 *
 * Campos:
 *   - nome: nome do território (até 30 caracteres)
 *   - cor: cor do exército que ocupa o território (até 10 caracteres)
 *   - tropas: quantidade de tropas estacionadas no território
 */
typedef struct {
    char nome[TAM_NOME];
    char cor[TAM_COR];
    int tropas;
} Territorio;

/*
 * Função: cadastrarTerritorio
 *
 * Realiza o cadastro de um território através da entrada do usuário.
 *
 * Parâmetros:
 *   - territorio: ponteiro para a struct Territorio que será preenchida
 *   - numero: número do território sendo cadastrado (para exibição)
 *
 * Retorno: void
 */
void cadastrarTerritorio(Territorio *territorio, int numero);

/*
 * Função: exibirTerritorio
 *
 * Exibe as informações de um território específico de forma formatada.
 *
 * Parâmetros:
 *   - territorio: ponteiro para a struct Territorio que será exibida
 *   - numero: número do território para identificação na listagem
 *
 * Retorno: void
 */
void exibirTerritorio(const Territorio *territorio, int numero);

/*
 * Função: exibirTodosTerritórios
 *
 * Exibe todos os territórios cadastrados em formato de lista.
 *
 * Parâmetros:
 *   - territorios: array de structs Territorio
 *   - quantidade: número de territórios no array
 *
 * Retorno: void
 */
void exibirTodosTerritórios(const Territorio territorios[], int quantidade);

/*
 * Função: validarTropas
 *
 * Valida se o número de tropas informado é válido (positivo).
 *
 * Parâmetros:
 *   - tropas: número de tropas a ser validado
 *
 * Retorno: 1 se válido, 0 se inválido
 */
int validarTropas(int tropas);

#endif // TERRITORIO_H