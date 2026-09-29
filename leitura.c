#include <stdio.h>
#include <string.h>
#include "LEITURA.h"

int carregarCatalogo(Filme catalogo[], int tamMax){
     FILE *arquivo = fopen(NOME_ARQUIVO, "r");
    if (arquivo == NULL) {
        printf("\nErro: nao foi possivel abrir o arquivo '%s'.\n\n", NOME_ARQUIVO);
        return -1;
    }

    char linha[TAM_TITULO + 50];
    int quantidade;


    if (fgets(linha, sizeof(linha), arquivo) == NULL ||
        sscanf(linha, "%d", &quantidade) != 1) {
        printf("\nErro: nao foi possivel ler a quantidade de filmes no arquivo.\n\n");
        fclose(arquivo);
        return -1;
    }

    if (quantidade < 0 || quantidade > tamMax) {
        printf("\nErro: quantidade de filmes invalida no arquivo (%d).\n\n", quantidade);
        fclose(arquivo);
        return -1;
    }

    int total = 0;
    int numeroLinha = 1;

     while (total < quantidade && fgets(linha, sizeof(linha), arquivo) != NULL) {
        numeroLinha++;

       
        linha[strcspn(linha, "\r\n")] = '\0';

        if (strlen(linha) == 0) {
            continue; 
        }

        char titulo[TAM_TITULO];
        int ano, nota;

 
        int lidos = sscanf(linha, "%99[^;];%d;%d", titulo, &ano, &nota);

        if (lidos != 3) {
            printf("Aviso: linha %d fora do formato esperado. Ignorada.\n", numeroLinha);
            continue;
        }

        if (ano <= 0) {
            printf("Aviso: ano de lancamento invalido na linha %d. Ignorada.\n", numeroLinha);
            continue;
        }

        if (nota < 0 || nota > 10) {
            printf("Aviso: nota invalida na linha %d (deve ser 0-10). Ignorada.\n", numeroLinha);
            continue;
        }

        strcpy(catalogo[total].titulo, titulo);
        catalogo[total].anoLancamento = ano;
        catalogo[total].nota = nota;
        total++;
    }

    fclose(arquivo);
    return total;
}



