#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 500000

int buscaSequencial(int vetor[], int tam, int key){
    for (int t = 0; t < tam; t++){
        if (vetor[t] == key){
            return t;
        }
    }

    return -1;
}

double pesquisaSequencial(int vetor[], int tam, int key){
    clock_t inicio = clock();

    buscaSequencial(vetor, tam, key);

    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;
    
    return tempo;
}

int achaMax(int vetor[], int tam){
    int maior = 0;

    for (int i = 0; i < tam; i++){
        if(vetor[i]>maior){
            maior = vetor[i];
        }
    }
    return maior;
}

int main(){
    int *vetor = (int *) malloc(TAM * sizeof(int));

    for(int cont= TAM, i=0; cont > 0; cont--, i++){
        vetor[i] = i;
    }

    int max = achaMax(vetor, TAM);

    double tempo = pesquisaSequencial(vetor, TAM, max);

    printf("Tempo decorrido %lf", tempo);
    getch();
}