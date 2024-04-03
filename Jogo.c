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
  for(int i = 0; i < areaAtual; i++){
    printf("Área %d: ", i+1);
    for(int j = 0; listaPercurso[i][j] != -1; j++)
    {
      printf("Sala %d -> ", listaPercurso[i][j]);
    }
    printf("FIM DA ÁREA\n\n");
  }
}

int eh_ultima_area(int dificuldade, int area_atual) {
  if(dificuldade == 1) {
    if(area_atual == 4) return 1;
  } else if (dificuldade == 2) {
    if(area_atual == 5) return 1;
  } else if (dificuldade == 3) {
    if(area_atual == 6) return 1;
  }
  return 0;
}

void imprime_mensagem_area(int areaAtual, int ehUltimaArea) {
  printf("\n\n======================================\n                ÁREA %d\n======================================\n\n", areaAtual);
  if(areaAtual == 1) {
    printf("Bem vindo à Primeira Área do Labirinto!\n\nA partir de agora, você enfrentará desafios que nunca imaginou... \nBoa sorte!\n\n");
  } else if (ehUltimaArea == 1) {
    printf("Parabéns, Guerreiro! \n\nVocê chegou à última área do labirinto.\nAgora, você precisa enfrentar o desafio final para ganhar sua liberdade.\n\nPorém, as regras agora são mais complexas...\nAchou que seria tão fácil? Ha Ha Ha\n\nVocê começa essa etapa com 3 pontos de vida. Cada vez que entrar em uma sala sem saída, volta ao ponto de partida e perde 1 ponto de vida.\nSe você perder todos os pontos de vida, você perde o jogo. SIMPLES!\n\nBoa sorte, Guerreiro, te vejo do outro lado!\n\n");
  }else {
    printf("Bem vindo à Área %d do Labirinto!\nVocê irá encontrar cada vez mais perigos conforme avança...\nBoa sorte!\n\n", areaAtual);
  }
}

void imprime_mensagem_derrota(){
  printf("Você perdeu todos os seus pontos de vida. Esse foi o seu último erro... VOCÊ PERDEU!");
  printf("===========================\n         GAME OVER         \n===========================\n\n");
}

void imprime_mensagem_vitoria(){
  printf("Parabéns, Guerreiro!\nVocê conseguiu superar um desafio que até mesmo os Deuses temem!\nGuerreiro, você está livre do Labirinto!!\n\n===========================\n    VOCÊ VENCEU O JOGO!\n===========================\n");
}

int calcula_pontuacao(int tempoDeJogoSeg, int pontosDeVida, int dificuldade) {
  //Pontuação = (5 minutos - Tempo de Jogo) + (Pontos de Vida * 50)
  int pontuacaoTotal = 0;
  int pontuacaoTempo = 0;
  
  if(tempoDeJogoSeg < 300) {
    pontuacaoTempo = 300 - tempoDeJogoSeg;
  }

  pontuacaoTotal = pontuacaoTempo + (pontosDeVida * 50);

  if (dificuldade == 2) {
    pontuacaoTotal += 150;
  } else if (dificuldade == 3) {
    pontuacaoTotal *= 3;
  }
  return pontuacaoTotal;
}

int calcula_tempo_de_jogo(int tempoDeJogoSeg[6]){
  int tempoTotal = 0;

  for(int i = 0; i < 6; i++){
    tempoTotal += tempoDeJogoSeg[i];
  }

  return tempoTotal;
}

void imprime_mensagem_pontuacao(int pontuacao) {
  printf("PONTUACAO FINAL: %d\n", pontuacao);
}