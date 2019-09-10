#include "tabelaf.h"
#include "huffman.h"

void listaVazia(TipoLista * Lista){
     Lista->Primeiro = (ApontadorCelula)malloc(sizeof(celula));
     Lista->Primeiro->prox = NULL;
     Lista->Ultimo = Lista->Primeiro;
}

void insereL(TipoLista *Lista, no Arvore){
     Lista->Ultimo->prox = (ApontadorCelula) malloc(sizeof(celula));
     Lista->Ultimo = Lista->Ultimo->prox;
     Lista->Ultimo->prox = NULL;
     Lista->Ultimo->Arvore = Arvore;    
}

void ordenaL(TipoLista *Lista){
	ApontadorCelula p;
	no r;
	for(p = Lista->Primeiro->prox; p->prox != NULL; p = p->prox){
		if(p->Arvore.ocorrencia >= p->prox->Arvore.ocorrencia){
			if(p->Arvore.ocorrencia == p->prox->Arvore.ocorrencia){
				if(p->Arvore.caracter == p->prox->Arvore.caracter){
					r = p->Arvore; p->Arvore = p->prox->Arvore; p->prox->Arvore = r;
				}
				else break;
			}
			else{
				r = p->Arvore; p->Arvore = p->prox->Arvore; p->prox->Arvore = r;
			}
		}

		else 
			break;
	}
}

void juntaArvore(TipoLista *Lista){

    ApontadorCelula p , q , r , s ;
    p = (ApontadorCelula) malloc(sizeof(celula));

    q = Lista->Primeiro->prox; r = q->prox; s = r->prox; 
    p->Arvore.esq = &r->Arvore; p->Arvore.dir = &q->Arvore; p->Arvore.ocorrencia = q->Arvore.ocorrencia + r->Arvore.ocorrencia;
    p->Arvore.caracter = '!';

    p->prox = s;
    Lista->Primeiro->prox = p;
}



void constroi(no *ArvoreHuffman, TabelaFrequencia *Tabela){
    int i , tam;
    tam = getTam(Tabela);
    TipoLista Lista;
    no aux;
    listaVazia(&Lista);

    for(i=tam; i<MAX; i++){
        aux.esq = NULL; aux.dir = NULL; aux.precisao = 0; aux.ocorrencia = Tabela->Simbolos[i].ocorrencia;
        aux.caracter = Tabela->Simbolos[i].caracter;
        insereL(&Lista,aux);
    }
//Errata
    tam = MAX - tam;
    for(i=0; i<tam-1; i++){
        juntaArvore(&Lista); ordenaL(&Lista);
    }
    ArvoreHuffman->ocorrencia = Lista.Primeiro->prox->Arvore.ocorrencia;
    ArvoreHuffman->caracter = Lista.Primeiro->prox->Arvore.caracter;
    ArvoreHuffman->codi= 0; ArvoreHuffman->precisao = 0;
    ArvoreHuffman->esq = Lista.Primeiro->prox->Arvore.esq;
    ArvoreHuffman->dir = Lista.Primeiro->prox->Arvore.dir;

}

void criaCaracter(no *arvore, int cod, int prec){
    if(arvore == NULL) return;
    else{
        arvore->precisao = prec; arvore->codi = cod;
        criaCaracter(arvore->esq,2*arvore->codi ,arvore->precisao +1);
        criaCaracter(arvore->dir,(2*arvore->codi)+1,arvore->precisao +1);
    }
    
}

void insereT(no *arvore, TabelaFrequencia *Tabela){

    int indice ;
    if (arvore == NULL) return;
        if (arvore->caracter != '!'){
            indice = getTam(Tabela);
            for (indice; indice<MAX; indice++){
                if ( Tabela->Simbolos[indice].caracter == arvore->caracter)
                    break;
            }
            Tabela->Simbolos[indice].precisao = arvore->precisao;
            Tabela->Simbolos[indice].binario = (int*) calloc(arvore->precisao,sizeof(int));
            decTobin(Tabela->Simbolos[indice].binario,arvore->codi,arvore->precisao);        
        }
    insereT(arvore->esq,Tabela); insereT(arvore->dir,Tabela);
}

void decTobin(int *binario ,int decimal, int precisao){
    int indice, dividendo , divisor;


    if (decimal == 0 || decimal == 1) {
        binario[precisao-1] = decimal;
    }
    else {
        dividendo = decimal; divisor = 2; indice = precisao-1;
        while (dividendo != 0 ){
            binario[indice] = dividendo % divisor; dividendo = dividendo / divisor; indice--;
        }  
    }
}

void printResult(TabelaFrequencia *Tabela , char *String){
	int tamanhostring, i,j, indice;
	tamanhostring = strlen(String);
	for(i=0; i<tamanhostring; i++){
        int tam = getTam(Tabela);
        for(indice = tam; indice<MAX; indice++){
            if(Tabela->Simbolos[indice].caracter == String[i]) break;
        }
		for(j=0; j<Tabela->Simbolos[indice].precisao; j++) printf("%d",Tabela->Simbolos[indice].binario[j]);
	}

}