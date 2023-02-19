#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct arv{
  char info;
  struct arv *dir;
  struct arv *esq;
}Arv;

Arv *ins_arv(char c, Arv*raiz)
{
  if(raiz == NULL)
  {
    Arv *novo=(Arv*)malloc(sizeof(Arv));
    novo->info = c;
    novo->dir = novo->esq = NULL;
    return novo;
  }
  if(c < raiz->info)
    raiz->esq = ins_arv(c,raiz->esq);
  else
    raiz->dir = ins_arv(c,raiz->dir);

  return raiz;
}

void impr_pre(Arv * a){
  if (a!=NULL) {
    printf("%c",a->info);   //raiz
    impr_pre(a->esq);         //sub esq
    impr_pre(a->dir);         //sub dir
  }
}

void impr_ord(Arv * a){
  if (a!=NULL) {
    impr_ord(a->esq);         //sub esq
    printf("%c",a->info );   //raiz
    impr_ord(a->dir);         //sub dir
  }
}

void impr_pos(Arv * a){
  if (a!=NULL) {
    impr_pos(a->esq);         //sub esq
    impr_pos(a->dir);         //sub dir
    printf("%c",a->info );   //raiz
  }
}

int main()
{
  char in[26];
  Arv* root = NULL;
    while (scanf("%s",in) != EOF)
    {     
      fflush(stdin);
      if (in[0]=='1')//quebra código remover depois somente para testes
        break;

      for (int i = 0; i < (int)strlen(in); i++)
      {
        root = ins_arv(in[i],root);
      }
    }
    impr_ord(root);
    return 0;
}
