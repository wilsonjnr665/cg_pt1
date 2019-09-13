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
#include "ListS.h"
#include <string>
#include "SRC.h"

#define WIDTH 600
#define HEIGHT 400
#define DEPTH 500
#define PI 3.14159265359

class Poligono
{
    private:
        vector<Aresta> arestas;
        ListS pontos;
        Matriz Pontos;
        vector<string> tagPontos;
        Ponto centro;
        Ponto centroTela;
        double maiorX, maiorY, maiorZ, menorX, menorY, menorZ;
        void defineCenter();

    public:
        Poligono();
        Poligono( const Poligono& );

        void addAresta( string , string );
        void addPonto( Ponto& );
        void draw();
        void refreshPoints();
        void moveToCenter();
        void Translar( Ponto );
        void RotacionarX( double );
        void RotacionarY( double );
        void RotacionarZ( double );
        void Escala( double );

        void multiplicarSRC( Matriz );

        Ponto getVRP();
        Ponto getFOCAL();

        Poligono& operator=( const Poligono& );
};

Poligono::Poligono()
{
    centroTela.setTag("centroTela");
    centroTela.setX( (double) WIDTH/2 );
    centroTela.setY( (double) HEIGHT/2 );
    centroTela.setZ( (double) DEPTH/2 );
    //centroTela.setZ( 0 );
}

Poligono::Poligono( const Poligono &cpy )
{
    arestas = cpy.arestas;
    pontos = cpy.pontos;
    Pontos = cpy.Pontos;
}

void Poligono::defineCenter()
{
    maiorX = menorX = pontos.at(0).getX();
    maiorY = menorY = pontos.at(0).getY();
    maiorZ = menorZ = pontos.at(0).getZ();

    for( int i = 0 ; i < pontos.getSize() ; i++ ){
        if( pontos.at(i).getX() > maiorX)
            maiorX = pontos.at(i).getX();
        if( pontos.at(i).getY() > maiorY)
            maiorY = pontos.at(i).getY();
        if( pontos.at(i).getZ() > maiorZ)
            maiorZ = pontos.at(i).getZ();
        if( pontos.at(i).getX() < menorX)
            menorX = pontos.at(i).getX();
        if( pontos.at(i).getY() < menorY)
            menorY = pontos.at(i).getY();
        if( pontos.at(i).getZ() < menorZ)
            menorZ = pontos.at(i).getZ();
    }

    centro.setX( (maiorX + menorX)/2 );
    centro.setY( (maiorY + menorY)/2 );
    centro.setZ( (maiorZ + menorZ)/2 );
}

void Poligono::moveToCenter()
{
    Pontos.polygonPoints(pontos);
    Ponto auxTrans( centro * -1 );
    Pontos.translar( auxTrans );
    Pontos.translar( centroTela );
    refreshPoints();
}

void Poligono::addPonto( Ponto& A)
{
    if( !tagPontos.size() )
    {
        maiorX = menorX = A.getX();
        maiorY = menorY = A.getY();
        maiorZ = menorZ = A.getZ();
    }

    pontos.addTail( A );
    tagPontos.push_back( A.getTag() );
}

void Poligono::addAresta( string tagA, string tagB )
{
    Aresta aux;
    aux.setA( pontos.getPontobyTag(tagA) );
    aux.setB( pontos.getPontobyTag(tagB) );
    arestas.push_back( aux );
}

void Poligono::draw()
{
    defineCenter();
    Pontos.polygonPoints(pontos);

    for (unsigned int i = 0; i < arestas.size(); i++){
        arestas.at(i).draw();
    }
}

void Poligono::refreshPoints()
{
    for( int i = 0 ; i < (int) pontos.getSize() ; i++ )
        pontos.at(i) = Pontos.getPonto( i , tagPontos);

    defineCenter();
}

void Poligono::Translar( Ponto A )
{
    Pontos.translar(A);
    refreshPoints();
}

void Poligono::RotacionarX( double angle )
{
    angle *= PI/180;
    Ponto auxRotate( centro * -1 );

    Matriz translateOrigin;
    translateOrigin.matrizTranslar( auxRotate );

    Matriz rotateX;
    rotateX.rotateX( angle );

    Matriz translateBack;
    translateBack.matrizTranslar( centro );

    Matriz operation = translateBack * rotateX * translateOrigin;

    Pontos = operation * Pontos;

    refreshPoints();
}

void Poligono::RotacionarY( double angle )
{
    angle *= PI/180;
    Ponto auxRotate( centro * -1);
    Pontos.translar( auxRotate );
    Pontos.rotateY(angle);
    Pontos.translar( centro );
    refreshPoints();
}

void Poligono::RotacionarZ( double angle )
{
    angle *= PI/180;
    Ponto auxRotate( centro * -1);
    Pontos.translar( auxRotate );
    Pontos.rotateZ(angle);
    Pontos.translar( centro );
    refreshPoints();
}

void Poligono::Escala( double scale )
{
    Pontos.polygonPoints(pontos);
    Pontos.applyScale(scale);
    refreshPoints();
}

void Poligono::multiplicarSRC( Matriz A )
{
    Pontos.polygonPoints(pontos);
    Pontos = A * Pontos;
    refreshPoints();
    cout << "Matriz PONTOS x SRC\n\n";
    Pontos.print();
}

Ponto Poligono::getFOCAL()
{
    return *pontos.getPontobyTag("FOCAL");;
}

Ponto Poligono::getVRP()
{
    return *pontos.getPontobyTag("VRP");
}

#endif
