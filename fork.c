#include <stdio.h>
#include <unistd.h>
#include <signal.h>
#include <sys/wait.h>

int main()
{
  pid_t ochild_pid = fork();
  if (ochild_pid == 0) {
    printf("I am the ochild\n");
    fflush(stdout);
    pid_t child_pid = fork();
    if (child_pid == 0) {
      printf("I am the child\n");
      fflush(stdout);
      return(0);
    } else {
      printf("I am the parent\n");
      fflush(stdout);
      wait(NULL);
    }  
    kill(child_pid, SIGKILL);
    return(0);
  }  else {
    printf("I am the oparent\n");
  }
  wait(NULL);
  return(0);
}
