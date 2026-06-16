#include <stdio.h>
#include <stdlib.h>
#include "app.h"
#include "tela.h"

// arquivo com as funções que movem o cursor
// e também as que modificam o retangulo

void movcursoresq(App *app)
{
    if(app->notas[app->notaativa].cursor.x > 1)
    {
        app->notas[app->notaativa].cursor.x -= 1;
    }
}

void movcursorcima(App *app)
{
    if(app->notas[app->notaativa].cursor.y < app->notas[app->notaativa].retangulo.altura - 2)
    {
        app->notas[app->notaativa].cursor.y += 1;
    }
}

void movcursorbaixo(App *app)
{
    if(app->notas[app->notaativa].cursor.y > 1)
    {
        app->notas[app->notaativa].cursor.y -= 1;
    }
}

void movcursordir(App *app)
{
    if(app->notas[app->notaativa].cursor.x < app->notas[app->notaativa].retangulo.largura - 2)
    {
        app->notas[app->notaativa].cursor.x += 1;
    }
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