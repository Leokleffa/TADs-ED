#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"

NODO* inicializaLista(){
    return NULL;
}

void leDados(NODO_INFO *info){

    printf("Insira o codigo do produto: ");
    scanf(" %d", &info->cod);
    printf("Insira o nome do produto: ");
    getchar();
    gets(info->nome);
    printf("Insira o preco do produto:");
    scanf(" %f", &info->preco);
}

NODO* inserir_ordenado(NODO* lista, NODO_INFO info){
    NODO *novo, *aux=lista;

    novo=(NODO*)malloc(sizeof(NODO));

    novo->info=info;

    if(lista==NULL || lista->info.cod > novo->info.cod){
        novo->prox=lista;
        novo->ant=NULL;
        if(lista!=NULL)
            lista->ant=novo;
        return novo;
    }
    else{
        while(info.cod > aux->prox->info.cod && aux->prox!=NULL)
            aux=aux->prox;
        novo->ant=aux;
        novo->prox=aux->prox;
        aux->prox=novo;
        if(novo->prox!=NULL)
            novo->prox->ant=novo;
        return lista;
    }
}

void imprime(NODO* lista){
    NODO* aux;
    char str[60]="Nome: ";
    if(lista==NULL){
        printf("\n------------------------------\n");
        printf("Lista vazia!");
        printf("\n------------------------------\n");
    }
    else{
        aux=lista;
        while(aux!=NULL){
            printf("\n------------------------------\n");
            printf("Codigo: %d\n", aux->info.cod);
            puts(strcat(str,aux->info.nome));
            printf("Preco: %.2f\n", aux->info.preco);
            aux=aux->prox;
        }
        printf("\n------------------------------\n");
    }
}

void imprimeInvertido(NODO* lista){
    NODO* aux;
    char str[60]="Nome: ";
    if(lista==NULL){
        printf("\n------------------------------\n");
        printf("Lista vazia!");
        printf("\n------------------------------\n");
    }
    else{
        aux=lista;
        while(aux->prox!=NULL)
            aux=aux->prox;
        while(aux!=NULL){
            printf("\n------------------------------\n");
            printf("Codigo: %d\n", aux->info.cod);
            puts(strcat(str,aux->info.nome));
            printf("Preco: %.2f\n", aux->info.preco);
            aux=aux->ant;
        }
        printf("\n------------------------------\n");
    }
}

NODO* remover(NODO* lista, int codRemover){
    NODO *aux=lista;

    while(aux!=NULL && codRemover!=aux->info.cod)
        aux=aux->prox;
    if(codRemover!=aux->info.cod || aux==NULL)
        return lista;
    if(aux->ant==NULL){
        printf("Removendo o primeiro da lista\n");
        lista=lista->prox;
        if(lista!=NULL)
            lista->ant=NULL;
    }
    else{
        aux->ant->prox-aux->prox;
        if(aux->prox!=NULL)
            aux->prox->ant=aux->ant;
    }
    free(aux);
    return lista;


}
void destruir(NODO** lista){
    NODO *aux;

    while(*lista!=NULL){
        aux=*lista;
        *lista=(*lista)->prox;
        free(aux);
    }
    *lista=NULL;
}
