#ifndef JOGO_H
#define JOGO_H
#define LINHA 10
#define COLUNA 20
#define TAMANHO_BLOCO 60
#include "raylib.h"
#include "jogador.h"
#include "jogador.h"
#include "chunk.h"
#include "ranking.h"

typedef enum {MENU, JOGANDO, GAME_OVER, RANKING} EstadoJogo;

typedef struct Jogo{ 
    Jogador *jogador;
    Chunk *chunks;
    EstadoJogo estado;
    float offset;
    float velocidade;
    int num_chunks;
    int pontos;
    Ranking ranking[MAX_RANKING];
    int num_ranking;
    char nome_jogador[50];
}Jogo;

void iniciar_jogo (Jogo*); 
void atualizar_jogo (Jogo*);  
void sprite_jogo (Jogo*);
void sprite_game_over(Jogo*);
void reiniciar_jogo(Jogo*);
void fechar_jogo (Jogo*); 

#endif