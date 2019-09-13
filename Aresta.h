#ifndef ARESTA_H_INCLUDED
#define ARESTA_H_INCLUDED

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Ponto.h"
#include <iostream>
#include <string>

using namespace std;

class Aresta
{
    private:
        Ponto *a, *b;

    public:
        Aresta();
        Aresta( Ponto*, Ponto* );
        Aresta( const Aresta& );

        void setA( Ponto* );
        void setB( Ponto* );
        Ponto* getA();
        Ponto* getB();

        void draw();
        void print();

        Aresta& operator=( const Aresta& );
};

Aresta::Aresta()
{
    a = nullptr;
    b = nullptr;
}

Aresta::Aresta( Ponto *A, Ponto *B )
{
    a = A;
    b = B;
}

Aresta::Aresta( const Aresta& cpy )
{
    a = cpy.a;
    b = cpy.b;
}

void Aresta::setA( Ponto* A )
{
    a = A;
}

void Aresta::setB( Ponto* B )
{
    b = B;
}

Ponto* Aresta::getA()
{
    return a;
}

Ponto* Aresta::getB()
{
    return b;
}

void Aresta::draw()
{
    glBegin(GL_LINES);
        glColor3f(1.0, 0.0, 0.0);
        glVertex3d(a->getX(), a->getY(), a->getZ());
        glVertex3d(b->getX(), b->getY(), a->getZ());
    glEnd();
}

void Aresta::print()
{
    cout << "A.x = " << getA()->getX() << "A.y = " << getA()->getY() << endl;
    cout << "B.x = " << getB()->getX() << "A.y = " << getB()->getY() << endl;
}

Aresta& Aresta::operator=(const Aresta &aux)
{
    if( this != &aux)
    {
        a = aux.a;
        b = aux.b;
    }

    return *this;
}

#endif
