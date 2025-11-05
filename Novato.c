#include <stdio.h>
#include <string.h>

// Definição da struct Territorio
// Armazena informações sobre cada território: nome, cor do exército e número de tropas
typedef struct {
    char nome[30];   // Nome do território
    char cor[10];    // Cor do exército
    int tropas;      // Número de tropas presentes
} Territorio;

int main() {
    Territorio territorios[5];  // Vetor para armazenar 5 territórios
    int i;

    printf("=== Cadastro de Territorios ===\n\n");

    // Laço para entrada de dados dos territórios
    for (i = 0; i < 5; i++) {
        printf("Territorio %d:\n", i + 1);

        printf("Nome: ");
        scanf(" %[^\n]", territorios[i].nome);  // Lê o nome com espaços

        printf("Cor do exército: ");
        scanf(" %s", territorios[i].cor);      // Lê a cor (uma palavra)

        printf("Número de tropas: ");
        scanf("%d", &territorios[i].tropas);   // Lê o número de tropas

        printf("\n"); // Linha em branco para separar cadastros
    }

    // Exibição dos dados cadastrados
    printf("=== Territorios Cadastrados ===\n");
    for (i = 0; i < 5; i++) {
        printf("Territorio %d:\n", i + 1);
        printf("Nome: %s\n", territorios[i].nome);
        printf("Cor do exército: %s\n", territorios[i].cor);
        printf("Número de tropas: %d\n", territorios[i].tropas);
        printf("\n");
    }

    return 0;
}
