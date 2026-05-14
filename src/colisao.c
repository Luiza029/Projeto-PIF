#include "colisao.h"
#include "chunk.h"
#include "jogo.h"
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

int houve_colisao(Jogador* j, Jogo *jogo){
    int chunk_index = 0;
    Chunk *atual = jogo ->chunks;

    while(atual){
        for(int l=0; l<CHUNK_ROWS; l++){
            for(int c=0; c<CHUNK_COLS; c++){
                if(atual->mapa[l][c] == 0){
                    continue;
                }

                int x = (chunk_index *CHUNK_COLS + c) * TAMANHO_BLOCO - (int)jogo->offset;
                int y = l *TAMANHO_BLOCO;

                Rectangle bloco = {x, y, TAMANHO_BLOCO, TAMANHO_BLOCO};

                if(CheckCollisionRecs(j->hitbox, bloco)){
                    if(atual->mapa[l][c] == 2){
                        j->vivo = 0;
                    } else{
                        tipo_de_colisao(j, l, bloco);
                    }

                    return 1;
                }
            }
        }

        chunk_index++;
        atual = atual ->proximo;
    }

    return 0;
}

void tipo_de_colisao(Jogador* j, int l, Rectangle bloco){
    (void) bloco;

    if(j->velocidadeY > 0){
        j->velocidadeY = 0;
        j->y = l * TAMANHO_BLOCO - j->hitbox.height;
    }

    else if(j->velocidadeY < 0){
        j->velocidadeY = 0;
        j->y = (l + 1) * TAMANHO_BLOCO;
    }

    else{
        j->vivo = 0;
    }

    j->hitbox.y = j->y;
}

void sprite_colidivel(Colidivel* c){

    DrawRectangleRec(c->hitbox, RED);
}

void sumir_colidivel(Colidivel* c){
    free(c);
    c = NULL;
}