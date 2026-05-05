#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ranking.h"

void salvar_pontos(Ranking* r){
    FILE* pontuacao = fopen("ranking.txt", "a");

    if(pontuacao == NULL){
        printf("Arquivo nao existe!");
    } else{
        fprintf(pontuacao, "%s %d", r->nome, r->pontos);
        fclose(pontuacao);
    }
}

Ranking* carregar_pontos(){
    Ranking* arquivo = (Ranking*) malloc(sizeof(Ranking));
    FILE* pontuacao = fopen("ranking.txt", "r");

    if(pontuacao == NULL){
        printf("Arquivo nao existe");
        free(arquivo);

        return NULL;
    } else{
        fscanf(pontuacao, "%s %d", arquivo->nome, &arquivo->pontos);
        fclose(pontuacao);
    }
    return arquivo;
}

void mostrar_na_tela(Ranking* r){
    DrawText(TextFormat("Nome: %s", r->nome), 100, 150, 100, RED);
    DrawText(TextFormat("Pontuacao: %d", r->pontos), 100, 100, 100 ,RED);
}