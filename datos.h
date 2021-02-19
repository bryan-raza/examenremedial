#ifndef DATOS_H
#define DATOS_H

#include <QDialog>
#include <QPen>
#include <QPainter>
#include <QPixmap>
namespace Ui {
class Datos;
}

class Datos : public QDialog
{
    Q_OBJECT
    Q_PROPERTY(QString dato READ dato WRITE setDato)

public:
    explicit Datos(QWidget *parent = nullptr);
    ~Datos();
    QString dato() const;
    void setDato(const QString &dato);

    void actualizar();
    /////////////////////////////////////////////////
    void Enterokay(int width, int tall);
    void dialogue(int x, int y, QString dialogue, int size);
    void coordinates(int startx,int starty, int thickness, int width, int tall, QColor color);
    void bar(int displacement,int startx, int starty, int tall, int note, QString name);
    void lines(int startx, int tall, int average);
    void dibujar();
    int width=400;
    int tall=400;
    int startx=50;
    int starty=85;


private:
    Ui::Datos *ui;
    QString m_dato;
    //////////////
    QPixmap pixmap;
    QPen pen;
    QPainter painter;
};

#endif // DATOS_H
