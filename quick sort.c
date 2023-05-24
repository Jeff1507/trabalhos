#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#define TAM 5

void troca(int vet[], int i, int j);
int particao(int vet[], int inicio, int fim);
void quickSort(int vet[], int inicio, int fim);
int particiona_random(int vet[], int inicio, int fim);
void print(int vet[], int tam);

int main()
{
    int vetor[TAM]={ 4, 7, 2, 6, 5};
    srand(time(NULL));

    printf("Vetor original:\n");
    print(vetor, TAM);

    quickSort(vetor, 0, TAM-1);// chamada do quicksort
    printf("\n");

    printf("Vetor ordenado (crescente):\n");
    print(vetor, TAM);

    return 0;
}
void troca(int vet[], int i, int j)// função que realiza a troca entre dois elementos
{
    int aux;
    aux=vet[i];
    vet[i]=vet[j];
    vet[j]=aux;
}
int particao(int vet[], int inicio, int fim)// particiona e retorna o índice do pivô
{
    int pivo, pivoIndice, i;

    pivo=vet[fim];// o pivô é sempre o último elemento
    pivoIndice=inicio;

    for(i=inicio; i<fim; i++)// verifica se o elemento é <= ao pivô
    {
        if(vet[i]<=pivo)
        {
            troca(vet, i, pivoIndice);// realiza a troca
            pivoIndice++;// incrementa o pivo_indice
        }
    }
    troca(vet, pivoIndice, fim);// troca o pivô

    return pivoIndice;// retorna o índice do pivô
}
int particiona_random(int vet[], int inicio, int fim)// escolhe um pivô aleatório para evitar o pior caso do quicksort
{
    int pivo_indice=(rand()%(fim - inicio + 1))+inicio;// seleciona um número entre fim (inclusive) e inicio (inclusive)

    troca(vet, pivo_indice, fim);// faz a troca para colocar o pivô no fim

    return particao(vet, inicio, fim);// chama a particao
}
void quickSort(int vet[], int inicio, int fim)
{
    if(inicio<fim)
    {
        int pivo_indice=particiona_random(vet, inicio, fim);// função particionar retorna o índice do pivô
        // chamadas recursivas quick_sort
        quickSort(vet, inicio, pivo_indice-1);
        quickSort(vet, pivo_indice + 1, fim);
    }
}
void print(int vet[], int tam)//mostra o vetor
{
    for(int i=0; i<tam; i++)
    {
        printf("[%d] ", vet[i]);
    }
    printf("\n");
}
