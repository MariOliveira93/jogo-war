/*
 * territorio.c
 *
 * Implementação das funções relacionadas ao gerenciamento de territórios.
 */

#include <stdio.h>
#include <string.h>
#include "../include/territorio.h"
#include "../include/utils.h"

/*
 * Implementação: cadastrarTerritorio
 *
 * Solicita ao usuário as informações do território e preenche a struct.
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
 * Exibe as informações de um território individual.
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
 * Percorre o array de territórios e exibe cada um deles.
 */
void exibirTodosTerritórios(const Territorio territorios[], int quantidade) {
    printf("\n");
    exibirSeparador();
    printf("        TERRITORIOS CADASTRADOS              \n");
    exibirSeparador();

    // Laço para percorrer todos os territórios
    for (int i = 0; i < quantidade; i++) {
        exibirTerritorio(&territorios[i], i + 1);
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