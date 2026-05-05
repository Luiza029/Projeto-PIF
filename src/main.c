#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "jogo.h"

int main(){
    srand(time(NULL));
    
    Jogo j;
    iniciar_jogo(&j);

    while(!WindowShouldClose()){
        atualizar_jogo(&j);
        sprites_jogo(&j);
    }

    fechar_jogo(&j);
    return 0;
}