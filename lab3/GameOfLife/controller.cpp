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
    connect(w->startBut(), SIGNAL(clicked()), this, SLOT(startGame()));
    connect(w->stopBut(), SIGNAL(clicked()), this, SLOT(stopGame()));
    connect(w->clearBut(), SIGNAL(clicked()), this, SLOT(clear()));
    connect(w->rulesCont(), SIGNAL(currentTextChanged(QString)), this, SLOT(setRule(QString)));
    connect(w->iterInter(), SIGNAL(valueChanged(int)), this, SLOT(setInterval(int)));
    connect(w->heightCont(), SIGNAL(valueChanged(int)), this, SLOT(setHeight(int)));
    connect(w->widthCont(), SIGNAL(valueChanged(int)), this, SLOT(setWidth(int)));
    connect(w->colorBut(), SIGNAL(clicked()), this, SLOT(selectMasterColor()));
    connect(w->loadBut(), SIGNAL(clicked()), this, SLOT(loadGame()));
    connect(w->saveBut(), SIGNAL(clicked()), this, SLOT(saveGame()));

    connect(view, SIGNAL(nextGeneration()), this, SLOT(newGeneration()));
    connect(model, SIGNAL(finishGame()), this, SLOT(finishGame()));
    connect(model, SIGNAL(lostGame()), this, SLOT(lostGame()));
    connect(model, SIGNAL(needUpdate()), this, SLOT(needUpdate()));
}

Controller::~Controller()
{
    delete model;
    delete view;
}

void Controller::selectMasterColor()
{
    view->selectMasterColor();
}

void Controller::finishGame()
{
    QMessageBox::information(this,
                             tr("Game finished."),
                             tr("Iterations finished."),
                             QMessageBox::Ok,
                             QMessageBox::Cancel);
    stopGame();
    emit(gameEnds(true));
}

void Controller::lostGame()
{
    QMessageBox::information(this,
                                tr("Game lost sense"),
                                tr("The End. Now game finished because all the next generations will be the same."),
                                QMessageBox::Ok);
    stopGame();
    emit(gameEnds(true));
}

void Controller::needUpdate()
{
    view->needUpdate();
}

void Controller::startGame()
{
    model->setGenerations(-1);
    view->startGame();
}

void Controller::stopGame()
{
    view->stopGame();
}

void Controller::clear()
{
    model->clear();
    emit(gameEnds(true));
    view->clear();
}

QString Controller::gameRule()
{
    return QString::fromStdString(model->gameRule());
}

void Controller::setRule(const QString &r)
{
    std::string rule = r.toStdString();
    model->setRule(rule);
    view->setRule();
}

int Controller::cellsHeight()
{
    return model->heightCellNumber();
}

void Controller::setHeight(const int h)
{
    model->setHeightCellNumber(h);
    view->setHeight();
}

int Controller::cellsWidth()
{
    return model->widthCellNumber();
}

void Controller::setWidth(const int w)
{
    model->setWidthCellNumber(w);
    view->setWidth();
}

void Controller::newGeneration()
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

void Controller::saveGame()
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

void Controller::loadGame()
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
    view->loadGame();
}
