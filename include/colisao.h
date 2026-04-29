//Criação da primeira parte da biblioteca própria de colisão

#ifndef COLISAO_H
#define COLISAO_H

#include "raylib.h" // Aqui incluimos a biblioteca "Raylib, importada do github"

typedef struct Colidivel { // Esta struct cria a possibilidade dos blocos serem colididos e cria os valores de X, Y, Altura e Largura para serem usadar na criação de paredes e chão
    Rectangle hitbox;
    int tipo;
}Colidivel;

// Declaracao das funcoes
Colidivel* criar_colidivel(float x, float y, float altura, float largura, int tipo); // vai criar um colidivel, tem que passar tudo do recrangle
int houve_colisao(Jogador*, Colidivel*); // vai verificar se o jogador bateu
void tipo_de_colisao(Jogador*, Colidivel*); // vai ver o tipo de colisao (chao, parede, algum bloco que mata)
void desenhar_colidivel(Colidivel*); // vai desenhar o obstaculo

#endif