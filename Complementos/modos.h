#ifndef MODOS_H
#define MODOS_H

#include <stdio.h>
#include <stdlib.h>
#include "app.h"
#include "tela.h"
#include "vetor.h"

void funcprincipal(Nota notas[], App *app);

void funceditatexto(App *app);

void funceditaretiqueta(App *app);

void funceditarcor(App *app, char cor);

void funcbuscatexto(App *app);

void funcbuscaetiqueta(App *app);

#endif