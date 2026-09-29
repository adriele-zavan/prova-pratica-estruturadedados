#include "NOTAGERAL.H"


float notaGeral(Filme catalogo[], int n){
    if (n <= 0){
        return 0.0f;
    }

    long soma = 0;
    for (int i =0; i < n; i++){
        soma += catalogo[i].nota;
    }
    return(float)soma / n;
}