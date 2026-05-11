#ifndef COLISAO_H
#define COLISAO_H
#include "jogador.h"
#include "raylib.h" 

typedef struct Colidivel { 
    Rectangle hitbox;
    int tipo;
}Colidivel;

struct Jogo;

Colidivel* criar_colidivel(float x, float y, float altura, float largura, int tipo); 
int houve_colisao(Jogador*, struct Jogo*); 
void tipo_de_colisao(Jogador*, int l); 
void sprite_colidivel(Colidivel*); 
void sprite_colidivel(Colidivel*);
void sumir_colidivel(Colidivel*);

#endif