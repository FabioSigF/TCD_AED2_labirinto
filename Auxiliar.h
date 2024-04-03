#include <stdio.h>
#include <stdlib.h>
#include <string.h>

char *fgets_wrapper(char *buffer, size_t buflen, FILE *fp);
void print_timer(char *str, int width);
void print_title(char *str, int width);
int verifica_retorno();
void encerrar_programa();
void print_transicao();