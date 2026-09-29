#ifndef ORDENACAO_H
#define ORDENACAO_H
#include "filme.h"
#include "leitura.h"

#define TAM_TITULO 100          
#define MAX_FILMES 1000         
#define NOME_ARQUIVO "filmes.txt" 



void mergeSort(Filme catalogo[], int esquerda, int direita);
void merge(Filme catalogo[], int esquerda, int meio, int direita);

#endif