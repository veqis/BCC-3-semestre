#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

bool first = true;

typedef struct arv{
    int info;
    struct arv *dir;
    struct arv *esq;
}Arv;

Arv *insert(int c, Arv*raiz)
{
    if (raiz==NULL)
    {
        Arv*novo=(Arv*)malloc(sizeof(Arv));
        novo->info = c;
        novo->dir = novo->esq = NULL;
        return novo;
    }else
        if(c < raiz->info)
            raiz->esq = insert(c,raiz->esq);
        else
            raiz->dir = insert(c,raiz->dir);
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
            root = insert(in,root);
        }
        impr_ord(root);
        printf("\n");
        root = remover(root);
        first = true;
    }
    return 0;
}
