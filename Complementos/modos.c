#include <stdio.h>
#include <stdlib.h>
#include "app.h"
#include "tela.h"
#include "vetor.c"
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
            movcursorcima;
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

        default:
            break;
    }