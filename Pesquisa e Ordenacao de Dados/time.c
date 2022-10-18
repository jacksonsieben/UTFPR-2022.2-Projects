#include <stdio.h>
#include <conio.h>
#include <time.h>

int main(){
    clock_t inicio = clock();       //aqui o tempo comeca a ser contado
    
    for (int i = 0; i < 1000000000; i++);       // faca qualquer coisa que o tempo continuara contando

    double tempo = (double) (clock() - inicio) / CLOCKS_PER_SEC;    //aqui o tempo e calculado em segundos e guardado dentro de tempo
    
    printf("%.3f segundos", tempo);
}