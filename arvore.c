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

Arv *ins_abb(int c, Arv*raiz)
{
  if(raiz == NULL)
  {
    Arv*n=(Arv*)malloc(sizeof(Arv));
    n->info = c;
    n->dir = n->esq = NULL;
    return n;
  }
  if (c < raiz->info) 
    raiz->esq = ins_abb(c,raiz->esq);
  else    
    raiz->dir = ins_abb(c,raiz->dir);
 
   return raiz;
}

Arv *busca(int c, Arv*raiz)
{
  if (raiz == NULL)
  {
    printf("%d nao existe\n",c);
    return NULL;
  }
  if (raiz->info == c)
  {
    printf("%d existe\n",c);
    return 0;
  }
  if (raiz->info > c)
  {
    return busca(c,raiz->esq);
  }
  if (raiz->info < c) 
  {
    return busca(c,raiz->dir);
  }
  return NULL;
}

void impr_pos(Arv * a)
{
  if (a!=NULL) 
  {
    impr_pos(a->esq);
    impr_pos(a->dir); 
    if (first==true)
    {
      first = false;
      printf("%d",a->info);
    }
    else
    {
      printf(" %d",a->info);
    }
    
  }
}

void impr_ord(Arv * a)
{
  if (a!=NULL) {
    impr_ord(a->esq);
    if (first==true)
    {
      printf("%d",a->info );
      first = false;
    }
    else
    {
      printf(" %d",a->info );
    }
    impr_ord(a->dir);
  }
}

void impr_pre(Arv *a)
{
  if (a != NULL)
  {
    if (first == true)
    {
      first = false;
      printf("%d", a->info);
    }
    else
    {
      printf(" %d", a->info);
    }
    impr_pre(a->esq);
    impr_pre(a->dir);
  }
}

Arv* remove_no(int c, Arv *raiz) {
    if (raiz == NULL) 
    {
        return NULL;
    }

    if (c < raiz->info) 
    {
        raiz->esq = remove_no(c, raiz->esq);
        return raiz;
    } else if (c > raiz->info) 
    { 
        raiz->dir = remove_no(c, raiz->dir);
        return raiz;
    } else 
    {
        if (raiz->esq == NULL && raiz->dir == NULL) 
        { 
            free(raiz);
            return NULL;
        } else if (raiz->esq == NULL || raiz->dir == NULL) 
        { 
            Arv *temp = raiz->esq ? raiz->esq : raiz->dir;
            free(raiz);
            return temp;
        } else 
        { 
            Arv *sucessor = raiz->dir;
            while (sucessor->esq != NULL) 
            { 
                sucessor = sucessor->esq;
            }
            raiz->info = sucessor->info;
            raiz->dir = remove_no(sucessor->info, raiz->dir);
            return raiz;
        }
    }
}


int main()
{
  char in[100];
  int num;
  char i[] = "I";
  char p[] = "P";
  char r[] = "R";
  char infix[] = "INFIXA";
  char prefix[] = "PREFIXA";
  char posfix[] = "POSFIXA";
  Arv*root=NULL;

  while (scanf("%s", in) != EOF)
  {
    if (strcmp(in,i)==0)
    {
      scanf("%d",&num);
      root=ins_abb(num,root);
    }
    if (strcmp(in,p)==0)
    {
      scanf("%d",&num);
      busca(num,root);
    }
    if (strcmp(in,r)==0)
    {
      scanf("%d",&num);
      root=remove_no(num,root);
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