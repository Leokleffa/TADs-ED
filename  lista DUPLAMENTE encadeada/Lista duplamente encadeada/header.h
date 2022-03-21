typedef struct{
    int cod;
    char nome[50];
    float preco;
}NODO_INFO;

typedef struct nodo{
    NODO_INFO info;
    struct nodo* prox;
    struct nodo* ant;
}NODO;


NODO* inicializaLista();

void leDados(NODO_INFO *info);

NODO* inserir_ordenado(NODO* lista, NODO_INFO info);

void imprime(NODO* lista);

void imprimeInvertido(NODO* lista);

NODO* remover(NODO* lista, int codRemover);

void destruir(NODO** lista);
