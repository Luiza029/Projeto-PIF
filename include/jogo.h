#ifndef JOGO_H
#define JOGO_H
#define LINHA 10
#define COLUNA 20
#define TAMANHO_BLOCO 60
#include "raylib.h"
#include "jogador.h"
#include "jogador.h"
#include "chunk.h"

typedef enum {MENU, JOGANDO, GAME_OVER} EstadoJogo;

typedef struct Jogo{ 
    Jogador *jogador;
    Chunk *chunks;
    EstadoJogo estado;
    float offset;
    float velocidade;
    int num_chunks;
}Jogo;

void iniciar_jogo (Jogo*); 
void atualizar_jogo (Jogo*);  
void sprites_jogo (Jogo*);
void fechar_jogo (Jogo*); 

#endif