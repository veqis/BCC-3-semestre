#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct arv {
    int info;
    int nivel;
    struct arv* dir;
    struct arv* esq;
} Arv;

Arv* insert(int c, int niv, Arv* raiz) {
    if (raiz == NULL) {
        Arv* novo = (Arv*)malloc(sizeof(Arv));
        novo->info = c;
        novo->nivel = niv;
        novo->dir = novo->esq = NULL;
        return novo;
    } else if (c < raiz->info) {
        raiz->esq = insert(c, niv + 1, raiz->esq);
    } else {
        raiz->dir = insert(c, niv + 1, raiz->dir);
    }
    return raiz;
}

void impr_nivel(Arv* raiz, int nivel_atual) {
    if (raiz == NULL) {
        return;
    }

    if (raiz->nivel == nivel_atual) {
        printf("%d ", raiz->info);
    }

    impr_nivel(raiz->esq, nivel_atual + 1);
    impr_nivel(raiz->dir, nivel_atual + 1);
}

int main() {
    Arv* root = NULL;
    int runs, qtd, in;

    scanf("%d", &runs);
    for (int i = 0; i < runs; i++) {
        root = NULL;

        scanf("%d", &qtd);
        for (int b = 0; b < qtd; b++) {
            scanf("%d", &in);
            root = insert(in, 0, root);
        }

        for (int nivel = 0; nivel < qtd; nivel++) {
            impr_nivel(root, nivel);
        }
        printf("\n");
    }

    return 0;
}
