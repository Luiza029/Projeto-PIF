#include "raylib.h"
#include "time.h" 
#include "raymath.h"
#include "animacao.h"

//Constantes usadas para tamanho da tela
const int screenWidth = 600;
const int screenHeigth = 600;
const Vector2 screenSize = {screenWidth, screenHeigth};

//Variáveis globais da main
int _Pausado = 0;
Texture2D _TexturaIdle;
Texture2D _TexturaRun;
Texture2D _TexturaPulo;
AnimacaoSprite _AnimacaoIdle;
AnimacaoSprite _AnimacaoRun;
AnimacaoSprite _AnimacaoPulo;
AnimacaoSprite* _AnimacaoAtual;

void AtualizarFrameCriado(void);

int main(void) {

    srand(time(0));

    InitWindow(screenWidth, screenHeigth, "Meu Jogo");

    _TexturaIdle = LoadTexture("assets/Sprites/IDLE.png");
    _TexturaRun = LoadTexture("assets/Sprites/RUN.png");
    _TexturaPulo = LoadTexture("assets/Sprites/RUNNING JUMP.png");

    Rectangle framesIdle[] = {
        {0, 0, 80, 64},
        {80, 0, 80, 64},
        {160, 0, 80, 64},
        {240, 0, 80, 64},
        {320, 0, 80, 64},
        {400, 0, 80, 64},
        {480, 0, 80, 64},
        {560, 0, 80, 64},
    };

    _AnimacaoIdle = Criar_Animacao_Sprite(_TexturaIdle, 10, framesIdle, 8);

    Rectangle framesRun[] = {
        {0, 0, 80, 64},
        {80, 0, 80, 64},
        {160, 0, 80, 64},
        {240, 0, 80, 64},
        {320, 0, 80, 64},
        {400, 0, 80, 64},
        {480, 0, 80, 64},
        {560, 0, 80, 64},
    };

    _AnimacaoRun = Criar_Animacao_Sprite(_TexturaRun, 25, framesRun, 8);

    // Rectangle framesPulo[] = {
    //     {0,0,80,64},
    //     {80,0,80,64},
    //     {160,0,80,64},
    // };

    // _AnimacaoPulo = Criar_Animacao_Sprite(_TexturaPulo, 10, framesPulo, 3);

    _AnimacaoAtual = &_AnimacaoIdle;

    while (!WindowShouldClose()) {
        AtualizarFrameCriado();
    }

    fechar_jogo(&j);
    return 0;
}

void AtualizarFrameCriado(void){

    if (IsKeyPressed(KEY_SPACE)){
        _AnimacaoAtual = &_AnimacaoRun;
    }

    // if (IsKeyPressed(KEY_SPACE)){
    //     _AnimacaoAtual = &_AnimacaoPulo;
    //     _AnimacaoAtual = &_AnimacaoRun;
    // }

    if (IsKeyPressed(KEY_ENTER)){
        _Pausado = !_Pausado;
    }
    BeginDrawing();
        ClearBackground(RAYWHITE);

        Rectangle dest = {200, 200, 80, 64};
        DesenhaAnimacaoSpritePro(_AnimacaoAtual, dest, (Vector2){0,0}, 0, WHITE, _Pausado);

    EndDrawing();

}
