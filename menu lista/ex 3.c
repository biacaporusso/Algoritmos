#include <stdio.h>
#include <stdlib.h>
#include <windows.h>

typedef struct cel
{
    int vet[3];
    struct cel *prox;
} Celula;

typedef struct lista
{
    int tamanho;
    Celula *inicio;
} Lista;

//PROTÓTIPOS
void insere_elemento(Lista *lista, int conteudo);
void remove_elemento(Lista *lista, int elemento);
Lista *compacta_lista(Lista *lista);
void imprime_lista(Lista *lista);

Lista *CriaLista();


int main()
{

    Lista *lista = CriaLista();
    int opcao;
    int ele;
    //int celula;

    while (1) {
        imprime_lista(lista);
        printf("\n:::::::::::: MENU ::::::::::::\n");
        printf("\nSelecione a opcao que deseja: \n");
        printf("\n(1) - Inserir elemento");
        printf("\n(2) - Remover elemento");
        printf("\n(3) - Compactar lista\n");
        scanf("%d", &opcao);

        switch (opcao)
        {
            case 1: // OKAY
                printf("\nDigite o elemento: ");
                scanf("%d", &ele);
                insere_elemento(lista, ele);
            break;

            case 2: //SEEMS TO BE OKAY
                printf("\nQual elemento?: ");
                scanf("%d", &ele);
                remove_elemento(lista, ele);
            break;
            case 3:
                lista = compacta_lista(lista);
            break;
        }
        //sleep(1);
        system("cls");
    }
}


void insere_elemento(Lista *lista, int elemento)
{

    Celula *aux;
    int i, j;

    aux = lista->inicio;

    if (lista->tamanho == 0)
    {
        Celula *novaCelula = malloc(sizeof(Celula));
        novaCelula->prox = NULL;
        for (i = 0; i < 3; i++)
            (novaCelula->vet[i]) = -9999;
        lista->inicio = novaCelula;
        lista->tamanho++;
        novaCelula->vet[0] = elemento;
        return;
    } 
    
    for (i=0; i< lista->tamanho; i++) {
        for (j=0; j<3; j++) {
            if (aux->vet[j] == -9999) {
                aux->vet[j] = elemento;
                return;
            } 
        }
        aux = aux->prox; // aux ta apontando pra ultima celula
    }

    aux = lista->inicio;

    for (i=0; i<(lista->tamanho - 1); i++) 
        aux = aux->prox;

    Celula *novaCelula;
    novaCelula = malloc(sizeof(Celula));
    aux->prox = novaCelula; //novaCelula se tornou a ultima celula
    novaCelula->prox = NULL;
    novaCelula->vet[0] = elemento;
    novaCelula->vet[1] = -9999;
    novaCelula->vet[2] = -9999;
    lista->tamanho++;

}

void remove_elemento(Lista *lista, int n)
{

    Celula *aux;
    Celula *aux2;
    //Celula *aux2;
    int i, j, k;
    int cont = 1;

    aux = lista->inicio;
    aux2 = lista->inicio;

    if (lista->tamanho == 0) {
        ("\nElemento nao removido.");
        return;
    } 

    for (i=0; i< lista->tamanho; i++) {
        for (j=0; j<3; j++) {
            if (aux->vet[j] == n) {
                aux->vet[j] = -9999;
                printf("\nElemento removido.");
                if (aux->vet[0] == -9999 && aux->vet[1] == -9999 && aux->vet[2] == -9999) {
                    if (aux != lista->inicio) {
                        for (k=0; k < cont-1; k++) {
                            aux2 = aux2->prox;
                        }
                        aux2->prox = aux->prox;
                        free(aux);
                        lista->tamanho--;
                    } else {
                        aux2 = aux->prox;
                        lista->inicio = aux2;
                        free(aux);
                        lista->tamanho--;
                    }
                }
                return;
            } 
        }
        aux = aux->prox; 
        cont++;
    }

    /*//para percorrer a lista toda(ir de celula em celula)
    for (i = 0; i < lista->tamanho; i++)
    {
        //se dentro de uma celula nenhum elemento for igual a n, pula pra proxima celula
        if (aux->vet[0] != n && aux->vet[1] != n && aux->vet[2] != n)
        {
            aux = aux->prox;
            printf("\nElemento nao removido.");
        }
        else
        { //se tiver algum elemento = n
            if (aux->vet[0] == n)
            {
                aux->vet[0] = -9999;
                printf("\nElemento removido.");
                if (aux->vet[1] == -9999 && aux->vet[2] == -9999)
                { //se os outros elementos do vetor tbm estiverem vazios, elimina celula
                    free(aux);
                    lista->tamanho--;
                }
                return;
            }
            if (aux->vet[1] == n)
            {
                aux->vet[0] = -9999;
                printf("\nElemento removido.");
                if (aux->vet[0] == -9999 && aux->vet[2] == -9999)
                {
                    free(aux);
                    lista->tamanho--;
                }
                return;
            }
            if (aux->vet[2] == n)
            {
                aux->vet[0] = -9999;
                printf("\nElemento removido.");
                if (aux->vet[0] == -9999 && aux->vet[1] == -9999)
                {
                    free(aux);
                    lista->tamanho--;
                }
                return;
            }
        }
    } */



}

void imprime_lista(Lista *lista)
{
    Celula *aux;
    aux = lista->inicio;

    printf("\nLista: ");
    
    for (int j = 0; j < lista->tamanho; j++)
    {
        for (int i = 0; i < 3; i++)
        {
            if (aux->vet[i] == -9999)
                printf("_ ");
            else
                printf("%d ", aux->vet[i]);
        }
        aux = aux->prox;
    }
    printf(" \n ");
}

Lista *CriaLista()
{
    Lista *lista;
    lista = malloc(sizeof(Lista));
    lista->inicio = NULL;
    lista->tamanho = 0;

    return (lista);
}

Lista *compacta_lista(Lista *lista) {

    Lista *listacompact = CriaLista();
    Celula *aux;
    aux = lista->inicio;

    int i, j;

    for (i=0; i<lista->tamanho; i++) { // PERCORRENDO A LISTA ORIGINAL 
        for (j=0; j<3; j++) { // PERCORRENDO A CELULA
            if (aux->vet[j] != -9999) {
                insere_elemento(listacompact, aux->vet[j]);
            }
        }
        aux = aux->prox;
    }
    return(listacompact);
}