#include "Mapa.h"
#include "Area.h"
#include "Jogo.h"

// Função para gerar uma árvore completa para o mapa. Ao chamar a função, o parâmetro "aut" deve ser passado com calc_dif_mapa(dificuldade)
void gera_mapa(ArvBin *raiz, int altura, int qtdSalas){

  if (altura <= 0)
    return;

  insere_area(&(*raiz)->esq, qtdSalas);
  gera_mapa(&(*raiz)->esq, altura-1, qtdSalas-1);

  insere_area(&(*raiz)->dir, qtdSalas);
  gera_mapa(&(*raiz)->dir, altura-1, qtdSalas-1);
}