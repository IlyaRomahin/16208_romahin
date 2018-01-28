#include "mainwindow.h"
#include "model.h"
#include "controller.h"
#include "renderarea.h"
#include <string>
#include <QTextStream>
#include <QFileDialog>
#include <QDebug>
#include <QColor>
#include <QColorDialog>
#include <QMessageBox>

Controller::Controller(QWidget *parent, Model *m, MainWindow *w) :
    QWidget(parent),
    model(m),
    view(w)
{
    connect(view, &MainWindow::startButclicked, [this](bool b){startGame(b);});
    connect(view, &MainWindow::stopButclicked, [this](bool b){stopGame(b);});
    connect(view, &MainWindow::clearButclicked, [this](bool b){clear(b);});
    connect(view, &MainWindow::rulesContValueChanged, [this](QString r){setRule(r);});
    connect(view, &MainWindow::iterInterValueChanged, [this](int it){setInterval(it);});
    connect(view, &MainWindow::heightContValueChanged, [this](int h){setHeight(h);});
    connect(view, &MainWindow::widthContValueChanged, [this](int w){setWidth(w);});
    connect(view, &MainWindow::colorButclicked, [this](bool b){selectMasterColor(b);});
    connect(view, &MainWindow::loadButclicked, [this](bool b){loadGame(b);});
    connect(view, &MainWindow::saveButclicked, [this](bool b){saveGame(b);});

    connect(view, &MainWindow::nextGeneration, [this](bool b){newGeneration(b);});
    connect(model, &Model::finishGame, [this](bool b){finishGame(b);});
    connect(model, &Model::lostGame, [this](bool b){lostGame(b);});
    connect(model, &Model::needUpdate, [this](bool b){needUpdate(b);});
    connect(model, &Model::myRule, [this](bool b){myRule(b);});
    connect(model, &Model::notMyRule, [this](bool b){notMyRule(b);});
}

void Controller::selectMasterColor(bool)
{
    view->selectMasterColor();
}

void Controller::finishGame(bool)
{
    QMessageBox::information(this,
                             tr("Game finished."),
                             tr("Iterations finished."),
                             QMessageBox::Ok,
                             QMessageBox::Cancel);
    stopGame(true);
}

void Controller::lostGame(bool)
{
    QMessageBox::information(this,
                                tr("Game lost sense"),
                                tr("The End. Now game finished because all the next generations will be the same."),
                                QMessageBox::Ok);
    stopGame(true);
}

void Controller::needUpdate(bool)
{
    view->setNext(model->getNext());
    view->setUniverse(model->getUniverse());
    view->needUpdate();
}

void Controller::myRule(bool)
{
    view->setEnabledBoxes();}

void Controller::notMyRule(bool)
{
    view->setDisabledBoxes();
}

void Controller::startGame(bool)
{
    model->setUniverse(view->getUniverse());
    model->setNext(view->getNext());
    model->setGenerations(-1);
    view->startGame();
}

void Controller::stopGame(bool)
{
    view->stopGame();
    view->setEnabledSpinBoxes();
}

void Controller::clear(bool)
{
    model->clear();
    needUpdate(true);
    stopGame(true);
}

QString Controller::gameRule()
{
    return QString::fromStdString(model->gameRule());
}

void Controller::setRule(const QString &r)
{
    std::string rule = r.toStdString();
    model->setRule(rule);
}

int Controller::cellsHeight()
{
    return model->heightCellNumber();
}

void Controller::setHeight(const int h)
{
    model->setHeightCellNumber(h);
    view->setHeight(h);
}

int Controller::cellsWidth()
{
    return model->widthCellNumber();
}

void Controller::setWidth(const int w)
{
    model->setWidthCellNumber(w);
    view->setWidth(w);}

void Controller::newGeneration(bool)
{
    model->newGeneration();
}

int Controller::interval()
{
    return view->interval();
}

void Controller::setInterval(const int msec)
{
    view->setInterval(msec);
}

QColor Controller::masterColor()
{
    return view->masterColor();
}

void Controller::setMasterColor(const QColor &color)
{
    view->setMasterColor(color);
}

void Controller::saveGame(bool)
{
    QString filename = QFileDialog::getSaveFileName(this,
                                                    tr("Save current game"),
                                                    QDir::homePath(),
                                                    tr("*.rle"));
    if(filename.length() < 1)
    {
        return;
    }
    QFile file(filename);
    if(!file.open(QIODevice::WriteOnly | QIODevice::Truncate))
    {
        return;
    }
    QString s = "x = " + QString::number(cellsWidth()) + " y = " + QString::number(cellsHeight())
                + " rule = " + gameRule() + "\n";
    file.write(s.toUtf8());
    file.write(QString::fromStdString(model->dump()).toUtf8());
    file.close();
}

void Controller::loadGame(bool)
{
    QString filename = QFileDialog::getOpenFileName(this,
                                                    tr("Open saved game"),
                                                    QDir::homePath(),
                                                    tr("*.rle"));
    if(filename.length() < 1)
    {
        return;
    }
    QFile file(filename);
    if(!file.open(QIODevice::ReadOnly))
    {
        return;
    }
//    QTextStream in(&file);

//    int sv;
//    in >> sv;
//    view->cellsControl->setValue(sv);

//    game->setCellNumber(sv);
//    QString dump="";
//    for(int k=0; k != sv; k++) {
//        QString t;
//        in >> t;
//        dump.append(t+"\n");
//    }
//    game->setDump(dump);

//    int r,g,b; // RGB color
//    in >> r >> g >> b;
//    currentColor = QColor(r,g,b);
//    game->setMasterColor(currentColor); // sets color of the dots
//    QPixmap icon(16, 16); // icon on the button
//    icon.fill(currentColor); // fill with new color
//    view->colorButton->setIcon( QIcon(icon) ); // set icon for button
//    in >> r; // r will be interval number
//    view->iterInterval->setValue(r);
//    game->setInterval(r);
    needUpdate(true);
}
