#include <stdio.h>
#include <stdlib.h>

typedef struct arv{
  int info;
  struct arv *dir;
  struct arv *esq;
}Arv;

Arv *ins_abb(int c, Arv*raiz){
  if(raiz == NULL){
    Arv*n=(Arv*)malloc(sizeof(Arv));
    n->info = c;
    n->dir = n->esq = NULL;
    return n;
  }else
  if (c < raiz->info) //anda a esquerda
    raiz->esq = ins_abb(c,raiz->esq);
  else                //anda a direita
    raiz->dir = ins_abb(c,raiz->dir);
    
   return raiz;
}


Arv *remover(int c, Arv*raiz){
  if (raiz == NULL)
    return NULL;
  else
  if (raiz->info > c) //elemento está a esquerda
    raiz->esq = remover(c,raiz->esq);
  else
  if (raiz->info < c) //elemento está a direita
      raiz->dir = remover(c,raiz->dir);
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
    raiz->esq = remover(c,raiz->esq);//remove c, a partir da esquerda da raiz original
    }
  }
  return raiz;
}


void impr_pre(Arv * a){
  if (a!=NULL) {
    printf("%d ",a->info);   //raiz
    impr_pre(a->esq);         //sub esq
    impr_pre(a->dir);         //sub dir
  }
}

void impr_ord(Arv * a){
  if (a!=NULL) {
    impr_ord(a->esq);         //sub esq
    printf("%d ",a->info );   //raiz
    impr_ord(a->dir);         //sub dir
  }
}

void impr_pos(Arv * a){
  if (a!=NULL) {
    impr_pos(a->esq);         //sub esq
    impr_pos(a->dir);         //sub dir
    printf("%d ",a->info );   //raiz
  }
}