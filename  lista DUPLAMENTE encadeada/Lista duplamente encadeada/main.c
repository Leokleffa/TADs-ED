#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include "header.h"

int main(){
    NODO* lista;
    NODO_INFO info;
    int opcao, codRemover;

    lista=inicializaLista();

    do{
        printf("Digite: \n<0> para fechar o programa\n<1> para inserir um produto\n<2> para imprimir a lista\n<3> para imprimir invertido\n<4>para remover\n\n");
        scanf(" %d", &opcao);
        switch(opcao){
            case 0: break;
            case 1:
                    leDados(&info);
                    lista=inserir_ordenado(lista, info); break;
            case 2: imprime(lista); break;
            case 3: imprimeInvertido(lista); break;
            case 4: printf("Insira o código do produto a ser removido: ");
                    scanf(" %d", &codRemover);
                    lista=remover(lista, codRemover);
                    break;
            default: printf("Opcao invalida!\n\n");
        }
    }while(opcao!=0);

    destruir(&lista);
    imprime(lista);
    imprimeInvertido(lista);
    return 0;
}
