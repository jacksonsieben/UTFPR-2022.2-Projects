#include <stdio.h>
#include <windows.h>

#define SCREEN_WIDTH 600
#define SCREEN_HEIGHT 600

void gotoxy(int x , int y)
{
/******************************* gotoxy ***************************************
    takes cursor to x and y coordinates
    
    PRE : x and y coordinates.  y will be minus from current y coordinate of 
			the cursor.
    POST: returns nothing.  moves cursor to x and y coordinates  
*******************************************************************************/
    HANDLE hConsoleOutput;
    COORD dwCursorPosition;
    CONSOLE_SCREEN_BUFFER_INFO  ConsoleInfo;
    
    _flushall();
    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOutput, &ConsoleInfo);
    dwCursorPosition.X = x;
    dwCursorPosition.Y = ConsoleInfo.dwCursorPosition.Y - y;  
    SetConsoleCursorPosition (hConsoleOutput, dwCursorPosition);
} /* gotoxy */ 

void showCursor(int bShow){
/******************************* showCursor ***********************************
    shows/hides the curser by TRUE/FALSE.
       
    PRE : bShow - TRUE/FALSE
    POST: Returns nothing.
*******************************************************************************/ 
    int nSize = 25; 	//The nSize = the cursor height, optional parameter, by default 25. Size range: 1 - 100
	CONSOLE_CURSOR_INFO CurInfo;
	
	//Define the cursor size
	if (nSize <= 0) nSize = 1;
	if (nSize > 100) nSize = 100;
	CurInfo.dwSize = nSize;
	CurInfo.bVisible = bShow;           //Define the visibility of the cursor
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE),&CurInfo);  //Set parameters
} /* showCursor */

void setScreenSize(int x, int y){
/**************** setScreenSize *******************************
    changes screen to full.
       
    PRE : x  - left/right width.
          y  - up/down length.
    POST: Returns nothing.
***************************************************************/ 
    HANDLE hConsoleOutput;
    COORD coord;
    CONSOLE_SCREEN_BUFFER_INFO  ConsoleInfo;
    HWND console = GetConsoleWindow();

    hConsoleOutput = GetStdHandle(STD_OUTPUT_HANDLE);
    GetConsoleScreenBufferInfo(hConsoleOutput, &ConsoleInfo);
    coord.X = x;
    coord.Y = y;
    SetConsoleScreenBufferSize(hConsoleOutput, coord);

    MoveWindow(console, 20, 20, SCREEN_WIDTH, SCREEN_HEIGHT, TRUE);
} /* setScreenSize */

int main(){
    //COORD SIZE_COORD = { 30, 50 };
	//setConsoleScreenBufferSize(GetStdHandle(STD_OUTPUT_HANDLE),SIZE_COORD);
    setScreenSize(900,900);
    showCursor(0);
    for(int i=0; i<80; i++){
        printf("|",i);
    }
}