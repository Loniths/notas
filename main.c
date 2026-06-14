#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Complementos/app.h"
#include "Complementos/vetor.h"

int main()
{
    App app;
    FILE *arq;
    arq = fopen("notas", "rt");
    if(arq != NULL)
    {
        int linhas = conseguirlinhas(arq);
        app.notas = malloc(linhas * sizeof(Nota));
        if(app.notas == NULL)
        {
            printf("Erro ao alocar a memória\n");
            return 1;
        }
        app.capacidade = linhas;
        app.ocupados = lernotas(arq, app.notas);
        app.notaativa = 0;
        // idealmente, todas as notas são válidas no arquivo
        // porem caso n seja, os espaços vazios vão ficar sobrando
        // sendo uteis para quando o usuario adicionar mais notas
    }
    else
    {
        app.notas = malloc(10 * sizeof(Nota));
        if(app.notas = NULL)
        {
            printf("Erro ao alocar a memória\n");
            return 1;
        }
        app.capacidade = 10;
        // acabei escolhendo 10 já que não é mto grande
        // nem muito pequeno
        app.ocupados = 0;
        app.notaativa = 0;
    }
} 
