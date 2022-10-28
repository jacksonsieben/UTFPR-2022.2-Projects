#include <GL/gl.h>
#include <GL/glut.h>

int planoCartesiano(){
    glColor3f(0,0,0);
   
    glBegin(GL_LINES);
        glVertex2f(-50,0);
        glVertex2f(50,0);
    glEnd();

    glBegin(GL_LINES);
        glVertex2f(0,-50);
        glVertex2f(0,50);
    glEnd();
}

void hexagono(){
    glColor3f(0,1,0);

    glBegin(GL_POLYGON);
        glVertex2f(6,8);
        glVertex2f(8,8);
        glVertex2f(9.5,6);
        glColor3f(1,0,0);
        glVertex2f(8,4);
        glVertex2f(6,4);
        glVertex2f(4.5,6);
    glEnd();

    glPointSize(6);           //adiciona espessura do ponto
    glColor3f(1,0,0);  

    glBegin(GL_POINTS);
        glVertex2f(6,8);
        glVertex2f(8,8);
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
        planoCartesiano();
    glPopMatrix();

    glPushMatrix();
        glScalef(2,2,0);
        glRotatef(30, 0,0,1);
        hexagono();
    glPopMatrix();

	glFlush();
}

int main(void){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,800);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-800)/2,
                           (glutGet(GLUT_SCREEN_HEIGHT)-740)/2);
	glutCreateWindow("Prova 1 - CG");
    glutDisplayFunc(desenhaObjeto);
    glClearColor(1, 1, 1,0);
    glutMainLoop();
    return 0;
}