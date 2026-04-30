#ifndef JOGO_H
#define JOGO_H
#include "raylib.h"
#include "jogador.h"
#include "obstaculo.h"
#include "colisao.h"

typedef struct Jogo{ 
    Jogador *jogador;
    Obstaculo *lista;
    int estado;
}Jogo;

void iniciar_jogo (Jogo*); 
void atualizar_jogo (Jogo*);  
void sprites_jogo (Jogo*);
void fechar_jogo (Jogo*); 

#endif