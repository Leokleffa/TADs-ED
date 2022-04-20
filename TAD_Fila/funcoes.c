#include <stdio.h>
#include <stdlib.h>
#include "header.h"

Fila* InicializaFila (Fila *fila){
    fila = (Fila*) malloc(sizeof(Fila)); //aloca descritor de fila
    if (fila != NULL){ //testa se conseguiu alocar o descritor
        fila->prim = NULL; //inicializa ponteiros
        fila->ult = NULL;
    }
    return fila;
}

TipoInfo ConsultaFila (Fila *fila){
    if (fila->prim == NULL)
        return 0;
    else
        return fila->prim->dado;
}

int InserirFila(Fila **fila, TipoInfo Dado){
    No *novo;
    if (*fila) { //testa se o descritor foi alocado
        novo = (No*) malloc (sizeof(No));
        novo->dado = Dado;
        novo->elo = NULL;
        if ((*fila)->prim == NULL) // vai ser o primeiro da fila
            (*fila)->prim = novo;
        else
            (*fila)->ult->elo = novo; //insere no final
        (*fila)->ult = novo;
        return 1;
    }
    else
        return 0;
}

int RemoverFila(Fila **fila, TipoInfo *Dado){
    Fila *aux;
    if (*fila){ //testa se o descritor foi alocado
        if ((*fila)->prim != NULL){ // testa se tem algum elemento na fila
            aux = (*fila)->prim;
            *Dado = (*fila)->prim->dado;
            (*fila)->prim = (*fila)->prim->elo;
            free(aux);
            if ((*fila)->prim == NULL) //testa se a fila ficou vazia
                (*fila)->ult = NULL;
            return 1;
        }
    }
    else
        return 0;
}

void ImprimirFila (Fila *fila){
    No *aux;
    if (fila){
        if (fila->prim != NULL){
            puts("---Imprimindo fila---");
            for (aux=fila->prim; aux!=NULL; aux=aux->elo)
                printf("%d\n",aux->dado);
            puts("-------Fim fila------");
        }
    }
    else
        puts("Fila vazia");
}

void DestroiFila (Fila **fila){
    Fila *aux;
    while ((*fila)->prim != NULL)
    {
        aux = (*fila)->prim;          //guarda o endereço do primeiro
        (*fila)->prim = (*fila)->prim->elo;     //o próximo passa a ser o topo
        free(aux);           //libera o que estava no topo
    }
    free(*fila);
    *fila = NULL;
}








