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
void centralEsq(Nodo *a){
    if (a!= NULL)
    {
        preFixadoEsq(a->esq);
        printf("%d\n",a->info);
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

int contaFolhas(Nodo *a){
    if(a==NULL)
        return 0;
    else if(a->dir==NULL && a->esq==NULL)
        return 1;
    else
        return contaFolhas(a->esq)+contaFolhas(a->dir);
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

/*float eval(Nodo p) {
    float valE, valD;
    if (!p->esq && !p->dir)
        return valor[p->info-’a’];
    valE = eval(p->esq, valor);
    valD = eval(p->dir, valor);
    switch (p->info) {
        case ’+’ : return valE + valD;
        case ’-’ : return valE - valD;
        case ’*’ : return valE * valD;
        case ’/’ : return valE / valD;
        case ’^’ : return pow(valE, valD);
        default: Erro("Tem algo errado na ´arvore!\n");
    }
}*/

/*int estrita(Nodo *a, int aux){
    if(a==NULL)
        return 0;
    if(a->dir==NULL && a->dir==NULL)
        return aux;
    else if(a->dir!=NULL && a->dir!=NULL){
        aux=estrita(a->esq);
        aux=estrita(a->dir);
    }
    else
        return 1;
}*/

int XXX(Nodo *a){
     int alt_esq, alt_dir;
     if (a!=NULL)
     {
     alt_esq = Altura(a->esq);
     alt_dir = Altura(a->dir);
     return ( (alt_esq - alt_dir <2) && (alt_dir - alt_esq <2) && (XXX(a->esq)) && (XXX(a->dir)) );
     }
     else
     return 1;
}

void insereIterativa(Nodo **a, int valor){
    Nodo *aux=*a;
    while(aux!=NULL){
        if(aux->info>valor)
            a=&aux->esq;
        else
            a=&aux->dir;
        aux=*a;
    }
    aux=(Nodo*)malloc(sizeof(Nodo));
    aux->info=valor;
    aux->dir=NULL;
    aux->esq=NULL;
    *a=aux;
}

Nodo* busca(Nodo *raiz, int valor){
    if(raiz!=NULL){
        if(valor==raiz->info)
            return raiz;
        else if(valor<raiz->info)
            return busca(raiz->esq,valor);
        else
            return busca(raiz->dir,valor);
    }
    return NULL;
}

Nodo* inter(Nodo *a, Nodo *b, Nodo *c){
    if(a!=NULL){
        if(busca(b,a->info)!=NULL)
            c=InsereArvore(c,a->info);
        c=inter(a->esq,b,c);
        c=inter(a->dir,b,c);
    }
    return c;
}

int testaIgual(Nodo *a, Nodo *b, int igual){            //igual inicia com 1, se ficar 0 a função retorna 0
    if(a != NULL && b != NULL && igual == 1){
        if(a->info == b->info){
            testaIgual(a->esq, b->esq, igual);
            testaIgual(a->dir, b->dir, igual);
        }
        else{
            igual = 0;
        }
    }
    else
        igual=0;
    return igual;
}

/*void Largura(Arv p) {
    inicializa_fila();
    if (!p)
        ins_fila(p);
    while (!fila_vazia()) {
        p = rem_fila();
        Visite(p);
        if (p->esq)
            ins_fila(p->esq);
        if (p->dir)
            ins_fila(p->dir);
    }
    finaliza_fila();
}*/

/*
        função para remover nós da Árvore binária
*/
Nodo* remover(Nodo *raiz, int chave) {
    if(raiz == NULL){
        printf("Valor nao encontrado!\n");
        return NULL;
    } else { // procura o nó a remover
        if(raiz->info == chave) {
            // remove nós folhas (nós sem filhos)
            if(raiz->esq == NULL && raiz->dir == NULL) {
                free(raiz);
                printf("Elemento folha removido: %d !\n", chave);
                return NULL;
            }
            else{
                // remover nós que possuem 2 filhos
                if(raiz->esq != NULL && raiz->dir != NULL){
                    Nodo *aux = raiz->esq;
                    while(aux->dir != NULL)
                        aux = aux->dir;
                    raiz->info = aux->info;
                    aux->info = chave;
                    printf("Elemento trocado: %d !\n", chave);
                    raiz->esq = remover(raiz->esq, chave);
                    return raiz;
                }
                else{
                    // remover nós que possuem apenas 1 filho
                    Nodo *aux;
                    if(raiz->esq != NULL)
                        aux = raiz->esq;
                    else
                        aux = raiz->dir;
                    free(raiz);
                    printf("Elemento com 1 filho removido: %d !\n", chave);
                    return aux;
                }
            }
        } else {
            if(chave < raiz->info)
                raiz->esq = remover(raiz->esq, chave);
            else
                raiz->dir = remover(raiz->dir, chave);
            return raiz;
        }
    }
}

