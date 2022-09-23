#include <stdio.h>
#include <windows.h>
 
//Função gotoxy
void gotoxy(int x, int y)
{
  COORD coord;
  coord.X = x;
  coord.Y = y;
  SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), coord);
}

    /*
        for (l=0; l<col; l++){
        for (c=0; c<lin; c++){
            gotoxy(10+l,1+c);
            switch (tabela [c][l]){
                case '*': printf(" ");   break;
                //case 'b': printf("%c", 3);   break;
                //case 'e': printf("%c", 42);  break;
                case '|': printf("%c", 179); break;
                default: printf("%c", tabela [c][l]);
            }
        }
    }
    */
 
main(){
  /*nt coluna = 5;
  int linha  = 3;
  system("cls");
   
  gotoxy(coluna, linha);
  printf("Terminal de");
   
  gotoxy(coluna, linha+1);
  printf("Informacao.\n");*/
  for (int i=0; i<256; i++){
    printf("%d %c\t", i, i);
  }
}