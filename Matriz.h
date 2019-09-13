#ifndef MATRIZ_H_INCLUDED
#define MATRIZ_H_INCLUDED

#include <cmath>
#include <iostream>
#include <vector>
#include "time.h"
#include <iomanip>
#include "Ponto.h"
#include "ListS.h"
#include <string>
#include <math.h>
#include "Vetor.h"

using namespace std;

class Matriz {

    private:

        int N;
        int M;

        void destructor();

    public:

        double **MATRIZ;
        Matriz();
        Matriz(int m, int n);
        Matriz(const Matriz&);

        int getN();
        int getM();
        void setN(int);
        void setM(int);
        void set(int, int);

        void generateRandom();
        void print();

        void polygonPoints(ListS &);
        void translar( Ponto& A);
        void matrizTranslar( Ponto& A );
        void rotateX( double& );
        void rotateY( double& );
        void rotateZ( double& );
        void matrizRotateX( double& );
        void matrizRotateY( double& );
        void matrizRotateZ( double& );
        void matrizVetor( Vetor, Vetor, Vetor);
        void applyScale( double& );
        void matrizScale( double& );
        void transpose();
        Ponto getPonto(const int&, vector<string> &tagPontos);

        Matriz  operator+(const Matriz&);
        Matriz  operator-(const Matriz&);
        Matriz  operator*(const Matriz&);
        Matriz& operator=(const Matriz&);
        ~Matriz();

};

///==================
///  Construtores
///==================

/**
 * Construtor Vazio
 */

Matriz::Matriz(){
    N = 0;
    M = 0;
}

/**
 * Construtor que inicializa uma matriz M x N
 *
 * @param m número de linhas, n número de colunas
 */

Matriz::Matriz(int m, int n){
    M = m;
    N = n;
    MATRIZ = new double*[M];
    for(int i = 0; i < M; i++)
        MATRIZ[i] = new double[N];
}

/**
 * Construtor de cópia
 *
 * @param uma Matriz qualquer
 */

Matriz::Matriz(const Matriz& cpy){
    N = cpy.N;
    M = cpy.M;
    MATRIZ = new double*[M];
    for(int i = 0; i < M; i++)
        MATRIZ[i] = new double[N];

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++)
            MATRIZ[i][j] = cpy.MATRIZ[i][j];
    }
}

///==================
///  Sets and Gets
///==================

int Matriz::getN(){
    return N;
}

int Matriz::getM(){
    return M;
}

void Matriz::setN(int n){
    destructor();
    N = n;

    MATRIZ = new double*[M];
    for(int i = 0; i < M; i++)
        MATRIZ[i] = new double[N];
}

void Matriz:: setM(int m){
    destructor();
    M = m;

    MATRIZ = new double*[M];
    for(int i = 0; i < M; i++)
        MATRIZ[i] = new double[N];
}

/**
 * Cria uma Matriz M x N
 *
 * @param m número de linhas, n número de colunas
 */

void Matriz:: set(int m, int n){
    destructor();
    N = n;
    M = m;

    MATRIZ = new double*[M];
    for(int i = 0; i < M; i++)
        MATRIZ[i] = new double[N];
}

///==================
///  Transformações
///==================

/**
 * Translada uma Matriz de Ponto(s) em relação a um Ponto A
 *
 * @param Ponto onde a matriz será transladada
 */

void Matriz::translar( Ponto &A )
{
    Matriz Trans;
    Trans.matrizTranslar( A );

    cout << "Matriz Pontos: \n\n";

    print();

    cout << "Matriz Transposta: \n\n";

    Trans.print();

    *this = Trans * (*this);

    cout << "Matriz Pontos depois da multiplicação: \n\n";

    print();
}

/**
 * Cria uma Matriz de translação em relação a um Ponto A
 *
 * @param Ponto onde a matriz será transladada
 */

void Matriz::matrizTranslar( Ponto &A )
{
    set(4,4);

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){

            if(i == j)
                MATRIZ[i][j] = 1;
            else
                MATRIZ[i][j] = 0;

        }
    }

    MATRIZ[0][3] = A.getX();
    MATRIZ[1][3] = A.getY();
    MATRIZ[2][3] = A.getZ();
}

/**
 * Rotaciona uma Matriz de Ponto(s) em X em relação a um ângulo
 *
 * @param ângulo de rotação
 */

void Matriz::rotateX( double &angle )
{
    Matriz RotateX;
    RotateX.matrizRotateX( angle );

    cout << "Matriz Pontos: \n\n";

    print();

    cout << "Matriz RotateX: \n\n";

    RotateX.print();

    *this = RotateX * (*this);

    cout << "Matriz Pontos depois da multiplicação: \n\n";

    print();
}

/**
 * Cria uma Matriz de rotação em X baseado em um ângulo
 *
 * @param valor do ângulo de rotação
 */

void Matriz::matrizRotateX( double &angle )
{
    set(4,4);

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){

            if(i == j)
                MATRIZ[i][j] = 1;
            else
                MATRIZ[i][j] = 0;

        }
    }

    MATRIZ[1][1] = MATRIZ[2][2] = cos(angle);
    MATRIZ[1][2] = sin(angle);
    MATRIZ[2][1] = -sin(angle);
}

/**
 * Rotaciona uma Matriz de Ponto(s) em Y em relação a um ângulo
 *
 * @param ângulo de rotação
 */

void Matriz::rotateY( double &angle )
{
    Matriz RotateY;
    RotateY.matrizRotateY( angle );

    cout << "Matriz Pontos: \n\n";

    print();

    cout << "Matriz RotateX: \n\n";

    RotateY.print();

    *this = RotateY * (*this);

    cout << "Matriz Pontos depois da multiplicação: \n\n";

    print();
}

/**
 * Cria uma Matriz de rotação em Y baseado em um ângulo
 *
 * @param valor do ângulo de rotação
 */

void Matriz::matrizRotateY( double &angle )
{
    set(4,4);

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){

            if(i == j)
                MATRIZ[i][j] = 1;
            else
                MATRIZ[i][j] = 0;

        }
    }

    MATRIZ[0][0] = MATRIZ[2][2] = cos(angle);
    MATRIZ[0][2] = sin(angle);
    MATRIZ[2][0] = -sin(angle);
}

/**
 * Rotaciona uma Matriz de Ponto(s) em Z em relação a um ângulo
 *
 * @param ângulo de rotação
 */

void Matriz::rotateZ( double &angle )
{
    Matriz RotateZ;
    RotateZ.matrizRotateZ( angle );

    cout << "Matriz Pontos: \n\n";

    print();

    cout << "Matriz RotateX: \n\n";

    RotateZ.print();

    *this = RotateZ * (*this);

    cout << "Matriz Pontos depois da multiplicação: \n\n";

    print();
}

/**
 * Cria uma Matriz de rotação em Y baseado em um ângulo
 *
 * @param valor do ângulo de rotação
 */

void Matriz::matrizRotateZ( double &angle )
{
    set(4,4);

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){

            if(i == j)
                MATRIZ[i][j] = 1;
            else
                MATRIZ[i][j] = 0;

        }
    }

    MATRIZ[0][0] = MATRIZ[1][1] = cos(angle);
    MATRIZ[1][0] = sin(angle);
    MATRIZ[0][1] = -sin(angle);
}

/**
 * Aplica uma escala a uma Matriz de Ponto(s)
 *
 * @param valor escalar
 */

void Matriz::applyScale( double &scale )
{
    Matriz Scale;
    Scale.matrizScale( scale );

    cout << "Matriz Pontos: \n\n";

    print();

    cout << "Matriz RotateX: \n\n";

    Scale.print();

    *this = Scale * (*this);

    cout << "Matriz Pontos depois da multiplicação: \n\n";

    print();
}

/**
 * Cria uma Matriz de escala baseado em um valor escalar
 *
 * @param valor escalar
 */

void Matriz::matrizScale( double &scale )
{
    set(4,4);

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){

            if(i == j)
                MATRIZ[i][j] = 1;
            else
                MATRIZ[i][j] = 0;

        }
    }

    MATRIZ[0][0] = MATRIZ[1][1] = MATRIZ[2][2] = scale;
}

/**
 * Cria uma Matriz de vetores ( usada na transformação SRU -> SRC )
 *
 * @param vetores n, v, u
 */

void Matriz::matrizVetor( Vetor n, Vetor v, Vetor u )
{
    set(4,4);

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){

            if(i == j)
                MATRIZ[i][j] = 1;
            else
                MATRIZ[i][j] = 0;

        }
    }

    MATRIZ[0][0] = u.getX();
    MATRIZ[0][1] = u.getY();
    MATRIZ[0][2] = u.getZ();

    MATRIZ[1][0] = v.getX();
    MATRIZ[1][1] = v.getY();
    MATRIZ[1][2] = v.getZ();

    MATRIZ[2][0] = n.getX();
    MATRIZ[2][1] = n.getY();
    MATRIZ[2][2] = n.getZ();
}

/**
 * Transforma uma coluna de uma Matriz de Pontos em um Ponto
 *
 * @param index número da coluna
 * @return Ponto referente a coluna
 */

Ponto Matriz::getPonto( const int& index, vector<string> &tagPontos )
{
    return( Ponto( tagPontos.at(index), MATRIZ[0][index], MATRIZ[1][index], MATRIZ[2][index] ) );
}

/**
 * Cria uma Matriz de Pontos pertencentes a um Polígono
 *
 * @param vector contendo todos os Pontos do Polígono
 */

void Matriz::polygonPoints( ListS &pontos )
{
    set( 4, pontos.getSize() );

    for( int i = 0 ; i < N ; i++ )
    {
        MATRIZ[0][i] = pontos.at( i ).getX();
        MATRIZ[1][i] = pontos.at( i ).getY();
        MATRIZ[2][i] = pontos.at( i ).getZ();
        MATRIZ[3][i] = 1;
    }
}

/**
 * Transpõe a Matriz
 */
void Matriz::transpose()
{
    if( N != M )
        return;

    Matriz aux(*this);

    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            MATRIZ[i][j] = aux.MATRIZ[j][i];
        }

    }
}

///==================
///  Auxiliares
///==================

/**
 * Limpa uma Matriz
 */

void Matriz:: destructor()
{
    if(!N || !M)
        return;

    for(int i = 0; i < M; i++)
        delete[] MATRIZ[i];
    delete[] MATRIZ;
}

/**
 * Imprime uma Matriz
*/

void Matriz::print()
{
    printf("|");

    for( int i = 0; i < M; i++ )
    {
        for( int j = 0; j < N; j++ )
        {
            cout << setw(10) << MATRIZ[i][j];

            if( j == (N - 1) )
            {
                printf("  |");
                cout << endl;
                if( i != (M - 1) )
                    printf("|");
            }
        }
    }

    cout << endl;
}

/**
 * Preenche a Matriz com valores aleatórios
 */

void Matriz::generateRandom()
{
    for( int i = 0 ; i < M ; i++ ){
        for( int j = 0 ; j < N ; j++ )
            MATRIZ[i][j] = rand() % 10;
    }
}

///==================
///  Sobrecarga de Operadores
///==================

Matriz Matriz::operator+( const Matriz& b )
{
    if( N != b.N && M != b.M )
        return *this;

    Matriz temp(M, N);

    for( int i = 0 ; i < M ; i++ ){
        for( int j = 0 ; j < N ; j++ )
            temp.MATRIZ[i][j] = MATRIZ[i][j] + b.MATRIZ[i][j];
    }

    return temp;
}

Matriz Matriz::operator-( const Matriz& b )
{
    if( N != b.N && M != b.M )
        return *this;

    Matriz temp;

    temp.set(M, N);

    for( int i = 0 ; i < M ; i++ ){
        for( int j = 0 ; j < N ; j++ )
            temp.MATRIZ[i][j] = MATRIZ[i][j] - b.MATRIZ[i][j];
    }

    return temp;
}

Matriz& Matriz::operator=( const Matriz& b )
{
    set(b.M, b.N);

    for( int i = 0 ; i < M ; i++ ){
        for( int j = 0 ; j < N ; j++ ){
            double a = b.MATRIZ[i][j];
            MATRIZ[i][j] = a;
        }
    }

    return *this;
}

Matriz Matriz::operator*( const Matriz& b ){
    if( N != b.M )
        return *this;

    double aux = 0;
    Matriz temp(M, b.N);

    for ( int i = 0 ; i < M ; i++) {
            for ( int j = 0 ; j < b.N ; j++ ) {
                for ( int k = 0 ; k < b.M ; k++ )
                {
                    aux += MATRIZ[i][k] * b.MATRIZ[k][j];
                    if(k == N-1){
                        temp.MATRIZ[i][j] = aux;
                        aux = 0;
                    }
                }
            }
        }

    return temp;
}

Matriz::~Matriz(){
    destructor();
}





#endif // MATRIZ_H_INCLUDED
