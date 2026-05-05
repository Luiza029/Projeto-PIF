#include "colisao.h"
#include <stdlib.h>

int houve_colisao(Jogador* j, Jogo* m){

    
    for(int l=0; l<LINHA; l++){
        for(int c=0; c<COLUNA; c++){
            
            int x = (c * TAMANHO_BLOCO) - m->offset;
            int y = l * TAMANHO_BLOCO;

            Rectangle bloco;
            bloco.x = x;
            bloco.y = y;
            bloco.width = TAMANHO_BLOCO;
            bloco.height = TAMANHO_BLOCO;

            if(m->mapa[l][c] == 1){
                if(CheckCollisionRecs(j->hitbox, bloco) == 1){
                    tipo_de_colisao(j , l);
                    return 1;
                }

            }
            
            else if(m->mapa[l][c] == 2){
                if(CheckCollisionRecs(j->hitbox, bloco) == 1){
                    tipo_de_colisao(j , l);
                    return 1;
                }
                
            }
        }
    }
    
    return 0;
}

void tipo_de_colisao(Jogador* j, int l){
    if(l == 0){
        j->velocidadeY = 0;
    }

    else if(l == LINHA - 1){
        j->velocidadeY = 0;
    }

    else{
        j->vivo = 0;
    }
}
