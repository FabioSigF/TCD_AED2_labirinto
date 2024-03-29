#ifndef GRAFO_H
#define GRAFO_H
#include <stdbool.h>

struct grafo{
    int eh_ponderado; // Sim 1 Não 0
    int nro_vertices; // Número de vértices do grafo
    int grau_max; //Quantidade máxima de arestas que podem sair dos vértices
    int** arestas; // Lista de adjacências: arestas[i][j] = k -> existe aresta de i para k. j é o índice do item na lista
    float** pesos; // Lista de peso da aresta: pesos[i][j] = k -> existe aresta partindo de i. O índice na lista é j (mesmo da lista de arestas). k é peso. Ex: arestas[i][j] = k. peso[i][j] = k2.
    int* grau; // quantidade de arestas que o vértice possui
};

typedef struct grafo Grafo;

Grafo* cria_grafo(int nro_vertices, int eh_ponderado);

void libera_grafo(Grafo* gr);

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso);

void gera_grafo(Grafo *gr);

bool aresta_existe(struct grafo* g, int u, int v);

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo);

bool valida_grafo(Grafo *gr);

void imprime_grafo(Grafo *gr);

#endif