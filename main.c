#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "Grafo.h"

int main(void) {
  int n = 6; // Número de vértices do grafo
  srand(time(NULL));

  struct grafo* g = cria_grafo(n, 0);

  // Gerar o grafo enquanto não for gerado um grafo válido, ou seja, um grafo que tenha arestas ligando o início (0) ao fim (n-1)
  do
    gera_grafo(g);
  while(!valida_grafo(g));
  
  // Imprimir o grafo gerado
  imprime_grafo(g);
  
  return 0;
}