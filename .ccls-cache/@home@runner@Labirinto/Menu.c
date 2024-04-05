#include "Menu.h"
#include "Auxiliar.h"
#include "ranking.h"
#include <unistd.h>

void menu(char *nomeJogador, int *dificuldade) {
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
    printf("    [ 1 ] JOGAR\n");
    printf("    [ 2 ] MANUAL\n");
    printf("    [ 3 ] RANKING\n");
    printf("    [ 4 ] SOBRE\n");
    printf("    [ 5 ] SAIR\n\n");
}

void escolha(int opt, char *nomeJogador, int *dificuldade) {
  // Variável coringa para texto
  char texto[50];

  switch (opt) {
  case 1: {
    // Inicia jogo
    char nome[15];
    strcpy(texto, "JOGAR");
    print_title(texto, strlen(texto));

    printf("\nParece que temos um desafiante!\nQual seu nome?\n\nResposta = ");
    setbuf(stdin, NULL);
    fgets_wrapper(nome, 15, stdin);
    printf("\n\n");

    // Copia nome do jogador
    strcpy(nomeJogador, nome);

    // Escolhe dificuldade de jogo
    *dificuldade = escolhe_dificuldade();
    getchar();

    printf("\nTudo pronto para começar, %s!\n", nome);
    strcpy(texto, "\nEssa é uma jornada só de ida. Boa Sorte!\n");
    print_timer(texto, strlen(texto));

    strcpy(texto, "\nEntrando no Labirinto...\n");
    print_timer(texto, strlen(texto));

    print_transicao();
  } break;
  case 2: {
    int opt;
    print_manual();
    opt = verifica_retorno();
    if (opt == 1) {
      menu(nomeJogador, dificuldade);
    } else {
      encerrar_programa();
    };
  } break;
  case 3: {
    int opt;
    ranking(); // Chamando a função para exibir o ranking
    opt = verifica_retorno();
    if (opt == 1) {
      menu(nomeJogador, dificuldade);
    } else {
      encerrar_programa();
    };
  } break;
  case 4: {
    int opt;
    print_sobre();
    opt = verifica_retorno();
    if (opt == 1) {
      menu(nomeJogador, dificuldade);
    } else {
      encerrar_programa();
    };
  } break;
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

void print_with_delay(const char *text) {
    int len = strlen(text);
    for (int i = 0; i < len; i++) {
        putchar(text[i]);
        fflush(stdout); // Força a saída para que seja exibida imediatamente
        usleep(10000); // Aguarda 100 milissegundos (0.1 segundo)
    }
}

void print_introducao() {
  printf("\n");
  printf("=====================================================================================================\n");
  printf("                                Jornada Épica Contra os Monstros dos Grafos\n");
  printf("=====================================================================================================\n\n");

  print_with_delay("Era uma vez, em um mundo onde o destino se entrelacava com a bravura e a determinacao, tres alunos se destacavam em meio ao caos e a incerteza. Entre os corredores de uma escola comum, onde sonhos nasciam e esperancas floresciam, surgiram tres nomes destinados a mudar o curso da historia: Andre, o Ultimo Heroi da Terra; Fabio do Zap; e Poderoso Casao.\n\n");

  print_with_delay("Andre, cujo coracao pulsava com a forca de mil sois, era conhecido por sua coragem inabalavel e seu espirito indomavel. Ele carregava consigo o fardo de uma profecia ancestral, que o destinava a ser o ultimo bastiao de esperanca em um mundo a beira do abismo.\n\n");

  print_with_delay("Fabio, um jovem de alma vibrante e mente afiada, dominava os segredos do mundo digital como ninguem. Conhecido como Fabio do Zap, ele navegava pelas correntes da informacao com destreza e perspicacia, buscando desvendar os misterios que assombravam sua realidade.\n\n");

  print_with_delay("Poderoso Casao, por sua vez, era um enigma envolto em misterio. Com sua habilidade unica de encontrar solucoes nos lugares mais inesperados, ele era a chave para desvendar os enigmas que desafiavam ate mesmo os mais sabios.\n\n");

  print_with_delay("Juntos, esses tres jovens embarcariam em uma jornada epica, enfrentando desafios inimaginaveis e descobrindo segredos que mudariam o destino de todos. Com seus conhecimentos em estruturas de dados lendarias, eles se preparavam para combater os terriveis monstros dos grafos, criaturas ancestrais que ameacavam a estabilidade do mundo conhecido.\n\n");

  print_with_delay("A jornada prometia ser ardua e perigosa, mas tambem repleta de aventuras e descobertas. O destino do mundo estava nas maos desses tres jovens herois, e o futuro aguardava ansiosamente pelo desfecho dessa epica batalha entre o bem e o mal.......\n\n");
      printf("=====================================================================================================\n\n");
  
  print_transicao();
}


int escolhe_dificuldade() {

  int opt;

  do {
    printf("Qual sera a dificuldade de jogo?\n\n[ 1 ] Facil\n[ 2 ] Medio\n[ 3 "
           "] Difícil\n\nResposta = ");
    scanf("%d", &opt);

    if (opt < 1 || opt > 3) {
      printf("Opção inválida!\n\n");
    }
  } while (opt < 1 || opt > 3);

  return opt;
}

void print_sobre() {
  char texto[50];
  strcpy(texto, "SOBRE");
  print_title(texto, strlen(texto));
  printf("O programa DashMaze foi desenvolvido como Trabalho de Conclusão de "
         "disciplina na matéria de Algoritmos e Estruturas de Dados 2 do curso de "
         "Ciência da Computação na Universidade Federal de Uberlândia.\n\n");
  printf("Possui o objetivo de apresentar um jogo de labirinto utilizando os "
         "conceitos de Grafos, Árvores e Algoritmos de Ordenação.\n\n");
  printf("Desenvolvedores:\n");
  printf("Andre Polimanti Mesquiari Lemos - 12221BCC023\n");
  printf("Fábio Signorini de Freitas - 12211BCC016\n");
  printf("Willian Henrique Vilela Casa Grandi - 12211BCC001\n");
}

void print_ranking(){};

void print_logo(int option) {
  system("clear");
  switch (option) {
  case 1:
    ASCIIart_1();
    break;
  case 2:
    ASCIIart_2();
    break;
  }
}

void ASCIIart_1() {

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

void ASCIIart_2() {
  printf("    ____                     __      __  ___                   \n");
  printf("   / __ \\  ____ _   _____   / /_    /  |/  /  ____ _ ____  ___ \n");
  printf("  / / / / / __ `/  / ___/  / __ \\  / /|_/ /  / __ `/ _ \\/ _ \\\n");
  printf(" / /_/ / / /_/ /  (__  )  / / / / / /  / /  / /_/ /  __/  __/\n");
  printf("/_____/  \\__,_/  /____/  /_/ /_/ /_/  /_/   \\__,_/\\___/\\___/\n");
  printf("\n");
  printf("\n");
  printf("\n");
}
