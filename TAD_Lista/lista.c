# include<stdio.h>
# include<stdlib.h>
# include<string.h>
# include "lista.h"
#define MAX 7

void inicializa ( TProduto t[], int *inicio, int *fim) {
    int i;
    for (i=0; i<MAX; i++) {
        strcpy(t[i].nome,"");
        t[i].cod=0;
        t[i].preco=0;
    }
    *inicio = -1;
    *fim = -1;
}

int consulta ( TProduto t[], int inicio, int fim, int posicao) {
    if ( posicao > fim - inicio +1 || posicao < 1)
        return -1;
    else
        return t[inicio+posicao-1].cod;
}

void insere ( TProduto t[], int *inicio, int *fim, int posicao) {
    int i;
    if ( ((*inicio == 0) && (*fim == MAX-1)) || //n�o tem espa�o
    (posicao > *fim - *inicio + 2 ) || //posi��o inv�lida
    (posicao < 1) || //posi��o inv�lida
    ((*inicio == -1) && (posicao != 1 )) ) { //lista vazia, s� pode ser o primeiro
        printf("erro - posicao invalida\n");
        return ;
    }
    else if (*inicio ==-1) {
        *inicio = 0;
        *fim = 0;
    }
    else if (*fim != MAX-1) {
        for (i=*fim; i >= *inicio + posicao -1; i--)
            t[i+1] = t[i];
        *fim = *fim + 1;
    }
    else {
        for (i=*inicio; i <= *inicio + posicao-1; i++)
            t[i-1] = t[i];
        *inicio = *inicio - 1;
    }
    /* Lendo os dados*/
    printf("Codigo: "); scanf("%d", &t[*inicio+posicao-1].cod);
    printf("Nome: "); scanf ("%s", t[*inicio+posicao-1].nome);
    printf("Preco: "); scanf ("%f", &t[*inicio+posicao-1].preco);
}

int remover ( TProduto t[], int *inicio, int *fim, int posicao) {
    int i, rem=0;
    if ( (*inicio == -1) || (posicao > *fim - *inicio + 1 ) || (posicao < 1))
        return -1;
    else{
        rem = t[*inicio+posicao-1].cod;
        for (i=*inicio+posicao-1; i <*fim; i++)
            t[i] = t[i+1];
        strcpy(t[*fim].nome,"");
        t[*fim].cod=0;
        t[*fim].preco=0;
        *fim = *fim -1;
        if (*fim == -1) *inicio= -1;
        return rem;
    }
}

void destroi (TProduto t[], int *inicio, int *fim) {
    *inicio = -1;
    *fim = -1;
    inicializa(t,inicio,fim);
}

int busca_posicao_lista (int vet[], int n)
{
    int i = 0;
    while(i < MAX){
        if (vet[i] == n)
            return i;
        else
            i++;
    }
    return -1;
}
