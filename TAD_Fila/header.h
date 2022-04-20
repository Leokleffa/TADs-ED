#include <stdio.h>
#include <stdlib.h>

typedef int TipoInfo;


typedef struct noAux{
        TipoInfo dado;
        struct noAux *elo;
}No;

typedef struct filaAux{
      No *prim;
      No *ult;
}Fila;

Fila* InicializaFila (Fila *PtDFila);
TipoInfo ConsultaFila (Fila *PtDFila);
void ImprimirFila (Fila *PtDFila);
int InserirFila(Fila **PtDFila, TipoInfo Dado);
int RemoverFila(Fila **PtDFila, TipoInfo *Dado);
void DestroiFila (Fila **PtDFila);

