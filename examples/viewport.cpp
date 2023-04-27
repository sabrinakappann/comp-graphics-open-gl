#include <stdlib.h>
#include <iostream>

#include <stdio.h>
#include <string.h>
#include <GL/glut.h> // OpenGL does not provide commands for performing windowing tasks or for obtaining user input. These commands are provided by GLUT

float red[3] = {1.0f, 0.0f, 0.0f};
float green[3] = {0.0f, 1.0f, 0.0f};
float blue[3] = {0.0f, 0.0f, 1.0f};

// SDO

float xA = 1.0f;
float xB = 1.0f;
float xC = 2.0f;
float xD = 2.0f;
float xE = 2.0f;
float xF = 3.0f;
float xG = 3.0f;
float xH = 2.5f;

float yA = 0.0f;
float yB = 2.0f;
float yC = 2.0f;
float yD = 0.0f;
float yE = 1.0f;
float yF = 1.0f;
float yG = 0.0f;
float yH = 2.0f;

float xwmin = -1.0;
float xwmax = 5.0;
float ywmin = -1.0;
float ywmax = 3.0;

float widthHeightMultiplier = 100;

float getModulus(float number) {
    if (number < 0) {
        return number*(-1);
    }
    return number;
}


float getViewportWidth(void) {
    return (getModulus(xwmin) + getModulus(xwmax)) * widthHeightMultiplier;
}


float getViewportHeight(void) {
    return (getModulus(ywmin) + getModulus(ywmax))* widthHeightMultiplier;
}


void displaySRU(void)
{
    glClear(GL_COLOR_BUFFER_BIT);

    // Define a cor da linha, os parâmetros são as cores RGB e variam de 0-1
    glColor3f(1.0, 2.0, 3.0);

    // red pilar
    glBegin(GL_POLYGON);
    glColor3f(red[0], red[1], red[2]);
    glVertex2f(xA - 1.0, yA - 1.0);
    glVertex2f(xB - 1.0, yB - 1.0);
    glVertex2f(xC - 1.0, yC - 1.0);
    glVertex2f(xD - 1.0, yD - 1.0);
    glEnd();

    // blue quad
    glBegin(GL_QUADS);
    glColor3f(blue[0], blue[1], blue[2]);
    glVertex2f(xD - 1.0, yD - 1.0);
    glVertex2f(xE - 1.0, yE - 1.0);
    glVertex2f(xF - 1.0, yF - 1.0);
    glVertex2f(xG - 1.0, yG - 1.0);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(green[0], green[1], green[2]);
    glVertex2f(xE - 1.0, yE - 1.0);
    glVertex2f(xH - 1.0, yH - 1.0);
    glVertex2f(xF - 1.0, yF - 1.0);
    glEnd();

    glFlush(); // Render now
}

void display(void)
{
    // Limpa a janela de visualização com a cor de fundo específica
    glClear(GL_COLOR_BUFFER_BIT);

    // Define a cor da linha, os parâmetros são as cores RGB e variam de 0-1
    glColor3f(1.0, 2.0, 3.0);

    // red pilar
    glBegin(GL_POLYGON);
    glColor3f(red[0], red[1], red[2]);
    glVertex2f(xA, yA);
    glVertex2f(xB, yB);
    glVertex2f(xC, yC);
    glVertex2f(xD, yD);
    glEnd();

    // blue quad
    glBegin(GL_QUADS);
    glColor3f(blue[0], blue[1], blue[2]);
    glVertex2f(xD, yD);
    glVertex2f(xE, yE);
    glVertex2f(xF, yF);
    glVertex2f(xG, yG);
    glEnd();

    glBegin(GL_TRIANGLES);
    glColor3f(green[0], green[1], green[2]);
    glVertex2f(xE, yE);
    glVertex2f(xH, yH);
    glVertex2f(xF, yF);
    glEnd();

    glFlush(); // Render now
}

void Inicializa(void)
{
    // Define a cor de fundo da janela de visualização como branca
    glClearColor(1.0, 1.0, 1.0, 1.0);
    // Define a espeçura da linha
    glLineWidth(1.0);

    // if called with gluOrtho2D and correctly width and height, plots ok
    glViewport(0, 0, getViewportWidth(), getViewportHeight());

    // if glViewport ok but gluOrtho2D not ok, object is transformed
    gluOrtho2D(xwmin, xwmax, ywmin, ywmax);
}

int main(int argc, char **argv)
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_SINGLE | GLUT_RGB); // usa um buffer e o sistema de cores RGB
    glutCreateWindow("Hello World");             // nome da janela
    glutDisplayFunc(displaySRU);
    Inicializa();   // funçao de inicialização da tela e fundo
    glutMainLoop(); // executa todo o processo
}