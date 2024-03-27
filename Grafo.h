#include <stdbool.h>

typedef struct grafo Grafo;

Grafo* cria_grafo(int nro_vertices, int eh_ponderado);

void libera_grafo(Grafo* gr);

int insereAresta(Grafo* gr, int orig, int dest, int eh_digrafo, float peso);

void gera_grafo(Grafo *gr);

bool aresta_existe(struct grafo* g, int u, int v);

int removeAresta(Grafo* gr, int orig, int dest, int eh_digrafo);

bool valida_grafo(Grafo *gr);

void imprime_grafo(Grafo *gr);