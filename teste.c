#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct cor
{
    int r;
    int g;
    int b;
} Cor;

typedef struct retangulo
{
    int x;
    int y;
    int largura;
    int altura;
} Ret;


typedef struct
{
    char texto[256];
    char etiqueta[4];
    Cor cor;
    Ret retangulo;
} Nota;

int main()
{
    char linha[] = "A12 255 10 10 1 1 5 1 \"Lavar a roupa\"";
    Nota nota;
    char ajuste[100];
    if(sscanf(linha,
          "%3s %d %d %d %d %d %d %d %[^\n]",
          nota.etiqueta,
          &nota.cor.r,
          &nota.cor.g,
          &nota.cor.b,
          &nota.retangulo.x,
          &nota.retangulo.y,
          &nota.retangulo.largura,
          &nota.retangulo.altura,
          ajuste) == 9)
    {
          printf("Leitura OK\n");
    }
    else
    {   
    printf("Leitura FALHOU\n");
    }
    printf("Etiqueta: [%s]\n", nota.etiqueta);
    printf("R: %d\n", nota.cor.r);
    printf("G: %d\n", nota.cor.g);
    printf("B: %d\n", nota.cor.b);

    printf("X: %d\n", nota.retangulo.x);
    printf("Y: %d\n", nota.retangulo.y);
    printf("L: %d\n", nota.retangulo.largura);
    printf("A: %d\n", nota.retangulo.altura);

    printf("Ajuste: [%s]\n", ajuste);
    printf("Tamanho ajuste: %zu\n", strlen(ajuste));
    if(ajuste[strlen(ajuste) - 1] == '"')
    {
        ajuste[strlen(ajuste) - 1] = '\0';
    }
    for(int i = 0;; i++)
    {
        nota.texto[i] = ajuste[i+1];
        if(ajuste[i+1] == '\0') break;
    }
    printf("Texto final: [%s]\n", nota.texto);
}
    /**
    FILE *arq;
    arq = fopen("notas", "rt");
    if(arq != NULL)
    {
        char vettemp1[500];
        int linhas = 0;
        while(fgets(vettemp1, sizeof(temp), arq) != NULL) //serve para contar as linhas do arquivo
        {
            linhas++;   
        }
        rewind(arq); //faz o ponteiro arq voltar para o começo do arquivo
        Nota *notas = malloc(linhas * sizeof(Nota));
        if(notas == NULL)
        {
            printf("Erro ao alocar a memória\n");
            return 1;
        }
        char vettemp2[500];
        for(int i = 0;;)
        {
            if(fgets(vettemp2, sizeof(vettemp2), arq) == NULL) break;
            char ajuste[100];
            if(sscanf(vettemp2, "%3s %d %d %d %d %d %d %d %[^\n]", notas[i].etiqueta, &notas[i].cor.r,
            &notas[i].cor.g, &notas[i].cor.b, &notas[i].retangulo.x, &notas[i].retangulo.y,
            &notas[i].retangulo.largura, &notas[i].retangulo.altura, ajuste) == 9)
            {
                if(ajuste[strlen(ajuste) - 1] == '"')
                {
                    ajuste[strlen(ajuste) - 1] = '\0';
                }
                for(int j = 0;; j++)
                {
                    notas[i].texto[j] = ajuste[j + 1];
                    if(ajuste[j + 1] == '\0') break;
                }
                i++;
            }
        }
    }
} 
    **/
