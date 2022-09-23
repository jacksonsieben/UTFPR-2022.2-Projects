#include <GL/gl.h> 					//biblioteca que permite todas as chamadas da API openGL
#include <GL/glut.h> 				//biblioteca que permite a manipulação de janelas
#include <Math.h>                   //conjunto de funções para operações matemáticas

//Função que adiciona linhas para montar um plano cartesiano
void cartesiano(){
    glLineWidth(1);               //adiciona espessura a linha desenhada
    glColor3f(0,0,0);             //adiciona cor às linhas
    glBegin(GL_LINES);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(-50.0, 0.0);   //desenha uma linha no eixo -50x até o ponto do eixo 50x
        glVertex2f(50, 0.0);
        glVertex2f(0.0, -50.0);   //desenha uma linha no eixo -50y até o ponto do eixo 50y
        glVertex2f(0, 50);
    glEnd();
}

void pontos(){
    glPointSize(8);           //adiciona espessura do ponto
    glColor3f(1,0,0);         //adiciona cor aos pontos

    glBegin(GL_POINTS);       //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
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

    glBegin(GL_LINE_STRIP);       //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(30, 11);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(28, 13);        //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(32, 16);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(25, 13);        //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(28, 25);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(29, 20);       //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
        glVertex2f(35, 35);      //adiciona um ponto na coordenada x, y que será usado para completar o segmento de reta
    glEnd();
}

void poligono(){
    glColor3f(1, 1, 0);   //adiciona cor ao poligono
    glBegin(GL_POLYGON);       //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(5, 30);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(10, 25);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(10, 15);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glColor3f(1, 0, 0);   //adiciona cor ao triângulo
        glVertex2f(5, 10);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(1, 15);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
        glVertex2f(1, 25);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso poligono
    glEnd();
}

void triangulos(){

    glBegin(GL_TRIANGLE_FAN);  //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glColor3f(0, 0, 1);    //adiciona cor ao triângulo
        glVertex2f( 10, -10);  //primeiro ponto, comum para todos os triângulos
        glVertex2f(25,-12);    //pontos para criação dos triângulos
        glVertex2f(25,-15);    //pontos para criação dos triângulos
        glColor3f(0, 1, 0);    //adiciona cor ao triângulo
        glVertex2f(20,-17);    //pontos para criação dos triângulos
        glVertex2f(15,-20);    //pontos para criação dos triângulos



    glEnd();
}

void triangulo(){
    glColor3f(0.8, 0.5, 0.2);    //adiciona cor ao nosso triângulo
    glBegin(GL_TRIANGLES);       //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(-20, 15);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso triângulo
        glVertex2f(-30, 15);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso triângulo
        glVertex2f(-25, 25);     //adiciona um ponto na coordenada x, y que será usado para fazer nosso triângulo
    glEnd();
}

void quadrado(){
    glColor3f(0.53, 0.81, 0.92);  //adiciona cor ao nosso quadrado
    glBegin(GL_QUADS);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(-20, 15);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-30, 15);      //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-30, 1);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-20, 1);       //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
}

void circulo(){
    glColor3f(1, 0.84, 0);                                        //adiciona cor ao nosso círculo
    glBegin(GL_POLYGON); //ou GL_LINE_LOOP                        //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        for(int i = 0; i < 350; i++){                             //estrutura de repetição necessária para gerar as posições dos pontos em x, y
            float theta = i*M_PI/180;                             // define um valor para a variável theta
            glVertex2f (-10+5*cos(theta), 40+5*sin(theta));       //adiciona a posição onde serão gerados os pontos para fechar nosso polígono (círculo)
        }
    glEnd();
}

void rotacao(){
    glColor3f(1, 0.84, 0);   //adiciona cor
    glRotatef(20,0,0,1);     // Gira o objeto 20 graus ao redor do eixo z
    glBegin(GL_LINES);       //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(0, 0);    //adiciona um ponto na coordenada x, y que será usado para fazer a linha
        glVertex2f(-20, 0);  //adiciona um ponto na coordenada x, y que será usado para fazer a linha
    glEnd();
}

void escala(){
    glColor3f(0.75, 1, 0);   //adiciona cor
    glScalef(2, 2, 2);       // aumenta nossa linha em 2x
    glBegin(GL_LINES);       //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(0, 0);    //adiciona um ponto na coordenada x, y que será usado para fazer a linha
        glVertex2f(-20, 0);  //adiciona um ponto na coordenada x, y que será usado para fazer a linha
    glEnd();
}

void translacao(){
    glColor3f(0, 1, 0);        //adiciona cor
    glTranslatef(-25, -10, 0);    // translada nossa linha
    glBegin(GL_LINES);            //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(-3, -10);      //adiciona um ponto na coordenada x, y que será usado para fazer a linha
        glVertex2f(-15, -10);     //adiciona um ponto na coordenada x, y que será usado para fazer a linha
    glEnd();
}


//Função de desenho
void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);  //buffer padrão (limpa a tela toda vez que a função é chamada)
	glMatrixMode(GL_PROJECTION);   //projeção dos pontos definidos no plano cartesiano
    glLoadIdentity();              //carrega a projeção
    gluOrtho2D(-60,60,-60,60);     // define o tamanho do plano cartesiano
	glMatrixMode(GL_MODELVIEW);    // projeção do tipo modelo
    glLoadIdentity();              // carrega a identidade de projeção de modelo

    glPushMatrix();       //insere a matriz de transformação corrente na pilha
        cartesiano();     //chama a função que desenha o plano cartesiano
    glPopMatrix();        //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    /*glPushMatrix();       //armazena as configurações gerais (insere a matriz de corrente na pilha)
        pontos();         //chama a função que desenha o pontos
    glPopMatrix();*/        //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    glPushMatrix();       //insere a matriz de transformação corrente na pilha
        linhas();         //chama a função que desenha o sequência de  linhas
    glPopMatrix();        //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    /*glPushMatrix();       //insere a matriz de transformação corrente na pilha
        triangulos();     //chama a função que desenha os triângulos
    glPopMatrix();        //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    glPushMatrix();      //insere a matriz de transformação corrente na pilha
        triangulo();     //chama a função que desenha o triângulo da casa
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    glPushMatrix();      //insere a matriz de transformação corrente na pilha
        quadrado();      //chama a função que desenha o quadrado da casa
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    glPushMatrix();      //insere a matriz de transformação corrente na pilha
        circulo();       //chama a função que desenha o sol
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    glPushMatrix();      //insere a matriz de transformação corrente na pilha
        poligono();      //chama a função que desenha um poligono
    glPopMatrix();       //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    glPushMatrix();      //insere a matriz de transformação corrente na pilha
        escala();        //chama a função que mostra um exemplo de transformação escala
    glPopMatrix();*/       //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    /*glPushMatrix();     //insere a matriz de transformação corrente na pilha
        translacao();   //chama a função que mostra um exemplo de transformação tranlação
    glPopMatrix();      //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

    /*glPushMatrix();     //insere a matriz de transformação corrente na pilha
        rotacao();      //chama a função que mostra um exemplo de transformação rotação
    glPopMatrix();*/      //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

	glFlush();          //carrega os comandos OpenGL (envia para o hardware os comandos, permitindo assim que os drivers GL iniciem o render)

}

/*int main(void){

    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);                                                      //somente um buffer | sistema de cores RGB
    glutInitWindowSize(800,600);                                                                      //define o tamanho da janela
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,(glutGet(GLUT_SCREEN_HEIGHT)-540)/2);   //medidas usadas para posicionar a janela no meio da tela - isso depende da resolução do monitor
    glutCreateWindow("Introdução ao OpenGL");                                                         //permite a criação de uma janela
    glutDisplayFunc(desenhaObjetos);                                                                  //função de callback - chama a função desenhaObjetos
    glClearColor(1,1,1,0);                                                                            //informa a cor de fundo da tela (branco)
    glutMainLoop();                                                                                   //loop infinito - escuta as informações do sistema até encerrar a aplicação
    return 0;                                                                                         //retorna zero
}*/
