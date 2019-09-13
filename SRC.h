#ifndef SRC_H_INCLUDED
#define SRC_H_INCLUDED

#include "Vetor.h"
#include <iostream>
#include <string>
#include "Matriz.h"
#include "math.h"
#include "Ponto.h"

using namespace std;

class SRC
{
    private:
        Vetor n, u, v;
        Ponto VRP, FOCAL;
        Matriz SRU_SRC;
        void setMatriz();

    public:
        SRC();
        SRC( Ponto&, Ponto& );
        SRC( Ponto, Ponto );
        Matriz getMatriz();

        SRC& operator=(const SRC&);
};

SRC::SRC()
{
    VRP.setPonto( Ponto(0,0,0) );
    FOCAL.setPonto( Ponto(0,0,0) );
}

SRC::SRC( Ponto& vrp, Ponto& focal)
{
    VRP = vrp;
    FOCAL = focal;

    n.PontoToVetor( VRP - FOCAL );
    n.transfUnitario();

    Vetor Y( 0, 1, 0 );
    v = Y - n * ( Y * n );
    v.transfUnitario();

    u = v ^ n;

    n.print();
    v.print();
    u.print();

    setMatriz();
}

SRC::SRC( Ponto vrp, Ponto focal)
{
    VRP = vrp;
    FOCAL = focal;

    n.PontoToVetor( VRP - FOCAL );
    n.transfUnitario();

    Vetor Y( 0, 1, 0 );
    v = Y - n * ( Y * n );
    v.transfUnitario();

    u = v ^ n;

    n.print();
    v.print();
    u.print();

    setMatriz();
}

void SRC::setMatriz()
{
    Ponto auxVRP( VRP * -1);

    Matriz Translar;
    Translar.matrizTranslar( auxVRP );

    Matriz R;
    R.matrizVetor(n, v, u);

    SRU_SRC = R * Translar;

    SRU_SRC.print();
}

SRC& SRC::operator=(const SRC& cpy)
{
    if( this != &cpy )
    {
        VRP = cpy.VRP;
        FOCAL = cpy.FOCAL;
    }

    return *this;
}

Matriz SRC::getMatriz()
{
    return SRU_SRC;
}

#endif // SRC_H_INCLUDED
