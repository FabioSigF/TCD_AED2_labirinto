#ifndef RANKING_H
#define RANKING_H

#define MAX_JOGADORES 10
#define TAMANHO_MAXIMO_NOME 255

void bubbleSort(int *pontuacao, char nomes[MAX_JOGADORES][TAMANHO_MAXIMO_NOME],int tamanho);
void ranking();

#endif /* RANKING_H */