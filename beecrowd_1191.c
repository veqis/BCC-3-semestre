#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct arv {
  char info;
  struct arv *dir;
  struct arv *esq;
} Arv;

Arv *ins_arv(char c, Arv *raiz)
{
  static bool lado = false;
  if (raiz == NULL) {
    Arv *novo = (Arv*)malloc(sizeof(Arv));
    novo->info = c;
    novo->dir = novo->esq = NULL;
    return novo;
  }
  if (lado == true) {
    lado = false;
    raiz->esq = ins_arv(c, raiz->esq);
  }
  else {
    lado = true;
    raiz->dir = ins_arv(c, raiz->dir);
  }
  lado = !lado;
  return raiz;
}

void impr(Arv *a)
{
  if (a != NULL) {
    printf("%c", a->info);
    impr(a->dir);
    impr(a->esq);
  }
}

int main()
{
  char in[26];
  Arv *root = NULL;
  while (scanf("%s", in) != EOF) {
    if (in[0] == '1')
      break;
    for (int i = 0; i < (int)strlen(in); i++) {
      root = ins_arv(in[i], root);
    }
  }
  impr(root);
  return 0;
}