#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"

void iniciar_jogo(Jogo* j){
    InitWindow(800, 600, "Projeto-PIF"); 
    ToggleFullscreen();

    j -> estado = 1; 
    j -> lista = NULL; 
    j -> jogador = criarJogador(100, 300, 50, 50);  
}

void atualizar_jogo(Jogo* j){
    float delta = GetFrameTime(); // GetFrameTime, retorna o tempo do ultimo frame redenrizado, com isso o delta recebe esse tempo 
    atualizarJogador(j->jogador, delta); // manda para a funcao de atualizar jogador (aquele para saber se ele cai para cima ou para baixo)
    atualizar_obstaculos(j->lista); // e os obstaculos vao sendo criado de acordo com a lista encadeada

    Obstaculo* atual = j->lista; // cria um ponteiro que aponta para o primeiro obstaculo da lista 
    while(atual != NULL){
        if(houve_colisao(j->jogador, &atual->hitbox) == 1){ // ai se tiver colisao 
            tipo_de_colisao(j->jogador, &atual->hitbox); // pega esse tipo de colisao
        }

        atual = atual->proximo;
    }
}

void sprites_jogo(Jogo* j){
    BeginDrawing(); // aq sao funcoes do raylib
        ClearBackground(BLACK); // cria um fundo preto para os obstaculos que passaram n bugar

        // add os sprites dps

        Obstaculo* atual = j->lista; 
        while(atual != NULL){
            sprite_obstaculo(atual); // cria o sprit do obstaculo toda vez que a lista aumentar
            atual = atual->proximo; 
        }
        sprite_Jogador(j->jogador); // recebe o estado do jogador
    EndDrawing();
}

void fechar_jogo(Jogo* j){ 

    Obstaculo* atual = j->lista; 
    while(atual != NULL){
        Obstaculo* proximo = atual->proximo; 
        free(atual); 
        atual = proximo; 
    }

    j->lista = NULL;

    free(j->jogador);
    j->jogador = NULL;

    CloseWindow(); // fecha o raylib
}