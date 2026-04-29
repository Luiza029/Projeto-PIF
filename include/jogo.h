#ifndef JOGO_H
#define JOGO_H
#include "raylib.h"
#include "jogador.h"
#include "obstaculo.h"
#include "colisao.h"

typedef struct Jogo{ //Criação da struct para funcionalidades do jogo
    Jogador *jogador;
    Obstaculo *lista;
    int estado;
}Jogo;

void iniciar_jogo (Jogo*); // Função que ao ser rodada, inicia todos os comandos que serão executados 
void atualizar_jogo (Jogo*); // É o loop que atualizará o jogo a cada frame 
void sprites_jogo (Jogo*); // Função que vai adicionar todos os tipos de sprites na tela
void fechar_jogo (Jogo*); // Fecha a tela do jogo e apaga os arquivos para evitar lixo de memória e bugs

#endif