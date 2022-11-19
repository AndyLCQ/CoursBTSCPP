#include <QtGui/QApplication>
#include "classeihm.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    classeIHM w;
    w.show();
    
    return a.exec();
}
