//Criação da primeira parte da biblioteca própria de colisão

#ifndef COLISAO_H
#define COLISAO_H
#include "jogador.h"
#include "raylib.h" // Aqui incluimos a biblioteca "Raylib, importada do github"

typedef struct Colidivel { 
    Rectangle hitbox;
    int tipo;
}Colidivel;

// Declaracao das funcoes
Colidivel* criar_colidivel(float x, float y, float altura, float largura, int tipo); 
int houve_colisao(Jogador*, Colidivel*); 
void tipo_de_colisao(Jogador*, Colidivel*); 
void sprite_colidivel(Colidivel*); 

#endif