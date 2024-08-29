/*
Imagine que sua equipe de desenvolvedores de software foi contratada para
desenvolver um micro navegador web para um console de caracteres.
Você é responsável por implementar uma estrutura de dados que armazene o endereço das abas abertas.
O usuário pode mover-se para a aba seguinte ou para a anterior.
Caso esteja na primeira aba e mova-se para a anterior, deverá ser direcionado para a última aba.
Se estiver na última e tentar mover-se para a próxima, deverá ser redirecionado para a primeira aba.

AUTOR: Enrico Souza Melo de Araujo
DATA: 15 de Maio de 2024
*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct t{
    char url[15];
    struct t *proximo;
    struct t *anterior;
}Tab;

typedef struct l{
    Tab *inicio;
    Tab *fim;
    int tamanhoLista;
}Lista;

void cria(Lista *l);
int insereTab(Lista* l, char endereco[]);
void mostraTab(Lista l, int sentido);


int main(){
    Lista l;
    int sentido = 1;
//    char endereco[50];
    insereTab(&l, "www.pucminas.br");
    insereTab(&l, "www.pucminas.instructure.com");
    insereTab(&l, "www.youtube.com");
    insereTab(&l, "www.sgapucminas.br");

    printf("\nTamanho da Lista: %d\n", l.tamanhoLista);
    //printf("Primeira tab = %s\n", l.inicio->url);
  //  printf("Ultima tab = %s\n", l.fim->url);
    printf("Mostrando todas abas\n");
    Tab *aux = l.inicio;
    for(int i = 0; i < l.tamanhoLista; i++){
        printf("URL: %s\n", aux->url);
        aux = aux -> proximo;
    }
    printf("\n===========================================\n");

    mostraTab(l, sentido);

    return 0;
}


void cria(Lista *l){
    l->inicio = NULL;
    l->fim = NULL;
    l->tamanhoLista = 0;
}

int insereTab(Lista* l, char *endereco){
    Tab *aux = (Tab*)malloc(sizeof(Tab));
    if(aux == NULL){
        return 0;
    }
    if(l -> inicio == NULL){
        strcpy(aux -> url, endereco);
        aux -> anterior = aux;
        aux -> proximo = aux;
        l -> inicio = aux;
        l -> fim = aux;
    }
    else{
        strcpy(aux -> url, endereco);
        aux -> anterior = l -> fim;
        aux -> proximo = l -> inicio;
        l -> fim -> proximo = aux;
        l -> inicio -> anterior = l -> fim;
    }
    l -> tamanhoLista ++;
    return 1;
}

void mostraTab(Lista l, int sentido){
    Tab *aux = l.inicio;
    do
    {
        if(sentido == 1){
            printf("\nExibindo primeira tab\n");
            printf("\nEndereco primeira tab: %s\n", aux->url);
            printf("\n===========================================\n");
        }
        if(sentido == 2){
            aux = aux -> proximo;
            printf("\nExibindo proxima tab\n\n");
            printf("\nEndereco tab: %s", aux->url);
        }
        if(sentido == 3){
            aux = aux -> anterior;
            printf("\nExibindo tab anterior\n");
            printf("\nEndereco tab: %s", aux->url);
        }
        printf("\nSe deseja ver a proxima tab, digite 2\n");
        printf("\nSe deseja ver a tab anterior, digite 3\n");
        printf("\nSe deseja sair, digite 0\n");
        scanf("%d", &sentido);
        printf("\n===========================================\n");
    } while (sentido != 0);
}
