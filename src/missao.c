/*
 * missao.c
 *
 * Implementação das funções relacionadas ao sistema de missões.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "../include/missao.h"
#include "../include/utils.h"

// Array estático com as missões disponíveis
static const char* missoes[TOTAL_MISSOES] = {
    "Conquistar 5 territorios com pelo menos 3 tropas cada",
    "Dominar 3 territorios seguidos (mesma cor)",
    "Eliminar todas as tropas de uma cor especifica (exceto a sua)",
    "Acumular 20 tropas no total em todos os seus territorios",
    "Conquistar pelo menos 4 territorios de cores diferentes",
    "Ter o territorio com maior numero de tropas no mapa",
    "Controlar mais da metade dos territorios do mapa"
};

/*
 * Implementação: obterMissoes
 *
 * Retorna o ponteiro para o array de missões.
 */
const char** obterMissoes(void) {
    return missoes;
}

/*
 * Implementação: atribuirMissao
 *
 * Sorteia uma missão aleatória e a atribui ao jogador usando malloc.
 * A missão é passada por referência (ponteiro) para o jogador.
 */
void atribuirMissao(Jogador *jogador, const char *missoes[], int totalMissoes) {
    // Sorteia um índice aleatório
    int indiceMissao = rand() % totalMissoes;

    // Aloca memória para a missão do jogador
    jogador->missao = (char*) malloc(TAM_MISSAO * sizeof(char));

    if (jogador->missao == NULL) {
        printf("Erro: Falha ao alocar memoria para a missao!\n");
        return;
    }

    // Copia a missão sorteada para o jogador usando strcpy (passagem por referência)
    strcpy(jogador->missao, missoes[indiceMissao]);

    printf("Missao atribuida para %s: %s\n", jogador->nome, jogador->missao);
}

/*
 * Implementação: exibirMissao
 *
 * Exibe a missão de forma formatada (passagem por valor - apenas leitura).
 */
void exibirMissao(const char *missao, const char *nomeJogador) {
    printf("\n");
    exibirSeparador();
    printf("       MISSAO DE %s        \n", nomeJogador);
    exibirSeparador();
    printf("\n%s\n\n", missao);
    exibirSeparador();
}

/*
 * Implementação: verificarMissao
 *
 * Implementa a lógica de verificação das missões.
 * Passagem por referência para atualizar o status do jogador.
 */
int verificarMissao(Jogador *jogador, const Territorio *mapa, int tamanho) {
    // Se já cumpriu, não precisa verificar novamente
    if (jogador->missaoCumprida) {
        return 1;
    }

    const char *corJogador = jogador->cor;
    const char *missao = jogador->missao;

    // Missão 1: Conquistar 5 territorios com pelo menos 3 tropas cada
    if (strstr(missao, "5 territorios com pelo menos 3 tropas") != NULL) {
        int territoriosValidos = 0;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, corJogador) == 0 && mapa[i].tropas >= 3) {
                territoriosValidos++;
            }
        }
        if (territoriosValidos >= 5) {
            jogador->missaoCumprida = 1;
            return 1;
        }
    }

    // Missão 2: Dominar 3 territorios seguidos
    if (strstr(missao, "3 territorios seguidos") != NULL) {
        int sequencia = 0;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, corJogador) == 0) {
                sequencia++;
                if (sequencia >= 3) {
                    jogador->missaoCumprida = 1;
                    return 1;
                }
            } else {
                sequencia = 0;
            }
        }
    }

    // Missão 3: Eliminar todas as tropas de uma cor (simplificado: verificar se existe alguma cor sem territórios)
    if (strstr(missao, "Eliminar todas as tropas de uma cor") != NULL) {
        // Verificação simplificada: se controla mais de 80% dos territórios
        int territoriosJogador = 0;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, corJogador) == 0) {
                territoriosJogador++;
            }
        }
        if (territoriosJogador >= (tamanho * 0.8)) {
            jogador->missaoCumprida = 1;
            return 1;
        }
    }

    // Missão 4: Acumular 20 tropas no total
    if (strstr(missao, "20 tropas no total") != NULL) {
        int totalTropas = 0;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, corJogador) == 0) {
                totalTropas += mapa[i].tropas;
            }
        }
        if (totalTropas >= 20) {
            jogador->missaoCumprida = 1;
            return 1;
        }
    }

    // Missão 5: Conquistar 4 territorios (simplificado)
    if (strstr(missao, "4 territorios de cores diferentes") != NULL) {
        int territoriosJogador = 0;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, corJogador) == 0) {
                territoriosJogador++;
            }
        }
        if (territoriosJogador >= 4) {
            jogador->missaoCumprida = 1;
            return 1;
        }
    }

    // Missão 6: Ter o territorio com maior número de tropas
    if (strstr(missao, "maior numero de tropas no mapa") != NULL) {
        int maiorTropas = 0;
        const char *corMaiorTropas = "";

        for (int i = 0; i < tamanho; i++) {
            if (mapa[i].tropas > maiorTropas) {
                maiorTropas = mapa[i].tropas;
                corMaiorTropas = mapa[i].cor;
            }
        }

        if (strcmp(corMaiorTropas, corJogador) == 0) {
            jogador->missaoCumprida = 1;
            return 1;
        }
    }

    // Missão 7: Controlar mais da metade dos territorios
    if (strstr(missao, "mais da metade dos territorios") != NULL) {
        int territoriosJogador = 0;
        for (int i = 0; i < tamanho; i++) {
            if (strcmp(mapa[i].cor, corJogador) == 0) {
                territoriosJogador++;
            }
        }
        if (territoriosJogador > (tamanho / 2)) {
            jogador->missaoCumprida = 1;
            return 1;
        }
    }

    return 0;
}

/*
 * Implementação: verificarTodasMissoes
 *
 * Verifica as missões de todos os jogadores e identifica vencedor.
 */
int verificarTodasMissoes(Jogador *jogadores, int quantidadeJogadores,
                          const Territorio *mapa, int tamanhoMapa) {
    for (int i = 0; i < quantidadeJogadores; i++) {
        if (verificarMissao(&jogadores[i], mapa, tamanhoMapa)) {
            return i; // Retorna o índice do vencedor
        }
    }
    return -1; // Ninguém venceu ainda
}