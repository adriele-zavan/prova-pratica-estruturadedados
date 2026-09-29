#ifndef FILME_H
#define FILME_H

#define TAM_TITULO 100          
#define MAX_FILMES 1000         
#define NOME_ARQUIVO "filmes.txt" 


typedef struct {
    char titulo[TAM_TITULO];
    int  anoLancamento;     
    int  nota;                
} Filme;

#endif
