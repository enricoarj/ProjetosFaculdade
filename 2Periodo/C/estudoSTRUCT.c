/*
16/02/2024
ESTUDO DE STRUCT
*/

#include <stdio.h>
#include <string.h>

typedef struct ps{
    int raStruct;
    float notasStruct[3];
}Aluno;

void insereAluno(Aluno*a);
void imprimeAluno(Aluno a);

int main(){
    Aluno jorge, douglas;
    insereAluno(&jorge);
    insereAluno(&douglas);
    imprimeAluno(jorge);
    imprimeAluno(douglas);
    return 0;
}

void insereAluno(Aluno*a){
    int ra;
    float notas[3];
    printf("\nDigite o R.A.= ");
    scanf("%d", &ra);
    a -> raStruct = ra;
    for(int i = 0; i < 3; i ++){
    printf("Digite a %d nota. = ", i+1);
    scanf("%f", &notas[i]);
    a -> notasStruct[i] = notas[i];
    }
    a++;
}

void imprimeAluno(Aluno a){
    printf("\nR.A. = %d\n", a.raStruct);
    printf("Notas: %.2f  %.2f   %.2f \n", a.notasStruct[0], a.notasStruct[1], a.notasStruct[2]);
}
