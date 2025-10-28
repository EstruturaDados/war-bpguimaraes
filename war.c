#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

// Estrutura do território
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Protótipos das funções
Territorio* cadastrarTerritorios(int n);
void exibirTerritorios(Territorio* mapa, int n);
void atacar(Territorio* atacante, Territorio* defensor);
void liberarMemoria(Territorio* mapa);

int main() {
    srand(time(NULL)); // garante aleatoriedade nos dados

    int n, i, opcao;
    printf("=== WAR ESTRUTURADO - NIVEL AVENTUREIRO ===\n");
    printf("Digite o numero de territorios do mapa: ");
    scanf("%d", &n);
    getchar(); // limpar buffer

    // Alocação dinâmica dos territórios
    Territorio* mapa = (Territorio*) calloc(n, sizeof(Territorio));
    if (mapa == NULL) {
        printf("Erro ao alocar memoria.\n");
        return 1;
    }

    // Cadastro dos territórios
    for (i = 0; i < n; i++) {
        printf("\n--- Cadastro do Territorio %d ---\n", i + 1);
        printf("Nome: ");
        scanf("%s", mapa[i].nome);
        printf("Cor do exercito: ");
        scanf("%s", mapa[i].cor);
        printf("Quantidade de tropas: ");
        scanf("%d", &mapa[i].tropas);
    }

    do {
        printf("\n===== MENU DE ACOES =====\n");
        printf("1. Exibir territorios\n");
        printf("2. Realizar ataque\n");
        printf("0. Sair\n");
        printf("Escolha uma opcao: ");
        scanf("%d", &opcao);

        switch (opcao) {
            case 1:
                exibirTerritorios(mapa, n);
                break;
            case 2: {
                int atq, def;
                exibirTerritorios(mapa, n);

                printf("\nEscolha o numero do territorio ATACANTE: ");
                scanf("%d", &atq);
                printf("Escolha o numero do territorio DEFENSOR: ");
                scanf("%d", &def);

                // Validações básicas
                if (atq < 1 || atq > n || def < 1 || def > n) {
                    printf("Territorios invalidos!\n");
                    break;
                }

                if (strcmp(mapa[atq - 1].cor, mapa[def - 1].cor) == 0) {
                    printf("Nao e permitido atacar um territorio da mesma cor!\n");
                    break;
                }

                atacar(&mapa[atq - 1], &mapa[def - 1]);
                exibirTerritorios(mapa, n);
                break;
            }
            case 0:
                printf("Encerrando o jogo...\n");
                break;
            default:
                printf("Opcao invalida!\n");
        }
    } while (opcao != 0);

    liberarMemoria(mapa);
    return 0;
}

// -------------------------------------------------------------
// Exibe todos os territórios cadastrados
void exibirTerritorios(Territorio* mapa, int n) {
    printf("\n=== TERRITORIOS CADASTRADOS ===\n");
    for (int i = 0; i < n; i++) {
        printf("%d. Nome: %s | Cor: %s | Tropas: %d\n",
               i + 1, mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
}

// -------------------------------------------------------------
// Função de ataque: simula uma batalha entre dois territórios
void atacar(Territorio* atacante, Territorio* defensor) {
    printf("\n--- ATAQUE ENTRE TERRITORIOS ---\n");
    printf("%s (%s) ATACA %s (%s)!\n",
           atacante->nome, atacante->cor, defensor->nome, defensor->cor);

    int dadoAtq = (rand() % 6) + 1;
    int dadoDef = (rand() % 6) + 1;

    printf("Dado do atacante: %d\n", dadoAtq);
    printf("Dado do defensor: %d\n", dadoDef);

    if (dadoAtq > dadoDef) {
        printf(">>> O atacante venceu a batalha!\n");
        strcpy(defensor->cor, atacante->cor);
        defensor->tropas = atacante->tropas / 2; // transfere metade das tropas
        atacante->tropas /= 2; // atacante mantém metade
    } else {
        printf(">>> O defensor resistiu ao ataque!\n");
        atacante->tropas -= 1; // atacante perde uma tropa
        if (atacante->tropas < 0)
            atacante->tropas = 0;
    }
}

// -------------------------------------------------------------
// Libera memória alocada dinamicamente
void liberarMemoria(Territorio* mapa) {
    free(mapa);
    printf("\nMemoria liberada com sucesso.\n");
}
