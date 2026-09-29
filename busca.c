#include "BUSCA.H"

int buscaBinariaRecursiva(Filme catalogo[], int inicio, int fim, int chave){
        if (inicio > fim){
            return -1;
        }

    int meio = inicio + (fim - inicio) / 2;

    if (catalogo[meio].nota == chave){
        return meio;
    }else if (catalogo[meio].nota < chave){
        return buscaBinariaRecursiva(catalogo, inicio, meio -1, chave);
    }else{
        return buscaBinariaRecursiva(catalogo,meio + 1, fim, chave);
    }

}