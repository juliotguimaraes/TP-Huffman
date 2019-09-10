#ifndef tabelaf_H
#define tabelaf_H

#define MAX 53 

typedef struct{
	int precisao;
	int ocorrencia;
	int *binario;
	char caracter;
}TipoItem;

typedef struct{
	TipoItem Simbolos[MAX];
}TabelaFrequencia;


void inicializaTabela(TabelaFrequencia *);  
void insere(TabelaFrequencia *, char *); 
void ordena(TabelaFrequencia *); 
int  getTam	(TabelaFrequencia *);
#endif
