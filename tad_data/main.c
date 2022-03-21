# include<stdio.h>
# include<stdlib.h>
#include<locale.h>
# include "data.h"
int main ()
{
    Data d1, d2;
    setlocale(LC_ALL,"");

    printf("Data 1\n");
    le_data(&d1);
    if (valida_data(d1)){
        printf("data 1 válida\n\n");
        printf("Data 2:\n");
        le_data(&d2);
        if(valida_data(d2)){
            printf("data 2 válida\n");
            printf("O número de dias entre a data 1 e data 2 é igual a %d", dias_entredatas(d1,d2));
            printf("\n");
            imprime_data(data_pascoa(d1.ano));
            if(d1.ano!=d2.ano)
                imprime_data(data_pascoa(d2.ano));
            printf("\n");
        }
        else
           printf("data 2 inválida\n");
    }
    else
        printf("data 1 inválida\n");
    return 0;
}
