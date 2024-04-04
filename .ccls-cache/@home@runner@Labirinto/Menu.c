#include "Menu.h"
#include "Auxiliar.h"
#include "ranking.h"

void menu(char *nomeJogador, int *dificuldade){
  print_logo(1);
  print_opcoes();

  int opt;
  printf("Resposta = ");
  scanf("%d", &opt);
  getchar();
  printf("\n\n");
  
  system("clear");
  escolha(opt, nomeJogador, dificuldade);
}

void print_opcoes(){
  printf("[ 1 ] JOGAR\n");
  printf("[ 2 ] MANUAL\n");
  printf("[ 3 ] RANKING\n");
  printf("[ 4 ] SOBRE\n");
  printf("[ 5 ] SAIR");
  printf("\n\n");
}

void escolha(int opt, char *nomeJogador, int *dificuldade){
  //Variável coringa para texto
  char texto[50];
  
  switch(opt){
    case 1:{
      //Inicia jogo
      char nome[15];
      strcpy(texto, "JOGAR");
      print_title(texto, strlen(texto));
    
      printf("\nParece que temos um desafiante!\nQual seu nome?\n\nResposta = ");
      setbuf(stdin, NULL);
      fgets_wrapper(nome, 15, stdin);
      printf("\n\n");

      //Copia nome do jogador
      strcpy(nomeJogador, nome);

      //Escolhe dificuldade de jogo
      *dificuldade = escolhe_dificuldade();
      getchar();

      printf("\nTudo pronto para começar, %s!\n", nome);
      strcpy(texto, "\nEssa é uma jornada só de ida. Boa Sorte!\n");
      print_timer(texto, strlen(texto));
      
      strcpy(texto, "\nEntrando no Labirinto...\n");
      print_timer(texto, strlen(texto));
      
      print_transicao();
    }
      break;
    case 2:{ 
      int opt;
      print_manual();
      opt = verifica_retorno();
      if(opt == 1){
        menu(nomeJogador, dificuldade);
      } else {
        encerrar_programa();
      };
    }
      break;
    case 3:
    { 
      int opt;
      ranking(); // Chamando a função para exibir o ranking
      opt = verifica_retorno();
      if(opt == 1){
        menu(nomeJogador, dificuldade);
      } else {
        encerrar_programa();
      };
    } 
    break;
    case 4:
      { 
        int opt;
        print_sobre();
        opt = verifica_retorno();
        if(opt == 1){
          menu(nomeJogador, dificuldade);
        } else {
          encerrar_programa();
        };
      } 
      break;
    case 5:
      encerrar_programa();
      break;
  }
}

void print_manual() {
  char texto[50];
  
  strcpy(texto, "MANUAL");
  print_title(texto, strlen(texto));
}

void print_introducao(){
  char texto[400];
  strcpy(texto, "Você faz parte de um povo originado de uma área inóspita, conhecida como 'O Labirinto'.\n\nSeu objetivo é, assim como o de todos do  seu povo, alcançar a maioridade para explorar o mundo e presenciar suas várias belezas.\n\nPorém, somente os 10 melhores e mais rápidos terão seus nomes gravados na história como grandes guerreiros.\n\nDê o seu melhor!");
  print_timer(texto, strlen(texto));
  print_transicao();
}

int escolhe_dificuldade(){

  int opt;

  do{ 
    printf("Qual será a dificuldade de jogo?\n\n[ 1 ] Fácil\n[ 2 ] Médio\n[ 3 ] Difícil\n\nResposta = ");
    scanf("%d", &opt);

    if(opt < 1 || opt > 3) {
       printf("Opção inválida!\n\n"); 
    }
  } while(opt < 1 || opt > 3);

  return opt;
}

void print_sobre(){
  char texto[50];
  strcpy(texto, "SOBRE");
  print_title(texto, strlen(texto));
  printf("O programa DashMaze foi desenvolvido como Trabalho de Conclusão de Curso na matéria de Algoritmos e Estruturas de Dados 2 do curso de Ciência da Computação na Universidade Federal de Uberlândia.\n\n");
  printf("Possui o objetivo de apresentar um jogo de labirinto utilizando os conceitos de Grafos, Árvores e Algoritmos de Ordenação.\n\n");
  printf("Desenvolvedores:\n");
  printf("Andre Polimanti Mesquiari Lemos - 12221BCC023\n");
  printf("Fábio Signorini de Freitas - 12211BCC016\n");
  printf("Willian Henrique Vilela Casa Grandi - 12211BCC001\n");
}

void print_ranking(){};

void print_logo(int option){
  system("clear");
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
