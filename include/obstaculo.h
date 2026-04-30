#ifndef OBSTACULO_H
#define OBSTACULO_H
#include "colisao.h"
#include "raylib.h"

typedef struct Obstaculo{ 
    Colidivel hitbox;
    Obstaculo *proximo;
} Obstaculo;

Obstaculo *criar_obstaculo (float x, float y, float altura, float largura, int tipo); 
void apagar_obstaculo (Obstaculo*); 
Obstaculo *adicionar_obstaculo (Obstaculo* lista, Obstaculo* obstaculo); 
Obstaculo *remover_obstaculo (Obstaculo* lista, Obstaculo* obstaculo); 
void sprite_obstaculo (const Obstaculo*); 
void atualizar_obstaculos (Obstaculo*);   
#endif