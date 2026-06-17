#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"
#include "tela.h"

// arquivo com todas as funções referentes a desenhar algo na tela
// talvez a pior parte do meu trabalho afinal, apresentei uma boa
// dificuldade nela

void desenharfundo(Nota *nota)
{
    int x = nota->retangulo.x;
    int y = nota->retangulo.y;
    int largura = nota->retangulo.largura;
    int altura = nota->retangulo.altura;
    int direita = x + largura - 1;
    int teto = y + altura - 1;
    for(int linha = y; linha <= teto; linha++)
    {
        for(int coluna = x; coluna <= direita; coluna++)
        {
            t_lincol(linha, coluna);
            printf(" ");
        }
    }
}

void linhahorizontal(Ret *ret)
{
    t_lincol(ret->y, ret->x);
    printf("+");
    for(int i = ret->x + 1; i <= ret->x + ret->largura - 2; i++)
    {
        t_lincol(ret->y, i);
        printf("-");
    }
    t_lincol(ret->y, ret->x + ret->largura - 1);
    printf("+");
}

void linhavertical(Ret *ret)
{
    for(int i = ret->y + 1; i < ret->y + ret->altura - 1; i++)
    {
        t_lincol(i, ret-> x);
        printf("|");
        t_lincol(i, ret->x + ret->largura - 1);
        printf("|");
    }
}

void escrevetexto(Nota *nota)
{
    int x = nota->retangulo.x;
    int y = nota->retangulo.y;
    int largura = nota->retangulo.largura;
    int altura = nota->retangulo.altura;
    int pontadireita = x + largura - 1;
    int teto = y + altura - 1;
    int interador = 0;
    for(int linha = y + 1; linha < teto; linha++)
    {
        for(int coluna = x + 1; coluna < pontadireita; coluna++)
        {
            if(nota->texto[interador] == '\0') return;
            t_lincol(linha, coluna);
            printf("%c", nota->texto[interador]);
            interador++;
        }
    }
}

void desenhanota(App *app, int indicador)
{
    t_corfundo(app->notas[indicador].cor.r, app->notas[indicador].cor.g, app->notas[indicador].cor.b);
    desenharfundo(&app->notas[indicador]);
    t_cortexto(255, 255, 255);
    linhahorizontal(&app->notas[indicador].retangulo);
    linhavertical(&app->notas[indicador].retangulo);
    escrevetexto(&app->notas[indicador]);
    // estava tendo muito problema desenhando texto junto com as paredes
    // por isso preferi desenhar as paredes primeiro e depois o texto
    // perdão por qualquer bug causado pela minha incompetencia
    // vou ainda rever um jeito de ajeitar isso
    t_cornormal();
}  

void todasnotas(App *app)
{
    if(app->ocupados <= 0) return;
    for(int i = 0; i < app->ocupados; i++)
    {
        desenhanota(app, i);
    }
}

void desenhartela(App *app)
{
    todasnotas(app);
    t_lincol(app->cursor.y, app->cursor.x);
    printf("_");
}

void desenhaapenastexto(char texto[], App *app)
{
    t_lincol(0, 0);
    int larguratela;
    int alturatela;
    t_tamanho(&larguratela, &alturatela);
    int k = 0;
    for(int i = 0; i <= alturatela; i++)
    {
        for(int j = 0; j <= alturatela; j++)
        {
            t_lincol(i, j);
            if(texto[k] == '\0') 
            {
                t_lincol(app->cursor.y, app->cursor.x);
                printf("_");
                return;
            }
            printf("%c", texto[k]);
            k++;
        }
    }
}