#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "jogo.h"
#include "colisao.h"

static void adicionar_chunks(Jogo* j, int indice){
    Chunk *nova = criar_chunks(indice);

    if(j->chunks == NULL){
        j->chunks = nova;
    } else{
        Chunk *atual = j->chunks;
        while(atual->proximo){
            atual = atual->proximo;
        }

        atual ->proximo = nova;
    }

    j->num_chunks++;
}

static void remover_primeira_chunk(Jogo *j){
    if(!j->chunks){
        return;
    }
    Chunk *removida = j->chunks;

    j->chunks = j->chunks->proximo;

    destruir_chunk(removida);
    
    j->num_chunks--;
}

void iniciar_jogo(Jogo *j){
    InitWindow(800, 600, "Projeto-PIF");
    ToggleFullscreen();

    j->estado = JOGANDO;
    j->jogador = criarJogador(100, (LINHA - 2) * TAMANHO_BLOCO, 50, 50);
    j->offset = 0;
    j->velocidade = 200;
    j->chunks = NULL;
    j->num_chunks = 0;

    adicionar_chunks(j, 0);

    for(int i=0; i<3; i++){
        adicionar_chunks(j, rand() % 20);
    }
}

void atualizar_jogo(Jogo *j){
    float delta = GetFrameTime();
    atualizarJogador(j->jogador, delta);

    if(IsKeyPressed(KEY_SPACE) || IsMouseButtonPressed(MOUSE_LEFT_BUTTON)){
        inverterGravidade(j->jogador);
    }

    houve_colisao(j->jogador, j);

    if(!j->jogador->vivo){
        j->estado = GAME_OVER;
        return;
    }

    j->offset += j->velocidade * delta;

    float largura_chunk = CHUNK_COLS * TAMANHO_BLOCO;

    if(j->offset >= largura_chunk){
        j->offset -= largura_chunk;
        remover_primeira_chunk(j);
        adicionar_chunks(j, rand() % 20);
    }

    j->velocidade += 0.5f * delta;
    if(j->velocidade > 500){
        j->velocidade = 500;
    }

    if(j->jogador->y > GetScreenHeight() || j->jogador->y + j->jogador->hitbox.height < 0){
        j->jogador->vivo = 0;
    }
}

void sprite_jogo(Jogo *j){
    BeginDrawing();
        ClearBackground(BLACK);

        int chunk_index = 0;
        Chunk *atual = j->chunks;

        while(atual){
            for(int l=0; l<CHUNK_ROWS;  l++){
                for(int c=0; c<CHUNK_COLS; c++){
                    int x = (chunk_index *CHUNK_COLS + c) * TAMANHO_BLOCO - (int)j->offset;
                    int y = l * TAMANHO_BLOCO;

                    if(x > -TAMANHO_BLOCO && x < GetScreenWidth()){
                        if(atual->mapa[l][c] == 1){
                            DrawRectangle(x, y, TAMANHO_BLOCO, TAMANHO_BLOCO, GRAY); // chao / teto
                        }

                        else if(atual->mapa[l][c] == 2){
                            DrawRectangle(x, y, TAMANHO_BLOCO, TAMANHO_BLOCO, RED); // obstaculo
                        }
                    }
                }
            }
            chunk_index++;
            atual = atual ->proximo;
        }

        sprite_Jogador(j->jogador);
    EndDrawing();
}

void sprite_game_over(Jogo*){
    BeginDrawing();
        ClearBackground(BLACK);
        DrawText("GAME OVER", GetScreenWidth()/2 - 150, GetScreenHeight()/2 - 50, 60, RED);
        DrawText("Pressione ENTER para reiniciar", GetScreenWidth()/2 - 200, GetScreenHeight()/2 + 30, 25, WHITE);
    EndDrawing();
}

void reiniciar_jogo(Jogo *j){
    Chunk *atual = j->chunks;

    while(atual){
        Chunk *next = atual->proximo;
        destruir_chunk(atual);
        atual = next;
    }

    free(j->jogador);

    j->estado = JOGANDO;
    j->jogador = criarJogador(100, (LINHA -2) * TAMANHO_BLOCO, 50, 50);
    j->offset = 0;
    j->velocidade = 200;
    j->chunks = NULL;
    j->num_chunks = 0;

    adicionar_chunks(j, 0);

    for(int i=0; i<3; i++){
        adicionar_chunks(j, rand() % 20);
    }
}

void fechar_jogo(Jogo *j){
    Chunk *atual = j->chunks;

    while(atual){
        Chunk *next = atual ->proximo;
        destruir_chunk(atual);
        atual = next;
    }

    free(j->jogador);
    CloseWindow();
}