#include <GL/gl.h>
#include <GL/glut.h>
#include <Math.h>

void quadrado(){
    glColor3f(0.66, 0.66, 0.66);
    glBegin(GL_QUADS);
        glVertex2f(-2, 2);
        glVertex2f(1, 2);
        glVertex2f(1, -2);
        glVertex2f(-2, -2);
    glEnd();
}

void escala(){
    glColor3f(0, 0, 0);
    glScalef(2, 2, 0);
    glBegin(GL_QUADS);
        glVertex2f(-2, 2);
        glVertex2f(1, 2);
        glVertex2f(1, -2);
        glVertex2f(-2, -2);
    glEnd();
}

void translacao(float x, float y){
    glColor3f(0.73, 0.33, 0.83);
    glTranslatef(x, y, 0);
    glBegin(GL_QUADS);
        glVertex2f(-2, 2);
        glVertex2f(1, 2);
        glVertex2f(1, -2);
        glVertex2f(-2, -2);
    glEnd();
}

void rotacao(){
    glColor3f(1, 0.84, 0);
    glRotatef(60,0,0,1);
    glBegin(GL_QUADS);
        glVertex2f(-2, 2);
        glVertex2f(1, 2);
        glVertex2f(1, -2);
        glVertex2f(-2, -2);
    glEnd();
}

void Desenha(void){
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-5,5,-5,5);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        quadrado();
    glPopMatrix();

	glPushMatrix();
        translacao(3,2);
    glPopMatrix();

    glPushMatrix();
        escala();
    glPopMatrix();

    glPushMatrix();
        rotacao();
    glPopMatrix();

	glFlush();
}

int main(void){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,600);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,
                           (glutGet(GLUT_SCREEN_HEIGHT)-780)/2);
    glutCreateWindow("Exemplo em OpenGL");
    glutDisplayFunc(Desenha);
    glClearColor(1,1,1,0);
    glutMainLoop();
    return 0;
}
