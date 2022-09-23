#include <GL/gl.h>
#include <GL/glut.h>

#define LMTY -40
#define LMTX  70

GLint movePontoY = 89;
GLint movePontoX = -89;
GLint direcao = 1;

void grama(){
    glColor3f(0.33, 0.45, 0.18);
    glBegin(GL_QUADS);
        glVertex2f(-100,-42);
        glVertex2f(100,-42);
        glVertex2f(100,-100);
        glVertex2f(-100,-100);
    glEnd();
}

void timerPonto(int passo){
    if (direcao == 1){
        movePontoY-=1;
        movePontoX+=1;
        if(movePontoY == LMTY){
            direcao = -1;
        }
    }
    else if(direcao == -1){
        movePontoY+=1;
        movePontoX+=1;
        if(movePontoY == LMTY + 3){
            direcao = 1;
        }
    }
    if(movePontoX >= LMTX){
        direcao = 0;
    }

    glutPostRedisplay();
    glutTimerFunc(50,timerPonto,1);
}


void pontoY(){
    glPointSize(25);
    glBegin(GL_POINTS);
        glColor3f(0.2,0.2,0.2);
        glVertex2f(movePontoX, movePontoY);
    glEnd();
}

void teclas (unsigned char tecla, GLint x, GLint y){
    if(tecla == 'a'){
        glutTimerFunc(10,timerPonto,1);
    }
}

void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);

	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-100,100,-100,100);
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        grama();
        pontoY();
    glPopMatrix();

	glutSwapBuffers();
}

int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,
                           (glutGet(GLUT_SCREEN_HEIGHT)-540)/2);
	glutCreateWindow("Tarefa - Timer Teclado");
    glutDisplayFunc(desenhaObjetos);
    glutKeyboardFunc(teclas);
    glClearColor(0.53, 0.81, 0.98,0);
    glutMainLoop();
    return 0;
}
