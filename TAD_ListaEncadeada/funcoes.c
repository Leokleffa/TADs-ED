#include <stdlib.h>
#include <stdio.h>
#include "head.h"

void inicializa(Lista *lista){
    lista->tamanho=0;
    lista->inicio=NULL;
}

void imprimeDado(INFO info){
    printf("codigo: %d\n", info.cod);
    printf("nome: %s\n",info.nome);
    printf("preco: %f\n", info.real);
}

void lerDados(INFO *info){
    printf("codigo:");
    scanf("%d", &info->cod);
    printf("nome:");
    getchar();
    gets(info->nome);
    printf("preco:");
    scanf("%.2f", &info->real);
}

void insereInicio(Lista *lista){
    Nodo *no=(Nodo*)malloc(sizeof(Nodo));

    no->prox=lista->inicio;
    lista->inicio=no;
    lerDados(&no->info);;
    lista->tamanho++;
}

void insereFim(Lista *lista){
    Nodo *no, *aux;

    no=(Nodo*)malloc(sizeof(Nodo));

    if(lista->inicio!=NULL){
        aux=lista->inicio;
        while(aux->prox!=NULL)
            aux=aux->prox;
        aux->prox=no;
    }
    else{
        lista->inicio=no;
    }
    no->prox=NULL;
    lerDados(&no->info);;
    lista->tamanho++;
}

void insereOrdenado(Lista *lista){
    Nodo *no=(Nodo*)malloc(sizeof(Nodo));
    Nodo *aux;

    lerDados(&no->info);
    aux=lista->inicio;
    if(lista->inicio==NULL || no->info.cod < aux->info.cod){
        no->prox=lista->inicio;
        lista->inicio=no;
    }
    else{
        while(aux->prox!=NULL && no->info.cod > aux->prox->info.cod)
            aux=aux->prox;
        no->prox=aux->prox;
        aux->prox=no;
    }
    lista->tamanho++;
}

void imprimir(Lista *lista){
    Nodo *aux=(Nodo*)malloc(sizeof(Nodo));

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

void imprimirInvertido(Lista *lista){
    Nodo *aux=lista->inicio;

    if(lista->inicio==NULL)
        printf("Lista vazia!\n");
    else{
        imprimirInvertido(&aux->prox);
        imprimeDado(aux->info);
    }
}

Lista* remover(Lista* lista, int cod){
    Nodo *ant=NULL;
    Nodo *aux=lista->inicio;

    while(aux!=NULL && aux->info.cod!=cod){
        ant=aux;
        aux=aux->prox;
    }
    if (aux==NULL) /*verifica se achou*/
        return lista; /*retorna a lista original*/
    if (ant==NULL) /*vai remover o primeiro elemento*/
        lista->inicio=aux->prox;
    else /*vai remover do meio ou do final*/
        ant->prox=aux->prox;

    free(aux); /*libera a memória alocada*/
    return lista;
}

void destruir(Lista *lista){
    Nodo *aux;

    while(lista->inicio!=NULL){
        aux=lista->inicio;
        lista->inicio=lista->inicio->prox;
        free(aux);
    }
}
