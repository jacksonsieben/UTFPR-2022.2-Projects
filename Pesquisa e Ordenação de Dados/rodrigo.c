#include <stdio.h>
#include <stdlib.h>
#include <locale.h>
#include <conio.h>

/**
                                                    Entrega 4 
    Não é possível adicionar mais carros que a capacidade e também não é possível abastecer se não houver carro na fila 
    (faça isso por meio do incremento/decremento de uma variável do tipo inteira). Lembre-se de contar quantos carros foram atendidos também. 
    Nesse momento você já deve se preocupar com o controle de quanto combustível está sendo vendido e quanto restará nos tanques.

    * * para fazer a entrega 4 devemos utilizar o while dentro de menuEscolha pra poder ter acesso aos dados sem a struct
    *TODO Entrega 4
    * ? struct e considerado variavel global?

    *TODO Entrega 5
    *? oque pode ser entregue? ele considera as funcoes feitas ate agora como essa entrega?

    *TODO Entrega 6
    *? quais informacoes do carro devem conter em TCarro
*/

struct TPosto{
    int maxFila;
    float valorGasolina;
    float qtdGasTanque;
    int filaCarro;
    float totalVenda;
    int carrosAtendidos;
};

struct TCarro{
    int atendido;
    float litroAbastecimento;
};

typedef struct TPosto Posto;

typedef struct TCarro Carro;

Posto criarPosto(){
    Posto p;

    p.maxFila = 40;
    p.valorGasolina = 0;
    p.qtdGasTanque = 500;
    p.filaCarro = 0;
    p.totalVenda = 0;
    p.carrosAtendidos = 0;

    return p;
}

float abastecimento(float valorGasolina){
    int quantidade;

    printf("Informe a quantidade de litros de combustivel: ");
    scanf("%d", &quantidade);

    return valorGasolina * quantidade;
}

char subMenu(Posto posto){

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
            printf("Quantidade de litros vendida\n\n");
            printf("Foram vendidos %.2f litros", (posto.qtdGasTanque - 500));
            break;
        case 'b':
            printf("Valor total arrecadado com as vendas\n\n");
            printf("Valor total: R$%.2f", posto.totalVenda);
            break;
        case 'c':
            printf("Quantidade de carros atendidos\n\n");
            printf("Carros atendidos: %d", posto.carrosAtendidos);
            break;
        case 'd':
            printf("Quantidade de combustível restante no tanque\n\n");
            printf("Resta %.2f litros no tanque", posto.qtdGasTanque);
            break;
        case 'e':
            printf("Voce gerou arquivos para impressão\n\n");
            //Implementar depois
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

Posto menuEscolha(Posto posto){
    int opcoes;

    while(opcoes!=5){
        system("cls");

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
                posto.filaCarro++;
                if(posto.filaCarro > posto.maxFila){
                    system("cls");
                    printf("O valor nao pode ser maior que %d\n", posto.maxFila);
                }
                break;
            case '2':
                printf("Voce selecionou Abastecimento\n");
                if(posto.filaCarro>0){
                    float valorTotal = abastecimento(posto.valorGasolina);
                    printf("\n\nValor total R$%.2f", valorTotal);
                    posto.filaCarro--;
                    posto.carrosAtendidos++;
                    posto.totalVenda += valorTotal;
                    posto.qtdGasTanque -= (valorTotal/posto.valorGasolina);
                }else{
                    printf("\n\nNao ha carros na fila para ser abastecido");
                }
                break;
            case '3':
                printf("Voce selecionou Carros exibidos na fila\n\n");
                printf("Ha %d carros na fila", posto.filaCarro);
                break;
            case '4':
                printf("Voce Entrou em Relatorios");
                while(subMenu(posto)!='f');
                break;
            case '5':
                printf("Voce Encerrou o Programa!");
                break;
            default:
                printf("ERRO");
                break;
        } 

        printf("\n\nAperte qualquer tecla para voltar ao menu!");
        getch();
        system("cls");

    }
    return posto;
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

    printf("Digite o Valor da Gasolina: ");
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
    Posto posto = criarPosto();

    setlocale(LC_ALL, "Portuguese");
    menuInicial();
    posto.valorGasolina = lerValorGasolina();
    posto.filaCarro = lerFilaCarro(posto.maxFila);
    posto = menuEscolha(posto);
}