//Criação da primeira parte da biblioteca própria de colisão

#ifndef NOME_DO_ARQUIVO_H
#define NOME_DO_ARQUIVO_H

#include "raylib.h" // Aqui incluimos a biblioteca "Raylib, importada do github"

typedef struct Retangulo { // Esta struct cria os valores de X, Y, Altura e Largura para serem usadar na criação de paredes e chão
    float x;
    float y;
    float altura;
    float largura;
} Retangulo;

typedef struct colidivel { // Esta struct cria a possibilidade dos blocos serem colididos
    Retangulo hitbox;
    int tipo;
}colidivel;


#endif