#include <stdio.h>
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

int imprime_portas(int qtd) {
  for(int i = 0; i < qtd; i++){
    printf("   _________     ");
  }
  printf("\n");
  for(int i = 0; i < qtd; i++){
    printf("  |  _____  |    ");
  }
  printf("\n");
  for(int i = 0; i < qtd; i++){
    printf("  | |  %c  | |    ", i+65);
  }
  printf("\n");
  for(int i = 0; i < qtd; i++){
    printf("  | |_____| |    ");
  }
  printf("\n");
  for(int i = 0; i < qtd; i++){
    printf("  |       o |    ");
  }
  printf("\n");
  for(int i = 0; i < qtd; i++){
    printf("  |         |    ");
  }
  printf("\n");
  for(int i = 0; i < qtd; i++){
    printf("  |_________|    ");
  }
  printf("\n");
}
