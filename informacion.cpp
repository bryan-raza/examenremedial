#include "informacion.h"

Informacion::Informacion(QObject *parent) : QObject(parent)
{

}

Informacion::Informacion(float altura, float peso)
{
    this->m_peso=peso;
    this->m_altura=altura;
}

float Informacion::altura() const
{
    return m_altura;
}

float Informacion::peso() const
{
    return m_peso;
}

void Informacion::setAltura(float altura)
{
    m_altura = altura;
}

void Informacion::setPeso(float peso)
{
    m_peso = peso;
}

/*void Informacion::calcular()
{
    float imcs;
    imcs=m_peso/(m_altura*m_altura);
}*/
