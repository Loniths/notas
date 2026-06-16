#include <stdio.h>
#include <stdlib.h>
#include "app.h"
#include "tela.h"
#include "vetor.h"

// arquivo com as funções que movem o cursor
// e também as que modificam o retangulo

void movcursoresq(App *app)
{
    if(app->cursor.x == 0) return;
    app->cursor.x--;
    verificarnotaatual(app);
}

void movcursorcima(App *app)
{
    if(app->cursor.y == 0) return;
    app->cursor.y--;
    verificarnotaatual(app);
}

void movcursorbaixo(App *app)
{
    int alturatela;
    int lixo;
    t_tamanho(&lixo, &alturatela);
    if(app->cursor.y == alturatela) return;
    app->cursor.y++;
    verificarnotaatual;
}

void movcursordir(App *app)
{
    int larguratela;
    int lixo;
    t_tamanho(&larguratela, &lixo);
    if(app->cursor.x == larguratela) return;
    app->cursor.x++;
    verificarnotaatual(app);
}

void movretesq(App *app)
{
    if(app->notas[app->notaativa].retangulo.x > 0)
    {
        app->notas[app->notaativa].retangulo.x--;
    }
}

void movretdir(App *app)
{
    int larguratela;
    int lixo;
    t_tamanho(&larguratela, &lixo);
    if(app->notas[app->notaativa].retangulo.x < larguratela)
    {
        app->notas[app->notaativa].retangulo.x++;
    }
}

void movretbaixo(App *app)
{
    if(app->notas[app->notaativa].retangulo.y > 0)
    {
        app->notas[app->notaativa].retangulo.y--;
    }
}

void movretcima(App *app)
{
    int alturatela;
    int lixo;
    t_tamanho(&lixo, &alturatela);
    if(app->notas[app->notaativa].retangulo.y < alturatela)
    {
        app->notas[app->notaativa].retangulo.y++;
    }
}

void aumentaretesq(App *app)
{
    int larguratela;
    int lixo;
    t_tamanho(&larguratela, &lixo);
    if(app->notas[app->notaativa].retangulo.x > 0 &&
       app->notas[app->notaativa].retangulo.x + app->notas[app->notaativa].retangulo.largura - 1 < larguratela)
    {
        movretesq(app);
        app->notas[app->notaativa].retangulo.largura++;
    }
}

void aumentarretdir(App *app)
{
    int larguratela;
    int lixo;
    t_tamanho(&larguratela, &lixo);
    if(app->notas[app->notaativa].retangulo.x < larguratela &&
        app->notas[app->notaativa].retangulo.x + app->notas[app->notaativa].retangulo.largura < larguratela)
    {
        app->notas[app->notaativa].retangulo.largura++;
    }
}

void aumentaretcima(App *app)
{
    int alturatela;
    int lixo;
    t_tamanho(&lixo, &alturatela);
    if(app->notas[app->notaativa].retangulo.y < alturatela &&
        app->notas[app->notaativa].retangulo.y + app->notas[app->notaativa].retangulo.altura - 1 < alturatela)
        {
            app->notas[app->notaativa].retangulo.altura++;
        }
}

void aumentaretbaixo(App *app)
{
    int alturatela;
    int lixo;
    t_tamanho(&lixo, &alturatela);
    if(app->notas[app->notaativa].retangulo.y > 0 &&
        app->notas[app->notaativa].retangulo.y + app->notas[app->notaativa].retangulo.altura - 1 < alturatela)
        {
            movretbaixo(app);
            app->notas[app->notaativa].retangulo.altura++;
        }
}

void diminuirretesqr(App *app)
{
    if(app->notas[app->notaativa].retangulo.largura <= 1)
    {
        return;
    }
    // nao é necessario mexer no cursor, pq ele é relativo a nota
    // e nao a tela inteira
    app->notas[app->notaativa].retangulo.largura--;
}

void diminuirretdir(App *app)
{
    int larguratela;
    int lixo;
    t_tamanho(&larguratela, &lixo);
    if(app->notas[app->notaativa].retangulo.largura <= 1)
    {
        return;
    }
    if(app->notas[app->notaativa].retangulo.x == larguratela)
    {
        return;
    }
    app->notas[app->notaativa].retangulo.x++;
}

void diminuirretcima(App *app)
{
    if(app->notas[app->notaativa].retangulo.altura <= 1)
    {
        return;
    }
    app->notas[app->notaativa].retangulo.altura--;
}

void diminuirretbaixo(App *app)
{
    int alturatela;
    int lixo;
    t_tamanho(&lixo, &alturatela);
    if(app->notas[app->notaativa].retangulo.altura <= 1) return;
    if(app->notas[app->notaativa].retangulo.y == alturatela) return;
    app->notas[app->notaativa].retangulo.y++;
}