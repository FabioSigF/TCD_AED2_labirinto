#include "Mapa.h"
#include "Area.h"
#include "Jogo.h"

// Função para gerar uma árvore completa para o mapa. Ao chamar a função, o parâmetro "aut" deve ser passado com calc_dif_mapa(dificuldade)
void gera_mapa(ArvBin *raiz, int qtdSalas, int qtdAreas, int dificuldade){

  int maxSalas = qtdAreas + qtdSalas;
  if(dificuldade == 1) {
      insere_area(&(*raiz)->dir, maxSalas-1);
      insere_area(&(*raiz)->esq, qtdSalas+1);

      insere_area(&(*raiz)->esq->esq, qtdSalas);
  }
  else if(dificuldade == 2) {
      insere_area(&(*raiz)->esq, maxSalas-2);
      insere_area(&(*raiz)->dir, maxSalas-1);

      insere_area(&(*raiz)->esq->esq, qtdSalas);
      insere_area(&(*raiz)->esq->dir, qtdSalas+1);
  }
  else if(dificuldade == 3) {
    insere_area(&(*raiz)->esq, maxSalas-3);
    insere_area(&(*raiz)->dir, maxSalas-1);
    insere_area(&(*raiz)->dir->dir, maxSalas-2);

    insere_area(&(*raiz)->esq->esq, qtdSalas);
    insere_area(&(*raiz)->esq->dir, qtdSalas+1);
  }

}