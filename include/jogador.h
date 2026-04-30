#ifndef JOGADOR_H
#define JOGADOR_H
#include "raylib.h"

typedef struct Jogador{
    float x; 
    float y; 
    float velocidadeY; 
    float velocidadeX; 
    int gravidade; 
    int vivo;
    Rectangle hitbox; 
    Color cor;  
} Jogador;

// declaracao das funcoes
Jogador* criarJogador(float x, float y, float altura, float largura); 
void atualizarJogador(Jogador*, float delta);  
void inverterGravidade(Jogador*); 
void sprite_Jogador(const Jogador*);
void destruirJogador(Jogador*); 

#endif