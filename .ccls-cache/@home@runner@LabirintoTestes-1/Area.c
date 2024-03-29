#include "Grafo.h"
#include "Area.h"
#include "ArvoreBinaria.h"
#include "Jogo.h"

void insere_area(ArvBin *raiz, int qtdSalas){
  //De acordo com a dificuldade, retorna a quantidade de vértices do labirinto(grafo)
  Grafo *g;

  do { 
    g = cria_grafo(qtdSalas, 0);
    gera_grafo(g);
  }
  while(!valida_grafo(g));

  insere_ArvBin(raiz, g);
}