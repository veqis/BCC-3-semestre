#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arv{
  char *info;
  int val;
  struct arv *dir;
  struct arv *esq;
}Arv;

typedef struct morte{
  char *info;
  struct morte *dir;
  struct morte *esq;
}Mort;

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
  {
    raiz->esq = insert(c, val, raiz->esq);
  }else
  {
    raiz->dir = insert(c, val, raiz->dir);
  }
   return raiz;
}

Mort *insert_mortos(char *c, Mort* raiz)
{
  if(raiz == NULL)
  {
    Mort*novo=(Mort*)malloc(sizeof(Mort));
    novo->info = (char*)malloc((strlen(c)+1)*sizeof(char));
    strcpy(novo->info,c);
    novo->dir = novo->esq = NULL;
    return novo;
  }
  if(strcmp(c,raiz->info) < 0)
  {
    raiz->esq = insert_mortos(c, raiz->esq);
  }else
  {
    raiz->dir = insert_mortos(c, raiz->dir);
  }
  return raiz;
}

void impr_ord(Arv * a)
{
  if (a!=NULL) 
  {
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

Mort *buscaM(char *c, Mort*raiz)
{
  if (raiz == NULL)
  {
    return NULL;
  }
  if (strcmp(c,raiz->info)==0)
  {
    return raiz;
  }
  if (strcmp(c,raiz->info) < 0)
  {
    return buscaM(c,raiz->esq);
  }
  else
  {
    return buscaM(c,raiz->dir);
  }
}

Arv *remove_no(char *c, Arv* raiz)
{
  if (raiz == NULL) 
  {
    return NULL;
  }else if (strcmp(c, raiz->info) < 0) 
  {
    raiz->esq = remove_no(c, raiz->esq);
  }else if (strcmp(c, raiz->info) > 0) 
  {
    raiz->dir = remove_no(c, raiz->dir);
  } 
  else{               //se chegou aqui, encontrou o elemento
  if (raiz->esq == NULL && raiz->dir == NULL) { //nó sem filhos
    free (raiz);
    raiz = NULL;
    }
  else
  if (raiz->esq == NULL) {//apenas filho a direita
    Arv*aux = raiz;
    raiz = raiz->dir;
    free (aux);
    }
  else
  if (raiz->dir == NULL) { //apenas filho a esquerda
    Arv*aux = raiz;
    raiz = raiz->esq;
    free (aux);
  }
  else{ //se chegou aqui, tem dois filhos
    Arv*aux = raiz->esq; //desce um nível a esquerda
    while (aux->dir != NULL) {  //busca último elemento a direita
      aux = aux->dir;
    }
    raiz->info = aux->info; //troca as informações
    aux->info = c;
    raiz->esq = remove_no(c,raiz->esq);//remove c, a partir da esquerda da raiz original
    }
  }
  return raiz;
}

int main()
{
  char assas[1000];
  char vitma[1000];
  Arv* root = NULL;
  Mort* mortos = NULL;
  int val = 1;

  printf("HALL OF MURDERERS\n");
  while (scanf("%s %s", assas, vitma) != EOF)
  {
    Mort* morreu = buscaM(vitma,mortos);//verifica se a vitma ja existe na arvore
    if (morreu == NULL)
    {
      mortos = insert_mortos(vitma,mortos);
    }

    Mort* verif = buscaM(assas, mortos);//verifica se o ass está na arovore dos mortos
    if (verif == NULL) 
    {
      Arv* matou = busca(assas, root);    //busca se assas já existe na arvore
      if (matou==NULL)
      {
        root = insert(assas, val, root);
      }
    }

    Arv* vit = busca(vitma, root); 
    if (vit != NULL)
    {
      root = remove_no(vitma, root);
    }
  }
  impr_ord(root);
  return 0;
}
