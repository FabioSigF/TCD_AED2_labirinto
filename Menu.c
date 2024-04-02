#include "Menu.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menuInterativo(){
  printLogo(2);
  printOpcoes();

  int opt;
  scanf("%d", &opt);

  escolha(opt);
}

void printOpcoes(){
  printf("1 - Jogar\n");
  printf("2 - Manual\n");
  printf("3 - Ranking\n");
  printf("4 - Sobre\n");
  printf("5 - Creditos\n");
  printf("6 - Sair");
  printf("\n\n");
}

void escolha(int opt){
  switch(opt){
    case 1:{
      char nome[15];
      
      printf("Insira seu nome: ");
      fgets(nome, 15, stdin);

      //Inicia o jogo aqui
    }
    case 2:
      //printManual(); //Ainda não sei como funciona
      break;
    case 3:
      //printRanking(); //Casão
      break;
    case 4:
      printSobre();
      break;
    case 5:
      printCreditos();
      break;
    case 6:
      break;
  }
}

void printSobre(){
  system("cls");
  printf("Você faz parte de um povo originado de uma area inospita, conhecida como o labirinto.\nSeu objetivo, assim como o de todos do  seu povo, eh, ao alcançar a maioridade, sair desse lugar para explorar o mundo e presenciar suas varias belezas.\n Mas, somente os 10 melhores e mais rapidos terão seus nomes passados na historia como grandes guerreiros.\nDe o seu melhor!");
  char c = getchar();
}

void printCreditos(){
  system("cls");
  printf("Criadores:\n");
  printf("Andre Polimanti Mesquiari Lemos - 12221BCC023\n");
  printf("Fabio Signorini de Freitas - 12211BCC016\n");
  printf("Willian Henrique Vilela Casa Grandi - 12211BCC001\n");

  char c = getchar();
}




void printLogo(int option){
  system("cls");
  switch(option){
    case 1:
      ASCIIart_1();
      break;
    case 2:
      ASCIIart_2();
      break;
  }
}

void ASCIIart_1(){

  printf(" ___                 _                                \n");
  printf("(  _`\\              ( )    /'\\_/`\\                    \n");
  printf("| | ) |   _ _   ___ | |__  |     |   _ _  ____    __  \n");
  printf("| | | ) /'_` )/',__)|  _ `\\| (_) | /'_` )(_  ,) /'__`\\ \n");
  printf("| |_) |( (_| |\\__, \\| | | || | | |( (_| | /'/_ (  ___/\n");
  printf("(____/'`\\__,_)(____/(_) (_)(_) (_)`\\__,_)(____)`\\____)\n");
  printf("\n");
  printf("\n");
  printf("\n");
}

void ASCIIart_2(){
  printf("    ____                     __      __  ___                   \n");
  printf("   / __ \\  ____ _   _____   / /_    /  |/  /  ____ _ ____  ___ \n");
  printf("  / / / / / __ `/  / ___/  / __ \\  / /|_/ /  / __ `/ _ \\/ _ \\\n");
  printf(" / /_/ / / /_/ /  (__  )  / / / / / /  / /  / /_/ /  __/  __/\n");
  printf("/_____/  \\__,_/  /____/  /_/ /_/ /_/  /_/   \\__,_/\\___/\\___/\n");
  printf("\n");
  printf("\n");
  printf("\n");
}