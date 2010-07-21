#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>

int main()
{
  int my_int = 1234567890;
  char * string = "Hello World";
  printf("My pid is %d\n", (int)getpid());
  printf("%s on the stack (%x)\n", string, (unsigned int) &string);
  printf("%d on the stack (%x)\n", my_int, (unsigned int) &my_int);
  printf("entering pause loop...\n");
  while(1) {
    usleep(1000 * 250);
  }

  return(0);
}
