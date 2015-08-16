#include <stdio.h>
#include <stdlib.h>

int Fatorial(int numero)
{
  int resultado=1;
  for (; numero > 1; numero--)
  {
    resultado=resultado * numero;
  }
  return resultado;
}

int main ()
{
  pid_t pid;
  printf("Inicio!\n");
  //pid = fork();
  //printf("Executando processo %d\n", pid);
  printf("Resultado: %d\n", Fatorial(5));
  return 0;
}
