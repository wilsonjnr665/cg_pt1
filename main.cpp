#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include <stdlib.h>
#include "Aresta.h"
#include "Matriz.h"
#include "Poligono.h"
#include "Ponto.h"
#include "NodeS.h"
#include "ListS.h"
#include <string>
#include <math.h>
#include "Vetor.h"
#include "SRC.h"

#define WIDTH 600
#define HEIGHT 400
#define DEPTH 500
#define PI 3.14159265359

//Ponto A("A", 20, 1, 1);
//Ponto B("B", 40, 1, 1);
//Ponto C("C", 40, 21, 1);
//Ponto D("D", 20, 21, 1);
//Ponto E("E", 30, 11, 20);

Ponto A("A", 30, 2, 25);
Ponto B("B", 35, 4, 20);
Ponto C("C", 25, 3, 18);
Ponto D("D", 20, 1, 23);
Ponto E("E", 30, 10, 22.5);
Ponto VRP("VRP", 50, 15, 30);
Ponto FOCAL("FOCAL", 20, 6, 15);

Poligono Piramide;

int index = 0;

static void resize(int width, int height)
{
    const float ar = (float) width / (float) height;

    glViewport(0, 0, width, height);
    glMatrixMode(GL_PROJECTION);
    glLoadIdentity();
    glFrustum(-ar, ar, -1.0, 1.0, 2.0, 100.0);

    glMatrixMode(GL_MODELVIEW);
    glLoadIdentity() ;
}

static void display(void)
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);

//    Piramide.RotacionarX(3);
//    Piramide.RotacionarY(3);
//    Piramide.RotacionarZ(3);

    glPointSize(5.0f);

    glBegin(GL_POINTS);
        glColor3f(0.3, 0.3, 0.3);

        glVertex3i(Piramide.getFOCAL().getX() , Piramide.getFOCAL().getY() , Piramide.getFOCAL().getZ() );
        glVertex3i(Piramide.getVRP().getX() , Piramide.getVRP().getY() , Piramide.getVRP().getZ() );
    glEnd();

    //Piramide.getFOCAL().print();

    Piramide.draw();

    glutSwapBuffers();
}


static void key(unsigned char key, int x, int y)
{
    switch (key)
    {
    }

    glutPostRedisplay();
}

static void idle(void)
{
    glutPostRedisplay();
}

void mouse(int button, int state, int x, int y) {
    if (button == GLUT_LEFT_BUTTON && state == GLUT_DOWN) {
    }
}

int main(int argc, char *argv[])
{
    glutInit(&argc, argv);
    glutInitDisplayMode(GLUT_DEPTH | GLUT_DOUBLE | GLUT_RGBA);
    glutInitWindowPosition(100, 100);
    glutInitWindowSize(WIDTH, HEIGHT);
    glutCreateWindow("Simple GLUT Application");
    glOrtho(0, WIDTH, HEIGHT, 0, 0, -DEPTH);
    //glOrtho(0, WIDTH, HEIGHT, 0, -DEPTH, DEPTH);
    glutDisplayFunc(display);
    glutKeyboardFunc(key);
    glutMouseFunc(mouse);

    Piramide.addPonto(A);
    Piramide.addPonto(B);
    Piramide.addPonto(C);
    Piramide.addPonto(D);
    Piramide.addPonto(E);
    Piramide.addPonto(VRP);
    Piramide.addPonto(FOCAL);
    Piramide.addAresta("A", "B");
    Piramide.addAresta("B", "E");
    Piramide.addAresta("A", "E");
    Piramide.addAresta("A", "D");
    Piramide.addAresta("C", "D");
    Piramide.addAresta("C", "E");
    Piramide.addAresta("C", "B");
    Piramide.addAresta("E", "D");

    SRC Camera1( Ponto(50, 15, 30), Ponto(20, 6, 15) );
    //Piramide.multiplicarSRC( Camera1.getMatriz() );

    //Piramide.moveToCenter();

    Piramide.Escala( 10 );
    Piramide.moveToCenter();





    glutMainLoop();

    return EXIT_SUCCESS;
}
