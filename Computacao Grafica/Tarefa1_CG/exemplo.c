#include <GL/gl.h> 					//biblioteca que permite todas as chamadas da API openGL
#include <GL/glut.h> 				//biblioteca que permite a manipula��o de janelas
#include <Math.h>                   //conjunto de fun��es para opera��es matem�ticas

//Fun��o que adiciona linhas para montar um plano cartesiano
void cartesiano(){
    glLineWidth(1);               //adiciona espessura a linha desenhada
    glColor3f(0,0,0);             //adiciona cor �s linhas
    glBegin(GL_LINES);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(-50.0, 0.0);   //desenha uma linha no eixo -50x at� o ponto do eixo 50x
        glVertex2f(50, 0.0);
        glVertex2f(0.0, -50.0);   //desenha uma linha no eixo -50y at� o ponto do eixo 50y
        glVertex2f(0, 50);
    glEnd();
}

void pontos(){
    glPointSize(8);           //adiciona espessura do ponto
    glColor3f(1,0,0);         //adiciona cor aos pontos

    glBegin(GL_POINTS);       //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(5, 5);     //desenha um ponto na coordenada x, y
        glVertex2f(6, 9);     //desenha um ponto na coordenada x, y
        glVertex2f(12, 7);    //desenha um ponto na coordenada x, y
        glVertex2f(3, 2);     //desenha um ponto na coordenada x, y
        glVertex2f(14, 11);   //desenha um ponto na coordenada x, y
        glVertex2f(10, 8);    //desenha um ponto na coordenada x, y
    glEnd();
}

void linhas(){
    glLineWidth(5);           //adiciona espessura das ponto
    glColor3f(0.99, 0.06, 0.75);   //adiciona cor as linhas

    glBegin(GL_LINE_STRIP);       //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(30, 11);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(28, 13);        //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(32, 16);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(25, 13);        //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(28, 25);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(29, 20);       //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
        glVertex2f(35, 35);      //adiciona um ponto na coordenada x, y que ser� usado para completar o segmento de reta
    glEnd();
}

void poligono(){
    glColor3f(1, 1, 0);   //adiciona cor ao poligono
    glBegin(GL_POLYGON);       //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(5, 30);     //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso poligono
        glVertex2f(10, 25);     //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso poligono
        glVertex2f(10, 15);     //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso poligono
        glColor3f(1, 0, 0);   //adiciona cor ao tri�ngulo
        glVertex2f(5, 10);     //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso poligono
        glVertex2f(1, 15);     //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso poligono
        glVertex2f(1, 25);     //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso poligono
    glEnd();
}

void triangulos(){

    glBegin(GL_TRIANGLE_FAN);  //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glColor3f(0, 0, 1);    //adiciona cor ao tri�ngulo
        glVertex2f( 10, -10);  //primeiro ponto, comum para todos os tri�ngulos
        glVertex2f(25,-12);    //pontos para cria��o dos tri�ngulos
        glVertex2f(25,-15);    //pontos para cria��o dos tri�ngulos
        glColor3f(0, 1, 0);    //adiciona cor ao tri�ngulo
        glVertex2f(20,-17);    //pontos para cria��o dos tri�ngulos
        glVertex2f(15,-20);    //pontos para cria��o dos tri�ngulos



    glEnd();
}

void triangulo(){
    glColor3f(0.8, 0.5, 0.2);    //adiciona cor ao nosso tri�ngulo
    glBegin(GL_TRIANGLES);       //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(-20, 15);     //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso tri�ngulo
        glVertex2f(-30, 15);     //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso tri�ngulo
        glVertex2f(-25, 25);     //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso tri�ngulo
    glEnd();
}

void quadrado(){
    glColor3f(0.53, 0.81, 0.92);  //adiciona cor ao nosso quadrado
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(-20, 15);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-30, 15);      //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-30, 1);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
        glVertex2f(-20, 1);       //adiciona um ponto na coordenada x, y que ser� usado para fazer nosso quadrado
    glEnd();
}

void circulo(){
    glColor3f(1, 0.84, 0);                                        //adiciona cor ao nosso c�rculo
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        for(int i = 0; i < 350; i++){                             //estrutura de repeti��o necess�ria para gerar as posi��es dos pontos em x, y
            float theta = i*M_PI/180;                             // define um valor para a vari�vel theta
            glVertex2f (-10+5*cos(theta), 40+5*sin(theta));       //adiciona a posi��o onde ser�o gerados os pontos para fechar nosso pol�gono (c�rculo)
        }
    glEnd();
}

void rotacao(){
    glColor3f(1, 0.84, 0);   //adiciona cor
    glRotatef(20,0,0,1);     // Gira o objeto 20 graus ao redor do eixo z
    glBegin(GL_LINES);       //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(0, 0);    //adiciona um ponto na coordenada x, y que ser� usado para fazer a linha
        glVertex2f(-20, 0);  //adiciona um ponto na coordenada x, y que ser� usado para fazer a linha
    glEnd();
}

void escala(){
    glColor3f(0.75, 1, 0);   //adiciona cor
    glScalef(2, 2, 2);       // aumenta nossa linha em 2x
    glBegin(GL_LINES);       //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(0, 0);    //adiciona um ponto na coordenada x, y que ser� usado para fazer a linha
        glVertex2f(-20, 0);  //adiciona um ponto na coordenada x, y que ser� usado para fazer a linha
    glEnd();
}

void translacao(){
    glColor3f(0, 1, 0);        //adiciona cor
    glTranslatef(-25, -10, 0);    // translada nossa linha
    glBegin(GL_LINES);            //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glVertex2f(-3, -10);      //adiciona um ponto na coordenada x, y que ser� usado para fazer a linha
        glVertex2f(-15, -10);     //adiciona um ponto na coordenada x, y que ser� usado para fazer a linha
    glEnd();
}


//Fun��o de desenho
void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);  //buffer padr�o (limpa a tela toda vez que a fun��o � chamada)
	glMatrixMode(GL_PROJECTION);   //proje��o dos pontos definidos no plano cartesiano
    glLoadIdentity();              //carrega a proje��o
    gluOrtho2D(-60,60,-60,60);     // define o tamanho do plano cartesiano
	glMatrixMode(GL_MODELVIEW);    // proje��o do tipo modelo
    glLoadIdentity();              // carrega a identidade de proje��o de modelo

    glPushMatrix();       //insere a matriz de transforma��o corrente na pilha
        cartesiano();     //chama a fun��o que desenha o plano cartesiano
    glPopMatrix();        //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

    /*glPushMatrix();       //armazena as configura��es gerais (insere a matriz de corrente na pilha)
        pontos();         //chama a fun��o que desenha o pontos
    glPopMatrix();*/        //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

    glPushMatrix();       //insere a matriz de transforma��o corrente na pilha
        linhas();         //chama a fun��o que desenha o sequ�ncia de  linhas
    glPopMatrix();        //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

    /*glPushMatrix();       //insere a matriz de transforma��o corrente na pilha
        triangulos();     //chama a fun��o que desenha os tri�ngulos
    glPopMatrix();        //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

    glPushMatrix();      //insere a matriz de transforma��o corrente na pilha
        triangulo();     //chama a fun��o que desenha o tri�ngulo da casa
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

    glPushMatrix();      //insere a matriz de transforma��o corrente na pilha
        quadrado();      //chama a fun��o que desenha o quadrado da casa
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

    glPushMatrix();      //insere a matriz de transforma��o corrente na pilha
        circulo();       //chama a fun��o que desenha o sol
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

    glPushMatrix();      //insere a matriz de transforma��o corrente na pilha
        poligono();      //chama a fun��o que desenha um poligono
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

    glPushMatrix();      //insere a matriz de transforma��o corrente na pilha
        escala();        //chama a fun��o que mostra um exemplo de transforma��o escala
    glPopMatrix();*/       //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

    /*glPushMatrix();     //insere a matriz de transforma��o corrente na pilha
        translacao();   //chama a fun��o que mostra um exemplo de transforma��o tranla��o
    glPopMatrix();      //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

    /*glPushMatrix();     //insere a matriz de transforma��o corrente na pilha
        rotacao();      //chama a fun��o que mostra um exemplo de transforma��o rota��o
    glPopMatrix();*/      //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

	glFlush();          //carrega os comandos OpenGL (envia para o hardware os comandos, permitindo assim que os drivers GL iniciem o render)

}

/*int main(void){

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);                                                      //somente um buffer | sistema de cores RGB
    glutInitWindowSize(800,600);                                                                      //define o tamanho da janela
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,(glutGet(GLUT_SCREEN_HEIGHT)-540)/2);   //medidas usadas para posicionar a janela no meio da tela - isso depende da resolu��o do monitor
    glutCreateWindow("Introdu��o ao OpenGL");                                                         //permite a cria��o de uma janela
    glutDisplayFunc(desenhaObjetos);                                                                  //fun��o de callback - chama a fun��o desenhaObjetos
    glClearColor(1,1,1,0);                                                                            //informa a cor de fundo da tela (branco)
    glutMainLoop();                                                                                   //loop infinito - escuta as informa��es do sistema at� encerrar a aplica��o
    return 0;                                                                                         //retorna zero
}*/
