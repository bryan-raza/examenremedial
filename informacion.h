#ifndef INFORMACION_H
#define INFORMACION_H

#include <QObject>

class Informacion : public QObject
{
    Q_OBJECT

public:
    explicit Informacion(QObject *parent = nullptr);
    Informacion(float altura, float peso);
    float altura() const;
    float peso() const;

    void setAltura(float altura);

    void setPeso(float peso);

    void calcular();

private:
    float m_altura;
    float m_peso;

signals:

};

#endif // INFORMACION_H
