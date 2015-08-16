#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>

int main ()
{
  pid_t pid, pid2;
  int numero=5, resultado=1;
  printf("Calculando Fatorial de %d!\n", numero);
  pid = fork();
  pid2 = fork();
  //switch (pid)
  if (pid == 0)
  {
    for (; numero > 1; numero--)
    {
      resultado=resultado * numero;
    }
    printf("Filho: %d\n", resultado);
    exit(resultado);
  }
    else
    {
      pid_t filho;
      int status;
      filho = wait(&status);
      printf("Executando processo %d\n", filho);
      printf("Resultado: %d\n", WEXITSTATUS(status));
      exit(0);
    }
}
