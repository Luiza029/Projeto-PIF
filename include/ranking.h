#ifndef RANKING_H
#define RANKING_H
#include "raylib.h"
#define MAX_RANKING 5

typedef struct Ranking{
    char nome[50];
    int pontos;
} Ranking;

void salvar_pontos(Ranking* lista, int tamanho);
void carregar_pontos(Ranking* lista, int* tamanho);
void inserir_pontuacao(Ranking* lista, int* tamanho, char* nome, int pontos);
void mostrar_na_tela(Ranking* lista, int tamanho);
#endif