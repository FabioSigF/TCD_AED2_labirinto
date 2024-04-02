#include <stdio.h>
#include <stdlib.h>
#include "Jogador.h"
#include "Jogo.h"

//Função para percorrer o labirinto.
void explorar_labirinto(Grafo *g, int listaPercurso[10][10], int dificuldade) {
  //Vértice 0 sempre é o início do labirinto.
  int atual = 0;
  int areaAtual = identifica_area(g, dificuldade);
  char escolha;
  //Lista de vértices visitados.
  int lista[15];
  for(int i = 0; i< 15; i++){
    lista[i] = -1;
  }

  if(areaAtual == 1) {
    printf("Bem vindo à primeira área do labirinto! A partir de agora, você irá enfrentas desafios que nunca imaginou... Boa sorte!\n");
  } else {
    printf("Bem vindo à área %d do labirinto! Você irá encontrar cada vez mais perigos conforme avança no labirinto... Boa sorte!\n", areaAtual);
  }

  do{
    lista[atual] = 1;
    printf("Você está na Sala %d desse Labirinto. Para qual porta deseja prosseguir?\n", atual);
    imprime_portas(g->grau[atual]); 
    printf("Resposta = ");
    setbuf(stdin, NULL);
    scanf("%c", &escolha);
    getchar();
    setbuf(stdin, NULL);
    printf("Abrindo porta...\n");

    atual = g->arestas[atual][escolha-65];

    if(lista[atual] == 1){
      printf("Você chegou em um beco sem saída! Você será enviado para a sala inicial para tentar novamente.\n\n");
      for(int i = 0; i < 15; i++)
        lista[i] = -1;
      atual = 0;
    }

  }while(atual != g->nro_vertices - 1);


  printf("Parabéns! Você conseguiu sair do labirinto.\n");

  //Faz o tracking de qual foi o caminho do usuário
  imprimir_percurso(listaPercurso, lista, areaAtual);
}

void explorar_mapa(ArvBin *raiz, int listaPercurso[10][10], int dificuldade){
  if(raiz == NULL)
      return;
  if(*raiz != NULL){
      explorar_mapa(&((*raiz)->esq), listaPercurso, dificuldade);
      explorar_mapa(&((*raiz)->dir), listaPercurso, dificuldade);
      explorar_labirinto((*raiz)->grafo, listaPercurso, dificuldade);
  }
}