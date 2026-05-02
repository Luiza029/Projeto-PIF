#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "obstaculo.h"
#include "colisao.h"

Obstaculo *criar_obstaculo (float x, float y, float altura, float largura, int tipo){
    Obstaculo* obs = malloc (sizeof(Obstaculo));

    obs->proximo = NULL; //ainda não existe um segundo obstáculo, por isso o NULL
    obs->hitbox.hitbox = (Rectangle){x, y, largura, altura};
    obs->hitbox.tipo = tipo;
    obs->velocidadeX = 500; //valor de teste
    obs->cor = PURPLE;
    
    return obs;
}
//função feita para dar free no obstáculo que sair da tela
void apagar_obstaculo (Obstaculo* obs){
    free(obs);
    obs = NULL;
}
//adiona um obstaculo na lista que vai aparecer na tela do jogo
Obstaculo *adicionar_obstaculo (Obstaculo* lista, Obstaculo* obstaculo){
    obstaculo->proximo = lista;
    return obstaculo;
}
//remove um obstaculo da mesma lista
Obstaculo *remover_obstaculo (Obstaculo* lista, Obstaculo* obstaculo){
    if (lista == NULL){
        return NULL;
    }
    //criei variaveis temporárias para percorrer a lista e conseguir manipular
    Obstaculo* atual = lista;
    Obstaculo* anterior = NULL;

    while(atual != NULL && atual != obstaculo){
        anterior = atual;
        atual = atual->proximo;
    }

    if (atual == NULL){ //casos possíveis de acontecer rodando o jogo
        return NULL;
    }else if (anterior == NULL){ 
        Obstaculo* tempo = atual->proximo;
        apagar_obstaculo(atual);
        return tempo;
    }else if(anterior != NULL){
        anterior->proximo = atual->proximo;
        apagar_obstaculo(atual);
        return lista;
    }
}

//Vai atualizzar a posição dos obstáculos a cada loop 
Obstaculo* atualizar_obstaculos(Obstaculo* lista, float delta){
    Obstaculo* atual = lista;
    while(atual != NULL){
        atual->hitbox.hitbox.x = atual->hitbox.hitbox.x - atual->velocidadeX * delta;  
        if(atual->hitbox.hitbox.x < 0){
            Obstaculo* proximo = atual->proximo;
            lista = remover_obstaculo(lista, atual);
            atual = proximo;
        }else{
            atual = atual->proximo;
        }
    }

    return lista;
}

void sprite_obstaculo (const Obstaculo* obs){
    DrawRectangleRec(obs->hitbox.hitbox, obs->cor);
}