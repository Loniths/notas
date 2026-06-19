#include <stdio.h>
#include <stdlib.h>
#include "app.h"
#include "tela.h"
#include "vetor.h"

// arquivo com as funções que movem o cursor
// e também as que modificam o retangulo

void movcursoresq(App *app)
{
    if(app->cursor.x == 1) return;
    app->cursor.x--;
    verificarnotaatual(app);
}

void movcursorcima(App *app)
{
    if(app->cursor.y == 1) return;
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
    verificarnotaatual(app);
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
    if(app->notaativa == -1) return;
    if(app->notas[app->notaativa].retangulo.x > 0)
    {
        app->notas[app->notaativa].retangulo.x--;
    }
}

void movretdir(App *app)
{
    if(app->notaativa == -1) return;
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
    if(app->notaativa == -1) return;
    int alturatela;
    int lixo;
    t_tamanho(&lixo, &alturatela);
    if( app->notas[app->notaativa].retangulo.y + app->notas[app->notaativa].retangulo.altura - 1 < alturatela)
    {
        app->notas[app->notaativa].retangulo.y++;
    }
}

void movretcima(App *app)
{
    if(app->notaativa == -1) return;
    if(app->notas[app->notaativa].retangulo.y > 0)
    {
        app->notas[app->notaativa].retangulo.y--;
    }
}

void aumentaretesq(App *app)
{
    if(app->notaativa == -1) return;
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
    if(app->notaativa == -1) return;
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
    if(app->notaativa == -1) return;
    int alturatela;
    int lixo;
    t_tamanho(&lixo, &alturatela);
    if(app->notas[app->notaativa].retangulo.y > 0)
    {
        if(app->notas[app->notaativa].retangulo.y + app->notas[app->notaativa].retangulo.altura - 1 < alturatela)
        {
            app->notas[app->notaativa].retangulo.y--;
            app->notas[app->notaativa].retangulo.altura++;
        }
    }
}

void aumentaretbaixo(App *app)
{
    if(app->notaativa == -1) return;
    int alturatela;
    int lixo;
    t_tamanho(&lixo, &alturatela);
    if(app->notas[app->notaativa].retangulo.y < alturatela)
    {
        if(app->notas[app->notaativa].retangulo.y + app->notas[app->notaativa].retangulo.altura - 1 < alturatela)
        {
            app->notas[app->notaativa].retangulo.altura++;
        }
    }
}

void diminuirretesqr(App *app)
{
    if(app->notaativa == -1) return;
    if(app->notas[app->notaativa].retangulo.largura <= 1)
    {
        return;
    }
    if(app->cursor.x == app->notas[app->notaativa].retangulo.x + app->notas[app->notaativa].retangulo.largura - 1)
    {
        app->cursor.x--;
    }
    app->notas[app->notaativa].retangulo.largura--;
}

void diminuirretdir(App *app)
{
    if(app->notaativa == -1) return;
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
    if(app->cursor.x == app->notas[app->notaativa].retangulo.x)
    {
        app->cursor.x++;
    }
    app->notas[app->notaativa].retangulo.x++;
}

void diminuirretcima(App *app)
{
    if(app->notaativa == -1) return;
    int alturatela;
    int lixo;
    t_tamanho(&lixo, &alturatela);
    if(app->notas[app->notaativa].retangulo.y >= alturatela)
    {
        return;
    }
    if(app->cursor.y == app->notas[app->notaativa].retangulo.y)
    {
        app->cursor.y++;
    }
    app->notas[app->notaativa].retangulo.y++;
}

void diminuirretbaixo(App *app)
{
    if(app->notaativa == -1) return;
    int alturatela;
    int lixo;
    t_tamanho(&lixo, &alturatela);
    if(app->notas[app->notaativa].retangulo.altura <= 1) return;
    if(app->cursor.y == app->notas[app->notaativa].retangulo.y + app->notas[app->notaativa].retangulo.altura - 1)
    {
        app->cursor.y--;
    }
    app->notas[app->notaativa].retangulo.altura--;
}

void textomovcursoresq(App *app)
{
    if(app->notaativa == -1) return;
    if(app->cursor.x == 1)
    {
        if(app->cursor.y > 1)
        {
            app->cursor.y--;
            int larguratela;
            int lixo;
            t_tamanho(&larguratela, &lixo);
            app->cursor.x = larguratela;
        }
        else
        {
            return;
        }
    }
    else{
        app->cursor.x--;
    }
}

void textomovcursordir(App *app, char texto[])
{
    if(app->notaativa == -1) return;
    int larguratela;
    int lixo;
    t_tamanho(&larguratela, &lixo);
    if(app->cursor.x == larguratela)
    {
        if((app->cursor.y-1)*larguratela + (app->cursor.x-1) < strlen(texto))
        {
            app->cursor.x = 1;
            app->cursor.y++;
        }
        else return;
    }
    else{
        app->cursor.x++;
    }
}