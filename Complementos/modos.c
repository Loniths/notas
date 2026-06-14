#include <stdio.h>
#include <stdlib.h>
#include "app.h"
#include "tela.h"
#include "vetor.c"

// arquivo dedicado as funções dos modos do programa

void principal(Nota notas[], App *app)
{
    //função do modo principal

    if(t_tecla() == 'i')
    {
        app->notaativa = 0;
    }
    if(t_tecla() == 'f')
    {
        app->notaativa = app->ocupados - 1;
        // se tem uma nota, ocupados = 1, e a nota esta em notas[0]
        // por isso ocupados - 1
    }
    if(t_tecla() == 'd' || t_tecla() == T_DEL)
    {
        excluirnota(app, app->notaativa);
        // função presente em vetor.c    
    }
    if(t_tecla() == 'L' || t_tecla() == T_INS)
    {
        reinserirnota(app);
        // função presente em vetor.c
    }
    if(t_tecla() == 'n')
    {
        criarnota(app, &app->padrão);
    }
    if(t_tecla() == 'g')
    {
        gravarnotas(app);
    }
    if(t_tecla() == 'e')
    {
        app->modo = EDITAR_TEXTO;
    }
    if(t_tecla() == 'b')
    {
        app->modo == BUSCAR_TEXTO;
    }
}