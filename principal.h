#ifndef PRINCIPAL_H
#define PRINCIPAL_H

#include <QMainWindow>
#include <QPen>
#include <QPainter>
#include <QPixmap>
QT_BEGIN_NAMESPACE
namespace Ui { class Principal; }
QT_END_NAMESPACE

class Principal : public QMainWindow
{
    Q_OBJECT

public:
    Principal(QWidget *parent = nullptr);
    ~Principal();
    ///////////////////////////////////
    void Entrada(int width, int tall);
    void dialogo(int x, int y, QString dialogue, int size);
    void coordenadas(int startx,int starty, int thickness, int width, int tall, QColor color);
    void barras(int displacement,int startx, int starty, int tall, int note, QString name);
    void lineas(int startx, int tall, int average);
    void dibujar();
    void guardar();
    int width=400;
    int tall=400;
    int startx=50;
    int starty=85;

private slots:
    void on_Calcular_clicked();
    void on_Guardar_clicked();
    void on_Imprimir_clicked();

private:
    Ui::Principal *ui;
    QPixmap pixmap;
    QPen pen;
    QPainter painter;
};
#endif // PRINCIPAL_H
