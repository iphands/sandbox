#include <stdio.h>
#include <stdlib.h>
#include <sys/ptrace.h>
#include <sys/types.h>


int main(int argc, char ** argv)
{

  if (argc < 2) {
    printf("Please pass in a pid number\n");
    return(1);
  }
  
  pid_t pid = atoi(argv[1]);
  printf("Attaching to pid %d\n", (int)pid);

  long data = ptrace(PTRACE_ATTACH, pid, 0, NULL);
  printf("attach return: %d\n", (int)data);
  if (data == -1) {
    printf("Failed to attach!\n");
    return(1);
  }

  for (int i = 0; i < 100; i++) {
    data = ptrace(PTRACE_PEEKUSER, pid, i, NULL);
    if ( (data == -1) || (data == 0) ) {
      continue;
    }
    printf("int[%d]: %ld\n", i, data);
    printf("hex[%d]: %x\n", i, (unsigned int) data);
  }

  ptrace(PTRACE_DETACH, pid, NULL, NULL);

  return(0);
}
