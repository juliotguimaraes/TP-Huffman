#ifndef huffman_H
#define huffman_H

#include "tabelaf.h"
#include <stdio.h>

typedef struct no *Apontador;

typedef struct no{
        int ocorrencia;
        int codi;
        int precisao;
        char caracter;
        Apontador esq,dir;
}no;

typedef struct celula *ApontadorCelula;

typedef struct celula{
        no Arvore;
        ApontadorCelula prox;
}celula;

typedef struct{
        ApontadorCelula Primeiro,Ultimo;
}TipoLista;

void listaVazia(TipoLista *);
void insereL(TipoLista *, no);
void ordenaL(TipoLista *);
void constroi(no *, TabelaFrequencia *);
void juntaArvore(TipoLista *);
void criaCaracter(no *, int, int);
void decTobin(int *,int, int);
void insereT(no *, TabelaFrequencia *);
void printResult(TabelaFrequencia *, char *);

#endif
