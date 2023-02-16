#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct arv{
  char *info;
  int val;
  struct arv *dir;
  struct arv *esq;
}Arv;

Arv *insert(char *c, int val, Arv* raiz)
{
  if(raiz == NULL)
  {
    Arv*novo=(Arv*)malloc(sizeof(Arv));
    novo->info = (char*) malloc((strlen(c)+1) * sizeof(char));
    strcpy(novo->info,c);
    novo->val = val;
    novo->dir = novo->esq = NULL;
    return novo;
  }
  if (strcmp(c,raiz->info)< 0)
    raiz->esq = insert(c, val, raiz->esq);
  else
    raiz->dir = insert(c, val, raiz->dir);
   return raiz;
}

void impr_ord(Arv * a)//infixa
{
  if (a!=NULL) {
    impr_ord(a->esq);
    printf("->>%s---%d\n",a->info,a->val);
    impr_ord(a->dir);
  }
}

Arv *busca(char *c, Arv*raiz)
{
  if (raiz == NULL)
  {
    printf("%s nao existe\n",c);
    return NULL;
  }
  if (strcmp(c,raiz->info)==0) // encontrou o nó desejado
  {
    raiz->val++; // atualiza o valor numerico
    return raiz;
  }
  if (strcmp(c,raiz->info) < 0) // a string buscada é menor que a string do nó atual
  {
    return busca(c,raiz->esq); // navega para o filho esquerdo
  }
  else // a string buscada é maior que a string do nó atual
  {
    return busca(c,raiz->dir); // navega para o filho direito
  }
}

int main()
{
  char in[100];
  Arv* root = NULL;
  int val = 1;

  while (scanf("%s", in) != EOF)
  {
    Arv* no = busca(in, root);
    if (no == NULL) // o nó não existe
    {
      root = insert(in, val, root); // insere o novo nó
      no = root;
    }
    impr_ord(root);
    //printf("%d\n", no->val); // imprime o valor numerico do nó
  }

  return 0;
}