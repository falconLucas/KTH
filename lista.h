#ifndef LISTA_H
#define LISTA_H

struct nod {
    char key[512];
    char value[512];
    struct nod * next;
    struct nod * prev;
};
typedef struct nod Nod;

Nod *new_nod(char *key, char *value);
void insertnod(Nod ** padr, Nod * tobeadded);
void appendnod(Nod ** padr, Nod * tobeadded);
void removenod(Nod ** padr, Nod * toberemoved);
void clear_list(Nod ** padr);
void printnod(Nod * p);
void printlist(Nod * p);
Nod * search(Nod * p, char *key);
Nod * search_value(Nod * p, char *value);

#endif
