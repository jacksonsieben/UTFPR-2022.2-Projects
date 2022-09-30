#include <GL/gl.h>
#include <GL/glut.h>

GLfloat r = 0, g = 0, b = 0;              // variáveis para controle de cor (inicia em preto)
int submenucor;                           //variável para o submenu

void quadrado(){
    glBegin(GL_QUADS);                    //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glVertex2f(-2, -2);               //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
        glVertex2f(-2, 2);                //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
        glVertex2f(2, 2);                 //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
        glVertex2f(2, -2);                //adiciona um ponto na coordenada x, y que será usado para completar nosso quadrado
    glEnd();
}

void desenhaObjeto(void){                 //função de desenho
    glClear(GL_COLOR_BUFFER_BIT);         //buffer padrão; limpa a tela toda vez que a função é chamada
	glMatrixMode(GL_PROJECTION);          //projeção dos pontos definidos no plano cartesiano
    glLoadIdentity(); 				      //carrega a projeção
    gluOrtho2D(-30,30,-30,30);            //define o tamanho do plano cartesiano
	glMatrixMode(GL_MODELVIEW);           //projeção do tipo modelo
    glLoadIdentity();                     //carrega essa identidade de projeção de modelo

    glColor3f(r, g, b);                   //adiciona cor ao quadrado (dependendo do valor das variáveis r, g e b)
    glPushMatrix();                       //insere a matriz de transformação corrente na pilha
        quadrado();                       //chama a função que desenha um quadrado
    glPopMatrix();                        //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente

 	glutSwapBuffers();                    //Executa uma troca de buffer na camada em uso para a janela atual (para que consiga trabalhar com dois buffers)
}

void escolheCor(int opcao){                //verifica a opção escolhida
    switch(opcao){
        case 0:                           //caso  o valor de opção for 0 pinta de vermelho
            r = 1;                        //atribui valores as variáveis de cor
            g = 0;                        //atribui valores as variáveis de cor
            b = 0;                        //atribui valores as variáveis de cor
        break;
        case 1:                           //caso  o valor de opção for 1 pinta de verde
            r = 0;                        //atribui valores as variáveis de cor
            g = 1;                        //atribui valores as variáveis de cor
            b = 0;                        //atribui valores as variáveis de cor
        break;
        case 2:                           //caso  o valor de opção for 2 pinta de azul
            r = 0;                        //atribui valores as variáveis de cor
            g = 0;                        //atribui valores as variáveis de cor
            b = 1;                        //atribui valores as variáveis de cor
        break;
    }
    glutPostRedisplay();                  //chama a função desenha toda vez que for necessária
}

void menuCor(){
    submenucor = glutCreateMenu(escolheCor);               //cria um novo menu pop-up
    glutAddMenuEntry("Vermelho", 0);                       //adiciona uma entrada de menu na parte inferior do menu atual
    glutAddMenuEntry("Verde", 1);                          //adiciona uma entrada de menu na parte inferior do menu atual
    glutAddMenuEntry("Azul", 2);                           //adiciona uma entrada de menu na parte inferior do menu atual
}


void criaMenu(){
    menuCor();                                             //Chama a função que cria o submenu cor
    glutCreateMenu(0);                                     //cria um novo menu pop-up (no caso, o principal, onde estarão adicionados os outros submenus)
    glutAddSubMenu("Escolha a Cor", submenucor);           //adiciona um gatilho de submenu à parte inferior do menu atual
    glutAttachMenu(GLUT_LEFT_BUTTON);                      //anexa um botão do mouse para a janela

}

void gerenciaMouse(int botao, int estado, int x, int y){      //Parâmetros de entrada da função: (int button, int state, int x, int y).  Os parâmetros x e y indicam a localização do mouse no momento que o evento ocorreu.
    if(botao == GLUT_LEFT_BUTTON)                             //se o botão do mouse clicado for o esquerdo
        if(estado == GLUT_DOWN){                              //O parâmetro state pode ser GLUT_UP ou GLUT_DOWN.
            criaMenu();                                       //chama a função que cria o menu
        }
    glutPostRedisplay();                                      //chama a função desenha toda vez que for necessária
}

int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);            //double buffer, pois single ficaria piscando, uma vez que ele tem que desenhar e redesenhar | sistema de cores RGB
    glutInitWindowSize(800,600);                            //define o tamanho da janela
    glutInitWindowPosition(320,150);                        //medidas usadas para posicionar a janela no meio da tela - isso depende da resolução do monitor
	glutCreateWindow("Função Menu - Interação");            //permite a criação de uma janela
    glutDisplayFunc(desenhaObjeto);                         //função de callback - chama a função desenhaObjetos
    glutMouseFunc(gerenciaMouse);                           //Estabelece a função callback que é chamada pela GLUT cada vez que ocorre um evento de mouse.
    glClearColor(1,1,1,0);                                  //informa a cor de fundo da tela (branco)
    glutMainLoop();                                         //loop infinito - escuta as informações do sistema até encerrar a aplicação
    return 0;                                               //retorna zero
}
