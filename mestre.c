#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>

#define TOTAL_MISSOES 5
#define TOTAL_TERRITORIOS 5

// Estrutura que representa um território
typedef struct {
    char nome[30];
    char cor[10];
    int tropas;
} Territorio;

// Função para atribuir uma missão sorteada a um jogador
void atribuirMissao(char **destino, char *missoes[], int totalMissoes) {
    int indice = rand() % totalMissoes;
    *destino = (char *)malloc((strlen(missoes[indice]) + 1) * sizeof(char));
    strcpy(*destino, missoes[indice]);
}

// Função para exibir a missão de um jogador
void exibirMissao(char *missao) {
    printf("Sua missão estratégica: %s\n", missao);
}

// Função para simular ataque entre territórios
void atacar(Territorio *atacante, Territorio *defensor) {
    int dadoAtacante = (rand() % 6) + 1;
    int dadoDefensor = (rand() % 6) + 1;
    printf("%s (Atacante) rola %d vs %s (Defensor) rola %d\n", atacante->nome, dadoAtacante, defensor->nome, dadoDefensor);

    if (dadoAtacante > dadoDefensor) {
        int tropasTransferidas = atacante->tropas / 2;
        atacante->tropas -= tropasTransferidas;
        defensor->tropas += tropasTransferidas;
        strcpy(defensor->cor, atacante->cor);
        printf("Ataque bem-sucedido! %d tropas transferidas.\n", tropasTransferidas);
    } else {
        atacante->tropas--;
        printf("Ataque falhou! Atacante perde 1 tropa.\n");
    }
}

// Função simples para verificar se a missão foi cumprida
int verificarMissao(char *missao, Territorio *mapa, int tamanho) {
    // Exemplo simples: missão de conquistar 3 territórios com a mesma cor
    if (strstr(missao, "3 territorios") != NULL) {
        char corAtual[10];
        int count = 0;
        for (int i = 0; i < tamanho; i++) {
            if (i == 0) {
                strcpy(corAtual, mapa[i].cor);
                count = 1;
            } else if (strcmp(mapa[i].cor, corAtual) == 0) {
                count++;
                if (count >= 3)
                    return 1; // Missão cumprida
            } else {
                strcpy(corAtual, mapa[i].cor);
                count = 1;
            }
        }
    }
    // Outras missões podem ser implementadas de forma similar
    return 0;
}

// Função para exibir o mapa
void exibirMapa(Territorio *mapa, int tamanho) {
    printf("Mapa atual:\n");
    for (int i = 0; i < tamanho; i++) {
        printf("%s | Cor: %s | Tropas: %d\n", mapa[i].nome, mapa[i].cor, mapa[i].tropas);
    }
    printf("\n");
}

// Função para liberar toda a memória alocada
void liberarMemoria(char **missoes, Territorio *mapa) {
    free(*missoes);
    free(mapa);
}

int main() {
    srand(time(NULL));

    // Definindo missões
    char *missoes[TOTAL_MISSOES] = {
        "Conquistar 3 territorios seguidos",
        "Eliminar todas as tropas vermelhas",
        "Conquistar todos os territórios de cor azul",
        "Ter 10 tropas em um território",
        "Conquistar pelo menos 2 territórios inimigos"
    };

    char *missaoJogador = NULL;

    // Criando mapa dinamicamente
    Territorio *mapa = (Territorio *)malloc(TOTAL_TERRITORIOS * sizeof(Territorio));
    strcpy(mapa[0].nome, "Territorio A"); strcpy(mapa[0].cor, "vermelha"); mapa[0].tropas = 5;
    strcpy(mapa[1].nome, "Territorio B"); strcpy(mapa[1].cor, "azul"); mapa[1].tropas = 3;
    strcpy(mapa[2].nome, "Territorio C"); strcpy(mapa[2].cor, "vermelha"); mapa[2].tropas = 4;
    strcpy(mapa[3].nome, "Territorio D"); strcpy(mapa[3].cor, "verde"); mapa[3].tropas = 2;
    strcpy(mapa[4].nome, "Territorio E"); strcpy(mapa[4].cor, "azul"); mapa[4].tropas = 6;

    // Atribuindo missão ao jogador
    atribuirMissao(&missaoJogador, missoes, TOTAL_MISSOES);
    exibirMissao(missaoJogador);

    // Loop simples de jogadas
    int turno = 1;
    int vitoria = 0;
    while (!vitoria && turno <= 5) { // Limite de turnos para o exemplo
        printf("=== Turno %d ===\n", turno);
        exibirMapa(mapa, TOTAL_TERRITORIOS);

        // Exemplo de ataque aleatório
        atacar(&mapa[0], &mapa[1]); // jogador ataca território 1
        vitoria = verificarMissao(missaoJogador, mapa, TOTAL_TERRITORIOS);

        if (vitoria) {
            printf("Parabéns! Você cumpriu sua missão: %s\n", missaoJogador);
        }
        turno++;
    }

    if (!vitoria) {
        printf("Missão não cumprida após %d turnos.\n", turno-1);
    }

    // Liberar memória
    liberarMemoria(&missaoJogador, mapa);

    return 0;
}
