#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define TAM 500000

typedef double (algOrdenacao(int v[], int tam));

int buscaBinaria(int vetor[], int ini, int fim, int key){

    int mei = (ini + fim) / 2;
    if((ini == fim) && !(key == vetor[mei])){
        return -1;
    }else{
        if(key == vetor[mei]){
            return mei;
        }
        else{
            if(key > vetor[mei]){
                return buscaBinaria(vetor, mei+1, fim, key);
            }else{
                return buscaBinaria(vetor, ini, mei-1, key);
            }
        }
    }
}

double pesquisaBinaria(int vetor[], int tam, int key){
    clock_t inicio = clock();

    buscaBinaria(vetor, 0, tam, key);

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

    printf("Valor Max %d\n", max);

    double tempo = pesquisaBinaria(vetor, TAM, max);

    printf("tempo %lf", tempo);
    getch();
}