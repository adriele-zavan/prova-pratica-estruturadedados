#include <stdio.h>
#include "menu.h"        // <- estava faltando: eh daqui que vem o tipo "Filme"
#include "leitura.h"
#include "classificacao.h"
#include "busca.h"
#include "notageral.h"

void menuPrincipal(void) {
    Filme catalogo[MAX_FILMES];
    int totalFilmes = 0;
    int catalogoCarregado = 0;
    int catalogoOrdenado = 0;
    int escolha;
    int rodando = 1;

    while (rodando) {
        printf("\n-----Morada do Stream-----\n");
        printf(" 1 - Carregar os filmes do catalogo\n");
        printf(" 2 - Exibir o catalogo ordenado por nota\n");
        printf(" 3 - Buscar filme por nota\n");
        printf(" 4 - Exibir nota geral do catalogo\n");
        printf(" 5 - Sair \n");
        printf("\nEscolha uma opção: ");

        if (scanf("%d", &escolha) != 1) {
            printf("\nEntrada invalida. Digite um numero.\n\n");
           
            continue;
        }
       

        switch (escolha) {

            case 5:
                printf("\nSaindo...\n");
                rodando = 0;
                break;

            case 1: {
                int lidos = carregarCatalogo(catalogo, MAX_FILMES);
                if (lidos >= 0) {
                    totalFilmes = lidos;
                    catalogoCarregado = 1;
                    catalogoOrdenado = 0;
                    printf("\n%d filme(s) foram carregados no catalogo.\n\n", totalFilmes);
                }
                break;
            }

            case 2: {
                if (!catalogoCarregado) {
                    printf("\nCarregue o catalogo primeiro (opcao 1).\n\n");
                    break;
                }
                if (!catalogoOrdenado) {
                    mergeSort(catalogo, 0, totalFilmes - 1);
                    catalogoOrdenado = 1;
                }
                exibirFilmesOrdem(catalogo, totalFilmes);
                break;
            }

            case 3: {
                if (!catalogoCarregado) {
                    printf("\nCarregue o catalogo primeiro (opcao 1).\n\n");
                    break;
                }
                if (!catalogoOrdenado) {
                    mergeSort(catalogo, 0, totalFilmes - 1);
                    catalogoOrdenado = 1;
                }

                int chave;
                printf("\nDigite a nota que deseja buscar (0 a 10): ");
                if (scanf("%d", &chave) != 1) {
                    printf("\nEntrada invalida.\n\n");
                   
                    break;
                }
             

                int indice = buscaBinariaRecursiva(catalogo, 0, totalFilmes - 1, chave);

                if (indice != -1) {
                    printf("\nFilme encontrado: %s (%d)\n\n",
                           catalogo[indice].titulo, catalogo[indice].anoLancamento);
                } else {
                    printf("\nNenhum filme encontrado com a nota %d.\n\n", chave);
                }
                break;
            }

            case 4: {
                if (!catalogoCarregado) {
                    printf("\nCarregue o catalogo primeiro (opcao 1).\n\n");
                    break;
                }
                printf("\nNota geral do catalogo: %.2f\n\n", notaGeral(catalogo, totalFilmes));
                break;
            }

            default:
                printf("\nOpcao invalida!\n\n");
        }
    }
}  
void exibirFilmesOrdem(Filme catalogo[], int n) {
    int limite;

    if (n < 10) {
        limite = n;
    } else {
        limite = 10;
    }

    printf("\n----- CATALOGO ORDENADO POR NOTA -----\n");
    for (int i = 0; i < limite; i++) {
        printf("%dº - %s (%d) - Nota: %d\n",
               i + 1, catalogo[i].titulo, catalogo[i].anoLancamento, catalogo[i].nota);
    }
    printf("----------------------------------------\n\n");
}