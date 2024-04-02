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

  //listaPercurso[i][j], sendo [i] a área e [j] as salas escolhidas
  int listaPercurso[10][10];
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      listaPercurso[i][j] = -1;
    }
  }

  //Dificuldade do jogo
  int dificuldade = 2;

  //Calcula dificuldade do labirinto da área central
  int difLab = calc_dif_lab(dificuldade) + calc_dif_mapa(dificuldade);

  //Cria labirinto da Área Central
  insere_area(mapa, difLab);

  //Gera mapa: áreas filhas da Área Central
  gera_mapa(mapa, calc_dif_lab(dificuldade), calc_dif_mapa(dificuldade), dificuldade);

  explorar_mapa(mapa, listaPercurso, dificuldade);
  //explorar_labirinto((*mapa)->grafo);
  return 0;
}