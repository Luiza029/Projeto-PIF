#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"

void iniciar_jogo(Jogo* j){
    InitWindow(800, 600, "Projeto-PIF"); 
    ToggleFullscreen();
    j ->estado = JOGANDO; 
    j -> jogador = criarJogador(100, (LINHA - 1) * TAMANHO_BLOCO, 50, 50);
    j -> offset = 0;
    j ->velocidade = 200;

    for(int l=0; l<LINHA; l++){
        for(int c=0; c<COLUNA; c++){
            if(l == 0){
                j->mapa[l][c] = 1; // preenche
            }

            else if(l == LINHA - 1){
                j->mapa[l][c] = 1;
            }

            else{
                j->mapa[l][c] = 0; // vazio
            }
        }
    }
}

void atualizar_jogo(Jogo* j){
    float delta = GetFrameTime(); // GetFrameTime, retorna o tempo do ultimo frame redenrizado, com isso o delta recebe esse tempo 
    atualizarJogador(j->jogador, delta); // manda para a funcao de atualizar jogador (aquele para saber se ele cai para cima ou para baixo)
    
    j->offset += j->velocidade *delta; 

    if(j->offset >= TAMANHO_BLOCO){
        j->offset = 0;
        
        for(int l=0; l<LINHA; l++){
            for(int c=0; c<COLUNA - 1; c++){
                j->mapa[l][c] = j->mapa[l][c+1];
            }

            if(l == 0){
                j->mapa[l][COLUNA - 1] = 1;
            }

            else if(l == LINHA - 1){
                j->mapa[l][COLUNA - 1] = 1;
            }

            else{
                j->mapa[l][COLUNA - 1] = rand() % 2;
            }
        }
    }

    j->velocidade += 0.5 * delta; // valocidade do mapa

    if(j->velocidade >= 500){
        j->velocidade = 500;
    }

}

void sprites_jogo(Jogo* j){
    BeginDrawing(); // aq sao funcoes do raylib
        ClearBackground(BLACK); // cria um fundo preto para os obstaculos que passaram n bugar

        for(int l=0; l<LINHA; l++){
            for(int c=0; c<COLUNA; c++){
                int x = (c * TAMANHO_BLOCO) - j->offset;
                int y = l * TAMANHO_BLOCO;
                
                // colocar as imahes dps
                if(j->mapa[l][c] == 1){ // chao e teto
                    DrawRectangle(x, y, TAMANHO_BLOCO, TAMANHO_BLOCO, GRAY);
                }

                else if(j->mapa[l][c] == 2){ // obstaculo
                    DrawRectangle(x, y, TAMANHO_BLOCO, TAMANHO_BLOCO, RED);
                }
            }
        }

        sprite_Jogador(j->jogador); // recebe o estado do jogador
    EndDrawing();
}

void fechar_jogo(Jogo* j){ 
    free(j->jogador);
    j->jogador = NULL;

    CloseWindow(); // fecha o raylib
}