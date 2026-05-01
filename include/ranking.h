#ifndef RANKING_H
#define RANKING_H
#include "raylib.h"

typedef struct Ranking{
    char nome[50];
    int pontos;
} Ranking;

Ranking* carregar_pontos();
void salvar_pontos(Ranking*);
void mostrar_na_tela(Ranking*);
#endif