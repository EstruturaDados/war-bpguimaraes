#include <stdio.h>
#include <string.h>

// Definição da estrutura Territorio
// Esta struct agrupa informações relacionadas a um território
typedef struct {
    char nome[30];     // Nome do território
    char cor[10];      // Cor do exército
    int tropas;        // Quantidade de tropas
} Territorio;

int main() {
    Territorio territorios[5]; // Vetor para armazenar 5 territórios
    int i;

    printf("=== Cadastro de Territórios ===\n");

    // Entrada dos dados de 5 territórios
    for (i = 0; i < 5; i++) {
        printf("\n--- Território %d ---\n", i + 1);

        // Leitura do nome
        printf("Digite o nome do território: ");
        scanf(" %[^\n]", territorios[i].nome); // lê até o ENTER

        // Leitura da cor do exército
        printf("Digite a cor do exército: ");
        scanf(" %[^\n]", territorios[i].cor);

        // Leitura da quantidade de tropas
        printf("Digite a quantidade de tropas: ");
        scanf("%d", &territorios[i].tropas);
    }

    // Exibição dos dados cadastrados
    printf("\n=== Territórios Cadastrados ===\n");
    for (i = 0; i < 5; i++) {
        printf("\nTerritório %d\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Tropas: %d\n", territorios[i].tropas);
    }

    printf("\nCadastro concluído com sucesso!\n");

    return 0;
}
