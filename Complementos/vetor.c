#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "app.h"

// arquivo dedicado as funções que cuidam do vetor
// ler vetor, expandir vetor etc

int conseguirlinhas(FILE *arq)
{
    char vettemp[500];
    int linhas = 0;
    while(fgets(vettemp, sizeof(vettemp), arq) != NULL) linhas++;
    rewind(arq);
    return linhas;
}

int lernotas(FILE *arq, Nota notas[])
{
    char vettemp[500];
    for(int i = 0;;)
    {
        if(fgets(vettemp, sizeof(vettemp), arq) == NULL) return i;
        char ajuste[100]; // vetor usado para remover as ""
        if(sscanf(vettemp, "%3s %d %d %d %d %d %d %d %99[^\n]", notas[i].etiqueta, &notas[i].cor.r, &notas[i].cor.g, &notas[i].cor.b,
        &notas[i].retangulo.x, &notas[i].retangulo.y, &notas[i].retangulo.largura, &notas[i].retangulo.altura, ajuste) == 9)
        {
            int tamanho = strlen(ajuste);
            if(tamanho > 0 && ajuste[tamanho - 1] == '"') // verificação para garantir que a palavra seja valida
            {
                ajuste[tamanho - 1] = '\0';
                strncpy(notas[i].texto, ajuste + 1, 256); // acabei só usando strncpy, pra caso eu realize alguma mudança, aqui não vire um possível erro
                i++;
            }
        }
    }
}

Nota* expandirvet(Nota notas[], int novotam)
{
    return realloc(notas, novotam * sizeof(Nota));
}

void excluirnota(App *app, int excluir)
{
    app->removida = app->notas[excluir];
    // salva a nota que vai ser removida
    // para caso o usuario se arrependa
    for(int i = excluir; i <= app->ocupados - 2; i++)
    {
        app->notas[i] = app->notas[i+1];
    }
    app->ocupados--;
    app->temremovida = true;
}

bool dobrarvet(App *app)
{
    // função que dobra a capacidade do vetor
    // fiz ela pq vi que muitas vezes essa linha ia se repetir
    // ent facilita a escrita e leitura do código
    // eu acho
    int novacapacidade =(app->capacidade > 0) ? app->capacidade * 2 : 10;
    // caso por algum problema demoniaco
    // a capacidade seja 0
    // o programa n vai quebrar
    // espero eu
    Nota *temp = expandirvet(app->notas, novacapacidade);
    if(temp == NULL)
    {
        return false;
    }
    app->notas = temp;
    app->capacidade = novacapacidade;
    return true;
}

void reinserirnota(App *app)
{
    if(app->ocupados >= app->capacidade)
    {
        if(!dobrarvet(app))
        {
            return;
        }
        // caso nao de pra reallocar mais memoria
    }
    // poderia ter usado um while, mas acho mto dificil de ocupados ser
    // maior que o dobro da capacidade
    // acho dificil até ser maior, mas nunca se sabe
    app->notas[app->ocupados] = app->removida;
    // não precisa do mais um por conta que o vetor é naturalmente ocupados - 1
    app->ocupados++;
    app->temremovida = false;
}

void criarnota(App *app, const Nota *padrão)
{
    if(app->ocupados >= app->capacidade)
    {
        if(!dobrarvet(app))
        {
            return;
        }
        // caso nao de pra reallocar mais memoria
    }
    app->notas[app->ocupados] = *padrão;
    // fiz dessa forma para não criar a padrão nessa função
    // já que para a criação inical do vetor (sem o arquivo)
    // ela vai ser chamada em um for loop
    app->ocupados++;
}

void gravarnotas(App *app)
{
    FILE *arq;
    arq = fopen("notas", "wt");
    for(int i = 0; i < app->ocupados; i++)
    {
        fprintf(arq, "%3s %d %d %d %d %d %d %d \"%s\"\n", app->notas[i].etiqueta, app->notas[i].cor.r,
        app->notas[i].cor.g, app->notas[i].cor.b, app->notas[i].retangulo.x, app->notas[i].retangulo.y,
        app->notas[i].retangulo.largura, app->notas[i].retangulo.altura, app->notas[i].texto);
    }
    fclose(arq);
}

void verificarnotaatual(App *app)
{
    int larguratela;
    int alturatela;
    t_tamanho(&larguratela, &alturatela);
    for(int i = app->ocupados - 1; i >= 0; i--)
    {
        if(app->cursor.x >= app->notas[i].retangulo.x && app->cursor.x <= app->notas[i].retangulo.x + app->notas[i].retangulo.largura - 1)
        {
            if(app->cursor.y >= app->notas[i].retangulo.y && app->cursor.y <= app->notas[i].retangulo.y + app->notas[i].retangulo. altura - 1)
                {
                    app->notaativa = i;
                    return;
                }
        }
    }
    app->notaativa = -1;
}

void removtextogeral(char vetor[], int alvo)
{
    for(int i = alvo;; i++)
    {
        vetor[i] = vetor[i+1];
        if(vetor[i+1] == '\0') return;
    }
}

void textoremoveranterior(char texto[], App *app)
{
    if(app->cursor.x == 0)
    {
        if(app->cursor.y == 0)
        {
            return;
        }
        int larguratela;
        int lixo;
        t_tamanho(&larguratela, &lixo);
        int linha = app->cursor.y;
        removtextogeral(texto, larguratela - linha);
    }
    else
    {
        removtextogeral(texto, app->cursor.x + app->cursor.y);
    }
}

void textoremovatual(char texto[], App *app)
{
    if(app->cursor.x + app->cursor.y == strlen(texto))
    {
        return;
    }
    removtextogeral(texto, app->cursor.x + app->cursor.y);
}

void textoadicionacaractere(char texto[], App *app, char letra)
{
    if(strlen(texto) == 256)
    {
        return;
    }
    for(int i = strlen(texto); i > app->cursor.x + app->cursor.y; i--)
    {
        texto[i] = texto[i-1];
    }
    texto[app->cursor.x + app->cursor.y] = letra;
    texto[strlen(texto)] = '\0';
}