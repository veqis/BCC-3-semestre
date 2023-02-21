#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool first = true;

typedef struct arv{
    int info;
    int nivel;
    struct arv *dir;
    struct arv *esq;
}Arv;

Arv *insert(int c, int niv, Arv*raiz)
{
    if (raiz==NULL)
    {
        Arv*novo=(Arv*)malloc(sizeof(Arv));
        novo->info = c;
        novo->nivel = niv;
        novo->dir = novo->esq = NULL;
        return novo;
    }else
        if(c < raiz->info)
        {
            niv++;
            raiz->esq = insert(c,niv,raiz->esq);
        }
        else
        {
            niv++;
            raiz->dir = insert(c,niv,raiz->dir);
        }
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
    }else
        return NULL;
    return raiz;
}

void impr_ord(Arv * a)
{
  if (a!=NULL) {
    impr_ord(a->esq);
    if (first==true)
    {
      printf("%d->%d",a->info, a->nivel );
      first = false;
    }
    else
    {
      printf(" %d->%d",a->info, a->nivel );
    }
    impr_ord(a->dir);
  }
}

int main()
{
    Arv*root=NULL;
    int runs, qtd, in;
    scanf("%d",&runs);
    for (int i = 0; i < runs; i++)
    {
        scanf("%d",&qtd);
        for (int b = 0; b < qtd; b++)
        {
            scanf("%d",&in);
            root = insert(in,0,root);
        }
        impr_ord(root);
        printf("\n");
        root = remover(root);
        first = true;
    }
    return 0;
}