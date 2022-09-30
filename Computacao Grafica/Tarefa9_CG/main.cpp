#include <GL/gl.h>
#include <GL/glut.h>
#include <stdio.h>

float win;                          
float aspecto;                      
int largura, altura;
GLfloat moveX =0, moveY=0;
GLfloat escala=1;
GLfloat rotacao=0;
float qRed = 0, qBlue = 0, qGreen = 0;
float speed = 0;

void ponto(){
    glPointSize(20);        //8 ficou muito pequeno, e nao quis mudar o win para nao ter q desenhar o resto novamente, entao coloquei 20
    glColor3f(0,0,1);
    glBegin(GL_POINTS);                      
                           
        glVertex2f(0, 0);                                   
    glEnd();
}

void quadrado(){
    glBegin(GL_QUADS);                      
        glColor3f(qRed,qBlue,qGreen);                   
        glVertex2f(-25, -25);                 
        glVertex2f(-25, 25);                  
        glVertex2f(25, 25);                   
        glVertex2f(25, -25);                  
    glEnd();
}

void triangulo(){
    glBegin(GL_TRIANGLES);                   
        glColor3f(1,0,0);                    
        glVertex2f(-6, -5);                  
        glVertex2f(0, 5);                    
        glVertex2f(6, -5);                   
    glEnd();
}

void linha(){
    glLineWidth(8);
    glBegin(GL_LINES);
        glColor3f(1,0,1);
        glVertex2f(-25,0);
        glVertex2f(25,0);
    glEnd();
}

void contorno(){                            
    glLineWidth(2);                         
    glBegin(GL_LINE_LOOP);                  
        glColor3f(0,0,0);                   
        glVertex2f(-win*aspecto, -win);     
        glVertex2f(-win*aspecto, win);      
        glVertex2f(win*aspecto, win);       
        glVertex2f(win*aspecto, -win);      
    glEnd();
}

void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);                         
    
    glViewport(0, altura, largura, altura);         //cima esquerda                    
	glPushMatrix();                                       
		quadrado();                                       
		contorno();                                       
	glPopMatrix();
    
    glViewport(largura, altura, largura, altura);   //cima direita              
    glPushMatrix(); 
        contorno();  
        glScalef(escala, escala, 0);                                    
		triangulo();                                                                
	glPopMatrix();       

    glViewport(0, 0, largura, altura);              //baixo esquerda                   
	glPushMatrix();
        contorno();
        glTranslatef(moveX, moveY,0);                                       
		ponto();                                                                           
	glPopMatrix();

	glViewport(largura, 0, largura, altura);        //baixo direita       
    glPushMatrix();
        contorno();
        glRotatef(rotacao, 0,0,1);                                       
		linha();                                                                       
	glPopMatrix();                          
	
	glutSwapBuffers();                                    
}

void timerRotacao(int passo){
    if(speed<79){
        speed++;
    }
    
    glutPostRedisplay();
    glutTimerFunc(100,timerRotacao,1);
}

void timerLinha(int passo){
    rotacao++;
    unsigned int time = (unsigned int) 80 - speed;
    
    glutPostRedisplay();
    glutTimerFunc(time,timerLinha,1);   
}

void gerenciaMouse(int botao, int estado, int x, int y){      
    if(botao == GLUT_RIGHT_BUTTON){
        if(estado == GLUT_DOWN){                              
            if(qRed>=1 && qBlue >= 1 && qGreen >=1){
                qRed = 0;
                qBlue = 0;
                qGreen = 0;
            }else{
                if(qRed<=1){
                    qRed += 0.2;
                }else if(qBlue<=1){
                    qBlue += 0.2;
                }else if(qGreen<=1){
                    qGreen += 0.2;
                }  
            }
        }
    }                             
    if(botao == GLUT_LEFT_BUTTON){
        if(estado == GLUT_DOWN){ 
            glutTimerFunc(1,timerLinha,1);
            glutTimerFunc(1,timerRotacao,1);
        }
    }
    glutPostRedisplay();                                      
}

void teclas(unsigned char tecla, GLint x, GLint y){
    switch(tecla){
        case '+': 
            escala++;
            break;
        case '-': 
            escala--;
            break;
    }
    glutPostRedisplay();
}

void setasDirecionais(GLint tecla, GLint x, GLint y){
    switch(tecla){
        case GLUT_KEY_LEFT: moveX--;
        break;
        case GLUT_KEY_RIGHT: moveX++;
        break;
        case GLUT_KEY_UP: moveY++;
        break;
        case GLUT_KEY_DOWN: moveY--;
        break;
    }
    glutPostRedisplay();
}

void alteraTamanhoJanela(GLsizei w, GLsizei h){           
    if(h == 0) h = 1;                                     
    largura = w/2;                                        
    altura = h/2;                                           

    aspecto = (float) largura / altura;                   

    glMatrixMode(GL_PROJECTION);                          
    glLoadIdentity();                                     
    gluOrtho2D(-win*aspecto, win*aspecto, -win, win);     
}

void inicializa(){                                        
    glClearColor(1,1,1,0);                               
    win = 80;                                            
}

int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);          
    glutInitWindowSize(800,600);                          
    glutInitWindowPosition(320,150);                      
	glutCreateWindow("Tarefa Viewport");                 
    glutDisplayFunc(desenhaObjetos); 
    glutKeyboardFunc(teclas);  
    glutSpecialFunc(setasDirecionais);
    glutMouseFunc(gerenciaMouse);                    
    glutReshapeFunc(alteraTamanhoJanela);
                     
    inicializa();
    glutMainLoop();                                       
    return 0;                                             
}