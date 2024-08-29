/*  NOME DO AUTOR DO JOGO: Enrico Souza Melo de Araujo

    PARTICIPANTES DO GRUPO: Enrico Souza Melo de Araujo;
                            Julia Romao;
                            Nicole Castro;
                            Rodrigo Grande;

    ASSUNTO: Jogo de escapar da sala.
*/

#include <stdio.h>
#include <ctype.h>

//Funcoes
void cozinha();
void banheiro();
void quarto();
void porta();

//Variaveis globais, pois diferentes funcoes as usam
char opcao = 'P', escolha = 'N';
int portaAberta = 0, itemsCozinha = 0, espelho = 0, quadro = 0, itemsQuarto = 0;

int main (void)
{


    //Comeco
    printf("\nVoce acorda num apartamento estranho, sem lembrancas de como chegou neste lugar.\nA primeira"
           " coisa que chama sua atencao eh a porta da saida, com diversos cadeados.\n");
    printf("\nAo lado direito da porta, ha uma cozinha; na esquerda, ha um banheiro;\n"
           "atras, voce ve uma porta aberta que leva ao quarto.\n");

    //Laco do jogo
    do
    {
        opcao = 'P';
        printf("\nPra onde voce quer ir?\n\n");
        printf("[P] Porta    [P]\n");
        printf("[C] Cozinha  [C]\n");
        printf("[B] Banheiro [B]\n");
        printf("[Q] Quarto   [Q]\n");
        scanf("%1c", &opcao);
        getchar();
        opcao = toupper(opcao);

        // Menu de opcoes e salas
        switch(opcao)
        {
        case 'C':
            cozinha();
            break;
        case 'B':
            banheiro();
            break;
        case 'Q':
            quarto();
            break;
        case 'P':
            porta();
            break;
        default:
            opcao = 'P';
            printf("\e[1;1H\e[2J");
            printf("\nOpcao invalida, digite uma das opcoes do menu...\n");
        }
    }

    while (portaAberta == 0);
    printf("\n\nParabens, voce conseguiu escapar!\n\n");
    return 0;
}

void cozinha()
{
     printf("\e[1;1H\e[2J");
            printf("\nVoce esta na cozinha\n");
            if(itemsCozinha == 0)
            {
                printf("\nNa cozinha, voce procura por algo que possa te ajudar, mas as gavetas estao praticamente vazias.\n"
                       "Voce encontra uma tesoura e uma chave de fenda em uma delas.\n\nPegar? [S/N] = ");
                scanf("%1c", &escolha);
                getchar();
                escolha = toupper(escolha);
                if(escolha == 'S')
                {
                    printf("\nVoce pegou os items.\n");
                    itemsCozinha = 1;
                    return;
                }
                else
                {
                    return;
                }
            }
            if(itemsCozinha == 1)
            {
                printf("\nVoce ja pegou tudo que havia aqui\n");

            }

            return;
}

void banheiro()
{
            printf("\e[1;1H\e[2J");
            printf("\nVoce esta no banheiro\n");
            if(espelho == 0)
            {
                printf("\nTudo parece em ordem, mas o espelho na frente da pia parece quebrado.\n"
                       "Parece haver algo escrito atras dos cacos, mas nao parece seguro tirar com as maos\n");
                if(itemsCozinha == 1)
                {
                    printf("\n\nUsar chave de fenda para tirar os cacos? [S/N] = ");
                    scanf("%1c", &escolha);
                    getchar();
                    escolha = toupper(escolha);
                    if(escolha == 'S')
                    {
                        printf("\nA frase ""Olhe alem do mar"" estava atras dos cacos.\n");
                        espelho = 1;
                        return;
                    }
                }
            }
            else
            {
                printf("\nA frase ""Olhe atras do mar"" estava atras dos cacos .\n");
            }
}

void quarto()
{
       printf("\e[1;1H\e[2J");
            printf("\nVoce esta no quarto\n");
            if(quadro == 0)
            {
                printf("\nO quarto esta completamente desarrumado, roupas jogadas pra todo lado\n"
                       "as janelas estao fechadas e nao da para ver nada fora. O que mais chama\n"
                       "sua atencao eh um quadro de um navio no meio do mar em uma das paredes.\n");
                if(espelho == 1)
                {
                    printf("\nQuer mexer no quadro? [S/N] = ");
                    scanf("%1c", &escolha);
                    getchar();
                    escolha = toupper(escolha);
                    if(escolha == 'S')
                    {
                        printf("\nO quadro parece preso na parede, escondendo algo atras, talvez seja possivel corta-lo.\n");
                        if(itemsCozinha == 1)
                        {
                            printf("Quer usar a tesoura para cortar o quadro? [S/N] = ");
                            scanf("%1c", &escolha);
                            getchar();
                            escolha = toupper(escolha);
                            if(escolha == 'S')
                            {
                                quadro = 1;
                                printf("\nVoce corta o quadro, revelando um alicate e um molho de chaves. Pegar? [S/N] = ");
                                scanf("%1c", &escolha);
                                getchar();
                                escolha = toupper(escolha);
                                if(escolha == 'S')
                                {
                                    printf("\nVoce pega as chaves e o alicate. Provavelmente, voce ja consegue abrir a porta.");
                                    itemsQuarto = 1;
                                }
                                else
                                {
                                    return;
                                }
                            }
                            else
                            {
                                return;
                            }
                        }
                        else
                        {
                            printf("\nVoce nao tem como abrir o quadro.\n");
                            return;
                        }
                        return;
                    }

                }

            }
            if(quadro == 1)
            {
                if(itemsQuarto == 0)
                {
                    printf("\nVoce cortou o quadro, revelando um alicate e um molho de chaves. Pegar? [S/N] = ");
                    scanf("%1c", &escolha);
                    getchar();
                    escolha = toupper(escolha);
                    if(escolha == 'S')
                    {
                        printf("\nVoce pega as chaves e o alicate. Provavelmente, voce ja consegue abrir a porta.");
                        itemsQuarto = 1;
                    }
                }
                else
                {
                    return;
                }

            }
            if(itemsQuarto == 1)
            {
                printf("\nVoce ja pegou tudo que podia no quarto, fuja!\n");
            }
}

void porta()
{
            printf("\e[1;1H\e[2J");
            printf("\nVoce esta na frente da porta...");
            printf("\nTentar abrir? [S/N]  ");
            scanf("%1c", &escolha);
            getchar();
            escolha = toupper(escolha);
            if(escolha == 'S')
            {
                if(itemsQuarto == 1)
                {
                    printf("\nVoce usa as chaves e o alicate para abrir os cadeados e cortar as correntes");
                    portaAberta = 1;
                }
                else
                {
                    printf("\nA porta esta trancada\n");
                }
            }
}
