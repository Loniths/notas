#include <stdio.h>
#include <stdlib.h>
#include "app.h"
#include "tela.h"
#include "vetor.h"
#include "desenho.h"
#include "movimento.h"

// arquivo dedicado as funções dos modos do programa

void funcprincipal(Nota notas[], App *app)
{
    desenhartela (app);
    switch(t_tecla())
    {
        case 'i':
            app->notaativa = 0;
            break;

        case 'f':
            app->notaativa = app->ocupados - 1;
            break;

        case 'd':
        case T_DEL:
            if(app->notaativa == -1) break;
            excluirnota(app, app->notaativa);
            break;

        case 'I':
        case T_INS:
            reinserirnota(app);
            break;

        case 'n':
            criarnota(app, &app->padrão);
            break;

        case 'g':
            gravarnotas(app);
            break;

        case 'e':
            app->modo = EDITAR_TEXTO;
            break;

        case 'b':
            app->modo = BUSCAR_TEXTO;
            break;

        case 'h':
        case T_ESQUERDA:
            movcursoresq(app);
            break;

        case 'j':
        case T_BAIXO:
            movcursorbaixo(app);
            break;

        case 'k':
        case T_CIMA:
            movcursorcima(app);
            break;
        
        case 'l':
        case T_DIREITA:
            movcursordir(app);
            break;
        
        case 'H':
        case T_SM_ESQUERDA:
            movretesq(app);
            break;
        
        case 'J':
        case T_SM_CIMA:
            movretcima(app);
            break;
        
        case 'K':
        case T_SM_BAIXO:
            movretbaixo(app);
            break;

        case 'L':
        case T_SM_DIREITA:
            movretdir(app);
            break;

        case T_CTRL_H:
        case T_C_ESQUERDA:
            aumentaretesq(app);
            break;
        
        case T_CTRL_J:
        case T_C_CIMA:
            aumentaretcima(app);
            break;

        case T_CTRL_K:
        case T_C_BAIXO:
            aumentaretbaixo(app);
            break;
        
        case T_CTRL_L:
        case T_C_DIREITA:
            aumentarretdir(app);
            break;
        
        case T_CTRL_Y:
        case T_A_ESQUERDA:
            diminuirretesqr(app);
            break;

        case T_CTRL_U:
        case T_A_CIMA:
            diminuirretcima(app);
            break;
        
        case T_CTRL_I:
        case T_A_BAIXO:
            diminuirretbaixo(app);
            break;

        case T_CTRL_O:
        case T_A_DIREITA:
            diminuirretdir(app);
            break;
        
        case 'p':
            app->notaativa = app->ocupados - 1;
            break;

        case 'c':
            app->modo = EDITAR_COR;
            break;
        
        case 't':
            app->modo = EDITAR_ETIQUETA;
            break;

        case 'B':
            app->modo = BUSCAR_ETIQUETA;
            break;

        case T_ESC:
            app->modo = TERMINAR;
        
        default:
            break;
    }
}

void funceditatexto(App *app)
{
    if(app->notaativa == -1) 
    {
        app->modo = PRINCIPAL;
        return;
    }
    char textoeditavel[256];
    strcpy(textoeditavel, app->notas[app->notaativa].texto);
    t_limpa();
    desenhaapenastexto(textoeditavel, app);
    tecla_t tecla = t_tecla();
    switch(tecla)
    {
        case T_ENTER:
            strcpy(app->notas[app->notaativa].texto, textoeditavel);
            app->modo = PRINCIPAL;
            break;
        
        case T_CTRL_C:
        case T_ESC:
            app->modo = PRINCIPAL;
            break;

        case T_CTRL_B:
        case T_BACKSPACE:
            textoremoveranterior(textoeditavel, app);
            break;

        case T_CTRL_D:
        case T_DEL:
            textoremovatual(textoeditavel, app);
            break;

        case T_CTRL_H:
        case T_ESQUERDA:
            textomovcursoresq(app);
            break;

        case T_CTRL_L:
        case T_DIREITA:
            textomovcursordir(app, textoeditavel);
            break;
        
        default:
            textoadicionacaractere(textoeditavel, app, tecla);
            break;
    }
}

void funceditaretiqueta(App *app)
{
    if(app->notaativa == -1)
    {
        app->modo = PRINCIPAL;
        return;
    }
    char ediquetaeditavel[4];
    strcpy(ediquetaeditavel, app->notas[app->notaativa].etiqueta);
    desenhaapenastexto(ediquetaeditavel, app);
    switch(t_tecla())
    {
        case T_CTRL_C:
        case T_ESC:
            app->modo = PRINCIPAL;
            break;
        
        case T_CTRL_B:
        case T_BACKSPACE:
            removtextogeral(ediquetaeditavel, strlen(ediquetaeditavel) - 1);
            break;
        
        case T_ENTER:
            if(strlen(ediquetaeditavel) == 3)
            {
                strcpy(app->notas[app->notaativa].etiqueta, ediquetaeditavel);
                app->modo = PRINCIPAL;
            }
            break;

        default:
            if(strlen(ediquetaeditavel) == 3)
            {
                break;
            }
            int index;
            for(int i = 0; i < 3; i++)
            {
                if(ediquetaeditavel[i] == '\0')
                {
                    index = i;
                    break;
                }
            }
            ediquetaeditavel[index] = t_tecla();
            ediquetaeditavel[index + 1] = '\0';
    }
}

void funceditarcor(App *app, char cor)
{
    if(app->notaativa == -1) return;
    char coredit;
    int corantiga;
    if(cor == 'a' || cor == 'b') 
    {
        coredit = 'b';
        corantiga = app->notas[app->notaativa].cor.b;
    }
    if(cor == 'e' || cor == 'r') 
    {
        coredit = 'r';
        corantiga = app->notas[app->notaativa].cor.r;
    }
    if(cor == 'v' || cor == 'g') 
    {
        coredit = 'g';
        corantiga = app->notas[app->notaativa].cor.g;
    }
    switch(t_tecla())
    {
        case 'k':
        case T_CIMA:
            if(coredit == 'r')
            {
                if(app->notas[app->notaativa].cor.r == 255) break;
                app->notas[app->notaativa].cor.r++;
            }
            if(coredit == 'g')
            {
                if(app->notas[app->notaativa].cor.g == 255) break;
                app->notas[app->notaativa].cor.g++;
            }
            if(coredit == 'b')
            {
                if(app->notas[app->notaativa].cor.b == 255) break;
                app->notas[app->notaativa].cor.b++;
            }
            break;
        
        case 'K':
        case T_S_CIMA:
            if(coredit == 'r')
            {
                if(app->notas[app->notaativa].cor.r + 10 > 255) break;
                app->notas[app->notaativa].cor.r += 10;
            }
            if(coredit == 'g')
            {
                if(app->notas[app->notaativa].cor.g + 10 > 255) break;
                app->notas[app->notaativa].cor.g += 10;
            }
            if(coredit == 'b')
            {
                if(app->notas[app->notaativa].cor.b + 10 > 255) break;
                app->notas[app->notaativa].cor.b += 10;
            }
            break;

        case 'j':
        case T_BAIXO:
            if(coredit == 'r')
            {
                if(app->notas[app->notaativa].cor.r == 0) break;
                app->notas[app->notaativa].cor.r--;
            }
            if(coredit == 'g')
            {
                if(app->notas[app->notaativa].cor.g == 0) break;
                app->notas[app->notaativa].cor.g--;
            }
            if(coredit == 'b')
            {
                if(app->notas[app->notaativa].cor.b == 0) break;
                app->notas[app->notaativa].cor.b--;
            }
            break;

        case 'J':
        case T_S_BAIXO:
            if(coredit == 'r')
            {
                if(app->notas[app->notaativa].cor.r - 10 < 0) break;
                app->notas[app->notaativa].cor.r -= 10;
            }
            if(coredit == 'g')
            {
                if(app->notas[app->notaativa].cor.g - 10 < 0) break;
                app->notas[app->notaativa].cor.g -= 10;
            }
            if(coredit == 'b')
            {
                if(app->notas[app->notaativa].cor.b - 10 < 0) break;
                app->notas[app->notaativa].cor.b -= 10;
            }
            break;

        case T_ENTER:
            app->modo = PRINCIPAL;
            break;
        
        case T_CTRL_T:
        case T_ALT_ENTER:
            // não achei shift + enter, ent mudei para o alt
            if(coredit == 'r')
            {
                for(int i = 0; i < app->ocupados; i++)
                {
                    app->notas[i].cor.r = app->notas[app->notaativa].cor.r;
                }
            }
            if(coredit == 'g')
            {
                for(int i = 0; i < app->ocupados; i++)
                {
                    app->notas[i].cor.g = app->notas[app->notaativa].cor.g;
                }
            }
            if(coredit == 'b')
            {
                for(int i = 0; i < app->ocupados; i++)
                {
                    app->notas[i].cor.b = app->notas[app->notaativa].cor.b;
                }
            }
            break;

        case T_CTRL_B:
        case T_ESC:
            if(coredit == 'r') app->notas[app->notaativa].cor.r = corantiga;
            if(coredit == 'g') app->notas[app->notaativa].cor.g = corantiga;
            if(coredit == 'b') app->notas[app->notaativa].cor.b = corantiga;
            app->modo = PRINCIPAL;
            break;

        default:
            break;
    }
}

void funcbuscatexto(App *app)
{
    char textoeditavel[100];
    strncpy(textoeditavel, app->filtrotexto, 99);
    int alturatela;
    int larguratela;
    t_tamanho(&larguratela, &alturatela);
    desenhaapenastexto(textoeditavel, app);
    tecla_t tecla = t_tecla();
    switch(tecla)
    {
        case T_CTRL_C:
        case T_ESC:
            app->filtrotexto[0] = '\0';
            app->modo = PRINCIPAL;
            break;

        case T_ENTER:
            app->modo = PRINCIPAL;
            break;
        

        case T_CTRL_B:
        case T_BACKSPACE:
            if(app->cursor.x + app->cursor.y * larguratela > 1)
                {
                    textoremovatual(textoeditavel, app);
                    if(app->cursor.x == 1)
                    {
                        app->cursor.x = larguratela;
                        app->cursor.y--;
                    }
                    else app->cursor.x--;
                }
            break;
        
        case T_CTRL_D:
        case T_DEL:
            if(app->cursor.x + app->cursor.y * larguratela < strlen(textoeditavel))
            {
                textoremovatual(textoeditavel, app);
            }                break;
            
        case T_CTRL_H:
        case T_ESQUERDA:
           if(app->cursor.x == 1)
            {
                if(app->cursor.y > 1)
                {
                    app->cursor.x = larguratela;
                    app->cursor.y--;
                }
            }
            else app->cursor.x--;
            break;
        
        case T_CTRL_L:
        case T_DIREITA:
            if((app->cursor.x-1) + (app->cursor.y - 1) * larguratela < strlen(textoeditavel))
            {
                if(app->cursor.x == larguratela)
                {
                    if(app->cursor.y < alturatela)
                    {
                        app->cursor.x == 1;
                        app->cursor.y++;
                    }
                }
                else app->cursor.x++;
            }
            break;
        
        case T_CTRL_K:
        case T_HOME:
            app->cursor.x = 1;
            app->cursor.y = 1;
        
        case T_CTRL_J:
        case T_END:
            while(1)
            {
                if((app->cursor.x - 1) + (app->cursor.y - 1) * larguratela < strlen(textoeditavel))
                {
                    app->cursor.x++;
                    app->cursor.y++;
                }
                else break;
            }
            
        default:
            if(tecla >= 32 && tecla <= 126)
            {
                textoadicionacaractere(textoeditavel, app, tecla);
            }
            break;
    }
}

void funcbuscaetiqueta(App *app)
{
    char textoeditavel[4];
    strncpy(textoeditavel, app->filtroetiqueta, 3);
    int alturatela;
    int larguratela;
    t_tamanho(&larguratela, &alturatela);
    desenhaapenastexto(textoeditavel, app);
    tecla_t tecla = t_tecla();
    switch(tecla)
    {
        case T_CTRL_C:
        case T_ESC:
            app->filtroetiqueta[0] = '\0';
            app->modo = PRINCIPAL;
            break;
        
        case T_ENTER:
            app->modo = PRINCIPAL;
            break;
        
        case T_CTRL_B:
        case T_BACKSPACE:
            int index;
            for(int i = 0; i < 3; i++)
            {
                if(textoeditavel[i] = '\0') index = i - 1;
            }
            if(index == -1) break;
            removtextogeral(textoeditavel, index);
            break;
        
        default:
            if(tecla >= 32 && tecla <= 126)
            {
                if(strlen(textoeditavel) < 3)
                {
                    int sla = strlen(textoeditavel);
                    textoeditavel[sla] = tecla;
                    textoeditavel[sla+1] = '\0';
                }
            }
    }
}

