// Para funções de entrada e saída, como "printf" e "scanf".
#include <stdio.h>
// Para funções de alocação de memória, como "malloc" e "free".
#include <stdlib.h>
// Para manipulação de strings, como "strcspn".
#include <string.h>
// Definição do Tipo Abstrato de Dados - Jogador
typedef struct {
    char nome[100];
    int jogos;
    int gols;
    int assistencias;
} Jogador;
/*
 * Lê os dados de n jogadores e armazena no vetor 'jogadores'.
 * Parâmetros:
 * - jogadores: ponteiro para o vetor de estruturas Jogador.
 * - n: número de jogadores a serem lidos.
*/
void lerJogadores(Jogador *jogadores, int n) {
    // Loop para fazer uma verificação dinamica do array
    for (int i = 0; i < n; i++) {
        printf("Jogador  %d", i + 1);
        printf("\nNome:");
        // Le o nome do jogador e armazena na estrutura
        fgets(jogadores[i].nome, sizeof(jogadores[i].nome), stdin);
        // remover o caractere de nova linha (\n) que "fgets" pode deixar no final da string
        jogadores[i].nome[strcspn(jogadores[i].nome, "\n")] = 0;
        printf("Saldo de - Jogos / Gols / Assistencias: \n");
        // Ler os 3 inteiros
        scanf("%d %d %d", &jogadores[i].jogos, &jogadores[i].gols, &jogadores[i].assistencias);
        // Consumir o caractere de nova linha que fica no buffer após a leitura dos inteiros
        getchar();
    }
}
/*
 * Identifica os jogadores com maior número de gols, assistências e jogos.
 * Imprime os respectivos nomes e valores.
*/
void informarMaioresSaldos(Jogador *jogadores, int n) {
    // Incializar as variaveis com zero para realizar a verificação na estratura condicional
    int maiorGoleadorIndex = 0;
    int melhorArmadorIndex = 0;
    int maiorParticipacaoIndex = 0;
    // Loop para realizar a condição com todos jogadores
    for (int i = 0; i < n; i++) {
        // Estrutura condicional, verifcar os maiores saldos
        if (jogadores[i].gols > jogadores[maiorGoleadorIndex].gols) {
            maiorGoleadorIndex = i;
        }
        if (jogadores[i].assistencias > jogadores[melhorArmadorIndex].assistencias) {
            melhorArmadorIndex = i;
        }
        if (jogadores[i].jogos > jogadores[maiorParticipacaoIndex].jogos) {
            maiorParticipacaoIndex = i;
        }
    }
    // Resultado encontrados
    printf("Maior Goleador: %s\nSaldo de Gols: %d\n", jogadores[maiorGoleadorIndex].nome, jogadores[maiorGoleadorIndex].gols);
    printf("Melhor Armador: %s\nSaldo de Assistencias: %d\n", jogadores[melhorArmadorIndex].nome, jogadores[melhorArmadorIndex].assistencias);
    printf("Maior Participacao: %s\nSaldo de Jogos: %d\n", jogadores[maiorParticipacaoIndex].nome, jogadores[maiorParticipacaoIndex].jogos);
}
/*
 * Função Principal - Onde será iniciado a execução
*/
int main() {
    int n;
    printf("Quantidade de jogadores:");
    // Ler numero de jogadores que deseja armazenar
    scanf("%d", &n);
    // Para consumir o newline(\n) após a leitura de n
    getchar();
    /*
     * Declarando um ponteiro chamado "jogadores" que irá apontar para um bloco de memória
     * que conterá múltiplas instâncias da estrutura Jogador.
     * O "malloc" é uma função da biblioteca stdlib.h que aloca um bloco de memória
     * do tamanho especificado e retorna um ponteiro para o início desse bloco.
     * O "sizeof(Jogador)" retorna o tamanho em bytes que uma única instância da
     * estrutura Jogador ocupa na memória.
     * O "n * sizeof(Jogador)" calcula o total de bytes que precisamos alocar,
     * resultando no total de bytes necessários para armazenar "n" jogadores
     * O "(Jogador *)" é para realizar o casting do malloc para o tipo de dado "Jogador"
    */
    Jogador *jogadores = (Jogador *)malloc(n * sizeof(Jogador));
    // Verificar se a alocação foi realizada
    if (jogadores == NULL) {
        fprintf(stderr, "Erro ao alocar memória.\n");
        return 1;
    }
    // Chamada das funções e passagem de parametnos
    lerJogadores(jogadores, n);
    informarMaioresSaldos(jogadores, n);
    // Liberar memoria
    free(jogadores);
    return 0;
}
