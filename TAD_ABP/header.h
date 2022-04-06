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
Nodo* inter(Nodo *a, Nodo *b, Nodo *c);
Nodo* destruir(Nodo *a);
int XXX(Nodo *a);
void insereIterativa(Nodo **a, int valor);
int contaFolhas(Nodo *a);
Nodo* remover(Nodo *raiz, int chave);
