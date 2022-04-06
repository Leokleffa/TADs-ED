typedef struct no{
    int valor;
    struct no *esquerdo, *direito;
    int altura;
}No;

No* novoNo(int x);
int maior(int a, int b);
int fatorDeBalanceamento(No *no);
int alturaDoNo(No *no);
No* rotacaoEsquerda(No *r);
No* rotacaoDireita(No *r);
No* rotacaoEsquerdaDireita(No *r);
No* rotacaoDireitaEsquerda(No *r);
No* balancear(No *raiz);
No* inserir(No *raiz, int x);
No* remover(No *raiz, int chave);
void imprimir(No *raiz, int nivel);
void imprimirNivel(No *raiz, int cont);
