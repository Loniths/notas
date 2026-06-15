#include <stdio.h>
#include <stdlib.h>
#include "app.h"
#include "tela.h"

// arquivo com as funções que movem o cursor

void movcursoresq(App *app)
{
    if(app->notas[app->notaativa].cursor.x > 1)
    {
        app->notas[app->notaativa].cursor.x -= 1;
    }
}

void movcursorcima(App *app)
{
    if(app->notas[app->notaativa].cursor.y > 1)
    {
        app->notas[app->notaativa].cursor.y -= 1;
    }
}

void movcursorbaixo(App *app)
{
    if(app->notas[app->notaativa].cursor.y < app->notas[app->notaativa].retangulo.altura - 2)
    {
        app->notas[app->notaativa].cursor.y += 1;
    }
}

void movcursordir(App *app)
{
    if(app->notas[app->notaativa].cursor.x < app->notas[app->notaativa].retangulo.largura - 2)
    {
        app->notas[app->notaativa].cursor.x += 1;
    }
}