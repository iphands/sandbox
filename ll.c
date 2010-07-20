#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct {
  struct str_list *prev;
  char *data;
  struct str_list *next;
} typedef str_list;

str_list* add_str(char * string, str_list * list);
void free_list(str_list * list);
void print_usage();

void print_usage()
{
  printf("Please give a number of elements.\n");
  return;
}

int main(int argc, char ** argv)
{
  if (argc < 2) {
    print_usage();
    return(1);
  }
  
  const int COUNT = atoi(argv[1]);

  str_list *my_list = malloc(sizeof(str_list));
  my_list->data = NULL;

  str_list *my_list_end = my_list;
  for (unsigned long i = 0; i < COUNT; i++) {
    char tmp_strn[50];
    sprintf(tmp_strn, "hello%d", (int)i);
    my_list_end = add_str(tmp_strn, my_list_end);
  }

  for (str_list *tmpl = my_list; tmpl != NULL; tmpl = (str_list*)tmpl->next) { 
    printf("test: %s\n", tmpl->data);
  }

  printf("\nRunning through the (doubly linked) list in reverse\n\n");

  for (str_list *tmpl = my_list_end; tmpl != NULL; tmpl = (str_list*)tmpl->prev) { 
    printf("test: %s\n", tmpl->data);
  }

  free_list(my_list);

  return(0);
}

void free_list(str_list * list)
{
  for (str_list *tmpl = list; tmpl != NULL; ) {
    void *tmp_next = tmpl->next;
    free(tmpl->data);
    free(tmpl);
    tmpl = (str_list *)tmp_next;
  }
  
  return;
}

str_list * add_str(char * string, str_list * list)
{   
  if (list->data == NULL) {
    list->data = strndup(string, 100);
    list->next = NULL;
    list->prev = NULL;
    return list;
  }

  str_list * new_list = list;

  while(list->next != NULL) {
    list = (str_list*) list->next;
  }

  new_list = malloc(sizeof(str_list));
  list->next = (struct str_list*) new_list;
  new_list->data = strndup(string, 100);
  new_list->prev = (struct str_list *)list;
  new_list->next = NULL;

  return new_list;
}
