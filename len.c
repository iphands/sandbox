#include <stdio.h>
#include <string.h>

int main()
{
  char * test = "hello";
  printf("test is yay big: %d\n", (int)strnlen(test, 50));

  return(0);
}
