/*
    1) Declare a estrutura vetorDinamico apresenta a seguir

    typedef struct{
        int *itens;
        int capacidade
        int tamanho;
    }VetorDinamico;

    2) Escreva a seguinte funcao vetorDinamico *criaVetor(int capacidadeInicial)
    que inicializa um vetor dinâmico com a capacidadde inicial fornecida  e
    retorne um ponteiro para ele

    3) Desenvolva a funcao redimensionaVetor(VetorDinamico *vetor) que dobre a
    capacidade do vetor.

    4) Implemente a funcao void adicionaVetor(VetorDinamico *vetor, int elemento)
    que adiciona um elemento ao vetor. A funcao devera redimensionar o vetor se o
    tamanho alcancar a capacidade.

    5) Escreva a funcao void liberaVetorDInamico(VetorDinamico *vetor) que libera a
    memoria alocada para os itens do vetor e, em seguida, para o proprio vetor.

    6) Implemente a funcao void removeElemento(VetorDinamico *vetor, int indice) que
    remova um elemento em um indice especificado e ajusta o tamanho do vetor se neces
    sario.

    7) Crie um programa chamado testaVetorDinamico que contenha a funcao main()
    que teste funcoes para tratamento do vetorDinamico
*/

#include <stdio.h>
#include <stdlib.h>
#include "vetorDinamico.h"

VetorDinamico *criaVetor(VetorDinamico *vetor, int capacidadeInicial)
{
    VetorDinamico *vetor = malloc(sizeof(VetorDinamico));
    if(vetor == NULL)
    {
        fprintf(stderr,"Sinto muito, houve falha na alocacao de memoria (memoria insuficiente)");
        return NULL;
    }

    vetor -> itens = malloc(sizeof(int) * capacidadeInicial);
        if(vetor -> itens == NULL)
    {
        fprintf(stderr,"Sinto muito, houve falha na alocacao de memoria (memoria insuficiente)");
        free(vetor);
        return NULL;
    }

    vetor -> capacidade = capacidadeInicial;
    vetor -> tamanho = 0;
    
    return vetor;
}

void redimensionaVetor(VetorDinamico *vetor)
{
}

void adicionaVetor(VetorDinamico *vetor, int elemento)
{
}

void removeElemento(VetorDinamico *vetor, int indice)
{
}

void liberaVetorDinamico(VetorDinamico *vetor)
{
}

 /*
                                        NOTAS

    fprintf funciona para arquivos, mensagens de erro sao comumente comunicadas como
    fprintf(stderr)
 */
