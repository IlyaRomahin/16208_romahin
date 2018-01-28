#include <QTextStream>
#include <QFileDialog>
#include <QDebug>
#include <QColor>
#include <QColorDialog>
#include "mainwindow.h"
#include "ui_mainwindow.h"

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
    connect(ui->scrollButton, SIGNAL(clicked()), this, SLOT(scrollBut()));
    connect(ui->loadButton, SIGNAL(clicked()), this, SLOT(loadBut()));
    connect(ui->saveButton, SIGNAL(clicked()), this, SLOT(saveBut()));

    connect(field, SIGNAL(environmentChanged(bool)), ui->heightControl, SLOT(setDisabled(bool)));
    connect(field, SIGNAL(environmentChanged(bool)), ui->widthControl, SLOT(setDisabled(bool)));
    connect(field, &RenderArea::nextGeneration, [this](bool b){newGeneration(b);});

    ui->rulesControl->addItem( "Conway`s" );
    ui->rulesControl->addItem( "HighLife" );
    ui->rulesControl->addItem( "Day & Night" );
    ui->rulesControl->addItem( "Life without Death" );
    ui->rulesControl->addItem( "Seeds" );
    ui->rulesControl->addItem( "My rule" );

    ui->mainLayout->setStretchFactor(ui->gameLayout, 8);
    ui->mainLayout->setStretchFactor(ui->setLayout, 2);
    ui->gameLayout->setStretchFactor(ui->scrollArea, 8);
    ui->scrollArea->setWidget(field);
    setDisabledBoxes();
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

void MainWindow::setEnabledSpinBoxes()
{
    ui->widthControl->setEnabled(true);
    ui->heightControl->setEnabled(true);
}

void MainWindow::setEnabledBoxes()
{
    ui->ac1->setEnabled(true);
    ui->ac2->setEnabled(true);
    ui->ac3->setEnabled(true);
    ui->ac4->setEnabled(true);
    ui->ac5->setEnabled(true);
    ui->ac6->setEnabled(true);
    ui->ac7->setEnabled(true);
    ui->ac8->setEnabled(true);
    ui->dc1->setEnabled(true);
    ui->dc2->setEnabled(true);
    ui->dc3->setEnabled(true);
    ui->dc4->setEnabled(true);
    ui->dc5->setEnabled(true);
    ui->dc6->setEnabled(true);
    ui->dc7->setEnabled(true);
    ui->dc8->setEnabled(true);
}

void MainWindow::setDisabledBoxes()
{
    ui->ac1->setDisabled(true);
    ui->ac2->setDisabled(true);
    ui->ac3->setDisabled(true);
    ui->ac4->setDisabled(true);
    ui->ac5->setDisabled(true);
    ui->ac6->setDisabled(true);
    ui->ac7->setDisabled(true);
    ui->ac8->setDisabled(true);
    ui->dc1->setDisabled(true);
    ui->dc2->setDisabled(true);
    ui->dc3->setDisabled(true);
    ui->dc4->setDisabled(true);
    ui->dc5->setDisabled(true);
    ui->dc6->setDisabled(true);
    ui->dc7->setDisabled(true);
    ui->dc8->setDisabled(true);
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

void MainWindow::scrollBut()
{
    field->returnToNormalZoom();
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
