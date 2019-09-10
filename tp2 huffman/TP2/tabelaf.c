#include "tabelaf.h"
#include <stdio.h>
#include <string.h>

void inicializaTabela(TabelaFrequencia *Tabela){
	int i;	char caracter;
	caracter = 'z';
	for(i=0; i<MAX/2 ; i++){
		Tabela->Simbolos[i].caracter = caracter;
		Tabela->Simbolos[i].ocorrencia = 0;
		caracter--;
	}
	caracter = 'Z';
	for(i=i; i<MAX-1; i++){
		Tabela->Simbolos[i].caracter = caracter;
		Tabela->Simbolos[i].ocorrencia = 0;
		caracter--;
	}
	Tabela->Simbolos[i].caracter = ' ';
	Tabela->Simbolos[i].ocorrencia = 0;
}

int getTam(TabelaFrequencia *Tabela){
	int i = MAX-1;
	while ( Tabela->Simbolos[i].ocorrencia != 0 && i < MAX) {i--;}
	return i+1;
}

void insere(TabelaFrequencia *Tabela, char * string){
	int tamanhostring , i, indice, esq, dir;
	tamanhostring = strlen(string);
	for(i=0; i<tamanhostring; i++){
		esq  = 0; dir  = MAX - 1;
		do{
			indice = ( esq + dir )/2 ;
			if(string[i] < Tabela->Simbolos[indice].caracter) 
				esq = indice + 1;
			else 
				dir = indice - 1;

		}while(Tabela->Simbolos[indice].caracter != string[i]);
		Tabela->Simbolos[indice].ocorrencia ++;
	}
}

void ordena(TabelaFrequencia *Tabela){

	int i, j, max, aux;
	char str;
	for(i = MAX-1; i > 0; i--){
		max = i;
		for(j = i-1; j >=0; j--){
			if(Tabela->Simbolos[j].ocorrencia > Tabela->Simbolos[max].ocorrencia || (Tabela->Simbolos[j].ocorrencia == Tabela->Simbolos[max].ocorrencia && Tabela->Simbolos[j].caracter < Tabela->Simbolos[max].caracter)){
				max = j;
			}
		}
		if(i != max){
			aux = Tabela->Simbolos[i].ocorrencia;
			str = Tabela->Simbolos[i].caracter;
			Tabela->Simbolos[i].ocorrencia = Tabela->Simbolos[max].ocorrencia;
			Tabela->Simbolos[i].caracter = Tabela->Simbolos[max].caracter;
			Tabela->Simbolos[max].ocorrencia = aux;
			Tabela->Simbolos[max].caracter = str;
		}
	}
}