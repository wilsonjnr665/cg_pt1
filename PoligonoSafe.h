#ifndef POLIGONO_H_INCLUDED
#define POLIGONO_H_INCLUDED

#ifdef __APPLE__
#include <GLUT/glut.h>
#else
#include <GL/glut.h>
#endif

#include "Aresta.h"
#include "Ponto.h"
#include "Matriz.h"
#include <vector>

#define WIDTH 600
#define HEIGHT 400

class Poligono
{
    private:
        vector<Aresta> arestas;
        vector<Ponto> pontos;
        Matriz Pontos;

    public:
        Poligono();
        Poligono( const Poligono& );

        void addAresta( const Ponto&, const Ponto& );
        void draw();
        void refreshPoints();
        void Translar( Ponto );

        Poligono& operator=( const Poligono& );
};

Poligono::Poligono()
{
}

Poligono::Poligono( const Poligono &cpy )
{
    arestas = cpy.arestas;
    pontos = cpy.pontos;
    Pontos = cpy.Pontos;
}

void Poligono::addAresta( const Ponto &A, const Ponto &B )
{
    Aresta aux;
    pontos.push_back( A );
    aux.setA( pontos.back() );
    pontos.push_back( B );
    aux.setB( pontos.back() );
    arestas.push_back( aux );
}

void Poligono::draw()
{
    for (unsigned int i = 0; i < arestas.size(); i++){
        arestas.at(i).draw();
        arestas.at(i).print();
    }

    Pontos.polygonPoints(pontos);
    Ponto auxTrans( WIDTH/2, HEIGHT/2, 0 );
    Pontos.translar( auxTrans );
    refreshPoints();

    for (unsigned int i = 0; i < arestas.size(); i++){
        arestas.at(i).draw();
        arestas.at(i).print();
    }
}

void Poligono::refreshPoints()
{
    for( int i = 0 ; i < (int) pontos.size() ; i++ )
        pontos.at(i) = Pontos.getPonto( i );
}

void Poligono::Translar( Ponto A )
{
    Pontos.translar(A);
    refreshPoints();
}

#endif
