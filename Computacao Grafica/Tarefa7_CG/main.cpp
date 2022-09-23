#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

int movex = 0, movey = 0;
int Ax = 350, Ay = 200;
int Bx = 450, By = 200;
int Cx = 450, Cy = 300;
int Dx = 350, Dy = 300;

int ax, ay, bx, by, cx, cy, dx, dy;

void ponto(){
    glPointSize(10);
    glBegin(GL_POINTS);
        glColor3f(0,1,0);
        glVertex2f(movex,movey);
    glEnd();
}

void quadrado(){
    glColor3f(0,0,0);
    glBegin(GL_QUADS);
        glVertex2f(Ax, Ay);
        glVertex2f(Bx, By);
        glVertex2f(Cx, Cy);
        glVertex2f(Dx, Dy);
    glEnd();
}

void pontos(){
    glPointSize(10);
    glBegin(GL_POINTS);
        glColor3f(0,0,0);
        glVertex2f(Ax, Ay);
        glColor3f(1,0,0);
        glVertex2f(Bx, By);
        glColor3f(0,1,0);
        glVertex2f(Cx, Cy);
        glColor3f(0,0,1);
        glVertex2f(Dx, Dy);
    glEnd();
}

void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(0,800,600,0);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        quadrado();
    glPopMatrix();

	glutSwapBuffers();
}

void printCoord(int x, int y){

    printf("[%d, %d]\n", x, y);

    glutPostRedisplay();
}
void guardarPontos(){
    ax = Ax;
    ay = Ay;
    bx = Bx;
    by = By;
    cx = Cx;
    cy = Cy;
    dx = Dx;
    dy = Dy;
}

void gerenciaMouse(int botao, int estado, int x, int y){
    if (botao == GLUT_LEFT_BUTTON){
        if(estado == GLUT_DOWN){
            printf("Left [%d, %d]\n", x, y);
            if(y>250){
                Dx = x;
                Dy = y;
            }else{
                Ax = x;
                Ay = y;
            }
        }
        guardarPontos();
    }
    if(botao == GLUT_RIGHT_BUTTON){
        if(estado == GLUT_DOWN){
            printf("Right [%d, %d]\n", x, y);
            if(y>250){
                Cx = x;
                Cy = y;
            }else{
                Bx = x;
                By = y;
            }
        }
        guardarPontos();
    }
    if(botao == GLUT_MIDDLE_BUTTON){
        if(estado == GLUT_DOWN){
            printf("Middle [%d, %d]\n", x, y);
            if(y<200){
                Ax = x;
                Ay = y;
                Bx = x;
                By = y;
            }else{
                Cx = x;
                Cy = y;
                Dx = x;
                Dy = y;
            }
        }else{
            Ax = ax;
            Ay = ay;
            Bx = bx;
            By = by;
            Cx = cx;
            Cy = cy;
            Dx = dx;
            Dy = dy;
        }
    }
    glutPassiveMotionFunc(printCoord);
    glutPostRedisplay();

}

int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition(320,150);
	glutCreateWindow("Funcao Mouse - Interacao");
    glutDisplayFunc(desenhaObjetos);
    glutMouseFunc(gerenciaMouse);
    glClearColor(1,1,1,0);
    glutMainLoop();
    return 0;
}



