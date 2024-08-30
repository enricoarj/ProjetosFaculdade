#include <stdio.h>

int fatorial(int numero);

int main()
{
    int x = 0;
    printf("\nDigite um numero para saber o fatorial = ");
    scanf("%d", &x);
    printf("\nO fatorial de %d eh %d \n", x, fatorial(x));
    return 0;
}

int fatorial(int numero)
{
    if(numero == 1 || numero < 0 )
    {
        return 1;
    }
    else
        return numero * fatorial(numero - 1);
}
