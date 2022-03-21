#include <stdlib.h>
#include <stdio.h>
#include "header.h"

void inicializacao(Lista *lista){
    lista->inicio=NULL;
    lista->fim=NULL;
    lista->tamanho=0;
}

void leDados(INFO *info){
    printf("codigo: ");
    scanf(" %d", &info->cod);
    printf("nome: ");
    getchar();
    gets(info->nome);
    printf("preco:");
    scanf(" %f", &info->preco);
}

void imprimeDado(INFO info){
    printf("codigo: %d\n", info.cod);
    printf("nome: %s\n",info.nome);
    printf("preco: %.2f\n", info.preco);
}

void inserirInicio(Lista *lista){
    Nodo *no=(Nodo*)malloc(sizeof(Nodo));

    leDados(&no->info);

    if(lista->inicio==NULL){
        no->ant=NULL;
        no->prox=NULL;
        lista->inicio=no;
        lista->fim=no;
    }
    else{
        no->ant=NULL;
        no->prox=lista->inicio;
        lista->inicio->ant=no;
        lista->inicio=no;
    }
    lista->tamanho++;
}

void inserirFim(Lista *lista){
    Nodo *no=(Nodo*)malloc(sizeof(Nodo));

    leDados(&no->info);

    if(lista->inicio==NULL){
        no->ant=NULL;
        no->prox=NULL;
        lista->inicio=no;
        lista->fim=no;
    }
    else{
        lista->fim->prox=no;
        no->ant=lista->fim;
        no->prox=NULL;
        lista->fim=no;
    }
    lista->tamanho++;
}

void inserir_ordenado(Lista* lista){
    Nodo *novo=(Nodo*)malloc(sizeof(Nodo)), *aux=lista->inicio;

    leDados(&novo->info);
    if(lista->inicio==NULL || novo->info.cod<lista->inicio->info.cod){
        novo->prox=lista->inicio;
        novo->ant=NULL;
        if(lista->inicio!=NULL)
            lista->inicio->ant=novo;
        else
            lista->fim=novo;
        lista->inicio=novo;
    }
    else{
        while(aux->prox!=NULL && info.cod>aux->prox->info.cod)
            aux=aux->prox;
        novo->ant=aux;
        novo->prox=aux->prox;
        aux->prox=novo;
        if(novo->prox)
            novo->prox->ant=novo;
        return lista;
    }
    lista->tamanho++;
}

void imprime(Lista* lista){
    Nodo *aux;

    if(lista->inicio==NULL)
            printf("Lista vazia!\n");
    else{
        aux=lista->inicio;
        while(aux!=NULL){
            imprimeDado(aux->info);
            aux=aux->prox;
        }
    }
}

void imprimeInvertido(Lista* lista){
    Nodo* aux=lista->fim;
    if(lista->inicio==NULL)
        printf("Lista vazia!\n");
    else
        while(aux!=NULL){
            imprimeDado(aux->info);
            aux=aux->ant;
        }
}

Lista* remover(Lista* lista, int codRemover){
    Nodo *aux=lista->inicio;

    while(aux!=NULL && codRemover!=aux->info.cod)
        aux=aux->prox;
    if(aux==NULL || codRemover!=aux->info.cod)
        return lista;
    if(aux->ant==NULL){
        lista->inicio=lista->inicio->prox;
        if(lista!=NULL)
            lista->inicio->ant=NULL;
    }
    else{
        aux->ant->prox=aux->prox;
        if(aux->prox!=NULL)
            aux->prox->ant=aux->ant;
    }
    free(aux);
    lista->tamanho--;
    return lista;


}
void destruir(Lista *lista){
    Nodo *aux;
    while(lista->inicio!=NULL){
        aux=lista->inicio;
        lista->inicio= lista->inicio->prox;
        free(aux);
    }
}


