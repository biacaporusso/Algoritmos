#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#define MAX_LIN 11
#define MAX_COL 20

typedef struct celula {
    int x;
    int y;
    int veloc;
    struct celula *prox;
} Celula;

typedef struct lista {
    int tamanho;
    Celula *inicio;
} Lista;

// PROTOTIPOS 
char **LerJanela();
void EscreveJanela(char **janela);
void LerCordenadas (Lista *lista);
void InsereFim(Lista *lista, int x, int y, int veloc);
void EscreveCordenadas(Lista *lista);
void InserirGotas(char **janela, Lista *lista);
void cairGotas(char **janela, Lista *lista);
void ApagarJanela(char **janela);
void DesalocarMemoria (char **janela);

int main () {

    int i;

    char **janela = malloc((MAX_LIN+2) * sizeof(char*));
    for (i=0; i<MAX_LIN+2; i++) {
        janela[i] = malloc((MAX_COL+3) * sizeof(char));
    }
    janela = LerJanela();

    ///////////////////////////////////////////////////////////////////////////////////

    Lista *cordenadas;
    cordenadas = malloc(sizeof(Celula));
    cordenadas->inicio = NULL;
    cordenadas->tamanho = 0;
    LerCordenadas(cordenadas);

    // JANELA COM AS GOTAS
    InserirGotas(janela, cordenadas);
    EscreveJanela(janela);
    Sleep(850);
    system("cls");

    // MOVIMENTO DA GOTA
    while (cordenadas->tamanho) {
        cairGotas(janela, cordenadas);
        EscreveJanela(janela);
        Sleep(850);
        system("cls");
    }

    //DesalocarMemoria(janela);
  
}

char **LerJanela() {

    FILE *arq1;
    arq1 = fopen("janela.txt", "r");

    int i, j;

    if (arq1 == NULL) //teste para ver se o arquivo consegue ser aberto ou nao 
    {
        printf("\nArquivo nao pode ser aberto");
        return 0;
    } 

    char **janela = calloc((MAX_LIN+2), sizeof(char*));

    for  (i = 0; i < MAX_LIN+2; i++) {
        janela[i] = calloc((MAX_COL+3), sizeof(char));
    }

    for (i=0; i<MAX_LIN+2; i++) {
        for (j=0; j<MAX_COL+3; j++) 
            fscanf(arq1, "%c", &janela[i][j]);
    }
    fclose(arq1);

    return (janela);
}

void EscreveJanela(char **janela) {

    int i, j;

    for (i=0; i<MAX_LIN+2; i++) {
        for (j=0; j<MAX_COL+3; j++) {
            printf("%c", janela[i][j]); 
        }
    }
}

void LerCordenadas (Lista *lista) {

    FILE *arq2;
    arq2 = fopen("coordenadas.txt", "r");
   

    if (arq2 == NULL) //teste para ver se o arquivo consegue ser aberto ou nao 
    {
        printf("\nArquivo nao pode ser aberto");
        return;
    } 
    
    int x=1;
    int y=1;
    int veloc;

    while (x != 0 && y != 0) {
        fscanf(arq2, "%d", &x);
        fscanf(arq2, "%d", &y);
        if (x == 1) {
            veloc = 2;
        } else {
            veloc = 1;
        }
        if (x != 0 && y != 0 && x <= MAX_LIN && y <= MAX_COL) {
            InsereFim(lista, x, y, veloc);
        }
        
    }

}

void InsereFim(Lista *lista, int x, int y, int veloc) {

    if (lista->tamanho == 0) {
        Celula *novaCelula;

        novaCelula = malloc(sizeof(Celula));
        novaCelula->x = x;
        novaCelula->y = y;
        novaCelula->veloc = veloc;
        novaCelula->prox = NULL;
        lista->inicio = novaCelula;
        lista->tamanho++;
        return;
    }

    Celula *novaCelula;
    Celula *aux;

    novaCelula = malloc(sizeof(Celula));
    aux = lista->inicio;

    while (aux->prox != NULL) {
        aux = aux->prox;
    }
    novaCelula->prox = NULL;
    aux->prox = novaCelula;
    novaCelula->x = x;
    novaCelula->y = y;
    novaCelula->veloc = veloc;
    lista->tamanho++;
}

void EscreveCordenadas(Lista *lista) {
    Celula *aux;
    aux = lista->inicio;
    int i;

    printf("\nCoordenadas: \n");

    for (i=0; i< lista->tamanho; i++) {
        printf("%d,%d", aux->x, aux->y);
        aux = aux->prox;
        printf("\n");
    }
}

void InserirGotas(char **janela, Lista *lista) {


    int i, j;
    Celula *aux;
    aux = lista->inicio;
    while (aux != NULL) {
        i = aux->x;
        j = aux->y;
        janela[i][j] = 'G';
        aux = aux->prox;
    }
}

void cairGotas(char **janela, Lista *lista) {

    int i, j, k;
    i=0;
    j=0;

    Celula *aux;
    aux = lista->inicio;

    for (i=0; i<lista->tamanho; i++) {

        if (aux->veloc == 2) 
            aux->x += 2;
        else
            aux->x = aux->x+1;
        aux = aux->prox;


    }
    CompararCordenadas(lista);
    ApagarJanela(janela);
    InserirGotas(janela, lista);

}

void ApagarJanela(char **janela) {

    int i, j;
    for (i=1; i<=MAX_LIN; i++) {
        for (j=1; j<=MAX_COL; j++) {
            janela[i][j] = ' ';
        }
    }

}

void CompararCordenadas(Lista *lista) {

    Celula *aux1, *aux2;
    aux1 = lista->inicio; // serve pra procurar a celula que a gota começa na linha 1
    aux2 = lista->inicio; // serve pra comparar com a da linha 1, se elas tiverem na mesma coluna

    int i, j;

    while (aux1 != NULL) {
        aux2 = lista->inicio;
        while (aux2 != NULL) {
            if (aux2->y == aux1->y && aux2->x == aux1->x && aux1->veloc == 2) {
                aux2->veloc = 2;
            }
            aux2 = aux2->prox;
        }
        if (aux1->x > MAX_LIN) {
            RemoveCelula(lista, aux1);
        }
        aux1 = aux1->prox;
    }
}

void RemoveCelula(Lista *lista, Celula *celula) {

    Celula *aux;
    Celula *aux2;

    if (celula == lista->inicio) {

        aux = lista->inicio;
        lista->inicio = aux->prox;
        free(aux);
        lista->tamanho--;
        return;
    }
    aux = lista->inicio;

    while (aux->prox != celula) {
        aux = aux->prox;
    } 

    aux2 = aux->prox; // proximo da celula que eu quero remover
    aux->prox = aux2->prox;
    free(aux2);
    lista->tamanho--;

} 

void DesalocarMemoria (char **janela) {

      for (int i=0; i<MAX_COL; i++) {
        printf("\nDesalocando %d", **(janela+i));
        free(janela[i]);
    }

    free (janela);
}




