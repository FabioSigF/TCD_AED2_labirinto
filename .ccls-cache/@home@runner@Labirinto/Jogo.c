#include "Jogo.h"

int calc_dif_lab(int dificuldade){
  //1 - Fácil; 2 - Médio; 3 - Difícil
  //Retorna a quantidade de vértices que cada grafo terá
  switch(dificuldade){
    case 1:
      return 5;
    case 2:
      return 7;
    case 3:
      return 9;
    default:
      return 0;
  }
}

int calc_dif_lab_centro(int dificuldade){
  //1 - Fácil; 2 - Médio; 3 - Difícil
  //Retorna a quantidade de vértices que cada grafo terá para o labirinto da área central.
  switch(dificuldade){
    case 1:
      return 10;
    case 2:
      return 11;
    case 3:
      return 13;
    default:
      return 0;
  }
}

int calc_dif_mapa(int dificuldade) {
  //1 - Fácil; 2 - Médio; 3 - Difícil
  //Retorna a altura que a árvore deve ter, sem contar com a raiz
  switch(dificuldade){
    case 1:
      return 1;
    case 2:
      return 2;
    case 3:
      return 3;
    default:
      return 0;
  }
}