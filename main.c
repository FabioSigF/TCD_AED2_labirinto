#include "bibliotecas.h"

int main(void) {

  print_introducao();
  system("clear");
//Menu
  char nomeJogador[15];
  int dificuldade;

  menu(nomeJogador, &dificuldade);

//Configurações de jogo
  //Tempo de jogo: Array vai guardar o tempo gasto em cada área
  int tempoDeJogoSeg[6];

  //Zera o tempo de jogo
  for(int i = 0; i < 6; i++){
    tempoDeJogoSeg[i] = 0; 
  }
  
  //Calcula dificuldade do labirinto da área central
  int difLab = calc_dif_lab(dificuldade) + calc_dif_mapa(dificuldade);
  //listaPercurso[i][j], sendo [i] a área e [j] as salas escolhidas
  int listaPercurso[10][10];
  //Configura lista
  for(int i = 0; i < 10; i++){
    for(int j = 0; j < 10; j++){
      listaPercurso[i][j] = -1;
    }
  }
  
//Configurações de Mapa
  //Inicializa mapa
  ArvBin* mapa = cria_ArvBin();
  //Cria labirinto da Área Central
  insere_area(mapa, difLab);
  //Gera mapa: áreas filhas da Área Central
  gera_mapa(mapa, calc_dif_lab(dificuldade), calc_dif_mapa(dificuldade), dificuldade);
  
  //Jogador explora Mapa
  system("clear");
  explorar_mapa(mapa, listaPercurso, dificuldade, tempoDeJogoSeg);
  int optFim = verifica_retorno();
  
  if(optFim == 1) {
    //Reseta Nome Jogador
    strcpy(nomeJogador, "");
    menu(nomeJogador, &dificuldade);
  } else {
    encerrar_programa();
  }
  return 0;
}