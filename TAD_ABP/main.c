#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
    Nodo *a, *b, *c;
    int cod, i;

    a=inicializa();
    for(i=0;i<7;i++){
        printf("Insira um codigo:");
        scanf(" %d", &cod);
        insereIterativa(&a, cod);
    }
    imprimirNivel(a,0);
    printf("qntd folhas: %d\n", contaFolhas(a));
    printf("Retorno=%d\n",XXX(a));

    b=inicializa();
    for(i=0;i<5;i++){
        printf("Insira um codigo:");
        scanf(" %d", &cod);
        b=InsereArvore(b, cod);
    }
    imprimirNivel(b, 0);
    printf("qntd folhas: %d\n", contaFolhas(b));
    printf("Retorno=%d\n",XXX(b));

    remover(a, 10);
    imprimirNivel(a,0);
    printf("qntd folhas: %d\n", contaFolhas(a));
    printf("Retorno=%d\n",XXX(a));

    c=inicializa();
    c=inter(a,b,c);
    imprimirNivel(c,0);
    printf("Retorno=%d\n",XXX(c));

    a=destruir(a);
    b=destruir(b);
    c=destruir(c);
    return 0;
}
