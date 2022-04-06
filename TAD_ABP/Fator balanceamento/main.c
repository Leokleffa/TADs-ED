#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main(){
    Nodo *raiz;
    int cod, i, fator=0;

    raiz=inicializa();
    for(i=0;i<10;i++){
        printf("Insira um codigo:");
        scanf(" %d", &cod);
        raiz=InsereArvore(raiz, cod);
    }
    imprimirNivel(raiz, 0);
    printf("Número de nodos: %d\n", contaNodos(raiz));
    fatorArv(raiz, &fator);
    printf("Fator de balanceamento da arvore: %d\n", fator);
    raiz=destruir(raiz);
    raiz=inicializa();
    for(i=0;i<4;i++){
        printf("Insira um codigo:");
        scanf(" %d", &cod);
        raiz=InsereArvore(raiz, cod);
    }
    imprimirNivel(raiz, 0);
    printf("Número de nodos: %d\n", contaNodos(raiz));
    fatorArv(raiz, &fator);
    printf("Fator de balanceamento da arvore: %d\n", fator);
    raiz=destruir(raiz);
    return 0;
}
