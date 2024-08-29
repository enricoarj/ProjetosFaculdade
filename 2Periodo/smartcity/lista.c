
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "smartcity.h"

//Funcoes Lista
void criaLista(ListaCDE *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->tamLista = 0;
}

int insereLista(ListaCDE *l, int numVia){
    // alocando no na memoria e checando se deu certo
    NodeCaminhos *aux = (NodeCaminhos *) malloc(sizeof(NodeCaminhos));
    if(aux == NULL)
        return 0;

    // guardando o numVia e incrementando o tamanho da lista
    aux->numVia = numVia;
    l->tamLista++;

    // 1o caso: primeiro elemento
    if(l->inicio == NULL){

        //todos apontam para o unico no existente
        l->inicio = aux;
        l->fim = aux;
        aux->ant = l->fim;
        aux->prox = l->inicio;

        return 1;
    }

    // 2o caso: ja ha elementos, insere no fim

    aux->ant = l->fim; //ant do novo fim aponta para antigo fim
    aux->prox = l->inicio; //prox do novo fim aponta pra inicio
    l->fim->prox = aux; //prox do antigo fim aponta para novo fim
    l->fim = aux; //l->fim aponta para novo fim
    l->inicio->ant = l->fim; //ant do inicio aponta para novo fim

    return 1;
}

int insereOrdenadoLista(ListaCDE *l, int numVia){

    // alocando no na memoria e checando se deu certo
    NodeCaminhos *aux = (NodeCaminhos *) malloc(sizeof(NodeCaminhos));
    if(aux == NULL)
        return 0;

    // guardando o numVia e incrementando o tamanho da lista
    aux->numVia = numVia;
    l->tamLista++;

    // 1o caso: primeiro elemento
    if(l->inicio == NULL){
        //todos apontam para o unico no existente
        l->inicio = aux;
        l->fim = aux;
        aux->ant = l->fim;
        aux->prox = l->inicio;
        return 1;
    }

    // 2o caso: numVia menor que o numVia do inicio, insere no inicio
    if(numVia < l->inicio->numVia){
        aux->ant = l->fim; //ant do novo inicio aponta para fim
        aux->prox = l->inicio; //prox do novo inicio aponta para antigo inicio
        l->inicio->ant = aux; // anterior do antigo inicio aponta para novo inicio
        l->inicio = aux; //l->inicio aponta para novo inicio
        l->fim->prox = l->inicio; //proximo do fim aponta para novo inicio
        return 1;
    }

    //3o caso: numVia maior que o numVia do fim, insere no fim 
    if(numVia > l->fim->numVia){
        aux->ant = l->fim; //ant do novo fim aponta para antigo fim
        aux->prox = l->inicio; //prox do novo fim aponta pra inicio
        l->fim->prox = aux; //prox do antigo fim aponta para novo fim
        l->fim = aux; //l->fim aponta para novo fim
        l->inicio->ant = l->fim; //ant do inicio aponta para novo fim
        return 1;
    }

    //4o caso: insercao ordenada no meio 
    // inicializa-se dois nos no comeco da lista, que serao responsaveis por percorre-la
    NodeCaminhos *anterior = l->inicio;
    NodeCaminhos *atual = anterior->prox;

    while(numVia > atual->numVia){
        // percorre a lista ate achar a posicao certa
        anterior = atual;
        atual = atual->prox;
    }
    // insiro o no entre anterior e atual
    aux->ant = anterior; // ant do novo no aponta para anterior
    aux->prox = atual; // prox do novo no aponta para atual
    anterior->prox = aux; // prox do anterior aponta para o novo no
    atual->ant = aux; // ant do atual aponta para o novo no
    return 1;
}

int retiraLista(ListaCDE *l, int numVia){
    NodeCaminhos *aux;
    if(l->inicio == NULL){
        printf("Lista vazia\n");
        return 0;
    }

    // 1o caso: lista unitaria
    if((numVia == l->inicio->numVia) && (l->inicio == l->fim)) {
        aux = l->inicio; // aux aponta para o no que vou remover
        l->inicio = NULL; //inicio aponta pra null
        l->fim = NULL; // fim aponta pra null
        free(aux); // libero a memoria
        l->tamLista--;
        return 1;
    }

    /* 2o caso: removendo primeiro elemento */
    if(numVia == l->inicio->numVia) {
        aux = l->inicio; // aux aponta para o no que vou remover
        l->inicio = aux->prox; //inicio aponta para o novo inicio (o segundo elemento)
        l->inicio->ant = l->fim; // o anterior do novo inicio aponta para o fim
        l->fim->prox = l->inicio; // o proximo do fim aponta para o novo inicio
        free(aux); //libero memoria
        l->tamLista--;
        return 1;
    }

    /* 3o caso: removendo ultimo elemento */
    if(numVia == l->fim->numVia) {
        aux = l->fim; // aux aponta para o no que vou remover
        l->fim = aux->ant; //fim aponta para o novo fim (penultimo elemento)
        l->fim->prox = l->inicio; // o proximo do novo fim aponta para o inicio
        l->inicio->ant = l->fim; // o anterior do inicio aponta para o novo fim
        free(aux); //libero a memoria
        l->tamLista--;
        return 1;
    }
    // 4o caso: removendo um elemento no meio
    aux = l->inicio->prox; // aux aponta para o segundo elemento
    //percorro a lista ate achar o elemento, ou chegar no fim
    while((numVia != aux->numVia) && (aux != l->fim))
        aux = aux->prox;
    if(aux == l->fim){ // se cheguei ao fim, nao encontrei o elemento
        printf("O elemento %d nao esta na lista.\n", numVia);
        return 0;
    }

    //se encontrei o elemento, removo ele
    aux->prox->ant = aux->ant; // o anterior do proximo a aux aponta para o elemento anterior a aux
    aux->ant->prox = aux->prox; // o proximo do anterior a aux aponta para o proximo elemento em relacao a aux
    free(aux); //libero a memoria
    l->tamLista--;
    return 1;
}

int estaVaziaLista(ListaCDE l){
    if(l.inicio == NULL)
        return 1;
    return 0;
}

int getInicio(ListaCDE l){
    return l.inicio->numVia;
}


int getFim(ListaCDE l){
    return l.fim->numVia;
}

int getTamanho(ListaCDE l){
    return l.tam;
}

/*
    Exibe os elementos da lista, dependendo do sentido:
    1 - exibe do inicio ao fim
    2 - exibe do fim ao inicio
*/
void mostra(ListaCDE l, int sentido){
    NodeCaminhos *aux;
    if(l.inicio == NULL) // lista vazia, nao mostra nada
            printf("Lista vazia!\n");
    else { // lista possui elementos, mostra dependendo do sentido
        if(sentido == 1){ // percorrendo do inicio ao fim
            printf("\nExibindo lista do inicio ao fim:\n\n");
            aux = l.inicio;
            do {
                printf("numVia: %d\n", aux->numVia);
                aux = aux->prox;
            }while(aux != l.inicio);
        }
        else { // percorrendo do fim ao inicio

            printf("\nExibindo lista do fim ao inicio:\n\n");
            aux = l.fim;
            do {
                printf("numVia: %d\n", aux->numVia);
                aux = aux->ant;
            } while(aux != l.fim);
        }
    }
}


