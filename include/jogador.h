#ifndef JOGADOR_H
#define JOGADOR_H
#include "raylib.h"

typedef struct Jogador{
    float x; 
    float y; 
    float velocidadeY; // muda
    float velocidadeX; // igual
    int gravidade; 
    int vivo;
    Rectangle hitbox; // tipo do raylib, ele guarda x, y, altura e largura
    Color cor;  
} Jogador;

// declaracao das funcoes
Jogador* criarJogador(float x, float y); 
void atualizarJogador(Jogador* j, float delta); // com o delta o movimento vai ficar igual para todos 
void inverterGravidade(Jogador* j); 
void sprite_Jogador(const Jogador* j);
void destruirJogador(Jogador* j); // libera a memoria alocada para o jogador

#endif