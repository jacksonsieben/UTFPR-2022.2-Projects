#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    int random;

    srand(time(NULL));      // srand serve para que toda vez que seja executado o numero mude e possa ser diferente do anterior, teste sem para entender
    random = rand() % 100;  // nessa linha esta sendo gerado um numero de 0 ate 100 por conta do %
    
    printf("Numero gerado %d", random);
}