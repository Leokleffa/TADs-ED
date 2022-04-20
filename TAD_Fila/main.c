#include <stdio.h>
#include <stdlib.h>
#include "header.h"

int main ()
{
    Fila *fila;
    TipoInfo dado;
    int i;

    fila=InicializaFila(fila);

    for (i=1;i<=5;i++){
      InserirFila(&fila, i);
      ImprimirFila(fila);
    }

    printf ("Consulta fila = %d\n",ConsultaFila(fila));

    for (i=1;i<=3;i++){
      RemoverFila(&fila, &dado);
      printf("%d removido da fila\n",dado);
      ImprimirFila(fila);
    }

    DestroiFila (&fila);

    ImprimirFila(fila);

    system("pause");
}

