#ifndef RANKING_H
#define RANKING_H

#define MAX_JOGADORES 10
#define TAMANHO_MAXIMO_NOME 255

#define COL_WIDTH_NOME 20
#define COL_WIDTH_PONTOS 10

void bubbleSort(int *pontuacao, char nomes[MAX_JOGADORES][TAMANHO_MAXIMO_NOME],int tamanho);
void ranking();
void inserir_pontuacao(char nome[], int pontos);

#endif /* RANKING_H */