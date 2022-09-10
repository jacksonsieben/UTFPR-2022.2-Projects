#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

/*
                                                    Entrega 4 
    Não é possível adicionar mais carros que a capacidade e também não é possível abastecer se não houver carro na fila 
    (faça isso por meio do incremento/decremento de uma variável do tipo inteira). Lembre-se de contar quantos carros foram atendidos também. 
    Nesse momento você já deve se preocupar com o controle de quanto combustível está sendo vendido e quanto restará nos tanques.
*/



float abastecimento(float valorGasolina){
    int quantidade;

    printf("Informe a quantidade de litros de combustivel: ");
    scanf("%d", &quantidade);

    return valorGasolina * quantidade;
}

char subMenu(){

    system("cls");    
    char opcoes;

    printf("\tRelatorio");
    printf("\na - Quantidade de litros vendida;");
    printf("\nb - Valor total arrecadado com as vendas;");
    printf("\nc - Quantidade de carros atendidos;");
    printf("\nd - Quantidade de combustível restante no tanque;");
    printf("\ne - Gerar arquivo para impressão (com todas as informações de A, B, C e D);");
    printf("\nf - Voltar ao menu anterior.");

    opcoes=getch();
    system("cls");

    switch(opcoes){
        case 'a':
            printf("Quantidade de litros vendida");
            break;
        case 'b':
            printf("Valor total arrecadado com as vendas");
            break;
        case 'c':
            printf("Quantidade de carros atendidos");
            break;
        case 'd':
            printf("Quantidade de combustível restante no tanque");
            break;
        case 'e':
            printf("Voce gerou arquivos para impressão");
            break;
        case 'f':
            return opcoes;
            break;
        default:
            printf("ERRO");
            break;

    }
    printf("\n\nAperte qualquer tecla para voltar ao menu!");
    getch();
    

    return opcoes;
}


int menuEscolha(int maxFila, int filaCarro, float valorGasolina){
    system("cls");
    int opcoes;

    printf("1- Adicionar um carro na fila\n");
    printf("2- Abastecimento\n");
    printf("3- Exibir carros na fila de espera\n");
    printf("4- Relatórios\n");
    printf("5- Encerrar\n");

    opcoes=getch();
    system("cls");

    switch(opcoes){
        case '1':
            printf("Carro adicionado");
            filaCarro++;
            if(filaCarro > maxFila){
                system("cls");
                printf("O valor nao pode ser maior que %d\n", maxFila);
            }
            break;
        case '2':
            printf("Voce selecionou Abastecimento\n");
            printf("\n\nValor total R$%.2f", abastecimento(valorGasolina));
            break;
        case '3':
            printf("Voce selecionou Carros exibidos na fila");
            break;
        case '4':
            printf("Voce Entrou em Relatorios");
            while(subMenu()!='f');
            return 0;
            break;
        case '5':
            printf("Voce Encerrou o Programa!");
            return 5;
            break;
        default:
            printf("ERRO");
            break;
    } 

    printf("\n\nAperte qualquer tecla para voltar ao menu!");
    getch();
    system("cls");

    return opcoes;
}

void menuInicial(){
    printf("Olá, meu nome é Rodrigo, Graduacao em Ciencia da Computacao na UTFPR\n");
    printf("Este é um projeto de sistema de gerenciamento de posto de combustiveis para informatizar algumas atividades");
    printf("\n");
    printf("Pressionar o botão Enter para continuar");
    getch();
    system("cls");
}

float lerValorGasolina(){
    float valorGasolina;

    printf("\nDigite o Valor da Gasolina: ");
    scanf("%f",&valorGasolina);

    return valorGasolina;
}

int lerFilaCarro(int maxFila){
    int filaCarro;
    while(filaCarro>maxFila){
        printf("Digite o tamanho da fila de Carros: ");
        scanf("%d",&filaCarro);
        if(filaCarro > maxFila){
            system("cls");
            printf("O valor nao pode ser maior que %d\n", maxFila);
        }
    }
    return filaCarro;
}

int main(){
    struct posto{
        int maxFila;
        float valorGasolina;
        int quantidadeGasolina;
    };
    
    int maxFila = 40, filaCarro;
    float valorGasolina;

    setlocale(LC_ALL, "Portuguese");
    menuInicial();
    valorGasolina = lerValorGasolina();
    filaCarro = lerFilaCarro(maxFila);
    while(menuEscolha(maxFila, filaCarro, valorGasolina)!=5);
}
//? rodrigo program
/*#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>
int submenu(){
    char opcoes;
    do{
    printf("\na - Quantidade de litros vendida;");
    printf("\nb - Valor total arrecadado com as vendas;");
    printf("\nc - Quantidade de carros atendidos;");
    printf("\nd - Quantidade de combustível restante no tanque;");
    printf("\ne - Gerar arquivo para impressão (com todas as informações de A, B, C e D);");
    printf("\nf - voltar ao menu anterior.");

    opcoes=getch();
    system("cls");

    switch(opcoes){
        case 'a':
            printf("Quantidade de litros vendida");
            break;
        case 'b':
            printf("Valor total arrecadado com as vendas");
            break;
        case 'c':
            printf("Quantidade de carros atendidos");
            break;
        case 'd':
            printf("Quantidade de combustível restante no tanque");
            break;
        case 'e':
            printf("Voce gerou arquivos para impressão");
            break;
        case 'f':
            return 1; //o 1 significa que tem que voltar ao menu anterior
            break;
        default:
            printf("ERRO");
            break;

    }
    return 0;
    }while (opcoes!='f');
}

void menuEscolha(){
    system("cls");
    int opcoes, retorno;
    do{
        printf("1- Adicionar um carro na fila\n");
        printf("2- Abastecimento\n");
        printf("3- Exibir carros na fila de espera\n");
        printf("4- Relatórios\n");
        printf("5- Encerrar\n");
        opcoes=getch();
        system("cls");
        switch(opcoes){
            case '1':
                printf("Carro adicionado");
                break;
            case '2':
                printf("Voce selecionou Abastecimento");
                break;
            case '3':
                printf("Voce selecionou Carros exibidos na fila");
                break;
                case '4':
                printf("Voce Entrou em Relatorios");
                retorno = submenu();
                if(retorno==1){
                    menuEscolha();
                }
                break;
            case '5':

                printf("Voce Encerrou o Programa!");
                return 0;
                break;
            default:
                printf("ERRO");
                break;
        }
        printf("\nPressionar qualquer tecla");
        getch();
        system("cls");
    
    }while(opcoes!=5);

}

void menuInicial(){
    printf("Olá, meu nome é Rodrigo, Graduacao em Ciencia da Computacao na UTFPR\n");
    printf("Este é um projeto de sistema de gerenciamento de posto de combustiveis para informatizar algumas atividades");
    printf("\n");
    printf("Pressionar o botão Enter para continuar");
    getch();
    system("cls");
}

void lerValorGasolina(){
    float valorGasolina;

    printf("\nDigite o Valor da Gasolina: ");
    scanf("%f",&valorGasolina);
}

void lerFilaCarro(){
    int filaCarro;
    printf("Digite o tamanho da fila de Carros: ");
    scanf("%d",&filaCarro);
}

int main(){
    setlocale(LC_ALL, "Portuguese");
    menuInicial();
    lerValorGasolina();
    lerFilaCarro();
    menuEscolha();
}*/