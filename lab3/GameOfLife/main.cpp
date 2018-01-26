#include <QApplication>
#include "mainwindow.h"
#include "model.h"
#include "controller.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow w;
    Model m;
    Controller(nullptr, &m, &w);
    w.show();
    
    return app.exec();
}
