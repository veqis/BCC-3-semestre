#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool first = true;

typedef struct arv{
  int info;
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
  else if (c < raiz->info) //anda a esquerda
    raiz->esq = ins_abb(c,raiz->esq);
  else //anda a direita
    raiz->dir = ins_abb(c,raiz->dir);
 
   return raiz;
}

Arv *remover(Arv*raiz)
{
  if (raiz)   
  {
      raiz->esq = remover(raiz->esq);
      raiz->dir = remover(raiz->dir);
      free(raiz);
      raiz=NULL;
  }
  else
    return NULL;

  return raiz;
}

void impr_pos(Arv * a)//posfixa
{
  if (a!=NULL) 
  {
    impr_pos(a->esq);  // sub esq
    impr_pos(a->dir);  // sub dir
    if (first==true)
    {
      first = false;
      printf("%c",a->info);   //raiz
    }
    else
    {
      printf(" %c",a->info);   //raiz
    }
    
  }
}

void impr_ord(Arv * a)//infixa
{
  if (a!=NULL) {
    impr_ord(a->esq);         //sub esq
    if (first==true)
    {
      printf("%c",a->info );   //raiz
      first = false;
    }
    else
    {
      printf(" %c",a->info );   //raiz
    }
    impr_ord(a->dir);         //sub dir
  }
}

void impr_pre(Arv *a)//prefixa
{
  if (a != NULL)
  {
    if (first == true)
    {
      first = false;
      printf("%c", a->info); //raiz
    }
    else
    {
      printf(" %c", a->info); //raiz
    }
    impr_pre(a->esq); //sub esq
    impr_pre(a->dir); //sub dir
  }
}



int main()
{
  char in[50];
  char infix[] = "INFIXA";
  char prefix[] = "PREFIXA";
  char posfix[] = "POSFIXA";
  Arv*root=NULL;

  while (scanf(" %[^\n]", &in) != EOF)
  {
    if (in[0]=='I' && in[1]==' ')
    {
      root=ins_abb(in[2],root);
    }
    else if (in[0]=='P' && in[1]==' ')
    {
      //rodar código de busca
    }
    else if (strcmp(in,infix)==0)
    {
      impr_ord(root);
      printf("\n");
    }
    else if (strcmp(in,posfix)==0)
    {
      impr_pos(root);
      printf("\n");
    }
    else if (strcmp(in,prefix)==0)
    {
      impr_pre(root);
      printf("\n");
    } 
    first = true;
  }
    return 0;
}
