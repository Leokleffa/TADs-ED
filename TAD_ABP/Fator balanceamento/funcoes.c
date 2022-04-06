#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "header.h"

Nodo* inicializa(){
    return NULL;
}

void preFixadoEsq(Nodo* a){
    if (a!= NULL)
    {
        printf("%d\n",a->info);
        preFixadoEsq(a->esq);
        preFixadoEsq(a->dir);
    }
}

Nodo* InsereArvore(Nodo *a, int ch){
    if(a==NULL){
        a=(Nodo*) malloc(sizeof(Nodo));
        a->info=ch;
        a->esq=NULL;
        a->dir=NULL;
    }
    else{
        if(ch<(a->info))
            a->esq=InsereArvore(a->esq,ch);
        else
            a->dir=InsereArvore(a->dir,ch);
    }
    return a;
}

int contaNodos(Nodo *a){
    if(a==NULL)
        return 0;
    else
        return 1+contaNodos(a->dir)+contaNodos(a->esq);
}

void imprimirNivel(Nodo *raiz, int cont){
    int i;

    if(raiz!=NULL){
        for(i=0;i<=cont;i++)
            printf("=");
        printf("%d\n", raiz->info);
        cont++;
        imprimirNivel(raiz->esq, cont);
        imprimirNivel(raiz->dir, cont);
    }
}

int Altura(Nodo *raiz)
{
    int auxE, auxD;
     if (raiz==NULL)
        return 0;
     else
     {
         auxE=Altura(raiz->esq);
         auxD=Altura(raiz->dir);
         if (auxE>auxD)
            return (1 + auxE);
         else
            return (1 + auxD);
     }
}

void fatorArv(Nodo *a, int *fator){
    int aux;
    if(a!=NULL){
        aux=abs(Altura(a->esq)-Altura(a->dir));
        if(aux > *fator)
            *fator=aux;
        fatorArv(a->esq, fator);
        fatorArv(a->dir, fator);
    }
}

Nodo* destruir(Nodo *a){
    if(a!=NULL){
        destruir(a->esq);
        destruir(a->dir);
        free(a);
    }
    return NULL;
}
