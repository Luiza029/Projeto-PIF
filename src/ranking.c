#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ranking.h"

void salvar_pontos(Ranking* lista, int tamanho){
    FILE* pontuacao = fopen("ranking.txt", "w");

    if(pontuacao == NULL){
        return;
    }

    for(int i=0; i<tamanho; i++){
        fprintf(pontuacao, "%s %d\n", lista[i].nome, lista[i].pontos);
    }

    fclose(pontuacao);
}

void carregar_pontos(Ranking* lista, int* tamanho){
    FILE* pontuacao = fopen("ranking.txt", "r");
    *tamanho = 0;

    if(pontuacao == NULL){
        return;
    }

    while(*tamanho < MAX_RANKING && fscanf(pontuacao, "%s %d", lista[*tamanho].nome, &lista[*tamanho].pontos) == 2){
        (*tamanho)++;
    }

    fclose(pontuacao);
}

void inserir_pontuacao(Ranking* lista, int* tamanho, char* nome, int pontos){
    // verifica se entra no top 5
    if(*tamanho == MAX_RANKING && pontos <= lista[*tamanho - 1].pontos){
        return;
    }

    // encontra a possicao
    int pos = *tamanho;
    for(int i=0; i<*tamanho; i++){
        if(pontos > lista[i].pontos){
            pos = i;
            break;
        }
    }

    // empuura os rankinfs para baixo
    int limite = *tamanho < MAX_RANKING ? *tamanho : MAX_RANKING - 1;
    for(int i=limite; i>pos; i--){
        lista[i] = lista[i-1];
    }

    // coloca na posicao correta
    strncpy(lista[pos].nome, nome, 49);
    lista[pos].pontos = pontos;

    if(*tamanho < MAX_RANKING){
        (*tamanho)++;
    }
}

void mostrar_na_tela(Ranking* lista, int tamanho){
    DrawText("RANKING", GetScreenWidth()/2 - 80, 150, 40, YELLOW);

    for(int i=0; i<tamanho; i++){
        DrawText(TextFormat("%d. %s - %d pts", i+1, lista[i].nome, lista[i].pontos), GetScreenWidth()/2 - 150, 220 + i, 30, WHITE);
    }
}