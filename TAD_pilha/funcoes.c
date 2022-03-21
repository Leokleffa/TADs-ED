#include <stdio.h>
#include <stdlib.h>
#include "header.h"

void inicializa(Pilha *pilha){
    pilha->topo=NULL;
}

void imprimeDado(INFO info){
    printf("codigo: %d\n", info.cod);
    printf("nome: %s\n",info.nome);
    printf("preco: %f\n", info.preco);
}

void lerDados(INFO *info){
    printf("codigo:");
    scanf("%d", &info->cod);
    printf("nome:");
    getchar();
    gets(info->nome);
    printf("preco:");
    scanf("%.2f", &info->preco);
}

int PilhaVazia (Pilha *pilha)
{
    if (pilha->topo==NULL)
       return 1;
    else
       return 0;
}

void push(Pilha *pilha){ //inserir no topo
    Nodo *novo=(Nodo*)malloc(sizeof(Nodo));

    lerDados(&novo->info);
    novo->prox=pilha->topo;
    pilha->topo=novo;
}

INFO* pop(Pilha *pilha){ //remove o topo e retorna as info do topo removido
    Nodo *aux=pilha->topo;
    INFO *auxInfo;
    if(pilha->topo==NULL)
        return NULL;
    else{
        *auxInfo=pilha->topo->info;
        pilha->topo=pilha->topo->prox;
        free(aux);
    }
    return auxInfo;
}

INFO* consultaPilha(Pilha *pilha){
    if(PilhaVazia(pilha)==1)
        return NULL;
    else
        return &pilha->topo->info;
}

Pilha* DestroiPilha (Pilha *pilha){
    Nodo *aux;
    while (pilha->topo!=NULL){
        aux=pilha->topo;          //guarda o endereço do topo
        pilha->topo=pilha->topo->prox;     //o próximo passa a ser o topo
        free(aux);           //libera o que estava no topo
    }
    return NULL;
}

void ImprimirPilha(Pilha *pilha){
    Nodo *aux;

    if (pilha->topo!=NULL){
        puts("---Imprimindo pilha---");
        for (aux=pilha->topo; aux!=NULL; aux=aux->prox)
            imprimeDado(aux->info);
    }
     else
         puts("Pilha vazia");
}

void ImprimirTopo(Pilha *pilha){
    Nodo *aux;

    if (pilha->topo!=NULL){
        aux=pilha->topo;
        imprimeDado(aux->info);
    }
     else
         puts("Pilha vazia");
}
