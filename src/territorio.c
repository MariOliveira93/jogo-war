/*
 * territorio.c
 *
 * Implementação das funções relacionadas ao gerenciamento de territórios.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include "../include/territorio.h"
#include "../include/utils.h"

/*
 * Implementação: alocarTerritorios
 *
 * Utiliza calloc para alocar memória inicializada com zeros para os territórios.
 */
Territorio* alocarTerritorios(int quantidade) {
    // Aloca memória usando calloc (inicializa com zeros)
    Territorio *territorios = (Territorio*) calloc(quantidade, sizeof(Territorio));

    if (territorios == NULL) {
        printf("Erro: Falha na alocacao de memoria!\n");
        return NULL;
    }

    return territorios;
}

/*
 * Implementação: liberarMemoria
 *
 * Libera a memória alocada dinamicamente para evitar memory leaks.
 */
void liberarMemoria(Territorio *mapa) {
    if (mapa != NULL) {
        free(mapa);
        printf("\nMemoria liberada com sucesso!\n");
    }
}

/*
 * Implementação: cadastrarTerritorio
 *
 * Solicita ao usuário as informações do território e preenche a struct
 * através do ponteiro recebido.
 */
void cadastrarTerritorio(Territorio *territorio, int numero) {
    int tropasValidas = 0;

    printf("\n=== Cadastro do Territorio %d ===\n", numero);

    // Leitura do nome do território
    printf("Digite o nome do territorio: ");
    scanf(" %[^\n]", territorio->nome);

    // Leitura da cor do exército
    printf("Digite a cor do exercito: ");
    scanf(" %[^\n]", territorio->cor);

    // Leitura e validação do número de tropas
    while (!tropasValidas) {
        printf("Digite o numero de tropas: ");
        scanf("%d", &territorio->tropas);

        if (validarTropas(territorio->tropas)) {
            tropasValidas = 1;
        } else {
            printf("Erro: O numero de tropas deve ser positivo!\n");
        }
    }

    limparBuffer(); // Limpa o buffer após as leituras
}

/*
 * Implementação: exibirTerritorio
 *
 * Acessa os dados do território através do ponteiro e exibe formatado.
 */
void exibirTerritorio(const Territorio *territorio, int numero) {
    printf("\nTerritorio %d:\n", numero);
    printf("  Nome: %s\n", territorio->nome);
    printf("  Cor do Exercito: %s\n", territorio->cor);
    printf("  Tropas: %d\n", territorio->tropas);
}

/*
 * Implementação: exibirTodosTerritórios
 *
 * Percorre o array de territórios usando aritmética de ponteiros.
 */
void exibirTodosTerritórios(const Territorio *territorios, int quantidade) {
    printf("\n");
    exibirSeparador();
    printf("        TERRITORIOS CADASTRADOS              \n");
    exibirSeparador();

    // Laço para percorrer todos os territórios usando ponteiros
    for (int i = 0; i < quantidade; i++) {
        // Acessa o território através de aritmética de ponteiros
        exibirTerritorio(territorios + i, i + 1);
    }

    printf("\n");
    exibirSeparador();
}

/*
 * Implementação: validarTropas
 *
 * Verifica se o número de tropas é válido (maior que zero).
 */
int validarTropas(int tropas) {
    return tropas > 0;
}

/*
 * Implementação: validarAtaque
 *
 * Valida se o ataque pode ser realizado conforme as regras do jogo.
 */
int validarAtaque(const Territorio *atacante, const Territorio *defensor) {
    // Verifica se o atacante tem tropas suficientes (precisa deixar pelo menos 1)
    if (atacante->tropas <= 1) {
        printf("Erro: O territorio atacante precisa ter mais de 1 tropa!\n");
        return 0;
    }

    // Verifica se os territórios pertencem a exércitos diferentes
    if (strcmp(atacante->cor, defensor->cor) == 0) {
        printf("Erro: Nao e possivel atacar um territorio do mesmo exercito!\n");
        return 0;
    }

    return 1;
}

/*
 * Implementação: atacar
 *
 * Simula um ataque entre territórios usando dados aleatórios (1-6).
 * Utiliza ponteiros para modificar diretamente os dados dos territórios.
 */
void atacar(Territorio *atacante, Territorio *defensor) {
    // Valida se o ataque é possível
    if (!validarAtaque(atacante, defensor)) {
        return;
    }

    printf("\n");
    exibirSeparador();
    printf("           SIMULACAO DE ATAQUE                \n");
    exibirSeparador();

    printf("\nAtacante: %s (%s) com %d tropas\n",
           atacante->nome, atacante->cor, atacante->tropas);
    printf("Defensor: %s (%s) com %d tropas\n",
           defensor->nome, defensor->cor, defensor->tropas);

    // Simula rolagem de dados (1-6) para cada lado
    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;

    printf("\nRolagem de dados:\n");
    printf("  Atacante: %d\n", dadoAtacante);
    printf("  Defensor: %d\n", dadoDefensor);

    // Determina o resultado do ataque
    if (dadoAtacante > dadoDefensor) {
        printf("\n>>> VITORIA DO ATACANTE! <<<\n");

        // Calcula tropas transferidas (metade das tropas do atacante, arredondado para baixo)
        int tropasTransferidas = atacante->tropas / 2;

        printf("\nO territorio %s foi conquistado!\n", defensor->nome);
        printf("Tropas transferidas: %d\n", tropasTransferidas);

        // Atualiza o defensor: transfere a cor e as tropas
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = tropasTransferidas;

        // Atualiza o atacante: reduz as tropas transferidas
        atacante->tropas -= tropasTransferidas;

    } else {
        printf("\n>>> VITORIA DO DEFENSOR! <<<\n");
        printf("\nO ataque foi repelido!\n");

        // Atacante perde uma tropa
        atacante->tropas--;
        printf("O atacante perdeu 1 tropa.\n");
    }

    // Exibe o estado final dos territórios
    printf("\n--- Estado apos o ataque ---\n");
    printf("Atacante %s: %d tropas\n", atacante->nome, atacante->tropas);
    printf("Defensor %s: %d tropas (%s)\n",
           defensor->nome, defensor->tropas, defensor->cor);

    exibirSeparador();
}