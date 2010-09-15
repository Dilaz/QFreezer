#include <QtGui/QApplication>
#include "qfreezer.h"

int main(int argc, char *argv[]) {
    QApplication a(argc, argv);
    QFreezer w;
    w.show();
    return a.exec();
}
