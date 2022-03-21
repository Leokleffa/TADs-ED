#define MAX 7

typedef struct T_Produto {
    int cod;
    char nome[40];
    float preco;
}TProduto;

int inicio, fim, maximo, num;
TProduto Lista[MAX];

void inicializa (TProduto t[], int *inicio, int *fim);

int consulta ( TProduto t[], int inicio, int fim, int posicao);

void insere ( TProduto t[], int *inicio, int *fim, int posicao);

int remover (TProduto t[], int *inicio, int *fim, int posicao);

void destroi (TProduto t[], int *inicio, int *fim);

int busca1 (int vet[], int num);

