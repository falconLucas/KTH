#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "hashfunc.h"
// #include "lista.h"

const int HASHVEKSIZE = 1048576;    // 2 upphöjt till 20 ungefär 1 miljon
//const int HASHVEKSIZE = 2097152     // 2 upphöjt till 21
//const int HASHVEKSIZE = 4194304     // 2 upphöjt till 22

uint32_t tilpro_hash(const char * s) {
  uint32_t hash = 0;
  size_t i = 0;
  while (s[i] != '\0') {
    hash += s[i++];
    hash += hash << 10;
    hash ^= hash >> 6;
  }
  hash += hash << 3;
  hash ^= hash >> 11;
  hash += hash << 13;

  hash = hash & ( HASHVEKSIZE - 1 );
  return hash;
}

void put(Nod ** hashtable, char * key, char * value) {
  uint32_t hash = tilpro_hash(key);
  Nod * slot;
  do{
    slot = *hashtable + hash;
    hash++;
    hash &= HASHVEKSIZE - 1;
  } while(slot != NULL);
  slot = new_nod(key, value);
}

char * get(Nod ** hashtable, char * key) {
  uint32_t hash = tilpro_hash(key);
  printf("%s\n", "hashfunc 1");
  char current_key[512];
  while(*(hashtable + hash) != NULL){
    printf("%s\n", "hashfunc 2");
    printf("%s\n", *(hashtable + hash)->key);
    printf("%s\n", "hashfunc 3");

    strcpy(current_key, (hashtable + hash)->key);
    if(strcmp(current_key, key)) return (*hashtable + hash)->value;
    hash++;
    hash &= HASHVEKSIZE - 1;
  }
  return NULL;
}

void init(Nod ** vek) {
  for(uint32_t i = 0; i < HASHVEKSIZE; i++){
    *(**vek + i) = NULL;
  }
}
