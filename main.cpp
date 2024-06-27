#include "fouriertransformapp.h"
#include <QLabel>
#include <QApplication>
#include <QPainter>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    FourierTransformApp appka;
    appka.show();

    return a.exec();
}
