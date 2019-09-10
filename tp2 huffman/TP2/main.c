#include <stdio.h>
#include "tabelaf.h"
#include "huffman.h"

int main ( int argc, char *arvg[] ) {

	TabelaFrequencia tabela;
	no arvore;
	char *str;

	inicializaTabela(&tabela);
	str = (char*) malloc(sizeof(char)*10001);
	
	scanf("%[^\n]",str);
	insere(&tabela,str);
	ordena(&tabela);
	constroi(&arvore,&tabela);
	criaCaracter(&arvore,0,0);
	insereT(&arvore,&tabela);
	printResult(&tabela,str);

	return 0;
}
