#ifndef OBSTACULO_H
#define OBSTACULO_H
#include "colisao.h"
#include "raylib.h"

typedef struct Obstaculo{ // Criação de uma struct para criar as hitbox dos objetos com lista encadeada
    Colidivel hitbox;
    Obstaculo *proximo;
} Obstaculo;

Obstaculo *criar_obstaculo (float x, float y, float altura, float largura, int tipo); // Função para criar os obstáculos
void apagar_obstaculo (Obstaculo*); // Apaga os obstáculos que sairem da tela
Obstaculo *adicionar_obstaculo (Obstaculo* lista, Obstaculo* obstaculo); // Adicona os obstaculos na telas 
Obstaculo *remover_obstaculo (Obstaculo* lista, Obstaculo* obstaculo); // Remove o obstaculo da tela quando chega no limite 
void sprite_obstaculo (const Obstaculo*); // Cria os sprites dos obstaculos
void atualizar_obstaculos (Obstaculo*);   //Atualiza a posição do objeto na tela em cada loop do código
#endif