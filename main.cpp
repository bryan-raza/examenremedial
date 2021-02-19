#include "principal.h"
#include <QTranslator>
#include <QApplication>
#include <QInputDialog>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    QTranslator t;
    QStringList langs;
    langs<<"Español"<<"Portugues"<<"English"<<"Italiano";
    const QString lang= QInputDialog::getItem(NULL,
                                               "Lenguaje",
                                               "Selecciones un lenguaje",
                                               langs);
    if(lang=="Portugues"){
        t.load(":/portugues.qm");
    }else if(lang=="English"){
        t.load(":/ingles.qm");
    }else if(lang=="Italiano"){
        t.load(":/italiano.qm");
    }
    if(lang!="Español"){
        a.installTranslator(&t);
    }
    Principal w;
    w.show();
    return a.exec();
}
