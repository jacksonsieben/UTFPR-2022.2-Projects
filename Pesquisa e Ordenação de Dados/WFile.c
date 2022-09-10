/*
? Nesse programa é criado um arquivo de numeros ordenados do tamanho escolhido
? ele sugere utilizar 500k 750k ou 1MM
*/
#define BB "BubbleSort"

#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <conio.h>

int randomInteger (int low, int high){
    double d;
    d = (double) rand () / ((double) RAND_MAX + 1);
    int k = d * (high - low + 1);
    return low + k;
}

void ordenado(char nome[], int tam){
    FILE *ordenado;
    char nomeArquivo[255];

    sprintf(nomeArquivo, "%sOrdenado%05d.txt", nome, tam);
    ordenado = fopen(nomeArquivo, "w");
    for(int x=1; x<tam; x++){
        fprintf(ordenado, "%d\n", x);
    }
    fclose(ordenado);
}

void invertido(char nome[], int tam){
    FILE *invertido;
    char nomeArquivo[255];

    sprintf(nomeArquivo, "%sInvertido%05d.txt", nome, tam);
    invertido = fopen(nomeArquivo, "w");
    for(int x=tam; x>=1; x--){
        fprintf(invertido, "%d\n", x);
    }
    fclose(invertido);
}

void aleatorio(char nome[], int tam){
    FILE *aleatorio;
    char nomeArquivo[255];

    srand(time(NULL));
    sprintf(nomeArquivo, "%sAleatorio%05d.txt", nome, tam);
    aleatorio = fopen(nomeArquivo, "w");
    for(int i=0; i<tam; i++){
        fprintf(aleatorio, "%d\n", randomInteger(0,tam)); //? gera numeros aleatorios de forma correta
    }
    fclose(aleatorio);
}

void copiarArquivo(char nome[], int tam){
    FILE *original, *novo;
    char nomeOriginal[255], nomeNovo[255], c;

    sprintf(nomeOriginal, "Aleatorio%05d.txt", tam);
    sprintf(nomeNovo, "%sAleatorio%05d.txt",nome, tam);

    original = fopen(nomeOriginal, "r");
    novo = fopen(nomeNovo, "w");

    c = fgetc(original);
    while (c != EOF){
        fputc(c, novo);
        c = fgetc(original);
    }

    fclose(novo);
    fclose(original);
}

int main(void){
    int tam = 500000;
    char nome[] = BB;
    
    //ordenado(nome, tam);
    //invertido(tam);
    aleatorio("", tam);
    copiarArquivo(BB, tam);

    printf("Arquivo gerado com 500 mil numeros aleatorios\n\n");
    return 0;
}
