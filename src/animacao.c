#include <animacao.h>


AnimacaoSprite Criar_Animacao_Sprite(Texture2D atlas, int fps, Rectangle retangulos[], int largura){
    AnimacaoSprite animacaosprite = {

        .atlas= atlas,
        .fps = fps,
        .larguraret = largura
    };

    Rectangle* mem = (Rectangle*) malloc (sizeof(Rectangle) * largura);
    if (mem == NULL){
        TraceLog(LOG_FATAL, "Sem memoria para criar Criar_Animacao_Sprite");
        animacaosprite.larguraret = 0;
        return animacaosprite;
    }

    animacaosprite.retangulos = mem;

    for ( int i=0; i< largura; i++){
        animacaosprite.retangulos[i] = retangulos[i];
    }

    return animacaosprite;
}

void PararAnimacaoSprite(AnimacaoSprite animacaosprite){
    free(animacaosprite.retangulos);
}

void DesenhaAnimacaoSpritePro(AnimacaoSprite animacao, Rectangle dest, Vector2 origin, float rotation, Color tint){
    int indice = (int)(GetTime() * animacao.fps) % animacao.larguraret;
    Rectangle source = animacao.retangulos[indice];
    DrawTexturePro(animacao.atlas, source, dest, origin, rotation, tint);
}