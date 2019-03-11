#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lista.h"



void insertnod(Nod ** padr, Nod * tobeadded){
  tobeadded -> next = *padr;
  tobeadded -> prev = NULL;
  if(*padr != NULL) tobeadded -> next -> prev = tobeadded;
  *padr = tobeadded;
};

void appendnod(Nod ** padr, Nod * tobeadded){
  /*
    Adds an element at the end of the list

    Input:  Pointer to pointer to first node, pointer to node to be added
  */

  //  Temporarily stores the first node of the list
  Nod * lastnod = * padr;

  //  Check if list is empty
  if(lastnod == NULL){
    insertnod(padr, tobeadded);
    return;
  }

  //  Find the last element in the list
  while(lastnod -> next != NULL){
    lastnod = lastnod -> next;
  }
  tobeadded -> prev = lastnod;
  lastnod -> next = tobeadded;
}

void removenod(Nod ** padr, Nod * toberemoved){
  // Removing the only node
  if(toberemoved -> prev == NULL && toberemoved -> next == NULL){
    *padr = NULL;
    free(toberemoved);
    return;
  }

  // Removing the first in queue
  if(toberemoved -> prev == NULL){
    *padr = toberemoved -> next;
    toberemoved -> next -> prev = NULL;
    free(toberemoved);
    return;
  }
  // Removing the last in queue
  if(toberemoved -> next == NULL){
    toberemoved -> prev -> next = NULL;
    free(toberemoved);
    return;
  }

  // Any other case
  toberemoved -> prev -> next = toberemoved -> next;
  toberemoved -> next -> prev = toberemoved -> prev;
  free(toberemoved);
};

void clear_list(Nod ** padr){
  Nod * current_nod = *padr;
  while(current_nod != NULL){
    Nod * next_nod = current_nod -> next;
    free(current_nod);
    current_nod = next_nod;
  }
}

void printnod(Nod * p){
  printf("%s\t%s\n", p->key, p->value);
};

void printlist(Nod * p){
  /*
    Input:  pointer to first element of the list
    Output: all names and telephone numbers printed in the prompt
  */
  // printf("\n");
  //  Go through all elements and print one by one
  while(p != NULL){
    printnod(p);
    p = p->next;
  }

};

Nod * search(Nod * p, char *key){
  while(strcmp(key, p->key)){
    p = p->next;
    if(p == NULL) return NULL;
  }
  return p;
};

Nod * search_value(Nod * p, char *value){
  while(strcmp(p->value, value) != 0){
    p = p->next;
    if(p == NULL) return NULL;
  }
  return p;
};
