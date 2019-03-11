#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "lista.h"

int main(void) {
  Nod * root = NULL;
  Nod * ny = new_nod("this is key", "this is value");
  insertnod(&root, ny);
  printnod(ny);
  Nod * found = search(root, "this is key");
  if(found != NULL){
    printf("%s\n", "Found it!");
  }
  else{
    printf("%s\n", "Something's wrong...");
  }
  clear_list(&root);
  return 0;
}
