#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void menu (char *nomeJogador, int *dificuldade); // Interação com o menu e suas funções internas
void print_opcoes (); // Imprime as opções de escolha do menu
void escolha(int opt, char *nomeJogador, int *dificuldade); // Segue aquilo que o usuário escolheu
int escolhe_dificuldade(); //Escolhe a dificuldade de jogo

void print_logo (int option); // Imprime a arte da logo do jogo
void print_introducao (); // Historia do jogo
void print_sobre (); // Credito aos criadores do programa
void print_manual (); // Como jogar
void print_ranking (); // Imprime o ranking dos 10 melhores jogadores com os melhores tempos

void ASCIIart_1();
void ASCIIart_2();


void login();