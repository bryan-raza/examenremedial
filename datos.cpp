#include "datos.h"
#include "ui_datos.h"
#include <QPainter>
#include<QPixmap>
Datos::Datos(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Datos)
{
    ui->setupUi(this);
    ui->out_grafica->resize(tall+40,width+20);
    pixmap = QPixmap(ui->out_grafica->size());
    Enterokay(width,10);
    coordinates(startx, starty, 2,width,tall,Qt::black);
    ui->out_grafica->setPixmap(pixmap);
}

Datos::~Datos()
{
    delete ui;
}
QString Datos::dato() const
{
    return m_dato;
}

void Datos::setDato(const QString &dato)
{
    m_dato = dato;
}

void Datos::actualizar()
{
    ui->out_texto->setPlainText(m_dato);
    ui->out_grafica->setPixmap(pixmap);
}
////////////////////////////////////////////////////////////////
void Datos::Enterokay(int width, int tall)
{
    pixmap.fill(Qt::white);
    painter.begin(&pixmap);
    pen.setColor(Qt::black);
    dialogue((width / 3), tall+15, "Resultados IMC", 15);
      ui->out_grafica->setPixmap(pixmap);
}

void Datos::dialogue(int x, int y, QString dialogue, int size)
{
    painter.setPen(pen);
    QFont font = painter.font();
    font.setPixelSize(size);
    painter.setFont(font);
    painter.drawText(x,y,dialogue);
    ui->out_grafica->setPixmap(pixmap);
}

void Datos::coordinates(int startx, int starty, int thickness, int width, int tall, QColor color)
{
    pen.setWidth(thickness);
    pen.setColor(Qt::red);
    pen.setJoinStyle(Qt::MiterJoin);
    painter.setPen(pen);
    painter.drawLine(startx,starty-40,startx,tall);
    dialogue(startx-12, 2, "", 16);
    painter.drawLine(startx,tall,width,tall);
    dialogue(width, tall+10, "", 16);
    painter.drawLine(startx +0,tall/2,12,tall/2);
    pen.setColor(Qt::black);
    dialogue(0, tall/1.05, "16", 8);
    dialogue(0, tall/1.3, "18.5", 8);
    dialogue(0, tall/1.6, "25", 8);
    dialogue(0, tall/2, "30", 8);
    dialogue(0, tall/2.9, "35", 8);
    dialogue(0, tall/4.2, "40", 8);
    ui->out_grafica->setPixmap(pixmap);
}


void Datos::bar(int displacement, int startx, int starty, int tall, int note, QString name)
{
   // QString imc;
    if(note<17){
       painter.setBrush(Qt::gray);
    }else if(note<19){
       painter.setBrush(Qt::blue);
    }else if(note<26){
       painter.setBrush(Qt::green);
    }else if(note<31){
       painter.setBrush(Qt::yellow);
    }else if(note<36){
       painter.setBrush(Qt::darkYellow);
    }else{
       painter.setBrush(Qt::red);
   }
    painter.setPen(pen);
             starty= tall -((tall*note)/100)+70;
    dialogue(startx+18+displacement, starty-8, name, 11);
    dialogue(startx+18+displacement, starty-20, QString::number(note), 10);
    painter.drawRect(startx+20+displacement, starty, 20,tall - starty);
    ui->out_grafica->setPixmap(pixmap);
}

void Datos::lines(int startx, int tall, int average)
{
    painter.setBrush(Qt::green);
    painter.setBrush(Qt::yellow);
    painter.setBrush(Qt::gray);
    painter.setBrush(Qt::blue);
    painter.setBrush(Qt::darkYellow);
    painter.setBrush(Qt::red);
    pen.setColor(Qt::black);
    painter.setPen(pen);
    int value;
       if (average==50)
          value=-(tall/2);
       else
          value= tall -((tall*average)/100)+15;
    painter.drawRect(startx+18, value ,width-20,1);
    dialogue(startx+18, value+18 ,QString::number(average), 10);
    ui->out_grafica->setPixmap(pixmap);
}

void Datos::dibujar()
{
    painter.setPen(pen);
    ui->out_grafica->setPixmap(pixmap);
}

