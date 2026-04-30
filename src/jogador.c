#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogador.h"

Jogador* criarJogador(float x, float y, float altura, float largura){
    Jogador* j = malloc(sizeof(Jogador));

    j -> x = x;
    j -> y = y;
    j -> velocidadeX = 500; // valor provisorio
    j -> velocidadeY = 500; // valor provisorio
    j -> gravidade = 1;
    j -> vivo = 1;
    j -> hitbox = (Rectangle){x, y, largura, altura};
    j -> cor = RED;

    return j;
}

void atualizarJogador(Jogador* j, float delta){
    if(j -> gravidade == 1){ // normal
        j -> velocidadeY += delta * 500; // cai para baixo
    } 

    if(j -> gravidade == -1){ // invertida
        j -> velocidadeY -= delta * 500; // cai para cima 
    }
    
    // a nova posicao sera: Posicao atual + a velocidade multiplicada pelo delta
    j -> x = j -> x + j -> velocidadeX * delta;
    j -> y = j -> y + j -> velocidadeY * delta;

    // atualiza a hitbox
    j -> hitbox.x = j -> x;
    j -> hitbox.y = j -> y;
}

void inverterGravidade(Jogador* j){
    // Inverte a direção da gravidade: 1 = cai para baixo, -1 = cai para cima
    if(j -> gravidade == 1){
        j-> gravidade = -1;

    } else if(j-> gravidade == -1){
        j -> gravidade = 1;
    }
}

void sprite_jogador(const Jogador* j){
    DrawRectangleRec(j -> hitbox, j -> cor); // colocar uma imagem futuramente
}

void destruirJogador(Jogador* j){
    free(j);
    j = NULL;
}