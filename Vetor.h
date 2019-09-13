#ifndef VETOR_H_INCLUDED
#define VETOR_H_INCLUDED

#include <iostream>
#include <string>
#include "Matriz.h"
#include "math.h"

using namespace std;

class Vetor
{
    private:
        double x, y, z;
        double norma;

    public:
        Vetor();
        Vetor(double X, double Y, double Z);
        Vetor(const Vetor&);
        Vetor( Ponto& );

        void setX(double);
        void setY(double);
        void setZ(double);
        void setVetor( const Vetor& );
        double getX();
        double getY();
        double getZ();
        void setNorma();
        double getNorma();

        void print();
        void transfUnitario(); /// transforma o vetor em um vetor unitário
        void PontoToVetor( Ponto ); /// transforma um ponto em um vetor

        Vetor operator+(const Vetor&);
        Vetor operator-(const Vetor&);
        double operator*(const Vetor&); /// produto escalar
        Vetor operator^(const Vetor&); /// produto vetorial
        Vetor operator/(const Vetor&);
        Vetor operator*(const double&); /// multiplicar por um escalar
        Vetor operator/(const double&); /// dividir por um escalar
        Vetor& operator=(const Vetor&);
};

Vetor::Vetor()
{
    x = 0;
    y = 0;
    z = 0;
    norma = 0;
}

Vetor::Vetor(double X, double Y, double Z)
{
    x = X;
    y = Y;
    z = Z;
}

Vetor::Vetor(const Vetor &cpy)
{
    x = cpy.x;
    y = cpy.y;
    z = cpy.z;
}

Vetor::Vetor( Ponto &cpy )
{
    x = cpy.getX();
    y = cpy.getY();
    z = cpy.getZ();
}


double Vetor::getX()
{
    return x;
}

double Vetor::getY()
{
    return y;
}

double Vetor::getZ()
{
    return z;
}

void Vetor::setX(double X)
{
    x = X;
}

void Vetor::setY(double Y)
{
    y = Y;
}

void Vetor::setZ(double Z)
{
    z = Z;
}

void Vetor::setVetor(const Vetor &cpy)
{
    x = cpy.x;
    y = cpy.y;
    z = cpy.z;
}


void Vetor::print()
{
    cout << "Vetor ( " << x << " , " << y << " , " << z << " )" << endl;
}

void Vetor::setNorma()
{
    norma = sqrt( x*x + y*y + z*z );
}

double Vetor::getNorma()
{
    return norma;
}

void Vetor::transfUnitario()
{
    setNorma();
    x = x/norma;
    y = y/norma;
    z = z/norma;
}

void Vetor::PontoToVetor( Ponto cpy )
{
    x = cpy.getX();
    y = cpy.getY();
    z = cpy.getZ();
}

Vetor Vetor::operator+(const Vetor& cpy)
{
    return Vetor(x + cpy.x, y + cpy.y, z + cpy.z );
}

Vetor Vetor::operator-(const Vetor& cpy)
{
    return Vetor(x - cpy.x, y - cpy.y, z - cpy.z );
}

Vetor Vetor::operator/(const Vetor& cpy)
{
    return Vetor(x / cpy.x, y / cpy.y, z / cpy.z );
}

Vetor Vetor::operator^(const Vetor& cpy)
{
    double auxX = y*cpy.z - z*cpy.y;
    double auxY = z*cpy.x - x*cpy.z;
    double auxZ = x*cpy.y - y*cpy.x;

    return ( Vetor( auxX, auxY, auxZ ) );
}

Vetor Vetor::operator*(const double& cpy)
{
    return Vetor(x * cpy, y * cpy, z * cpy );
}

Vetor Vetor::operator/(const double& cpy)
{
    return Vetor(x / cpy, y / cpy, z / cpy );
}

double Vetor::operator*(const Vetor& cpy)
{
    return ( x * cpy.x + y * cpy.y + z * cpy.z );
}

Vetor& Vetor::operator=(const Vetor& cpy)
{
    if( this != &cpy )
    {
        x = cpy.x;
        y = cpy.y;
        z = cpy.z;
    }

    return *this;
}

#endif // Vetor_H_INCLUDED
