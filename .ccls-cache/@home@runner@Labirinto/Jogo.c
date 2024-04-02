#include <stdio.h>
#include "Jogo.h"

int calc_dif_lab(int dificuldade){
  //1 - Fácil; 2 - Médio; 3 - Difícil
  //Retorna a quantidade de vértices que o grafo inicial terá
  switch(dificuldade){
    case 1:
      return 3;
    case 2:
      return 4;
    case 3:
      return 5;
    default:
      return 0;
  }
}

int calc_dif_mapa(int dificuldade) {
  //1 - Fácil; 2 - Médio; 3 - Difícil
  //Retorna a quantidade de Áreas(nós) que o Mapa(árvore) terá, excluindo a raíz.
  switch(dificuldade){
    case 1:
      return 3;
    case 2:
      return 4;
    case 3:
      return 5;
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

int identifica_area(Grafo *g, int dificuldade) {
  int qtdVertices = g->nro_vertices;

  if(dificuldade == 1) {
    switch(qtdVertices) {
      case 3:
        return 1;
      case 4:
        return 2;
      case 5:
        return 3;
      case 6:
        return 4;
    }
  } else if (dificuldade == 2) {
    switch(qtdVertices) {
      case 4:
        return 1;
      case 5:
        return 2;
      case 6:
        return 3;
      case 7:
        return 4;
      case 8:
        return 5;
    } 
  }else if (dificuldade == 3) {
    switch(qtdVertices) {
      case 5:
        return 1;
      case 6:
        return 2;
      case 7:
        return 3;
      case 8:
        return 4;
      case 9:
        return 5;
      case 10:
        return 6;
    }
  }

  return -1;
}

void imprimir_percurso(int listaPercurso[10][10], int listaArea[15], int areaAtual){
  int cont = 0;
  for(int i = 0; i < 15; i++) {
    if(listaArea[i] == 1){
      listaPercurso[areaAtual-1][cont] = i;
      cont++;
    }
  }

  printf("\n\nPercurso até agora...\n\n");

  for(int i = 0; i < areaAtual; i++){
    printf("Área %d: ", i+1);
    for(int j = 0; listaPercurso[i][j] != -1; j++)
    {
      printf("Sala %d -> ", listaPercurso[i][j]);
    }
    printf("FIM DO LABIRINTO\n\n");
  }
}