#include <QTextStream>
#include <QFileDialog>
#include <QDebug>
#include <QColor>
#include <QColorDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

#include<iostream>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    currentColor(QColor("#000")),
    field(new RenderArea(this))
{
    ui->setupUi(this);

    QPixmap icon(16, 16);
    icon.fill(currentColor);
    ui->colorButton->setIcon( QIcon(icon) );

    connect(ui->startButton, SIGNAL(clicked()), this, SLOT(startBut()));
    connect(ui->stopButton, SIGNAL(clicked()), this, SLOT(stopBut()));
    connect(ui->clearButton, SIGNAL(clicked()), this, SLOT(clearBut()));
    connect(ui->rulesControl, SIGNAL(currentTextChanged(QString)), this, SLOT(rulesCont(QString)));
    connect(ui->iterInterval, SIGNAL(valueChanged(int)), this, SLOT(iterInter(int)));
    connect(ui->heightControl, SIGNAL(valueChanged(int)), this, SLOT(heightCont(int)));
    connect(ui->widthControl, SIGNAL(valueChanged(int)), this, SLOT(widthCont(int)));
    connect(ui->colorButton, SIGNAL(clicked()), this, SLOT(colorBut()));
    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(loadBut()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveBut()));

    connect(field, SIGNAL(gameEnds(bool)), ui->rulesControl, SLOT(setEnabled(bool)));
    connect(field, SIGNAL(gameEnds(bool)), ui->heightControl, SLOT(setEnabled(bool)));
    connect(field, SIGNAL(gameEnds(bool)), ui->widthControl, SLOT(setEnabled(bool)));
    connect(field, SIGNAL(environmentChanged(bool)), ui->heightControl, SLOT(setDisabled(bool)));
    connect(field, SIGNAL(environmentChanged(bool)), ui->widthControl, SLOT(setDisabled(bool)));
    connect(field, SIGNAL(nextGeneration(bool)), this, SLOT(newGeneration(bool)));

    ui->rulesControl->addItem( "Conway`s" );
    ui->rulesControl->addItem( "HighLife" );
    ui->rulesControl->addItem( "Day & Night" );
    ui->rulesControl->addItem( "Life without Death" );
    ui->rulesControl->addItem( "Seeds" );
    ui->rulesControl->addItem( "Your rule" );

    ui->mainLayout->setStretchFactor(ui->gameLayout, 8);
    ui->mainLayout->setStretchFactor(ui->setLayout, 2);
    ui->gameLayout->addWidget(field);
}

MainWindow::~MainWindow()
{
    delete ui;
    delete field;
}

void MainWindow::startGame()
{
    field->startGame();
}

void MainWindow::stopGame()
{
    field->stopGame();
}

std::vector<bool> &MainWindow::getUniverse()
{
    return field->getUniverse();
}

std::vector<bool> &MainWindow::getNext()
{
    return field->getNext();
}

void MainWindow::setNext(std::vector<bool> &n)
{
    field->setNext(n);
}

void MainWindow::setUniverse(std::vector<bool> &u)
{
    field->setUniverse(u);
}

void MainWindow::setHeight(const int h)
{
    field->setHeight(h);
}

void MainWindow::setWidth(const int w)
{
    field->setWidth(w);
}

void MainWindow::needUpdate()
{
    field->needUpdate();
}

void MainWindow::newGeneration(bool)
{
    emit(nextGeneration(true));
}

int MainWindow::interval()
{
    return field->interval();
}

void MainWindow::setInterval(const int msec)
{
    field->setInterval(msec);
}

void MainWindow::startBut()
{
    emit startButclicked(true);
    std::cout << "bnbnj" << std::endl;
}

void MainWindow::stopBut()
{
    emit(stopButclicked(true));
}

void MainWindow::clearBut()
{
    emit(clearButclicked(true));
}

void MainWindow::saveBut()
{
    emit(saveButclicked(true));
}

void MainWindow::loadBut()
{
    emit(loadButclicked(true));
}

void MainWindow::colorBut()
{
    emit(colorButclicked(true));
}

void MainWindow::rulesCont(QString r)
{
    emit(rulesContValueChanged(r));
}

void MainWindow::iterInter(int it)
{
    emit(iterInterValueChanged(it));
}

void MainWindow::heightCont(int h)
{
    emit(heightContValueChanged(h));
}

void MainWindow::widthCont(int w)
{
    emit(widthContValueChanged(w));
}

QColor MainWindow::masterColor()
{
    return field->masterColor();
}

void MainWindow::setMasterColor(const QColor &color)
{
    field->setMasterColor(color);
}

void MainWindow::selectMasterColor()
{
    QColor color = QColorDialog::getColor(currentColor, this, tr("Select color of figures"));
    if(!color.isValid())
        return;
    currentColor = color;
    field->setMasterColor(color);
    QPixmap icon(16, 16);
    icon.fill(color);
    ui->colorButton->setIcon( QIcon(icon) );
}
