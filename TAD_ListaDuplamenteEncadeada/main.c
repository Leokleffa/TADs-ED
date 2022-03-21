#include "header.h"
#include<stdlib.h>
#include<stdio.h>

int main(){
    Lista lista;
    int opcao, cod;

    inicializacao(&lista);

    do{
        printf("Digite: \n<0> para fechar o programa\n<1> para inserir ordenadamente um produto\n<2> para imprimir a lista\n");
        printf("<3>para inserir no inicio\n<4>para inserir no fim\n<5> para remover um produto\n<6>para destruir e criar outra lista\n");
        printf("<7>para destruir a lista\n<8>para imprimir na ordem inversa\n\n");
        fflush(stdin);
        scanf("%d", &opcao);
        switch(opcao){
            case 0: opcao=0; break;
            //case 1: inserir_ordenado(&lista); break;
            case 2: imprime(&lista); break;
            case 3: inserirInicio(&lista); break;
            case 4: inserirFim(&lista); break;
            case 5: printf("Insira o codigo a ser removido\n");
                    scanf("%d", &cod);
                    remover(&lista, cod);
                    break;
            case 6: destruir(&lista);
                    inicializacao(&lista);
                    break;
            case 7: destruir(&lista); break;
            case 8: imprimeInvertido(&lista); break;
            default: printf("Opcao invalida!\n\n");
        }
    }while(opcao!=0);
    destruir(&lista);
    imprime(&lista);
    getchar();
    return 0;
}


