#ifndef JOGO_H
#define JOGO_H
#define LINHA 10
#define COLUNA 50
#define TAMANHO_BLOCO 32
#include "raylib.h"
#include "jogador.h"

typedef enum {MENU, JOGANDO, GAME_OVER} EstadoJogo;

typedef struct Jogo{ 
    Jogador *jogador;
    int mapa [LINHA][COLUNA];
    EstadoJogo estado;
    float offset; // deslocamento do mapa em pixels
    float velocidade; // velocidade que o mapa se move para a esquerda
}Jogo;

void iniciar_jogo (Jogo*); 
void atualizar_jogo (Jogo*);  
void sprites_jogo (Jogo*);
void fechar_jogo (Jogo*); 

#endif