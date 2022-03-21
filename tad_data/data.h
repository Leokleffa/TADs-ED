/*TAD DATA (dd,mm,aaaa)*/
/* TIPO DE DADO exportado */
typedef struct {
    int dia;
    int mes;
    int ano;
}Data;
/* OPERAÇÕES Exportadas */
void le_data (Data *d);//lê data
int valida_data(Data d);//Valida data
void imprime_data(Data d);//Imprime data
int dias_entredatas(Data d1, Data d2);//dia entre duas datas
Data data_pascoa(int a);
