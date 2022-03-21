# include<stdio.h>
# include<stdlib.h>
# include<math.h>
# include "data.h"
//lê data
void le_data (Data *d) {
    printf("Dia:");
    scanf(" %d",&d->dia);
    printf("Mes:");
    scanf(" %d",&d->mes);
    printf("Ano:");
    scanf(" %d",&d->ano);
}
/* Valida data */
int valida_data(Data d) {
    if ((d.dia < 1) || (d.dia > 31) || (d.ano>2100) || (d.mes<1) || (d.mes>12))
        return 0;
    else
        return 1;
}
/* Imprime data */
void imprime_data(Data d) {
    printf("%d/%d/%d\n", d.dia, d.mes, d.ano);
}
/*calcula o número de dias entre duas datas*/
int dias_entredatas(Data d1, Data d2){
    return(abs(d1.dia-d2.dia)+30*abs(d1.mes-d2.mes)+360*abs(d1.ano-d2.ano));
}
//calcula a data da Páscoa
Data data_pascoa(int a){
    Data data;
    int c, n, k, i, j, l;
    data.ano=a;
    data.mes=0;
    data.dia=0;
    c = data.ano/100;
    n = data.ano-(19*(data.ano/19));
    k =(c-17)/25;
    i = c-c/4-((c-k)/3)+(19*n)+15;
    i = i-(30*(i/30));
    i = i-((i/28)*(1-(i/28))*(29/(i+1))*((21-n)/11));
    j = data.ano+data.ano/4+i+2-c+c/4;
    j = j-(7*(j/7));
    l = i-j;
    data.mes = 3+((l+40)/44);
    data.dia = l+28-(31*(data.mes/4));

    return data;
}
