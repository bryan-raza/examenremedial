#include "principal.h"
#include "ui_principal.h"
#include "informacion.h"
#include <QDate>
#include <QDebug>
#include <QDir>
#include <QFileDialog>
#include "datos.h"
#include <QPen>
#include <QPainter>
#include <QPixmap>

Principal::Principal(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::Principal)
{
    ui->setupUi(this);
    QDate vista;
    vista=QDate::currentDate();
    ui->Fecha->setText(vista.toString());
    ui->Resultado->setText("0.0");
    //////////////////////////////////////
    ui->grafica->resize(tall+40,width+20);
    pixmap = QPixmap(ui->grafica->size());
    Entrada(width,10);
    coordenadas(startx, starty, 2,width,tall,Qt::black);
    ui->grafica->setPixmap(pixmap);
}

Principal::~Principal()
{
    delete ui;
}

void Principal::on_Calcular_clicked()
{
    ui->Resultado->setText(QString::number(ui->peso->value()/(ui->altura->value()*ui->altura->value())));
}
void Principal::on_Imprimir_clicked()
{
     QString altura=ui->altura->text();
     QString peso=ui->peso->text();
     QString imc=ui->Resultado->text();
     QString datos="Peso Actual: "+peso+"kg"+"\n"+
                   "Peso Maximo: "+peso+"kg"+"\n"+
                   "Peso Minimo: "+peso+"kg"+"\n"+
                   "Altura Actual: "+altura+"cm"+"\n"+
                   "IMC: "+imc;
    ui->out_texto->setPlainText(datos);
    if(imc<17){
       painter.setBrush(Qt::gray);
    }else if(imc<19){
       painter.setBrush(Qt::blue);
    }else if(imc<26){
       painter.setBrush(Qt::green);
    }else if(imc<31){
       painter.setBrush(Qt::yellow);
    }else if(imc<36){
       painter.setBrush(Qt::darkYellow);
    }else{
       painter.setBrush(Qt::red);
   }
   painter.setPen(pen);
   ui->grafica->setPixmap(pixmap);
}
///////////////////////////////////////////////////////////////////////////
void Principal::Entrada(int width, int tall)
{
    pixmap.fill(Qt::white);
    painter.begin(&pixmap);
    pen.setColor(Qt::black);
    dialogo((width / 3), tall+15, "", 15);
}

void Principal::dialogo(int x, int y, QString dialogue, int size)
{
    painter.setPen(pen);
    QFont font = painter.font();
    font.setPixelSize(size);
    painter.setFont(font);
    painter.drawText(x,y,dialogue);
}

void Principal::coordenadas(int startx, int starty, int thickness, int width, int tall, QColor color)
{
    pen.setWidth(thickness);
    pen.setColor(Qt::red);
    pen.setJoinStyle(Qt::MiterJoin);
    painter.setPen(pen);
    painter.drawLine(startx,starty-40,startx,tall);
    dialogo(startx-12, 2, "", 16);
    painter.drawLine(startx,tall,width,tall);
    dialogo(width, tall+10, "", 16);
    painter.drawLine(startx +0,tall/2,12,tall/2);
    pen.setColor(Qt::black);
    dialogo(0, tall/1.05, "16", 8);
    dialogo(0, tall/1.3, "18.5", 8);
    dialogo(0, tall/1.6, "25", 8);
    dialogo(0, tall/2, "30", 8);
    dialogo(0, tall/2.9, "35", 8);
    dialogo(0, tall/4.2, "40", 8);
}
void Principal::barras(int displacement, int startx, int starty, int tall, int note, QString name)
{
    painter.setPen(pen);
             starty= tall -((tall*note)/100)+70;
    dialogo(startx+18+displacement, starty-8, name, 11);
    dialogo(startx+18+displacement, starty-20, QString::number(note), 10);
    painter.drawRect(startx+20+displacement, starty, 20,tall - starty);
}

void Principal::lineas(int startx, int tall, int average)
{
    painter.setBrush(Qt::green);
    painter.setPen(pen);
    int value;
       if (average==50)
          value=-(tall/2);
       else
          value= tall -((tall*average)/100)+15;
    painter.drawRect(startx+18, value ,width-20,1);
    dialogo(startx+18, value+18 ,QString::number(average), 10);
}

void Principal::guardar()
{
    QString temportal=QDir::home().absolutePath();
    qDebug()<<temportal;
    QString nombreArchivo = QFileDialog::getSaveFileName(this, ("Guardar Configuracion "),
                                                      temportal,
                                                      ("Archivos de configuracion (*.csv)"));
     QFile data(nombreArchivo);
     if (data.open(QFile::WriteOnly | QFile::Truncate)) {
      QTextStream out(&data);
      out<<ui->out_texto->toPlainText();
      qDebug() << "Archivo almacenado en:" << nombreArchivo;
      //Cerrando el archivo
      data.close();
     }
}
void Principal::on_Guardar_clicked(){
    guardar();
}
