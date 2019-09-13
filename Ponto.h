#ifndef PONTO_H_INCLUDED
#define PONTO_H_INCLUDED

#include <iostream>
#include <string>

#define SCALE 10

using namespace std;

class Ponto
{
    private:
        double x, y, z;
        string tag; // Nome único que representa o ponto (pedreiragem)

    public:
        Ponto();
        Ponto(double X, double Y, double Z);
        Ponto(string , double X, double Y);
        Ponto(string, double X, double Y, double Z);
        Ponto(const Ponto&);

        void setTag(const string&);
        void setX(double);
        void setY(double);
        void setZ(double);
        void setPonto( const Ponto& );
        string getTag();
        double getX();
        double getY();
        double getZ();

        void escalar( const double& );
        void print();

        Ponto operator+(const Ponto&);
        Ponto operator-(const Ponto&);
        Ponto operator*(const double&);
        Ponto& operator=(const Ponto&);
};

Ponto::Ponto()
{
    x = 0;
    y = 0;
    z = 0;
}

Ponto::Ponto(double X, double Y, double Z)
{
    tag = "";
    x = X;
    y = Y;
    z = Z;
}

Ponto::Ponto(string TAG, double X, double Y)
{
    tag = TAG;
    x = X;
    y = Y;
    z = 0;
}

Ponto::Ponto(string TAG, double X, double Y, double Z)
{
    tag = TAG;
    x = X;
    y = Y;
    z = Z;
}

Ponto::Ponto(const Ponto &cpy)
{
    x = cpy.x;
    y = cpy.y;
    z = cpy.z;
    tag = cpy.tag;
}

string Ponto::getTag()
{
    return tag;
}

double Ponto::getX()
{
    return x;
}

double Ponto::getY()
{
    return y;
}

double Ponto::getZ()
{
    return z;
}

void Ponto::setTag(const string &TAG)
{
    tag = TAG;
}

void Ponto::setX(double X)
{
    x = X;
}

void Ponto::setY(double Y)
{
    y = Y;
}

void Ponto::setZ(double Z)
{
    z = Z;
}

void Ponto::setPonto(const Ponto &cpy)
{
    x = cpy.x;
    y = cpy.y;
    z = cpy.z;
}

void Ponto::escalar( const double& scale)
{
    x *= scale;
    y *= scale;
    z *= scale;
}

void Ponto::print()
{
    cout << "Ponto " << tag <<" ( " << x << " , " << y << " , " << z << " )" << endl;
}

Ponto Ponto::operator+(const Ponto& cpy)
{
    return Ponto( tag, x + cpy.x, y + cpy.y, z + cpy.z );
}

Ponto Ponto::operator-(const Ponto& cpy)
{
    return Ponto( tag, x - cpy.x, y - cpy.y, z - cpy.z );
}

Ponto Ponto::operator*(const double& cpy)
{
    return Ponto( tag, x * cpy, y * cpy, z * cpy );
}

Ponto& Ponto::operator=(const Ponto& cpy)
{
    if( this != &cpy )
    {
        x = cpy.x;
        y = cpy.y;
        z = cpy.z;
        tag = cpy.tag;
    }

    return *this;
}

#endif // PONTO_H_INCLUDED
