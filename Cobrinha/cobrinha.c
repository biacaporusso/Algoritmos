#include <stdio.h>
#include <stdlib.h>
#include <windows.h> // necessaria p/ função sleep
#include <conio.h> // necessaria p/ funçao _kbhit
#define M 32
#define N 33

void clrscr();

int main ()
{
    FILE *arq;
    int i, j, x[6], y[6], mov1, mov2;
    char cerc[M][N];
    char cobra1[] = {178};
    char cobra2[] = {177};
    char cobra3[] = {176};

    arq = fopen("cercadinho.txt", "r");

    if (arq == NULL) //teste para ver se o arquivo consegue ser aberto ou nao 
    {
        printf("Arquivo nao pode ser aberto");
        return 0;
    }
    
    //imprimindo primeira matriz com cobrinha
    for (i=0; i<M; i++)
    {
        for (j=0; j<N; j++)
        {
            fscanf(arq, "%c", &cerc[i][j]); // leitura da matriz que contem o arquivo

            //posição da cobrinha no inicio (linha 7 e colunas 20, 21, 22, 23, 24 e 25)
            x[0]=7;
            y[0]=20;
            for(int k = 1; k < 6; k++){
                x[k] = x[k-1];
                y[k] = y[k-1] + 1;
            }

            //atribuindo caracteres da tabela ascii na matriz p/ compor o corpo da cobrinha
            cerc[x[0]][y[0]] = cobra1[0]; //cabeça
            cerc[x[1]][y[1]] = cobra1[0]; //pescoço (cabeça e pescoço sao o mesmo caractere)
            cerc[x[2]][y[2]] = cobra2[0]; //meio do corpo
            cerc[x[3]][y[3]] = cobra2[0]; //meio do corpo
            cerc[x[4]][y[4]] = cobra3[0]; //fim do corpo
            cerc[x[5]][y[5]] = cobra3[0]; //fim do corpo
    
            if (cerc[i][j] != '0') 
            {
                printf("%c", cerc[i][j]); // printar apenas o cercadinho e os obstaculos
            } else 
            {
                printf(" "); // nao printar nada alem do cercadinho e obstaculos (para que ele transforme os zeros em espaços vazios)
            }
        }
    } 
    fclose(arq);

    srand(time(NULL));

    while ( !_kbhit() ) //O programa deve ser encerrado ao ser teclado qualquer tecla.
    {

        // sorteando o movimento (-1, 0 ou 1 = volta uma linha/coluna, mesma linha/coluna, avança uma linha/coluna)
        mov1 = (rand() % 3) -1;  //mov1 refere-se a linha       
        mov2 = (rand() % 3) -1; //mov2 refere-se a coluna

        while(mov1 == 0 && mov2 == 0){
            mov1 = (rand() % 3) -1;  //mov1 refere-se a linha       
            mov2 = (rand() % 3) -1; //mov2 refere-se a coluna
        }

        //condições: posição da cabeça ser diferente da posição do "pescoço" E posição da cabeça ser diferente de 1 (obstaculo ou cercadinho)
        if (cerc[x[0]+mov1][y[0]+mov2] != cerc[x[1]][y[1]] && cerc[x[0]+mov1][y[0]+mov2] != '1')  
        {
            //movimento da cobra: atualização do corpo da cobrinha (cabeça recebe pescoço, pescoço recebe corpo, corpo recebe cauda...)
            cerc[x[0]+mov1][y[0]+mov2] = cobra1[0];
            cerc[x[0]][y[0]] = cobra1[0];
            cerc[x[1]][y[1]] = cobra2[0];
            cerc[x[2]][y[2]] = cobra2[0];
            cerc[x[3]][y[3]] = cobra3[0];
            cerc[x[4]][y[4]] = cobra3[0];
            cerc[x[5]][y[5]] = '0';

            //atualização dos valores de x e y começando do final (ordem "decrescente" = da cauda pra cabeça)
            for(i = 5; i > 0; i--){
                x[i] = x[i-1];
                y[i] = y[i-1];
            }

            x[0] = x[0] + mov1;
            y[0] = y[0] + mov2;

            //imprimindo a matriz com o movimento realizado
            Sleep(200);
            system("cls");
            for (i=0; i<M; i++)
            {
                for (j=0; j<N; j++)
                {
                    if (cerc[i][j] != '0')
                    {
                        printf("%c", cerc[i][j]);
                    } else 
                    {
                        printf(" ");
                    }
                }
            }
        }
    }

    return 0;
}

void clrscr()
{
    system("cls");
}
