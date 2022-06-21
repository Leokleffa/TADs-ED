#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
    Nodo *a, *b, *c;
    int cod, i;

    a=inicializa();
    for(i=0;i<3;i++){
        printf("Insira um codigo:");
        scanf(" %d", &cod);
        insereIterativa(&a, cod);
    }
    imprimirNivel(a,0);
    printf("qntd folhas: %d\n", contaFolhas(a));
    printf("nivel=%d\n",nivel(a, 1,0));
    if(estritaBin(a))
        printf("Estritamente binaria\n");
    else
        printf("Não estritamente binaria\n");

    b=inicializa();/*
    for(i=0;i<5;i++){
        printf("Insira um codigo:");
        scanf(" %d", &cod);
        b=InsereArvore(b, cod);
    }*/
    imprimirNivel(b, 0);
    printf("qntd folhas: %d\n", contaFolhas(b));
    printf("Retorno=%d\n",XXX(b));
    printf("nivel=%d\n",nivel(b, 1,0));
    if(estritaBin(b))
        printf("Estritamente binaria\n");
    else
        printf("Não estritamente binaria\n");

    c=inicializa();
    c=inter(a,b,c);
    imprimirNivel(c,0);

    a=destruir(a);
    b=destruir(b);
    c=destruir(c);
    return 0;
}
