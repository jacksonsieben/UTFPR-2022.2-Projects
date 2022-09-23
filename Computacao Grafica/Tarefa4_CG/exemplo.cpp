#include <GL/gl.h> 					//biblioteca que permite todas as chamadas da API openGL
#include <GL/glut.h> 				//bibliotecao que permite a manipula��o de janelas
#include <Math.h>                   //conjunto de fun��es para opera��es matem�ticas

GLfloat escalaEX=1;                  // vari�vel para escala
GLfloat rotacaoEX=0;                 // vari�vel para rota��o
GLfloat movexEX = 0, moveyEX = 0;      // vari�veis de movimenta��o para x e y

void quadradoEX(){
    glBegin(GL_QUADS);             //lBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glColor3f(0,1,0);          //adiciona cor ao quadrado
        glVertex2f(-2,-2);         //adiciona um ponto na coordenada x, y que ser� usado para completar nosso quadrado
        glVertex2f(-2,2);          //adiciona um ponto na coordenada x, y que ser� usado para completar nosso quadrado
        glColor3f(1,0,0);          //adiciona cor ao quadrado
        glVertex2f(2,2);           //adiciona um ponto na coordenada x, y que ser� usado para completar nosso quadrado
        glVertex2f(2,-2);          //adiciona um ponto na coordenada x, y que ser� usado para completar nosso quadrado
    glEnd();
}


void desenhaObjetoEX(void){                 //fun��o de desenho
    glClear(GL_COLOR_BUFFER_BIT);         //buffer padr�o; limpa a tela toda vez que a fun��o � chamada
	glMatrixMode(GL_PROJECTION);          //proje��o dos pontos definidos no plano cartesiano
    glLoadIdentity(); 				      //carrega a proje��o
    gluOrtho2D(-50,50,-50,50);            //define o tamanho do plano cartesiano
	glMatrixMode(GL_MODELVIEW);           //proje��o do tipo modelo
    glLoadIdentity();                     //carrega essa identidade de proje��o de modelo

    glPushMatrix();                           //insere a matriz de transforma��o corrente na pilha
        glScalef(escalaEX, escalaEX, 0);          //chama a fu��o escala e passa como par�metro o valor da escala ( as mesmas para x e y)
        glRotatef(rotacaoEX, 0,0,1);            //chama a fu��o rota��o e passa como par�metro o �ngulo
        glTranslatef(movexEX, moveyEX,0);         //chama a fu��o de tranla��o e passa como par�metro o valor para transladar em x e y
        quadradoEX();                           // chama a fun��o que desenha um quadrado
    glPopMatrix();                            //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

	glFlush();                                //carrega os comandos OpenGL (envia para o hardware os comandos, permitindo assim que os drivers GL iniciem o render)
}

/*fun��o que atriui valores as nossas vari�veis de escala e rota��o (dependendo da tecla pressionada) */
void teclasEX(unsigned char tecla, GLint x, GLint y){
    switch(tecla){
        case '+': escalaEX++;         // adiciona 1 ao valor de escala
        break;
        case '-': escalaEX--;         // remove 1 ao valor de escala
        break;
        case '1': rotacaoEX-=10;      // rotaciona o objeto no sentido hor�rio (diminui o �ngulo em 10)
        break;
        case '2': rotacaoEX+=10;      // rotaciona o objeto no sentido anti-hor�rio (aumenta o �ngulo em 10)
        break;
    }
    glutPostRedisplay();            //redesenha a cena que est� na janela
}

/*fun��o que atriui valores as nossas vari�veis de movimenta��o x e y (dependendo da tecla pressionada) */
void setasDirecionaisEX(GLint tecla, GLint x, GLint y){
    switch(tecla){
        case GLUT_KEY_LEFT: movexEX--;               // move nosso objeto para a esquerda
        break;
        case GLUT_KEY_RIGHT: movexEX++;              // move nosso objeto para a direita
        break;
        case GLUT_KEY_UP: moveyEX++;                 // move nosso objeto para cima
        break;
        case GLUT_KEY_DOWN: moveyEX--;               // move nosso objeto para baixo
        break;
    }
    glutPostRedisplay();
}

int mainEX(void){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);                        // somente um buffer | sistema de cores RGB
    glutInitWindowSize(800,600);                                        // define o tamanho da janela
     glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,         // medidas usadas para posicionar a janela no meio
                           (glutGet(GLUT_SCREEN_HEIGHT)-540)/2);        // da tela - isso depende da resolu��o do monitor
	glutCreateWindow("Exemplo - Teclado");                              // permite a cria��o de uma janela
    glutDisplayFunc(desenhaObjetoEX);                                     // fun��o de callback - chama a fun��o Desenha
    glutKeyboardFunc(teclasEX);                                           // Chamada da fun��o teclado (cada pressionamento gera uma chamada do teclado)
    glutSpecialFunc(setasDirecionaisEX);                                  // Chamada da fun��o teclado especial (para quando as teclas direcionais s�o pressionadas)
    glClearColor(1,1,1,0);                                              // informa a cor de fundo da tela
    glutMainLoop();                                                     // loop infinito - escuta as informa��es do sistema at� encerrar a aplica��o
    return 0;                                                           // retorna zero
}

