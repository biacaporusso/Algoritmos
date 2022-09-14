#include <stdio.h>
#include <stdlib.h>

#define D 12
//prototipos
int AnalisarSubmatriz (int **matriz, int linha, int coluna); //analisa se tem elementos repetidos dentro das submatrizes
int AnalisarLinha(int **matriz, int linha);
int AnalisarColuna(int **matriz, int coluna);
int AnalisarDiagonalPrincipal(int **matriz, int valorTeste);
int AnalisarDiagonalSecundaria (int **matriz, int valorTeste);
void DesalocarMemoria (int **sudoku);

int main () {

    FILE *arq;
    int i, j;

    //ABERTURA E ESCRITA DO ARQUIVO TEXTO
    arq = fopen("sudoku.txt", "r");

    if (arq == NULL) //teste para ver se o arquivo consegue ser aberto ou nao 
    {
        printf("\nArquivo nao pode ser aberto");
        return 0;
    } 

    int **sudoku = malloc(sizeof(int*)*12);
    for (int i = 0; i < 12; i++) {
        sudoku[i] = malloc(sizeof(int)*12);
    }

    for (i=0; i<D; i++) {
        for (j=0; j<D; j++) {

            fscanf(arq, "%d", &sudoku[i][j]);
            printf("%d ", sudoku[i][j]);
        }
        printf("\n");
    }
    fclose(arq);

    //VERIFICAÇÃO DE ELEMENTOS REPETIDOS DENTRO DAS SUBMATRIZES
    int repete1;
    int m=3, n=4;
    int verificaSubmatriz; 

    for (i=0; i<12; i++) {
        for (m=3; m<12; m=m+3) {
            for (n=4; n<12; n=n+4) {

                repete1 = AnalisarSubmatriz(sudoku, m, n);
                if (repete1 > 12) 
                    verificaSubmatriz = 1;
                else 
                    verificaSubmatriz = 0;
            }
        }
    }
    printf ("\n%d", verificaSubmatriz);


    //VERIFICAÇÃO DE ELEMENTOS REPETIDOS NAS LINHAS
    int k;
    int repete2;
    int verificaLinha=0;

    for (k=0; k<12; k++) {
        repete2 = AnalisarLinha(sudoku, k);
        if (repete2 > 1) { //ao comparar o primeiro ele com todos da linha, vai dar igual ao primeiro ele, por isso >1
            verificaLinha = 1;
            break;
        }
    }
    printf("\n%d", verificaLinha);

    //VERIFICAÇÃO DE ELEMENTOS REPETIDOS NAS COLUNAS
    int repete3;
    int verificaColuna=0;

    for (k=0; k<12; k++) {
        repete3 = AnalisarColuna(sudoku, k);
        if (repete3 > 1) { //ao comparar o primeiro ele com todos da linha, vai dar igual ao primeiro ele, por isso >1
            verificaColuna = 1;
            break;
        }
    }
    printf("\n%d", verificaColuna);

    //VERIFICAÇÃO DE ELEMENTOS REPETIDOS NA DIAGONAL PRINCIPAL
    int repete4;
    int verificaDP;

    for (k=0; k<12; k++) {
        repete4 = AnalisarDiagonalPrincipal(sudoku, sudoku[k][k]);
        if (repete4 > 12) {
            verificaDP = 1;
            break;
        } else
            verificaDP = 0;
    }
    printf("\n%d", verificaDP);

    //VERIFICAÇÃO DE ELEMENTOS REPETIDOS NA DIAGONAL SECUNDÁRIA
    int repete5;
    int verificaDS = sudoku[0][11];
    i=0;
    j=11;
    while (i<12) {
        repete5 = AnalisarDiagonalSecundaria(sudoku, sudoku[i][j]);
        if (repete5 > 12) {
            verificaDS = 1;
            break;
        } else
            verificaDS = 0;
        i++;
        j--;
    }
    printf("\n%d", verificaDS);

    //CONCLUSAO
    if (verificaLinha ==1 || verificaColuna == 1 || verificaSubmatriz == 1 || verificaDP == 1 || verificaDS == 1) {
        printf("\nNao eh uma solucao para sudoku :(");
    } else {
        printf("\nEh uma solucao para sudoku! :D"); 
    }
    
    DesalocarMemoria(sudoku);
    printf("\nMemoria desalocada.");


}

int AnalisarSubmatriz (int **matriz, int linha, int coluna) {

    int i, j;
    int m, n;    
    int valorTeste;
    int repete=0;
    for (m=linha-3; m < linha; m++){
        for (n=coluna-4; n<coluna; n++){
            valorTeste = matriz[m][n];

            for (i=(linha-3); i<linha; i++) {
                for (j=(coluna-4); j<coluna; j++) {
                    if (valorTeste == matriz[i][j])
                    repete++;
                }
            }
        }
    }

    return (repete);
}

int AnalisarLinha(int **matriz, int linha)  {

    int j, repete=0;
    int valorTeste = matriz[linha][0];

    for (j=0; j<12; j++) {

        if (valorTeste == matriz[linha][j]) 
            repete++; 
    }

    return (repete);

}

int AnalisarColuna(int **matriz, int coluna)  {

    int i, repete=0;
    int valorTeste = matriz[0][coluna];

    for (i=0; i<12; i++) {
        if (valorTeste == matriz[i][coluna])
            repete++;
    }

    return (repete);

}

int AnalisarDiagonalPrincipal (int **matriz, int valorTeste) {

    int repete=0;
    int k;

    for (k=0; k<12; k++) {
        if (valorTeste == matriz[k][k]) {
            repete++;
        }
    }

    return (repete);

}

int AnalisarDiagonalSecundaria (int **matriz, int valorTeste) {

    int i, j;
    int repete=0;

    for (i=0; i<12; i++) {
        for (j=11; j>-1; j--) {

            if (i+j == 11) {
                if (valorTeste == matriz[i][j]) {
                    repete++;
                }
            }
        }
    }
    //dessa maneira o repete esta dando apenas 1, pq o valorTeste está fixo em matriz[0][11]
    //tem que atualizar o valor do valorTeste na main, ai o repete vai dar 12 vezes
    return (repete);

}

void DesalocarMemoria (int **sudoku) {

    for (int i=0; i<D; i++) {
        printf("\nDesalocando %d", **(sudoku+i));
        free(sudoku[i]);
    }

    free (sudoku);

}