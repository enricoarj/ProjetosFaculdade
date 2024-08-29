#include <stdio.h>

typedef struct{
    char tipoGrao[7];
    int quantidade;
}producao;

main(){
    producao p[5]={ "arroz",  634,
                    "cafe",   123,
                    "soja",   846,
                    "milho",  90,
                    "feijao", 234};
    int i, maior, aux;

    aux = 0;
    maior = p[0].quantidade;

    for(i=1; i < 5; i++){
        if( p[i].quantidade > maior ){
            aux = i;
            maior = p[i].quantidade;
        }
    }
        printf("%d", p[aux].quantidade);
        printf("%s", p[aux].tipoGrao);
}
