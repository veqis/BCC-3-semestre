#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

bool first = true;

typedef struct arv{
  char info;
  struct arv *dir;
  struct arv *esq;
}Arv;

Arv *ins_abb(char c, Arv*raiz)
{
  if(raiz == NULL)
  {
    Arv*n=(Arv*)malloc(sizeof(Arv));
    n->info = c;
    n->dir = n->esq = NULL;
    return n;
  }
  if (c < raiz->info)            //anda a esquerda
    raiz->esq = ins_abb(c,raiz->esq);
  else                                //anda a direita
    raiz->dir = ins_abb(c,raiz->dir);
 
   return raiz;
}

Arv *busca(char c, Arv*raiz)
{
  if (raiz == NULL)
  {
    printf("%c nao existe\n",c);
    return NULL;
  }
  if (raiz->info == c)
  {
    printf("%c existe\n",c);
    return 0;
  }
  if (raiz->info > c) //navega para a esquerda
  {
    return busca(c,raiz->esq);
  }
  if (raiz->info < c) //navega para a direita
  {
    return busca(c,raiz->dir);
  }
  return 0;
}

void impr_pos(Arv * a)//posfixa
{
  if (a!=NULL) 
  {
    impr_pos(a->esq);
    impr_pos(a->dir); 
    if (first==true)
    {
      first = false;
      printf("%c",a->info);
    }
    else
    {
      printf(" %c",a->info);
    }
    
  }
}

void impr_ord(Arv * a)//infixa
{
  if (a!=NULL) {
    impr_ord(a->esq);
    if (first==true)
    {
      printf("%c",a->info );
      first = false;
    }
    else
    {
      printf(" %c",a->info );
    }
    impr_ord(a->dir);
  }
}

void impr_pre(Arv *a)//prefixa
{
  if (a != NULL)
  {
    if (first == true)
    {
      first = false;
      printf("%c", a->info);
    }
    else
    {
      printf(" %c", a->info);
    }
    impr_pre(a->esq);
    impr_pre(a->dir);
  }
}

int main()
{
  char in[50];
  char infix[] = "INFIXA";
  char prefix[] = "PREFIXA";
  char posfix[] = "POSFIXA";
  Arv*root=NULL;

  while (scanf(" %[^\n]", in) != EOF)
  {
    if (in[0]=='I' && in[1]==' ')
    {
      root=ins_abb(in[2],root);
    }
    if (in[0]=='P' && in[1]==' ')
    {
      busca(in[2],root);
    }
    if (strcmp(in,infix)==0)
    {
      impr_ord(root);
      printf("\n");
    }
    if (strcmp(in,posfix)==0)
    {
      impr_pos(root);
      printf("\n");
    }
    if (strcmp(in,prefix)==0)
    {
      impr_pre(root);
      printf("\n");
    } 
    first = true;
  }
    return 0;
}