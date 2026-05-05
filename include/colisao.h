#ifndef COLISAO_H
#define COLISAO_H
#include "jogador.h"
#include "jogo.h"
#include "raylib.h" // Aqui incluimos a biblioteca "Raylib, importada do github"

// Declaracao das funcoes
int houve_colisao(Jogador*, Jogo*); 
void tipo_de_colisao(Jogador*, int l); 

#endif