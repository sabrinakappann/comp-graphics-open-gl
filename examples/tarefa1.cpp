#include <GL/glut.h>
#include <iostream>

void Desenha(void)
{
	//Limpa a janela de visualização com a cor de fundo específica
	glClear(GL_COLOR_BUFFER_BIT);

	//Define a cor da linha, os parâmetros são as cores RGB e variam de 0-1
	glColor3f(0.0, 0.0, 0.0);

	glBegin(GL_QUADS);
	glVertex2f(50.0, 150.0);
	glVertex2f(50.0, 450.0);
	glVertex2f(350.0, 150.0);
	glVertex2f(350.0, 450.0);

	glVertex2f(100.0, 50.0);
	glVertex2f(100.0, 150.0);
	glVertex2f(300.0, 50.0);
	glVertex2f(300.0, 150.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(350.0, 150.0);
	glVertex2f(50.0, 150.0);
	glVertex2f(200.0, 450.0);

	glVertex2f(100.0, 50.0);
	glVertex2f(300.0, 50.0);
	glVertex2f(200.0, 150.0);
	glEnd();

	glColor3f(1.0, 1.0, 1.0);

	glBegin(GL_QUADS);
	glVertex2f(175.0, 400.0);
	glVertex2f(175.0, 300.0);
	glVertex2f(75.0, 400.0);
	glVertex2f(75.0, 300.0);

	glVertex2f(325.0, 400.0);
	glVertex2f(325.0, 300.0);
	glVertex2f(225.0, 400.0);
	glVertex2f(225.0, 300.0);

	glVertex2f(195.0, 200.0);
	glVertex2f(195.0, 250.0);
	glVertex2f(205.0, 200.0);
	glVertex2f(205.0, 250.0);

	glVertex2f(150.0, 125.0);
	glVertex2f(150.0, 75.0);
	glVertex2f(250.0, 125.0);
	glVertex2f(250.0, 75.0);
	glEnd();

	glBegin(GL_TRIANGLES);
	glVertex2f(175.0, 400.0);
	glVertex2f(75.0, 400.0);
	glVertex2f(125.0, 300.0);

	glVertex2f(325.0, 400.0);
	glVertex2f(225.0, 400.0);
	glVertex2f(275.0, 300.0);

	glVertex2f(150.0, 125.0);
	glVertex2f(250.0, 125.0);
	glVertex2f(200.0, 75.0);
	glEnd();

	glColor3f(0.0, 0.0, 0.0);
	glBegin(GL_LINES);
	for (int i = 150; i <= 250; i = i + 5)
	{
		glVertex2i(i, 125);
		glVertex2i(i, 75);
	}
	glVertex2i(150, 100);
	glVertex2i(250, 100);
	glEnd();
	//Executa os comandos openGL
	glFlush();
}

// Inicializa parâmetros de rendering
void Inicializa(void)
{
	// Define a cor de fundo da janela de visualização como branca
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// Define a espeçura da linha
	glLineWidth(3.0);
	// Define a janela na tela que sera desenhado
	gluOrtho2D(0.0, 500.0, 0.0, 500.0);
}

int main(int argc, char **argv)
{	
	     glutInit(&argc, argv);

	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);// usa um buffer e o sistema de cores RGB
	glutCreateWindow("Hello World");// nome da janela
	glutDisplayFunc(Desenha);
	Inicializa(); // funçao de inicialização da tela e fundo
	glutMainLoop(); // executa todo o processo
}