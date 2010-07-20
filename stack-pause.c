#include <stdio.h>

int main()
{
  int my_int = 1234567890;
  printf("%d on the stack, pausing...\n", my_int);
  getchar();
  return(0);
}
