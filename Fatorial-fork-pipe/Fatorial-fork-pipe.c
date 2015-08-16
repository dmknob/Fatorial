#include <sys/wait.h>
#include <sys/types.h>
#include <stdio.h>
#include <stdlib.h>
//#include <unistd.h>

int main ()
{
  pid_t pid;
  int numero=5, resultado=1, fd[2];
  printf("Calculando Fatorial de %d!\n", numero);
  pipe(fd);
  pid = fork();
  //switch (pid)
  if (pid == 0)
  {
    close(fd[0]);
    for (; numero > 1; numero--)
    {
      resultado=resultado * numero;
    }
    printf("Filho: %d\n", resultado);
    write(fd[1], &resultado, sizeof(resultado));
    exit(0);
  }
    else
    {
      pid_t filho;
      int status;
      close(fd[1]);

      read(fd[0], resultado, sizeof(resultado) );
      filho = wait(&status);
      printf("Executando processo %d\n", filho);
//      printf("Resultado: %d\n", WEXITSTATUS(status));
      printf("Resultado: %d\n", resultado);
      exit(0);
    }
}
