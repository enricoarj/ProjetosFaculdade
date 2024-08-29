#ifndef SMART_CITY_H
#define SMART_CITY_H

typedef struct
{
    int codigo;
    char nome[30];
    float comprimento;
    int tipo_piso;
} via;

typedef struct
{
    via *vias;
    int capacidade;
    int tamanho;
} smart_city;

typedef struct noPedido{
    noPedido *prox;
    int pedido;
}NodePedido;

typedef struct noCaminhos{
    noCaminhos *ant;
    noCaminhos *prox;
    int numVia;
}NodeCaminhos;

typedef struct{
    NodePedido *inicio;
    NodePedido *fim;
    int tamFila;
}Fila;

typedef struct{
    NodeCaminhos *inicio;
    NodeCaminhos *fim;
    int tamLista;
}ListaCDE;

typedef struct

// Funcoes smartcity
smart_city* criaCidade(smart_city *cidade, int capacidade);
void redimensionaCapacidade(smart_city *cidade);
void adicionaVia(smart_city *cidade, via novaVia);
void removeVia(smart_city *cidade, int codigo);
void exibeVias(smart_city cidade);
void liberaMemoria(smart_city *cidade);

// funcoes fila
void criaFila(Fila *q);
int insereFila(Fila *q, int numeroPedido);
int retiraFila(Fila *q, int *numeroPedido);
int filaVazia(Fila q);
int getInicioFila(Fila q);
int getFimFila(Fila q);
int getTamanhoFila(Fila q);
void mostraFila(Fila q);


// funcoes lista
void criaLista(ListaCDE *l);
int insereLista(ListaCDE *l, int numVia);
//int insereOrdenadoLista(ListaCDE *l, int dado);
int retiraLista(ListaCDE *l, int numVia);
int estaVaziaLista(ListaCDE l);
int getInicioLista(ListaCDE l);
int getFimLista(ListaCDE l);
int getTamanhoLista(ListaCDE l);
void mostraLista(ListaCDE, int sentido);


#endif
