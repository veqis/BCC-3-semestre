#include <stdio.h>
#include <stdlib.h>
#include "arvores.h"

int main(){
  int opc;
  int val;
  int curr=0, runs;

  scanf("%d",&runs);

  Arv*a=NULL;
  while (curr!=runs) {
    printf ("(1)inserir (2)remover (3)imprimir (0) sair --> ");
    scanf("%d",&opc );

        printf("Caractere: ");
        scanf(" %d",&val);
        a=ins_abb(val,a);
    curr++;
  }
    system ("clear");
    printf("\npre: "); impr_pre(a);
    printf("\nord: "); impr_ord(a);
    printf("\npos: "); impr_pos(a);
    printf ("\n");

  printf("\n");
  return 0;
}
