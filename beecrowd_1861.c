#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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
    printf("%s %d\n",a->info,a->val);
    impr_ord(a->dir);
  }
}

Arv *busca(char *c, Arv*raiz)
{
  if (raiz == NULL)
  {
    return NULL;
  }
  if (strcmp(c,raiz->info)==0)
  {
    raiz->val++;
    return raiz;
  }
  if (strcmp(c,raiz->info) < 0)
  {
    return busca(c,raiz->esq);
  }
  else
  {
    return busca(c,raiz->dir);
  }
}

Arv *remove_no(char *c, Arv* raiz)
{
  if (raiz == NULL) 
  {
    return NULL;
  }
  if (strcmp(c, raiz->info) < 0) 
  {
    raiz->esq = remove_no(c, raiz->esq);
  }
  if (strcmp(c, raiz->info) > 0) 
  {
    raiz->dir = remove_no(c, raiz->dir);
  } 
  else 
  { 
    if (raiz->esq == NULL && raiz->dir == NULL)
    {
      free(raiz->info);
      free(raiz);
      return NULL;
    }
    if (raiz->esq == NULL) 
    {
      Arv *temp = raiz->dir;
      free(raiz->info);
      free(raiz);
      return temp;
    }
    if (raiz->dir == NULL) 
    {
      Arv *temp = raiz->esq;
      free(raiz->info);
      free(raiz);
      return temp;
    }
    Arv *temp = raiz->dir;
    while (temp && temp->esq != NULL) 
    {
      temp = temp->esq;
    }
    raiz->val = temp->val;
    free(raiz->info);
    raiz->info = strdup(temp->info);
    raiz->dir = remove_no(temp->info, raiz->dir);
  }
  return raiz;
}

int main()
{
  char assas[100];
  char vitma[100];
  Arv* root = NULL;
  int val = 1;

  printf("HALL OF MURDERERS\n");
  while (scanf("%s %s", assas, vitma) != EOF)
  {
    Arv* no = busca(assas, root);
    if (no == NULL) 
    {
      root = insert(assas, val, root);
      no = root;
    }
    Arv* vit = busca(vitma, root);
    if (vit != NULL)
    {
      root = remove_no(vitma, root);
      vit = root;
    }
    impr_ord(root);
    //printf("%d\n", no->val); 
  }

  return 0;
}