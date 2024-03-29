#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Grafo.h"
#include "ArvoreBinaria.h"
#include "Area.h"
#include "ArvoreBinaria.h"
#include "Mapa.h"
#include "Jogo.h"

int main(void) {

  ArvBin* mapa = cria_ArvBin();

  int dif = calc_dif_lab(2) + calc_dif_mapa(2);
  insere_area(mapa, dif);
  gera_mapa(mapa, calc_dif_mapa(2), dif-1);

  printf("Altura: %d", altura_ArvBin(mapa));

  return 0;
}