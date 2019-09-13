#ifndef NodeS_H_INCLUDED
#define NodeS_H_INCLUDED

#include "Ponto.h"

class NodeS {

    private:
        NodeS *next;
        Ponto info;

    public:
        NodeS();
        NodeS(const NodeS&);
        NodeS(NodeS*, const Ponto&);

        void setInfo(const Ponto &);
        Ponto getInfo();
        Ponto* getPointerInfo();

        void setNext(NodeS*);
        NodeS* getNext();

        NodeS& operator=(const NodeS&);

        ~NodeS();

};

#include "NodeS.h"

/**
 * Constructors
 */

NodeS::NodeS()
{
    next = nullptr;
}
NodeS::NodeS(const NodeS &cpy)
{
    next = cpy.next;
    info = cpy.info;
}

NodeS::NodeS(NodeS* ptr, const Ponto& inf)
{
    info = inf;
    next = ptr;
}

/**
 * Setters and Getters
 */

void NodeS::setInfo(const Ponto &inf)
{
    info = inf;
}

Ponto NodeS::getInfo()
{
    return info;
}

Ponto* NodeS::getPointerInfo()
{
    return &info;
}


void NodeS::setNext(NodeS *aux)
{
    next = aux;
}

NodeS* NodeS::getNext()
{
    return next;
}

NodeS& NodeS::operator=(const NodeS &aux)
{

    if(this != &aux)
    {
        info = aux.info;
        next = aux.next;
    }

    return *this;

}

NodeS::~NodeS()
{
    next = nullptr;
}

#endif
