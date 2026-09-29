#include <stdio.h>
#include <string.h>
#include "classificacao.h"


void merge(Filme catalogo[], int esquerda, int meio, int direita) {
    int i, j, k;
    int n1 = meio - esquerda + 1;
    int n2 = direita - meio;

    Filme V_Esquerda[n1];
    Filme V_Direita[n2];


    for (i = 0; i < n1; i++)
        V_Esquerda[i] = catalogo[esquerda + i];
    for (j = 0; j < n2; j++)
        V_Direita[j] = catalogo[meio + 1 + j];


    i = 0; 
    j = 0; 
    k = esquerda; 

    
    while (i < n1 && j < n2) {
        if (V_Esquerda[i].nota >= V_Direita[j].nota) {
            catalogo[k] = V_Esquerda[i];
            i++;
        } else {
            catalogo[k] = V_Direita[j];
            j++;
        }
        k++;
    }

    
    while (i < n1) {
        catalogo[k] = V_Esquerda[i];
        i++;
        k++;
    }


    while (j < n2) {
        catalogo[k] = V_Direita[j];
        j++;
        k++;
    }
}


void mergeSort(Filme catalogo[], int esquerda, int direita) {
    if (esquerda < direita) {
      
        int meio = esquerda + (direita - esquerda) / 2;

      
        mergeSort(catalogo, esquerda, meio);
        mergeSort(catalogo, meio + 1, direita);

       
        merge(catalogo, esquerda, meio, direita);
    }
}
