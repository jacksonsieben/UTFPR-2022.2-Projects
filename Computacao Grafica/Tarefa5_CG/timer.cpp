#include <GL/gl.h> 					//biblioteca que permite todas as chamadas da API openGL
#include <GL/glut.h> 				//biblioteca que permite a manipulação de janelas

GLint moveponto = 0; //para mover o ponto em incrementais (1 em 1)
GLint direcao = 1;   // para saber a direção do ponto no eixo y (+ ou -)

void timerPontox(int passo){                //função timerPonto, que verifica o local do ponto para saber quando deve parar de subir (ou descer) o ponto no eixo y
    if (direcao == 1){                     //se a direção for 1, o ponto sobre, se for -1 ele desce
        moveponto+=1;                      //incrementa nosso moveponto até o limite estipulado
        if(moveponto == 90){               //se move ponto for igual ao nosso limite superior máximo no eixo y+
            direcao = -1;                  // começa a descer no eixo y, quando chegar no limite de 90y
        }
    }
    else{
        moveponto-=1;                     //decrementa nosso moveponto até o limite estipulado
        if(moveponto == -90){             //se move ponto for igual ao nosso limite inferior máximo no eixo y-
            direcao = 1;                  //começa a subir no eixo y, quando chegar no limite de -90y
        }
    }
    glutPostRedisplay();                 //chama a função desenha toda vez que for necessária
    glutTimerFunc(10,timerPontox,1);      //precisamos chamar a função timer toda vez, Ele executa essa função timer e entra aqui novamente. Até eu querer sair da função timer (neste caso, não queremos sair)
}


void pontoY(){
    glPointSize(20);                   //adiciona espessura do ponto
    glBegin(GL_POINTS);                //glBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glColor3f(0,1,0);              //adiciona cor
        glVertex2f(0,moveponto);       //desenha um ponto na coordenada x, y, onde y vai ser a variável que criamos para deslocar o ponto neste eixo
    glEnd();
}


void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);      //buffer padrão (limpa a tela toda vez que a função é chamada)

	glMatrixMode(GL_PROJECTION);       //projeção dos pontos definidos no plano cartesiano
    glLoadIdentity();                  //carrega a projeção
    gluOrtho2D(-100,100,-100,100);     // define o tamanho do plano cartesiano
    glMatrixMode(GL_MODELVIEW);        // projeção do tipo modelo
    glLoadIdentity();                  // carrega a identidade de projeção de modelo

    glPushMatrix();                    //insere a matriz de transformação corrente na pilha
        pontoY();                       //chama a função que desenha o ponto
    glPopMatrix();                     //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

	glutSwapBuffers();                 //Executa uma troca de buffer na camada em uso para a janela atual (para que consiga trabalhar com dois buffers de)
}

/*int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);                    //double buffer, pois single ficaria piscando, uma vez que ele tem que desenhar e redesenhar | sistema de cores RGB
    glutInitWindowSize(800,600);                                    //define o tamanho da janela
    glutInitWindowPosition((glutGet(GLUT_SCREEN_WIDTH)-960)/2,
                           (glutGet(GLUT_SCREEN_HEIGHT)-540)/2);    //medidas usadas para posicionar a janela no meio da tela - isso depende da resolução do monitor
	glutCreateWindow("Exemplo Timer");                              //permite a criação de uma janela
    glutDisplayFunc(desenhaObjetos);                                //função de callback - chama a função desenhaObjetos
    glutTimerFunc(10,timerPonto,1);                                 // três valores disponíveis (tempo (milissegundos) a o nome da função e valor padrão para retorno)
    glClearColor(1,1,1,0);                                          //informa a cor de fundo da tela (branco)
    glutMainLoop();                                                 //loop infinito - escuta as informações do sistema até encerrar a aplicação
    return 0;                                                       //retorna zero
}*/

