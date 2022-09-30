#include <GL/gl.h>
#include <GL/glut.h>

GLfloat r = 0, g = 0, b = 0;
GLfloat Ax = -2, Ay = -2;
GLfloat Bx = -2, By = 2;
GLfloat Cx = 2, Cy = 2;
GLfloat Dx = 2, Dy = -2;

int submenucor, subMenuForma;                           

void quadrado(){
    glBegin(GL_QUADS);                    
        /*glVertex2f(-2, -2);               
        glVertex2f(-2, 2);                
        glVertex2f(2, 2);                 
        glVertex2f(2, -2);*/    
        glVertex2f(Ax, Ay);               
        glVertex2f(Bx, By);                
        glVertex2f(Cx, Cy);                  
        glVertex2f(Dx, Dy);            
    glEnd();
}

void desenhaObjeto(void){                 
    glClear(GL_COLOR_BUFFER_BIT);         
	glMatrixMode(GL_PROJECTION);          
    glLoadIdentity(); 				      
    gluOrtho2D(-30,30,-30,30);            
	glMatrixMode(GL_MODELVIEW);           
    glLoadIdentity();                     

    glColor3f(r, g, b);                   
    glPushMatrix();                       
        quadrado();                       
    glPopMatrix();                        

 	glutSwapBuffers();                    
}

void escolheCor(int opcao){                
    switch(opcao){
        case 0:                           
            r = 1;                        
            g = 0;                        
            b = 0;                        
        break;
        case 1:                           
            r = 0;                        
            g = 1;                        
            b = 0;                        
        break;
        case 2:                           
            r = 0;                        
            g = 0;                        
            b = 1;                        
        break;
    }
    glutPostRedisplay();                  
}

void escolheForma(int opcao){ 
    switch(opcao){
        case 0:     //Triangulo                     
            Ax = -2;
            Ay = -2;
            Bx =  0;
            By =  2;
            Cx =  0;
            Cy =  2;
            Dx =  2;
            Dy = -2;                    
        break;
        case 1:     //Losango
            Ax = -2;
            Ay =  0;
            Bx =  0;
            By =  2;
            Cx =  2;
            Cy =  0;
            Dx =  0;
            Dy = -2;                    
        break;
        case 2:     //Quadrado                  
            Ax = -2;
            Ay = -2;
            Bx = -2;
            By =  2;
            Cx =  2;
            Cy =  2;
            Dx =  2;
            Dy = -2;                       
        break;
    }
    glutPostRedisplay();    
}

void menuCor(){
    submenucor = glutCreateMenu(escolheCor);               
    glutAddMenuEntry("Vermelho", 0);                       
    glutAddMenuEntry("Verde", 1);                          
    glutAddMenuEntry("Azul", 2);                           
}

void menuForma(){
    subMenuForma = glutCreateMenu(escolheForma);               
    glutAddMenuEntry("Triangulo", 0);                       
    glutAddMenuEntry("Losango", 1);                          
    glutAddMenuEntry("Quadrado", 2);                           
}

void criaMenu(){
    menuCor();  
    menuForma();                                 
    glutCreateMenu(0);                                     
    glutAddSubMenu("Escolha a Cor", submenucor);  
    glutAddSubMenu("Escolha a Forma", subMenuForma);        
    glutAttachMenu(GLUT_LEFT_BUTTON);                        
}

void gerenciaMouse(int botao, int estado, int x, int y){      
    if(botao == GLUT_LEFT_BUTTON)                             
        if(estado == GLUT_DOWN){                              
            criaMenu();                             
        }
    glutPostRedisplay();                                      
}

int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);            
    glutInitWindowSize(800,600);                            
    glutInitWindowPosition(320,150);                        
	glutCreateWindow("Função Menu - Interação");            
    glutDisplayFunc(desenhaObjeto);                         
    glutMouseFunc(gerenciaMouse);                           
    glClearColor(1,1,1,0);                                  
    glutMainLoop();                                         
    return 0;                                               
}
