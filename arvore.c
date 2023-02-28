#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct assasinos{
  char *info;
  int val;
  struct assasinos *dir;
  struct assasinos *esq;
}Ass;

typedef struct morte{
  char *info;
  struct morte *dir;
  struct morte *esq;
}Morte;

Ass *insert_ass(char *c, int val, Ass* raiz)
{
  if(raiz == NULL)
  {
    Ass*novo=(Ass*)malloc(sizeof(Ass));
    novo->info = (char*) malloc((strlen(c)+1) * sizeof(char));
    strcpy(novo->info,c);
    novo->val = val;
    novo->dir = novo->esq = NULL;
    return novo;
  }
  if (strcmp(c,raiz->info) < 0)
    raiz->esq = insert_ass(c, val, raiz->esq);
  else
    raiz->dir = insert_ass(c, val, raiz->dir);
   return raiz;
}

Morte *insert_mortos(char *c, Morte* raiz)
{
  if(raiz == NULL)
  {
    Morte*novo=(Morte*)malloc(sizeof(Morte));
    novo->info = (char*)malloc((strlen(c)+1)*sizeof(char));
    strcpy(novo->info,c);
    novo->dir = novo->esq = NULL;
    return novo;
  }
  if(strcmp(c,raiz->info) < 0)
    raiz->esq = insert_mortos(c, raiz->esq);
  else
    raiz->dir = insert_mortos(c, raiz->dir);
  return raiz;
}

Ass *busca_ass(char *c, Ass*raiz)
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
    return busca_ass(c,raiz->esq);
  else
    return busca_ass(c,raiz->dir);
}

Morte *busca_mort(char *c, Morte *raiz)
{
  if (raiz == NULL)
  {
    return NULL;
  }
  if (strcmp(c,raiz->info))
    return raiz;
  if(strcmp(c,raiz->info) < 0)
    return busca_mort(c, raiz->esq);
  else
    return busca_mort(c, raiz->dir);
}

void impr_ord(Ass * a)//infixa
{
  if (a!=NULL) {
    impr_ord(a->esq);
    printf("%s %d\n",a->info,a->val);
    impr_ord(a->dir);
  }
}

Ass *remove_no(char *c, Ass* raiz)
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
      Ass *temp = raiz->dir;
      free(raiz->info);
      free(raiz);
      return temp;
    }
    if (raiz->dir == NULL) 
    {
      Ass *temp = raiz->esq;
      free(raiz->info);
      free(raiz);
      return temp;
    }
    Ass *temp = raiz->dir;
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
  Ass* matou = NULL;
  Morte* mortos = NULL;
  int val = 1;

  printf("HALL OF MURDERERS\n");
  while (scanf("%s %s", assas, vitma) != EOF)
  {
    Morte* a = busca_mort(vitma,mortos);
    Morte* b = busca_mort(assas,mortos);
    Ass* c = busca_ass(assas,matou);
    
    if (a==NULL)//busca se nome da vitma já existe, se n add
    {
      insert_mortos(vitma,mortos);
    }
    if (b==NULL)//mesma coisa da anterior mas para assasino
    {
      if (c==NULL)
      {
        insert_ass(assas,val,matou);
      }  
    }
  }
  impr_ord(matou);
  return 0;
}