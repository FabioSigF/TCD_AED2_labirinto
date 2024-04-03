#include "Auxiliar.h"
#include <time.h>
#include <unistd.h>

char *fgets_wrapper(char *buffer, size_t buflen, FILE *fp){
    if (fgets(buffer, buflen, fp) != 0)
    {
        buffer[strcspn(buffer, "\n")] = '\0';
        return buffer;
    }
    return 0;
}

//Função usada para adicionar timer
void my_sleep(int sleepms){
#ifdef WINDOWS_SYSTEM
  Sleep(sleepms);
#else
  usleep(sleepms * 1000);
#endif
}

//Função que printa a string como se estivesse escrevendo. Possui um timer em cada letra.
void print_timer(char *str, int width){
  for (int i = 0; i < width; i++)
  {
    printf("%c", *str);
    my_sleep(20);
    str++;
  }
}

//Função que printa títulos:
/*
======================
        TÍTULO
======================
*/
void print_title(char *str, int width){
  int calc;
  calc = (32 - width) / 2;
  printf("\n");
  for (int i = 0; i < 32; i++)
  {
    printf("=");
  }
  printf("\n");
  for (int i = 0; i < calc; i++)
  {
    printf(" ");
  }
  printf("%s", str);
  for (int i = 0; i < calc; i++)
  {
    printf(" ");
  }
  printf("\n");
  for (int i = 0; i < 32; i++)
  {
    printf("=");
  }
  printf("\n");
}

int verifica_retorno(){
  int opt;

  do{
    printf("Retornar para página anterior?\n\n[ 1 ] SIM\n[ 2 ] NÃO\n\nResposta = ");
    scanf("%d", &opt);
    getchar();
    if(opt < 1 || opt > 2) {
      printf("\n\nOpção inválida!\n\n");
    }
  } while(opt < 1 || opt > 2);

  return opt;
}

void encerrar_programa() {
    printf("\nEncerrando o programa...\n");
    exit(0);
}
