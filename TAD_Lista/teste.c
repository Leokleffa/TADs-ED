#include <stdio.h>
#include <stdlib.h>
#define MAX 7
int busca4(int vet[], int n)
{
 int inf = 0, sup = MAX -1, meio;

 while(inf <= sup) {
 meio = (inf + sup)/2;
 printf("meio=%d\n inf=%d\n sup=%d\n", meio, inf, sup);
 if (vet[meio] == n) {
 inf = sup + 1;
 return meio;
 }
 else if (vet[meio] < n) inf = meio +1;
 else sup = meio - 1;
}
if (inf >= sup) return -1;
}
int main()
{
 int v[]={8,7,6,5,4,3,2,1}, i;
 int resultado;
 resultado = busca4(v, 4);
 printf("%d\n", resultado);
 for(i=0;i<MAX;i++)
    printf("\nv[%d]=%d\n", i, v[i]);
 system("pause");
}
