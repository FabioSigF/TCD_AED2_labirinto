#ifndef JOGO_H
#define JOGO_H
#include "Grafo.h"

int calc_dif_lab(int dificuldade);
int calc_dif_lab_centro(int dificuldade);
int calc_dif_mapa(int dificuldade);
int imprime_portas(int qtd);
int identifica_area(Grafo *g, int dificuldade);
void imprimir_percurso(int listaPercurso[10][10], int listaArea[15], int areaAtual);
int eh_ultima_area(int dificuldade, int area_atual);
void imprime_mensagem_area(int areaAtual, int ehUltimaArea);
void imprime_mensagem_derrota();
void imprime_mensagem_vitoria();
int calcula_pontuacao(int tempoDeJogoSeg, int pontosDeVida, int dificuldade);
int calcula_tempo_de_jogo(int tempoDeJogoSeg[6]);
void imprime_mensagem_pontuacao(int pontuacao);
#endif