#ifndef LISTS_H_INCLUDED
#define LISTS_H_INCLUDED

#include "NodeS.h"
#include <iostream>
#include <string>

class ListS {

    private:

        NodeS *head, *tail;
        int size;

    public:

        ListS();
        ListS(const ListS&);

        bool addHead(const Ponto&);
        bool addTail(const Ponto&);
        Ponto removeHead();
        Ponto removeTail();
        int getSize();
        Ponto* getTailInfo();
        Ponto& at( const int& );
        Ponto* getPontobyTag( string );

        void print();

        bool isEmpty();
        void removeList();

        ~ListS();

        ListS& operator=(const ListS&);
};


ListS::ListS()
{
    head = nullptr;
    tail = nullptr;
    size = 0;
}

ListS::ListS( const ListS &cpy )
{
    NodeS *aux = cpy.head;

    while( aux != nullptr )
    {
        addHead( aux->getInfo() );
        aux = aux->getNext();
    }
}

bool ListS::isEmpty()
{
    return (size == 0);
}

bool ListS::addHead( const Ponto &inf )
{
    if( isEmpty() )
    {
        NodeS *newNode = new NodeS( nullptr, inf );
        head = tail = newNode;
        size++;

        return true;
    } else
    {
        NodeS *aux = head;
        NodeS *newNode = new NodeS( aux, inf );
        head = newNode;
        size++;

        return true;
    }

    return false;
}

Ponto ListS::removeHead()
{
    if(size != 0)
    {
        NodeS *aux = head;
        Ponto inf = aux->getInfo();

        if(size == 1)
        {
            delete aux;
            head = nullptr;
            tail = nullptr;
        }

        else
        {
            head = aux->getNext();
            delete aux;
        }

        size--;
        return inf;
    }

    cout << "Ponto n�o existe. Retornando um Ponto (0, 0, 0)\n\n";

    return Ponto(0, 0, 0);
}

 bool ListS::addTail( const Ponto &inf )
{
    NodeS *aux = tail;

    if( isEmpty() )
    {
        addHead( inf );
        return true;
    }
    else
    {
        NodeS *newNode = new NodeS( nullptr, inf );
        aux->setNext( newNode );
        tail = newNode;
        size++;
        return true;
    }

    return false;
}

 Ponto ListS::removeTail()
{
    if(size != 0)
    {
        NodeS *aux = head;
        Ponto inf = tail->getInfo();

        if(size == 1)
        {
            removeHead();
        }

        else
        {
            while( aux->getNext()->getNext() != nullptr )
                aux = aux->getNext();

            delete tail;
            tail = aux;
            aux->setNext( nullptr );
            size--;
        }

        return inf;
    }

    cout << "Ponto n�o existe. Retornando um Ponto (0, 0, 0)\n\n";

    return Ponto(0, 0, 0);
}

int ListS::getSize()
{
    return size;
}


Ponto* ListS::getTailInfo()
{
    return tail->getPointerInfo();
}

Ponto* ListS::getPontobyTag( string TAG )
{
    NodeS *aux = head;

    while( aux != nullptr)
    {
        if( aux->getInfo().getTag() == TAG )
            return aux->getPointerInfo();

        aux = aux->getNext();
    }

    return nullptr;
}

Ponto& ListS::at( const int &index )
{
    if(size == 0 || index < 0)
        cout << "Acesso de ponteiro inválido\n";

    NodeS *aux = head;
    int counter = 0;

    while( counter != index){
        counter++;
        aux = aux->getNext();
    }

    Ponto &A = *aux->getPointerInfo();

    return A;
}

void ListS::print()
{
    NodeS *aux = head;

    std::cout << "Lista de Pontos:\n\n";

    while ( aux != nullptr )
    {
        aux->getInfo().print();
        cout << endl;
        aux = aux->getNext();
    }

    std::cout << "\n\n";
}

void ListS::removeList()
{
    NodeS *aux = head;
    NodeS *deleter;

    while( aux != nullptr )
    {
        deleter = aux;
        aux = aux->getNext();
        delete deleter;
    }
}

 ListS::~ListS()
{
    removeList();
}

 ListS& ListS::operator=(const ListS &cpy)
{
    if( this != &cpy )
    {
        removeList();

        NodeS *aux = cpy.head;

        while( aux != nullptr )
        {
            addHead( aux->getInfo() );
            aux = aux->getNext();
        }

    }

    return *this;
}

#endif
