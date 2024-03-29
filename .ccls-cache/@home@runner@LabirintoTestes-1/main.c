#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Grafo.h"
#include "ArvoreBinaria.h"
#include "Area.h"
#include "ArvoreBinaria.h"
#include "Mapa.h"
#include "Jogo.h"
#include "Jogador.h"
int main(void) {
  
  //Inicializa mapa
  ArvBin* mapa = cria_ArvBin();

  //Dificuldade do jogo
  int dificuldade = 2;
  
  //Calcula dificuldade do labirinto da área central
  int difLab = calc_dif_lab(2) + calc_dif_mapa(2);

  //Cria labirinto da Área Central
  insere_area(mapa, difLab);
  //Gera mapa: áreas filhas da Área Central
  gera_mapa(mapa, calc_dif_mapa(2), difLab-1);

  preOrdem_ArvBin(mapa);
  explorar_labirinto((*mapa)->grafo);
  return 0;
}