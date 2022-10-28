#include <GL/gl.h>
#include <GL/glut.h>

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

void desenhaObjeto(void){
    glClear(GL_COLOR_BUFFER_BIT);
	glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluOrtho2D(-50,50,-50,50);
	glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();

    glPushMatrix();
        carrinho();
    glPopMatrix();

	glFlush();
}

int main(void){
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);
    glutInitWindowSize(800,800);
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-800)/2, (glutGet(GLUT_SCREEN_HEIGHT)-740)/2);
	glutCreateWindow("Prova Prática 1");
    glutDisplayFunc(desenhaObjeto);
    //glutKeyboardFunc(teclas);
    //glutSpecialFunc(setasDirecionais);
    glClearColor(1, 1, 1,0);
    glutMainLoop();
    return 0;
}