#ifndef ANIMACAO_H
#define ANIMACAO_H

#include <raylib.h>
#include <stdlib.h>

typedef struct AnimacaoSprite {
    Texture2D atlas;
    int fps;

    Rectangle* retangulos;
    int larguraret;
}AnimacaoSprite;

AnimacaoSprite Criar_Animacao_Sprite(Texture2D atlas, int fps, Rectangle retangulos[], int largura);

void DesenhaAnimacaoSpritePro(AnimacaoSprite animacao, Rectangle dest, Vector2 origin, float rotation, Color tint);

#endif