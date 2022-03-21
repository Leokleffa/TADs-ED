/*Nome: Leonardo Kauer Leffa        Cartão: 00333399*/
typedef struct{
    int posicao_vetor; //posição em que o desempregado está no vetor
    int numero; //número dado ao desempregado
    int K; //indica se o desempregado foi escolhido pela contagem 1
    int M; //indica se o desempregado foi escolhido pela contagem 2
}DESEMPREGADO;

typedef struct{
    int inicio;
    int fim;
}DESCRITOR;

/*--------------------Operações Básicas--------------------*/
void inicializa (DESEMPREGADO d[], DESCRITOR *d); /*inicializa as variáveis do descritor e percorre o array zerando todas as posições*/

int insere (DESEMPREGADO d[], DESCRITOR *d, int posicao); /*insere um novo produto na posição desejada e atualiza descritor*/

int remove (DESEMPREGADO d[], DESCRITOR *d, int posicao); /*remove o produto da posição especificada deslocando os elementos do array*/

DESEMPREGADO consulta (DESEMPREGADO d[], DESCRITOR d, int posicao); /*consulta o elemento da posição especificada*/

void destroi (DESEMPREGADO d[], DESCRITOR *d); /* reinicializa o array*/
/*---------------------------------------------------------*/

/*--------------------Operações Problema-------------------*/
void enumera_horario(DESEMPREGADO d[], DESCRITOR *d); /*A função escolhe um número randômico(n) entre 0 e N-1 (inclusive) e enumera de 1 a N
sendo 1 na posição n, sendo 2 na posição n+1%N, sendo 3 na posição n+2%N, assim por diante.*/

void escolhe1_horaio(DESEMPREGADO d[], DESCRITOR d); /*A função escolhe um número randômico(k) entre 0 e N-1 (inclusive) e escolherá o desempregado
da posição n+k%N. Assim, aumentará K=K+1; para identificar o desempregado escolhido na primeira escolha.*/

void escolhe2_antihoraio(DESEMPREGADO d[], DESCRITOR d);/*A função escolhe um número randômico(m) entre 0 e N-1 (inclusive) e escolherá o desempregado
da posição n-m%N. Assim, aumentará M=M+1; para identificar o desempregado escolhido na segunda escolha.*/

int analisa_escolha(DESEMPREGADO d[], DESCRITOR d, int posicao);/*A função testa e, caso necessário, atualiza  a situação do desempregado caso ele
seja escolhido, analisando se K==0, K==1, M==0 ou M==1; e zera o número de identificação do desempregado se deixar de ser desempregado, senão mantém-se igual.
Além disso, no final, retornará 0 se for desempregado, retornará 1 se for estagiáro ou retornará 2 se for político.*/
/*---------------------------------------------------------*/
