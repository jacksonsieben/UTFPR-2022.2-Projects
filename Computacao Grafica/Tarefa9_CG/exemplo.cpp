#include <GL/gl.h>
#include <GL/glut.h>

float win;                          // win (window), vai definir o tamanho de cada viewport (quanto maior valor de win, mais longe da tela)
float aspecto;                      // aspecto: variável para controlar windowsize
int largura, altura;                //largura e altura da minha janela

void quadrado(){
    glBegin(GL_QUADS);                      //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glColor3f(0,1,0);                   //adiciona cor ao nosso quadrado
        glVertex2f(-5, -5);                 //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(-5, 5);                  //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(5, 5);                   //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
        glVertex2f(5, -5);                  //adiciona um ponto na coordenada x, y que será usado para fazer nosso quadrado
    glEnd();
}

void triangulo(){
    glBegin(GL_TRIANGLES);                   //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glColor3f(1,0,0);                    //adiciona cor ao nosso quadrado
        glVertex2f(-6, -5);                  //adiciona um ponto na coordenada x, y que será usado para fazer nosso triangulo
        glVertex2f(0, 5);                    //adiciona um ponto na coordenada x, y que será usado para fazer nosso triangulo
        glVertex2f(6, -5);                   //adiciona um ponto na coordenada x, y que será usado para fazer nosso triangulo
    glEnd();
}

void contorno(){                            //desenha linhas para ter melhor visualização das viewports
    glLineWidth(2);                         //adiciona espessura da linha
    glBegin(GL_LINE_LOOP);                  //lBegin e glEnd delimitam os vértices que definem uma primitiva ou um grupo de primitivas semelhantes (definida como parâmetro).
        glColor3f(0,0,0);                   //adiciona cor na linha
        glVertex2f(-win*aspecto, -win);     //inferior esquerdo
        glVertex2f(-win*aspecto, win);      //superior esquerdo
        glVertex2f(win*aspecto, win);       //superior direito
        glVertex2f(win*aspecto, -win);      //inferior direito
    glEnd();
}

void desenhaObjetos(void){
    glClear(GL_COLOR_BUFFER_BIT);                         //buffer padrão (limpa a tela toda vez que a função é chamada)
    
	glViewport(0, 0, largura, altura);                    //liga viewport com o desenho, aqui eu digo qual janela eu vou utilizar
	glPushMatrix();                                       //insere a matriz de transformação corrente na pilha
		quadrado();                                       //chama a função quadrado
		contorno();                                       //chama a função contorno
	 glPopMatrix();                                       //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente
	glViewport(largura, 0, largura, altura);              //liga viewport com o desenho, aqui eu digo qual janela eu vou utilizar
    glPushMatrix();                                       //insere a matriz de transformação corrente na pilha
		triangulo();                                      //chama a função triangulo
		contorno();                                       //chama a função contorno
	 glPopMatrix();                                       //retira a matriz do topo da pilha e torna esta última a matriz de transformação corrente
	
	glutSwapBuffers();                                    //Executa uma troca de buffer na camada em uso para a janela atual (para que consiga trabalhar com dois buffers)
}

void alteraTamanhoJanela(GLsizei w, GLsizei h){           //faz o controle do tamanho das viewports (padrão de parâmetros, altura e largura) (800x600 no glutInitWindowSize)
    if(h == 0) h = 1;                                     //caso altura seja = 0, setamos ela pra 1, pra corrigir eventuais erros
    largura = w/2;                                        //largura eu divido o valor da janela por 2, para criar duas viewports do mesmo tamanho, no caso 800/2
    altura = h;                                           //altura eu mantenho a mesma, pois vou dividir só em duas partes.

    aspecto = (float) largura / altura;                   // largura dividida pela altura (utilizada para controlar a largura da janela automaticamente, independente de eu alterar a windowsize) (faz com que as janelas tenham a mesma proporção em cada viewport)

    glMatrixMode(GL_PROJECTION);                          //projeção do tipo modelo
    glLoadIdentity();                                     //carrega a identidade de projeção de modelo
    gluOrtho2D(-win*aspecto, win*aspecto, -win, win);     //sistema de coordenadas, agora definido de acordo com os parâmetros de janela, win e aspecto) direta x, esqueda -x, abaixo -y e acima y (cada viewport terá seu sistema de coordenadas)
}

void inicializa(){                                        // inicializa nossas variáveis
     glClearColor(1,1,1,0);                               //informa a cor de fundo da tela (branco)
     win = 80;                                            // quanto menor o valor de win, mais perto da tela (como se fosse um zoom)
}

int main(void){
    glutInitDisplayMode(GLUT_DOUBLE | GLUT_RGB);          //somente um double buffer | sistema de cores RGB
    glutInitWindowSize(800,600);                          //define o tamanho da janela
    glutInitWindowPosition(320,150);                      //medidas usadas para posicionar a janela no meio da tela - isso depende da resolução do monitor
	glutCreateWindow("Exemplo Viewport");                 //permite a criação de uma janela
    glutDisplayFunc(desenhaObjetos);                      //função de callback - chama a função desenhaObjetos
    glutReshapeFunc(alteraTamanhoJanela);                 //função que altera o tamanho da janela, redesenha o tamanho da janela
    inicializa();
    glutMainLoop();                                       //loop infinito - escuta as informações do sistema até encerrar a aplicação
    return 0;                                             //retorna zero
}