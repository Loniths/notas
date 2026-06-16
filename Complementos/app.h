#ifndef APP_H
#define APP_H

#include <stdbool.h>

typedef enum
{
    PRINCIPAL,
    EDITAR_TEXTO,
    EDITAR_ETIQUETA,
    EDITAR_COR,
    BUSCAR_TEXTO,
    BUSCAR_ETIQUETA,
    TERMINAR,
} Modo;

typedef struct cor
{
    int r;
    int g;
    int b;
} Cor;

typedef struct retangulo
{
    int x;
    int y;
    // resolvi definir a cordenada {x, y} como canto inferior esquerdo da nota
    // assim x + largura - 1, é o canto direito do retangulo
    // mesma lógica para o y
    int largura;
    int altura;
} Ret;

typedef struct CursorNota
{
    int x;
    int y;
} CursorNota;


typedef struct
{
    char texto[256];
    char etiqueta[4];
    Cor cor;
    Ret retangulo;
    CursorNota cursor;
} Nota;

typedef struct
{
    Nota *notas;
    Nota padrão;
    int ocupados;
    int capacidade;
    int notaativa;
    Modo modo;
    char filtrotexto[100];
    char filtroetiqueta[4];
    Nota removida;
    bool temremovida;
} App;

#endif