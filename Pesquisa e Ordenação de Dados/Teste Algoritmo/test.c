#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
int main(){
    //menu
    int opcao;
    inicio:
    system("cls");
    system("color 0F");
    printf("1 - JOGAR \n2 - RANKINGS \n3 - CREDITOS \n4 - SAIR\n");
    opcao = getch();
    switch (opcao) {
    case '1':
        system("cls");
        printf("GAME\n");
        break;
    case '2':
        system("cls");
        printf("Ranking\n");
        break;
    case '3':
        system("cls");
        printf("Creditos\n");
        break;
    case '4':
        system("cls");
        printf("voce pediu para sair, prencione qualquer tecla para continuar\n");
        break;
    default:
        printf("voce deve escolher uma opcao valida\n");
        printf("Precione qualquer tecla para voltar ao menu\n");
        system("pause");
        goto inicio;
    }
}