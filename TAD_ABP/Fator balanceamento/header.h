typedef struct NO{
    int info;
    struct NO *esq;
    struct NO *dir;
}Nodo;

Nodo* inicializa();
void preFixadoEsq(Nodo* a);
Nodo* InsereArvore(Nodo *a, int info);
int contaNodos(Nodo *a);
void imprimirNivel(Nodo *raiz, int cont);
int Altura(Nodo *raiz);
void fatorArv(Nodo *a, int *zero);
