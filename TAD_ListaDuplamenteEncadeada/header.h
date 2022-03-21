typedef struct{
    int cod;
    char nome[50];
    float preco;
}INFO;

typedef struct NO{
    INFO info;
    struct NO *ant;
    struct NO *prox;
}Nodo;

typedef struct{
    Nodo *inicio;
    Nodo *fim;
    int tamanho;
}Lista;

void inicializacao(Lista *lista);
void leDados(INFO *info);
void imprimeDado(INFO info);
void inserirInicio(Lista *lista);
void inserirFim(Lista *lista);
//void inserir_ordenado(Lista* lista);
void imprime(Lista* lista);
void imprimeInvertido(Lista* lista);
Lista* remover(Lista* lista, int codRemover);
void destruir(Lista *lista);
