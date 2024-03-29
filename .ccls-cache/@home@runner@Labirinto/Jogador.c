#include <stdio.h>
#include <stdlib.h>
#include "Jogador.h"
#include "Jogo.h"

//Função para percorrer o labirinto.
void explorar_labirinto(Grafo *g) {
  //Vértice 0 sempre é o início do labirinto.
  int atual = 0;
  char escolha;
  //Lista de vértices visitados.
  int lista[15] = {-1};

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
}