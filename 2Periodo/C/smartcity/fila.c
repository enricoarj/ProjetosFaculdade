
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smartcity.h"

// Funcoes Fila
void criaFila(Fila *q){
    q->inicio = NULL;
    q->fim = NULL;
    q->tamFila = 0;
}

/*
    A funcao 'insere' insere um No sempre ao final da fila.
    - Se Fila eh vazia, inicio e fim apontam pra esse no.
    - Se Fila nao eh vazia, insere ao final, fazendo:
        - o ponteiro de proximo do fim atual apontar para o novo no
        - o ponteiro de fim passa a apontar para o novo no
*/
int insereFila(Fila *q, int numPedido){
    NodePedido *aux;
    aux = (NodePedido*) malloc(sizeof(NodePedido));
    if(aux == NULL) //checa se deu certo
        return 0;

    //inicializa o no
    aux->numPedido = numPedido;
    aux->prox = NULL;

    q->tamFila++; //incrementa o tamanho da fila

    //se for o primeiro elemento, tanto inicio quanto fim apontam pra ele
    if(q->inicio == NULL){
        q->inicio = aux;
        q->fim = aux;
        return 1;
    }

    //se nao, prox do antigo fim aponta pro novo no e fim passa a apontar pro novo no
    q->fim->prox = aux;
    q->fim = aux;
    return 1;
}

/*
    A funcao 'retira' remove sempre o numVia do comeco da Fila.
    - O inicio passa a apontar para o proximo do inicio.
    - se a fila nao tem mais elementos, tanto inicio quanto fim irao apontar para NULL.
*/
int retiraFila(Fila *q, int *numPedido){
    NodePedido *aux;
    aux = q->inicio;
    if(aux == NULL) // checa se fila esta vazia
        return 0;
    *numPedido = aux->numPedido; //recupera o numVia
    q->tamFila--; //diminui o tamanho da fila
    q->inicio = aux->prox; //inicio aponta para o segundo elemento
    //se fila esta vazia agora, fim deve apontar para null tambem
    if(q->inicio == NULL) //
        q->fim = NULL;
    free(aux); //libera a memoria
    return 1;
}

//Verifica se esta vazio (1) ou nao (0)
int estaVaziaFila(Fila q){
    if(q.inicio == NULL)
        return 1;
    return 0;
}

//Retorna o numVia do No apontado por inicio.
int getInicioFila(Fila q){
    return q.inicio->numVia;
}

 // Retorna o numVia do No apontado por fim.
int getFimFila(Fila q){
    return q.fim->numVia;
}

// Retorna o tamanho da Fila.
int getTamanhoFila(Fila q){
    return q.tamFila;
}

// Imprime os elementos da Fila do primeiro ao ultimo se ela nao estiver vazia.
void mostraFila(Fila q){
    NodePedido *aux;
    aux = q.inicio;
    if (aux == NULL){
        printf("Fila vazia!\n");
    }
    while(aux != NULL){
        printf("numVia enfileirado: %d\n", aux->numVia);
        aux = aux->prox;
    }
}




