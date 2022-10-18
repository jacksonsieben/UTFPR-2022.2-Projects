#include <stdio.h>
#include <string.h>

struct TPessoa{
    int idade;
    float altura;
    char *nome;
};

typedef struct TPessoa Pessoa;

int main(){
    Pessoa p;

    p.nome = "Rodrigo";

    printf("%s", p.nome);
}