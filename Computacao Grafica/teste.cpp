#include <GL/gl.h>
#include <GL/glut.h>

int planoCartesiano(){
    glColor3f(1,0,0);
   
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
        glVertex2f(10,6);
        glColor3f(1,0,0);
        glVertex2f(8,4);
        glVertex2f(6,4);
        glVertex2f(4,6);
    glEnd();
}

void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);
    glPushMatrix();                                        
        //planoCartesiano(); 
        hexagono();                   
	glPopMatrix();
    glutSwapBuffers();
}

int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);          
    glutInitWindowSize(800,600);                          
    glutInitWindowPosition(320,150);                      
	glutCreateWindow("Prova");                 
    glutDisplayFunc(desenhaObjetos); 

    glutMainLoop();                                       
    return 0;                                             
}