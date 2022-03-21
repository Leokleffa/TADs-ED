typedef struct{
    int cod;
    char nome[50];
    float preco;
}INFO;

typedef struct NO{
    INFO info;
    struct NO *prox;
}Nodo;

typedef struct{
    Nodo *topo;
}Pilha;

