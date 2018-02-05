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
#include <iostream>

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
    connect(view, &MainWindow::environmentChanged, [this](bool b){updateModel(b);});
    connect(view, &MainWindow::needCheck, [this](std::vector<bool> birth, std::vector<bool> life){check(birth, life);});
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

void Controller::updateModel(bool)
{
    model->setUniverse(view->getUniverse());
    model->setNext(view->getNext());
}

void Controller::myRule(bool)
{
    view->setEnabledBoxes();
}

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

void Controller::check(std::vector<bool> birth, std::vector<bool> life)
{
    model->setBirth(birth);
    model->setLife(life);
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
    QTextStream in(&file);
    QString articleQ = in.readLine();
    std::string article = articleQ.toStdString();
    std::size_t foundx = article.find(" y = ");
    std::size_t foundy = article.find(" rule = ");
    std::string cws = article.substr(4, foundx - 4);
    std::string chs = article.substr(foundx + 5, foundy - 11);
    std::string fRule = article.substr(foundy + 8, article.length());
    std::cout << cws << std::endl;
    std::cout << chs << std::endl;
    std::cout << fRule << std::endl;
    int cw = std::stoi(cws);
    int ch = std::stoi(chs);
    view->setCellsWidth(cw);
    view->setCellsHeight(ch);
    view->setRule(fRule);
    QString dumpQ = in.readLine();
    std::string dump = dumpQ.toStdString();
    model->setDump(dump);
    needUpdate(true);
}
