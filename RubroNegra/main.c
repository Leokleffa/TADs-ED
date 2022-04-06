#include "header.h"

/*----------------------------------------------------------------------------*/
/* Menu fun�oes                                                               */
/*----------------------------------------------------------------------------*/
int arvRN_menu (void) {
    int f;
    printf ("+--------------------------------+\n");
    printf ("+       Arvore Rubro Negra       +\n");
    printf ("+--------------------------------+\n");
    printf ("1 - Inserir                     \n");
    printf ("2 - Remover                     \n");
    printf ("3 - Buscar                      \n");
    printf ("4 - Imprimir                    \n");
    printf ("5 - Esvaziar                    \n");
    printf ("0 - Sair                        \n");
    printf ("Digite o numero da fun�ao RN: ");
    scanf ("%d", &f);
    return f;
}
/*----------------------------------------------------------------------------*/

/*----------------------------------------------------------------------------*/
/* Menu Imprimir                                                              */
/*----------------------------------------------------------------------------*/
int arvRN_menuImprimir (void) {
    int f;
    printf ("+--------------------------------+\n");
    printf ("+            Imprimir            +\n");
    printf ("+       Arvore Rubro Negra       +\n");
    printf ("+--------------------------------+\n");
    printf ("1 - Pre-ordem                     \n");
    printf ("2 - Em ordem                      \n");
    printf ("3 - Pos-ordem                     \n");
    printf ("4 - Voltar                        \n");
    printf ("Digite o numero da fun�ao RN: ");
    scanf ("%d", &f);
    return f;
}
/*----------------------------------------------------------------------------*/

void main () {
    int op, chave;
    Apontador aux;

    arvRN_inicializa();
    system ("clear");
    op = arvRN_menu ();
    while (op != 0) {
        switch (op) {
            case 1: //Inserir
                printf ("Digite o valor da chave que deseja\ninserir na �rvore RN: ");
                scanf ("%d", &chave);
                raiz =  arvRN_insere (raiz, chave);
                system ("clear");
                printf ("A chave foi inserida com sucesso!\n");
            break;
            case 2: //Remover
                printf ("Digite o valor da chave que deseja\nremover da �rvore RN: ");
                scanf ("%d", &chave);
                aux = arvRN_busca (raiz, chave);
                arvRN_remove (raiz, aux);
                system ("clear");
                if (aux != nodonull)
                    printf ("A chave foi removida com sucesso!\n");
                else
                    printf ("Esta chave nao existe.\n");
            break;
            case 3: //Buscar
                printf ("Digite o valor da chave que deseja\nbuscar na �rvore RN: ");
                scanf ("%d", &chave);
                aux = arvRN_busca (raiz, chave);
                system ("clear");
                if (aux == nodonull)
                    printf ("Chave n�o encontrada.\n");
                else
                    printf ("%d\n", aux->chave);
            break;
            case 4: //Imprimir
                system ("clear");
                if (raiz != nodonull) {
                    op = arvRN_menuImprimir ();
                    system ("clear");
                    if (op == 1)
                        arvRN_imprimePreOrdem (raiz);
                    else if (op == 2)
                        arvRN_imprimeEmOrdem (raiz);
                    else if (op == 3)
                        arvRN_imprimePosOrdem (raiz);
                    }
                else
                    printf ("A arvore esta vazia.\n");
            break;
            case 5:
                arvRN_destroi (raiz);
                arvRN_destroi (nodonull);
                arvRN_inicializa();
                system ("clear");
            break;
            default:
            break;
        }
        op = arvRN_menu ();
    }
    arvRN_destroi (raiz);
    arvRN_destroi (nodonull);
}
