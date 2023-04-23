#include <stdlib.h>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <GL/glut.h> // OpenGL does not provide commands for performing windowing tasks or for obtaining user input. These commands are provided by GLUT

int width = 500, height = 500;
float red[3] = {1.0f, 0.0f, 0.0f};
float green[3] = {0.0f, 1.0f, 0.0f};
float blue[3] = {0.0f, 0.0f, 1.0f};


float A[3] = {0, 0, 0};
float B[3] = {1, 0, 0};
float C[3] = {1, 1, 0};
float D[3] = {0, 1, 0};
float E[3] = {0, 0, 1};
float F[3] = {1, 0, 1};
float G[3] = {1, 1, 1};
float H[3] = {0, 1, 1};

int xMin = -10;
int yMin = -10;
int zMin = -10;
int xMax = 10;
int yMax = 10;
int zMax = 10;


void drawLine(float vertixOne[3], float vertixTwo[3], float colorRgb[3]) {
      int width = 100, height=100;

    // set up the camera projection (if you haven't done this in init)
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    gluPerspective(45.0f, float(width) / height, 0.1f, 100.0f);

    // set camera position & orientation
    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity();
    gluLookAt(1, 1, -3, //< eye position
              0, 0, 0,  //< aim position
              0, 1, 0); //< up direction
    glColor3f(colorRgb[0], colorRgb[1], colorRgb[2]);
    glBegin(GL_LINES);
    glVertex3f(vertixOne[0], vertixOne[1], vertixOne[2]);
    glVertex3f(vertixTwo[0], vertixTwo[1], vertixTwo[2]);
    glEnd();
}

void display(void)
{
	//Limpa a janela de visualização com a cor de fundo específica
	glClear(GL_COLOR_BUFFER_BIT);

	//Define a cor da linha, os parâmetros são as cores RGB e variam de 0-1
	glColor3f(1.0, 2.0, 3.0);

   drawLine(E, H, red);
   drawLine(H, G, green);
    drawLine(G, F, blue);
    drawLine(F, E, green);
    drawLine(E, A, red);
    drawLine(A, B, green);
    drawLine(B, F, blue);
    drawLine(H, D, green);
    drawLine(D, C, blue);
    drawLine(C, G, green);
    drawLine(A, D, red);
    drawLine(C, B, green);
    glFlush(); // Render now
}

 
void Inicializa(void)
{
	// Define a cor de fundo da janela de visualização como branca
	glClearColor(1.0, 1.0, 1.0, 1.0);
	// Define a espeçura da linha
	glLineWidth(1.0);
	// Define a janela na tela que sera desenhado
    // IMPORTANTE definir  os x e y max do seu desenho
    // é a visão da câmera

	glOrtho(xMin, xMax, yMin, yMax, zMin, zMax);

    
    // xmin, xmax, ymin, ymax
}


int main(int argc, char **argv)
{

    glutInit(&argc, argv);
	glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB);// usa um buffer e o sistema de cores RGB
	glutCreateWindow("Cube by lines");// nome da janela
	glutDisplayFunc(display);
	Inicializa(); // funçao de inicialização da tela e fundo
	glutMainLoop(); // executa todo o processo
}