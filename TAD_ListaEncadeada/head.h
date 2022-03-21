typedef struct{
    int cod;
    char nome[50];
    float real;
}INFO;

typedef struct NO Nodo;
struct NO{
    INFO info;
    Nodo *prox;
};

typedef struct{
    Nodo *inicio;
    int tamanho;
}Lista;

void inicializa(Lista *lista);
void insereInicio(Lista *lista);
void insereFim(Lista *lista);
void insereOrdenado(Lista *lista);
void imprimir(Lista *lista);
Lista* remover(Lista* lista, int cod);
void destruir(Lista *lista);
void imprimeDado(INFO info);
void lerDados(INFO *info);

