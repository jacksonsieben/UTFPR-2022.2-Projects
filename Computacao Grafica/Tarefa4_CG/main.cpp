#include <GL/gl.h>
#include <GL/glut.h>
#include <Math.h>

GLfloat escala=1;
GLfloat rotacao=0;
GLfloat movex = 0, movey = -29;

void quadrado(){
    glColor3f(1,0,0);
    glBegin(GL_QUADS);
        glVertex2f(1,-1);
        glVertex2f(1,1);
        glVertex2f(3,1);
        glVertex2f(3,-1);
    glEnd();
}

void estrada(){
    glColor3f(0.1,0.1,0.1);
    glBegin(GL_QUADS);
        glVertex2f(-35,35);
        glVertex2f(35,35);
        glVertex2f(35,-35);
        glVertex2f(-35,-35);
    glEnd();
}

void circuito(){
    glColor3f(0.1,0.1,0.1);
    glBegin(GL_POLYGON);

        glVertex2f(-15,35);
        glVertex2f(35,35);
        glVertex2f(35,0);
        glVertex2f(17,0);
        glVertex2f(17,-35);
        glVertex2f(-35,-35);
        glVertex2f(-35,1);
        glVertex2f(-20,1);
    glEnd();
}

void estradaDentro(int x, int y){
    glColor3f(0.33, 0.45, 0.18);
    glBegin(GL_POLYGON);
        glVertex2f(-35+x,35-y);
        glVertex2f(35-x,35-y);
        glVertex2f(35-x,-35+y);
        glVertex2f(-35+x,-35+y);

    glEnd();
}

void pontosEstrada(){
    glPointSize(3);
    glColor3f(1,0,0);
    glBegin(GL_POINTS);

        glVertex2f(-15,35);
        glVertex2f(35,35);
        glVertex2f(35,0);
        glVertex2f(17,0);
        glVertex2f(17,-35);
        glVertex2f(-35,-35);
        glVertex2f(-35,1);
        glVertex2f(-20,1);

        glColor3f(0,0,1);
    glEnd();
}

void linhaTracejada(){
    int x=4, y=4;
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(2,0x00FF);
    glLineWidth(3);
    glColor3f(1,1,0);
    glBegin(GL_LINES);
        glVertex2f(-35+x,35-y);
        glVertex2f(35-x,35-y);

        glVertex2f(35-x,35-y);
        glVertex2f(35-x,-35+y);

        glVertex2f(35-x,-35+y);
        glVertex2f(-35+x,-35+y);

        glVertex2f(-35+x,-35+y);
        glVertex2f(-35+x,35-y);
    glEnd();
}

void linhaChegada(){
    glEnable(GL_LINE_STIPPLE);
    glLineStipple(4,0xAAAA);
    glLineWidth(20);
    glColor3f(1,1,1);
    glBegin(GL_LINES);
        glVertex2f(0,-27);
        glVertex2f(0,-35);
    glEnd();
}

void carrinho(){
    glColor3f(1,0,0);
    glBegin(GL_POLYGON);
        glVertex2f(0,0);
        glVertex2f(2,0);
        glVertex2f(2.5,3);
        glVertex2f(2.5, 5);
        glVertex2f(2,8);
        glVertex2f(0,8);
        glVertex2f(-0.5,5);
        glVertex2f(-0.5,3);
    glEnd();
}

void circulo(int x, int y, int tam){
    for(int i = 0; i < 360; i++){
            float theta = i*M_PI/180;
            glVertex2f (x+tam*cos(theta), y+tam*sin(theta));
    }
}
void desenhaArvore(){
    glColor3f(0.13, 0.55, 0.13);
    glBegin(GL_POLYGON);
        circulo(-3,41,2);
        circulo(-1.5,43.5,2);
        circulo(1,41,2);
        circulo(-1.5,39,2);
    glEnd();
    glBegin(GL_POLYGON);
        circulo(-43,1,2);
        circulo(-41.5,3.5,2);
        circulo(-39,1,2);
        circulo(-41.5,-1,2);
    glEnd();
    glBegin(GL_POLYGON);
        circulo(-3,-41,2);
        circulo(-1.5,-43.5,2);
        circulo(1,-41,2);
        circulo(-1.5,-39,2);
    glEnd();
    glBegin(GL_POLYGON);
        circulo(41.5,3.5,2);
        circulo(39,1,2);
        circulo(41.5,-1,2);
        circulo(43,1,2);
    glEnd();
}

void casa(int x, int y){
    glColor3f(0.43, 0.21, 0.1);
    glBegin(GL_POLYGON);
        glVertex2f(0+x,0+y);
        glVertex2f(10+x,0+y);
        glVertex2f(11+x,5+y);
        glVertex2f(10+x,10+y);
        glVertex2f(0+x,10+y);
        glVertex2f(-1+x,5+y);
    glEnd();
    glColor3f(0.38, 0.18, 0.1);
    glBegin(GL_LINES);
        glVertex2f(-1+x,5+y);
        glVertex2f(11+x,5+y);
    glEnd();
}

void desenhaObjeto(void){
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50,50,-50,50);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        estrada();
        estradaDentro(8,8);
        linhaTracejada();
        linhaChegada();
        desenhaArvore();
        casa(10,37);
        casa(-20,-47);
    glPopMatrix();

    glPushMatrix();
        glScalef(escala, escala, 0);
        glRotatef(rotacao, 0,0,1);
        glTranslatef(movex, movey,0);
        quadrado();
    glPopMatrix();

	glFlush();
}


void teclas(unsigned char tecla, GLint x, GLint y){
    switch(tecla){
        case '+': escala++;
        break;
        case '-': escala--;
        break;
        case '1': rotacao-=10;
        break;
        case '2': rotacao+=10;
        break;
    }
    glutPostRedisplay();
}


void setasDirecionais(GLint tecla, GLint x, GLint y){

    //if((movex>-36 && movex<32) && (movey>-34 && movey<34)){ //tentativa de limitar aonde o quadrado pode andar, mas nao funciona 100%
        switch(tecla){
            case GLUT_KEY_LEFT: movex--;
            break;
            case GLUT_KEY_RIGHT: movex++;
            break;
            case GLUT_KEY_UP: movey++;
            break;
            case GLUT_KEY_DOWN: movey--;
            break;
        }
    /*}else{
        switch(tecla){
            case GLUT_KEY_LEFT: movex = -35;
            break;
            case GLUT_KEY_RIGHT: movex = 31;
            break;
            case GLUT_KEY_UP: movey = 33;
            break;
            case GLUT_KEY_DOWN: movey = -33;
            break;
        }
    }*/
    glutPostRedisplay();

}

int main(void){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,800);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-800)/2,
                           (glutGet(GLUT_SCREEN_HEIGHT)-740)/2);
	glutCreateWindow("Tarefa - Interação com Teclado");
    glutDisplayFunc(desenhaObjeto);
    glutKeyboardFunc(teclas);
    glutSpecialFunc(setasDirecionais);
    glClearColor(0.33, 0.45, 0.18,0);
    glutMainLoop();
    return 0;
}
