#ifndef OBSTACULO_H
#define OBSTACULO_H
#include "colisao.h"
#include "raylib.h"

//Criamos a struct que vai determinar a geração de obstáculos na tela
typedef struct Obstaculo{ 
    Colidivel hitbox;
    Obstaculo *proximo;
    float velocidadeX;
    Color cor;
} Obstaculo;

Obstaculo *criar_obstaculo (float x, float y, float altura, float largura, int tipo); 
void apagar_obstaculo (Obstaculo* obs); 
Obstaculo *adicionar_obstaculo (Obstaculo* lista, Obstaculo* obstaculo); 
Obstaculo *remover_obstaculo (Obstaculo* lista, Obstaculo* obstaculo); 
void sprite_obstaculo (const Obstaculo* obs); 
//Esta função vai determinar como os obstáculos vão se comportar durante o jogo
Obstaculo* atualizar_obstaculos(Obstaculo* lista, float delta);   
#endif