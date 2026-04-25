#ifdef JOGADOR_H
#define JOGADOR_H
#include "raylib.h"

typedef struct jogador{
    float x; 
    float y; 
    float velocidade;
    int gravidade; 
    int vivo;
    Color cor;  
} Jogador;

// declaracao das funcoes

Jogador* criarJogador(float x, float y); 
void atualizarJogador(Jogador* j); 
void inverterGravidade(Jogador* j); 
void desenharJogador(Jogador* j);
void destruitJogador(Jogador* j); // libera a memoria alocada para o jogador

#endif