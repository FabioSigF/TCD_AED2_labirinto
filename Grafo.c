#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>
#include "Grafo.h"

struct grafo{
    int eh_ponderado; // Sim 1 Não 0
    int nro_vertices; // Número de vértices do grafo
    int grau_max; //Quantidade máxima de arestas que podem sair dos vértices
    int** arestas; // Lista de adjacências: arestas[i][j] = k -> existe aresta de i para k. j é o índice do item na lista
    float** pesos; // Lista de peso da aresta: pesos[i][j] = k -> existe aresta partindo de i. O índice na lista é j (mesmo da lista de arestas). k é peso. Ex: arestas[i][j] = k. peso[i][j] = k2.
    int* grau; // quantidade de arestas que o vértice possui
};
//oifabo
Grafo* cria_grafo(int nro_vertices, int eh_ponderado){
    Grafo *gr;
    gr = (Grafo*) malloc(sizeof(struct grafo));
    if(gr != NULL){
        int i;
        gr->nro_vertices = nro_vertices;
        gr->grau_max = nro_vertices-1;
        gr->eh_ponderado = (eh_ponderado != 0)?1:0;
        gr->grau = (int*) calloc(nro_vertices,sizeof(int));

        gr->arestas = (int**) malloc(nro_vertices * sizeof(int*));
        for(i=0; i<nro_vertices; i++)
            gr->arestas[i] = (int*) malloc(gr->grau_max * sizeof(int));

        if(gr->eh_ponderado){
            gr->pesos = (float**) malloc(nro_vertices * sizeof(float*));
            for(i=0; i<nro_vertices; i++)
                gr->pesos[i] = (float*) malloc(gr->grau_max * sizeof(float));
        }

    }
    return gr;
}

//Verifica se existem arestas repetidas no grafo
bool aresta_existe(struct grafo* gr, int u, int v) {
  int cont = 0;
  
  if(gr->arestas[u][v] == 1 || gr->arestas[v][u] == 1) { 
    return true;
  }
  else {
    for(int i = 0; i < gr->grau[u]; i++){
      if(gr->arestas[u][i] == v) {
        return true;
      }
    }  
  }
  return false;
}

//Constrói o grafo
void gera_grafo(Grafo *gr) {
  srand(time(NULL));
  
  for (int i = 0; i < gr->nro_vertices; i++) {
      //número aleatório para definir a quantidade de arestas
      int num_arestas = rand() % (gr->nro_vertices) - 1;
      //precisa ter ao menos 1 aresta por vértice
      if(num_arestas <= 0)
        num_arestas = 1;
      while (num_arestas > 0) {
          //escolhe um vértice aleatório para fazer ligação
          int v = rand() % gr->nro_vertices;
          //verifica se a aresta já existe
          if (i != v && !aresta_existe(gr, i, v)){
            insereAresta(gr, i, v, 1, 0);
            num_arestas--;
          }
      }
  }

}

void libera_grafo(Grafo* gr){
    if(gr != NULL){
        int i;
        for(i=0; i<gr->nro_vertices; i++)
            free(gr->arestas[i]);
        free(gr->arestas);

        if(gr->eh_ponderado){
            for(i=0; i<gr->nro_vertices; i++)
                free(gr->pesos[i]);
            free(gr->pesos);
        }
        free(gr->grau);
        free(gr);
    }
}

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso){
    if(gr == NULL)
        return 0;
    if(gr->grau[orig] >= gr->grau_max)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    gr->arestas[orig][gr->grau[orig]] = dest;
    if(gr->eh_ponderado)
        gr->pesos[orig][gr->grau[orig]] = peso;
    gr->grau[orig]++;

    if(eh_digrafo == 0)
        insereAresta(gr,dest,orig,1,peso);
    return 1;
}

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo){
    if(gr == NULL)
        return 0;
    if(orig < 0 || orig >= gr->nro_vertices)
        return 0;
    if(dest < 0 || dest >= gr->nro_vertices)
        return 0;

    int i = 0;
    while(i<gr->grau[orig] && gr->arestas[orig][i] != dest)
        i++;
    if(i == gr->grau[orig])//elemento nao encontrado
        return 0;
    gr->grau[orig]--;
    gr->arestas[orig][i] = gr->arestas[orig][gr->grau[orig]];
    if(gr->eh_ponderado)
        gr->pesos[orig][i] = gr->pesos[orig][gr->grau[orig]];
    if(eh_digrafo == 0)
        removeAresta(gr,dest,orig,1);
    return 1;
}

void imprime_grafo(Grafo *gr){
    if(gr == NULL)
        return;

    int i, j;
    for(i=0; i < gr->nro_vertices; i++){
        printf("%d: ", i);
        for(j=0; j < gr->grau[i]; j++){
            if(gr->eh_ponderado)
                printf("%d(%.2f), ", gr->arestas[i][j], gr->pesos[i][j]);
            else
                printf("%d, ", gr->arestas[i][j]);
        }
        printf("\n");
    }
}

void buscaProfundidade(Grafo *gr, int vertice, bool aresta_de_zero[], bool *eh_valido, bool *visitados){

    if(visitados[vertice] != true) {      
      for(int i=0; i< gr->grau[vertice]; i++){
        if(gr->arestas[vertice][i] != gr->nro_vertices -1)
        { 
            visitados[vertice] = true;
            buscaProfundidade(gr,gr->arestas[vertice][i],aresta_de_zero, eh_valido, visitados);
        }
        else
            *eh_valido = true;
      } 
    }
}

//Faz a validação do grafo para ver se existem arestas que ligam o vértice 0 ao último vértice
bool valida_grafo(Grafo *gr){
    //vértices que foram visitados
    bool visitados[100] = {false};
    //vértices que possuem conexão com o vértice 0
    bool aresta_de_zero[gr->nro_vertices];
    //dirá se o grafo é válido ou não
    bool eh_valido = false;

    for(int i = 0; i < gr->nro_vertices; i++)
      aresta_de_zero[i]  = false;
  
    buscaProfundidade(gr,0,aresta_de_zero, &eh_valido, &visitados);

    return eh_valido;
}