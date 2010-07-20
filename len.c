#include <stdio.h>
#include <string.h>

int main()
{
  char * test = "hello";
  printf("test is yay big: %d\n", strnlen(test, 50));

  return(0);
}
