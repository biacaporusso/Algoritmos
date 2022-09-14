#include <stdio.h>
#include <string.h>

int main ()
{
    float cent;
    float n;
    int dezenacent, unidadecent;
    int  a, restoA, b, restoB, c, restoC, d;

    //int vetorinteiro[4], vetordecimal[2];
    char extenso[4][15];
    char extensocentavo[2][15];

    char vetormilhar[10][20] = {"mil ", "dois mil ", "tres mil ", "quatro mil ", "cinco mil ", "seis mil ", "sete mil ", "oito mil ", "nove mil "};
    char vetorcentena[10][20] = {"cento ", "duzentos ", "trezentos ", "quatrocentos ", "quinhentos ", "seiscentos ", "setecentos ", "oitocentos ", "novecentos "};
    char vetordezena[10][20] = {"dez ", "e vinte ", "e trinta ", "e quarenta ", "e cinquenta ", "e sessenta ", "e setenta ", "e oitenta ", "e noventa "};
    char vetorunidade[10][20] = {"e um ", "e dois ", "e tres ", "e quatro ", "e cinco ", "e seis ", "e sete ", "e oito ", "e nove "};

    char casadez[10][30] = {"e dez ", "e onze ", "e doze ", "e treze ", "e quatorze ", "e quinze ", "e dezesseis ", "e dezessete ", "e dezoito ", "dezenove "};
    char casadezseme[10][30] = {"dez ", "onze ", "doze ", "treze ", "quatorze ", "quinze ", "dezesseis ", "dezessete ", "dezoito ", "dezenove "};
    char vetorvazio[1][3] = {" "};

    char centenacome[10][20] = {"e cem", "e duzentos", "e trezentos", "e quatrocentos", "e quinhentos", "e seiscentos", "e setecentos", "e oitocentos", "e novecentos"};

    char centenaseme[10][20] = {"cem", "duzentos", "trezentos", "quatrocentos", "quinhentos", "seiscentos", "setecentos", "oitocentos", "novecentos"};
    char dezenaseme[10][20] = {"dez", "vinte ", "trinta ", "quarenta ", "cinquenta ", "sessenta ", "setenta ", "oitenta ", "noventa "};
    char unidadeseme[10][20] = {"um ", "dois ", "tres ", "quatro ", "cinco ", " seis ", "sete ", "oito ", "nove "};


    printf("Digite o valor: RS");
    scanf(" %f", &n);

    while (n != 0) {
            //PARTE INTEIRA (REAIS)
            //A = PARTE DO MILHAR
            a = ((int) n / 1000);

            restoA = ((int)n % 1000);
            //vetorinteiro[0] = a;
            strcpy(extenso[0], vetormilhar[a-1]);

            //B = PARTE DA CENTENA
            b = ((int)restoA / 100);
            restoB = ((int)restoA%100);
            //vetorinteiro[1] = b;
            strcpy(extenso[1], vetorcentena[b-1]);

            //C = PARTE DA DEZENA
            c = restoB/10;
            restoC = restoB%10;
            //vetorinteiro[2] = c;
            strcpy(extenso[2], vetordezena[c-1]);

            //D = PARTE DA UNIDADE
            d = restoC;
            //vetorinteiro[3] = d;
            strcpy(extenso[3], vetorunidade[d-1]);

            //tem milhar e tem centena e nao tem dezena nem unidade
            if (a!=0 && b!=0 && c==0 && d==0)
            {
                strcpy(extenso[1], centenacome[b-1]);
            }

            //apenas centena
            if (a == 0 && b!=0 && c==0)
            {
                strcpy(extenso[1], centenaseme[b-1]);
            }

            //apenas dezena e unidade
            if (a==0 && b==0)
            {
                strcpy(extenso[2], dezenaseme[c-1]);
            }

            //de um ate nove
            if (a==0 && b==0 && c==0)
            {
                strcpy(extenso[3], unidadeseme[d-1]);
            }

            //quando nao tem unidade
            if (d==0)
            {
                strcpy(extenso[3], vetorvazio[0]);
            }

            //quando nao tem dezena nem unidade
            if (restoB==0 && c==0)
            {
               strcpy(extenso[2], vetorvazio[0]);
               strcpy(extenso[3], vetorvazio[0]);
            }

            //onze, doze, treze...
            if (c==1)
            {
                strcpy(extenso[2], casadez[d]);
                strcpy(extenso[3], vetorvazio[0]);
                if (a==0 && b==0) ///apenas onze, doze, treze...
                {
                    strcpy(extenso[2], casadezseme[d]);
                }
            }

            //PARTE DECIMAL
            if (n - (int)n != 0)
            {
                cent = n - (int)n;
                cent = round(cent * 100);
                dezenacent = ((int)cent / 10);
                unidadecent = ((int)cent % 10);
                strcpy(extensocentavo[0], vetordezena[(int)dezenacent - 1]);
                strcpy(extensocentavo[1], vetorunidade[(int)unidadecent - 1]);
                if (dezenacent == 1)
                {
                    strcpy(extensocentavo[0], casadez[(int)unidadecent]);
                    strcpy(extensocentavo[1], vetorvazio[0]);
                }

                printf("Numero: %s%s%s%sreais %s%scentavos\n", extenso[0], extenso[1], extenso[2], extenso[3], extensocentavo[0], extensocentavo[1]);
                printf("\nDigite o valor (digite 0 para encerrar): RS");
                scanf(" %f", &n);
            } else {

            printf("Numero: %s%s%s%sreais\n", extenso[0], extenso[1], extenso[2], extenso[3]);
            printf("\nDigite o valor (digite 0 para encerrar): RS");
            scanf(" %f", &n);
            }

    }

    return 0;
}


