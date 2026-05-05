#include "colisao.h"
#include <stdlib.h>

Colidivel* criar_colidivel(float x, float y, float altura, float largura, int tipo){
    Colidivel *colid = malloc(sizeof(Colidivel));

    colid -> hitbox.x = x;
    colid -> hitbox.y = y;
    colid -> hitbox.height = altura;
    colid -> hitbox.width = largura;
    colid -> tipo = tipo;

    return colid;
}

int houve_colisao(Jogador* j, Colidivel* c){

    return CheckCollisionRecs(j->hitbox, c->hitbox);
}

void tipo_de_colisao(Jogador* j, Colidivel* c){

    switch (c->tipo){
        case 1: //chão
            j->velocidadeY = 0;
            break;
        case 2: //teto
            j->velocidadeY = 0;
            break;
        case 3: //parede
            j->vivo = 0;
            break;
        case 4: //buraco
            j->vivo = 0;
            break;
        default:
            break;
    }
}

void sprite_colidivel(Colidivel* c){

    DrawRectangleRec(c->hitbox, RED);
}

void sumir_colidivel(Colidivel* c){
    free(c);
    c = NULL;
}