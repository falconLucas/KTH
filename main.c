#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "hashfunc.c"
#include "lista.c"

extern const int HASHVEKSIZE;

Nod *new_nod(char *key, char *value){
  //  Function to generate a node
  Nod * ny = malloc(sizeof(Nod)); // Allocate memory for node and store its pointer
  ny -> next = NULL;
  ny -> prev = NULL;
  strcpy(ny -> key, key);
  strcpy(ny -> value, value);
  return ny;                       // Return poiner to node
}

int main(void) {
  printf("%s\n", "main 1");
  Nod ** myhashvek = malloc(sizeof(Nod *) * HASHVEKSIZE);
  init(myhashvek);
  printf("%s\n", "main 2");
  put(myhashvek, "Adam", "123321");
  printf("%s\n", "main 3");
  char * s = get(myhashvek, "Adam");
  printf("%s\n", "main 4");
  printf("Adam -> value = %s expecting Adam\n", s);

  // ...
  return 0;
}
