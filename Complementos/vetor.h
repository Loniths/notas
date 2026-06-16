#ifndef VETOR_H
#define VETOR_H

#include <stdio.h>
#include "app.h"

// funções de vetor
int conseguirlinhas(FILE *arq);

int lernotas(FILE *arq, Nota notas[]);

Nota *expandirvet(Nota notas[], int novotam);

void excluirnota(App *app, int excluir);

bool dobrarvet(App *app);

void reinserirnota(App *app);

void criarnota(App *app, const Nota *padrão);

void gravarnotas(App *app);

void verificarnotaatual(App *app);

void removtextogeral(char vetor[], int alvo);

void textoremoveranterior(char texto[], App *app);

#endif