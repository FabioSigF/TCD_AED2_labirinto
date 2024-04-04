#include "ranking.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void bubbleSort(int *pontuacao, char nomes[MAX_JOGADORES][TAMANHO_MAXIMO_NOME],int tamanho) {
  int i;
  int trocou;

  do {
    trocou = 0;
    for (i = tamanho - 1; i > 0; i--) {
      if (pontuacao[i] > pontuacao[i - 1]) {
        int pAux;
        char nAux[TAMANHO_MAXIMO_NOME];
        pAux = pontuacao[i];
        strcpy(nAux, nomes[i]);
        pontuacao[i] = pontuacao[i - 1];
        strcpy(nomes[i], nomes[i - 1]);
        pontuacao[i - 1] = pAux;
        strcpy(nomes[i - 1], nAux);
        trocou = 1;
      }
    }
  } while (trocou);
}

void ranking() {
  printf("\n ######- Ranking de Jogadores -######\n\n");
  printf(" NOME - PONTOS \n\n");

  FILE *pont_arq;
  pont_arq = fopen("data.txt", "r");
  if (pont_arq == NULL) {
    printf("Erro ao abrir o arquivo.\n");
    return;
  }

  char nomes[MAX_JOGADORES][TAMANHO_MAXIMO_NOME];
  int pontuacoes[MAX_JOGADORES];
  int tamanho = 0;

  while (fscanf(pont_arq, "%s %d\n", nomes[tamanho], &pontuacoes[tamanho]) !=
             EOF &&
         tamanho < MAX_JOGADORES) {
    tamanho++;
  }

  fclose(pont_arq);

  bubbleSort(pontuacoes, nomes, tamanho);

  printf("Ranking:\n");
  for (int i = 0; i < tamanho; i++) {
    printf("%s %d\n", nomes[i], pontuacoes[i]);
  }
}
