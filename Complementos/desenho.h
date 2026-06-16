#ifndef DESENHO_H
#define DESENHO_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"
#include "tela.h"

// arquivo de header dos desenhos

void desenharfundo(Nota *nota);

void linhahorizontal(Ret *ret);

void linhavertical(Ret *ret);

void escrevetexto(Nota *nota);

void desenhanota(App *app, int indicador);

void todasnotas(App *app);

void desenhartela(App *app);

void desenhaapenastexto(char texto[], App *app);

#endif