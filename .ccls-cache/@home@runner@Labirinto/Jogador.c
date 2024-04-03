#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Jogador.h"
#include "Jogo.h"
#include "Auxiliar.h"

//Função para percorrer o labirinto.
void explorar_labirinto(Grafo *g, int listaPercurso[10][10], int dificuldade, int tempoDeJogoSeg[6]) {
  //Vértice 0 sempre é o início do labirinto.
  int salaAtual = 0;
  int areaAtual = identifica_area(g, dificuldade);
  
  //Verifica se a área atual é a Área Central
  int ehUltimaArea = eh_ultima_area(dificuldade, areaAtual);

  int contador = 3;//contador para pontuação do jogador na última área
  
  char escolha;
  //Lista de vértices visitados.
  int lista[15];
  for(int i = 0; i< 15; i++){
    lista[i] = -1;
  }
  //Tempo de início da área
  time_t inicio, fim;
  time(&inicio);
  float tempoTotal;

  int pontuacao = 0;
  
  imprime_mensagem_area(areaAtual, ehUltimaArea);
  
  do{
    lista[salaAtual] = 1;  
    printf("Você está na Sala %d do Labirinto.\nPara qual porta deseja prosseguir?\n", salaAtual);
    imprime_portas(g->grau[salaAtual]); 
    printf("\nResposta = ");
    scanf("%c", &escolha);
    getchar();
    printf("\nAbrindo porta...\n\n");

    salaAtual = g->arestas[salaAtual][escolha-65];

    if(lista[salaAtual] == 1){
      printf("\nVocê chegou em um beco sem saída! Você será enviado para a sala inicial para tentar novamente.\n\n");
      for(int i = 0; i < 15; i++)
        lista[i] = -1;

      if(ehUltimaArea == 1) {
          contador--;
        if(contador > 0) { 
          printf("Com esse erro, você acaba de perder um ponto. Tome cuidado, agora te restam apenas %d pontos de vida.\n", contador);
        }
      }
      salaAtual = 0;
    }

  }while(salaAtual != g->nro_vertices - 1 && contador > 0);

  if(ehUltimaArea == 1) {
    
    time(&fim);
    if(contador > 0) { 
      imprime_mensagem_vitoria();
      tempoTotal = difftime(fim, inicio);
      tempoDeJogoSeg[areaAtual-1] = (int)tempoTotal;

      int tempoDeJogo = calcula_tempo_de_jogo(tempoDeJogoSeg);
      pontuacao = calcula_pontuacao(tempoDeJogo, contador, dificuldade);

      imprime_mensagem_pontuacao(pontuacao);
      //inserir pontuação no arquivo
    } else {
      imprime_mensagem_derrota();
      //Como ele perdeu, não pontua.
    }

    printf("\n\nPercurso final...\n\n");
    
  } else if (ehUltimaArea != 1) {
    printf("Parabéns! Você conseguiu avançar de fase.");
    printf("\n\nPercurso até agora...\n\n");
    time(&fim);
    //Calcula tempo de jogo da área
    tempoTotal = difftime(fim, inicio);
    tempoDeJogoSeg[areaAtual-1] = (int)tempoTotal;
  } 
  imprimir_percurso(listaPercurso, lista, areaAtual);

  print_transicao();
  system("clear");
  printf("\n\n");
}
//Pos ordem
void explorar_mapa(ArvBin *raiz, int listaPercurso[10][10], int dificuldade, int tempoDeJogoSeg[6]){
  if(raiz == NULL)
      return;
  if(*raiz != NULL){
      explorar_mapa(&((*raiz)->esq), listaPercurso, dificuldade, tempoDeJogoSeg);
      explorar_mapa(&((*raiz)->dir), listaPercurso, dificuldade, tempoDeJogoSeg);
      explorar_labirinto((*raiz)->grafo, listaPercurso, dificuldade, tempoDeJogoSeg);
  }
}