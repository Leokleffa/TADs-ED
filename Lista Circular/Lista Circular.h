/*Nome: Leonardo Kauer Leffa        Cart�o: 00333399*/
typedef struct{
    int posicao_vetor; //posi��o em que o desempregado est� no vetor
    int numero; //n�mero dado ao desempregado
    int K; //indica se o desempregado foi escolhido pela contagem 1
    int M; //indica se o desempregado foi escolhido pela contagem 2
}DESEMPREGADO;

typedef struct{
    int inicio;
    int fim;
}DESCRITOR;

/*--------------------Opera��es B�sicas--------------------*/
void inicializa (DESEMPREGADO d[], DESCRITOR *d); /*inicializa as vari�veis do descritor e percorre o array zerando todas as posi��es*/

int insere (DESEMPREGADO d[], DESCRITOR *d, int posicao); /*insere um novo produto na posi��o desejada e atualiza descritor*/

int remove (DESEMPREGADO d[], DESCRITOR *d, int posicao); /*remove o produto da posi��o especificada deslocando os elementos do array*/

DESEMPREGADO consulta (DESEMPREGADO d[], DESCRITOR d, int posicao); /*consulta o elemento da posi��o especificada*/

void destroi (DESEMPREGADO d[], DESCRITOR *d); /* reinicializa o array*/
/*---------------------------------------------------------*/

/*--------------------Opera��es Problema-------------------*/
void enumera_horario(DESEMPREGADO d[], DESCRITOR *d); /*A fun��o escolhe um n�mero rand�mico(n) entre 0 e N-1 (inclusive) e enumera de 1 a N
sendo 1 na posi��o n, sendo 2 na posi��o n+1%N, sendo 3 na posi��o n+2%N, assim por diante.*/

void escolhe1_horaio(DESEMPREGADO d[], DESCRITOR d); /*A fun��o escolhe um n�mero rand�mico(k) entre 0 e N-1 (inclusive) e escolher� o desempregado
da posi��o n+k%N. Assim, aumentar� K=K+1; para identificar o desempregado escolhido na primeira escolha.*/

void escolhe2_antihoraio(DESEMPREGADO d[], DESCRITOR d);/*A fun��o escolhe um n�mero rand�mico(m) entre 0 e N-1 (inclusive) e escolher� o desempregado
da posi��o n-m%N. Assim, aumentar� M=M+1; para identificar o desempregado escolhido na segunda escolha.*/

int analisa_escolha(DESEMPREGADO d[], DESCRITOR d, int posicao);/*A fun��o testa e, caso necess�rio, atualiza  a situa��o do desempregado caso ele
seja escolhido, analisando se K==0, K==1, M==0 ou M==1; e zera o n�mero de identifica��o do desempregado se deixar de ser desempregado, sen�o mant�m-se igual.
Al�m disso, no final, retornar� 0 se for desempregado, retornar� 1 se for estagi�ro ou retornar� 2 se for pol�tico.*/
/*---------------------------------------------------------*/
