#include <GL/gl.h> 					//biblioteca que permite todas as chamadas da API openGL
#include <GL/glut.h> 				//biblioteca que permite a manipula��o de janelas

GLint moveponto = 0; //para mover o ponto em incrementais (1 em 1)
GLint direcao = 1;   // para saber a dire��o do ponto no eixo y (+ ou -)

void timerPontox(int passo){                //fun��o timerPonto, que verifica o local do ponto para saber quando deve parar de subir (ou descer) o ponto no eixo y
    if (direcao == 1){                     //se a dire��o for 1, o ponto sobre, se for -1 ele desce
        moveponto+=1;                      //incrementa nosso moveponto at� o limite estipulado
        if(moveponto == 90){               //se move ponto for igual ao nosso limite superior m�ximo no eixo y+
            direcao = -1;                  // come�a a descer no eixo y, quando chegar no limite de 90y
        }
    }
    else{
        moveponto-=1;                     //decrementa nosso moveponto at� o limite estipulado
        if(moveponto == -90){             //se move ponto for igual ao nosso limite inferior m�ximo no eixo y-
            direcao = 1;                  //come�a a subir no eixo y, quando chegar no limite de -90y
        }
    }
    glutPostRedisplay();                 //chama a fun��o desenha toda vez que for necess�ria
    glutTimerFunc(10,timerPontox,1);      //precisamos chamar a fun��o timer toda vez, Ele executa essa fun��o timer e entra aqui novamente. At� eu querer sair da fun��o timer (neste caso, n�o queremos sair)
}


void pontoY(){
    glPointSize(20);                   //adiciona espessura do ponto
    glBegin(GL_POINTS);                //glBegin e glEnd delimitam os v�rtices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como par�metro).
        glColor3f(0,1,0);              //adiciona cor
        glVertex2f(0,moveponto);       //desenha um ponto na coordenada x, y, onde y vai ser a vari�vel que criamos para deslocar o ponto neste eixo
    glEnd();
}


void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);      //buffer padr�o (limpa a tela toda vez que a fun��o � chamada)

	glMatrixMode(GL_PROJECTION);       //proje��o dos pontos definidos no plano cartesiano
    glLoadIdentity();                  //carrega a proje��o
    gluOrtho2D(-100,100,-100,100);     // define o tamanho do plano cartesiano
    glMatrixMode(GL_MODELVIEW);        // proje��o do tipo modelo
    glLoadIdentity();                  // carrega a identidade de proje��o de modelo

    glPushMatrix();                    //insere a matriz de transforma��o corrente na pilha
        pontoY();                       //chama a fun��o que desenha o ponto
    glPopMatrix();                     //retira a matriz do topo da pilha e torna esta �ltima a matriz de transforma��o corrente

	glutSwapBuffers();                 //Executa uma troca de buffer na camada em uso para a janela atual (para que consiga trabalhar com dois buffers de)
}

/*int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);                    //double buffer, pois single ficaria piscando, uma vez que ele tem que desenhar e redesenhar | sistema de cores RGB
    glutInitWindowSize(800,600);                                    //define o tamanho da janela
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,
                           (glutGet(GLUT_SCREEN_HEIGHT)-540)/2);    //medidas usadas para posicionar a janela no meio da tela - isso depende da resolu��o do monitor
	glutCreateWindow("Exemplo Timer");                              //permite a cria��o de uma janela
    glutDisplayFunc(desenhaObjetos);                                //fun��o de callback - chama a fun��o desenhaObjetos
    glutTimerFunc(10,timerPonto,1);                                 // tr�s valores dispon�veis (tempo (milissegundos) a o nome da fun��o e valor padr�o para retorno)
    glClearColor(1,1,1,0);                                          //informa a cor de fundo da tela (branco)
    glutMainLoop();                                                 //loop infinito - escuta as informa��es do sistema at� encerrar a aplica��o
    return 0;                                                       //retorna zero
}*/

