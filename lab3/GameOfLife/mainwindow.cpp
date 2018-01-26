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

    connect(field, SIGNAL(gameEnds(bool)), ui->rulesControl, SLOT(setEnabled(bool)));
    connect(field, SIGNAL(gameEnds(bool)), ui->heightControl, SLOT(setEnabled(bool)));
    connect(field, SIGNAL(gameEnds(bool)), ui->widthControl, SLOT(setEnabled(bool)));
    connect(field, SIGNAL(environmentChanged(bool)), ui->heightControl, SLOT(setDisabled(bool)));
    connect(field, SIGNAL(environmentChanged(bool)), ui->widthControl, SLOT(setDisabled(bool)));
    connect(field, SIGNAL(nextGeneration(bool)), this, SLOT(newGeneration()));

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

void MainWindow::clear()
{
    field->clear();
}

void MainWindow::setRule()
{
    field->setRule();
}

void MainWindow::setHeight()
{
    field->setHeight();
}

void MainWindow::setWidth()
{
    field->setWidth();
}

void MainWindow::loadGame()
{
    field->loadGame();
}

void MainWindow::needUpdate()
{
    field->needUpdate();
}

void MainWindow::newGeneration()
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

QPushButton *  MainWindow::startBut()
{
    return ui->startButton;
}

QPushButton * MainWindow::stopBut()
{
    return ui->stopButton;
}

QPushButton * MainWindow::clearBut()
{
    return ui->clearButton;
}

QPushButton * MainWindow::saveBut()
{
    return ui->saveButton;
}

QPushButton * MainWindow::loadBut()
{
    return ui->loadButton;
}

QPushButton * MainWindow::colorBut()
{
    return ui->colorButton;
}

QComboBox * MainWindow::rulesCont()
{
    return ui->rulesControl;
}

QSpinBox * MainWindow::iterInter()
{
    return ui->iterInterval;
}

QSpinBox * MainWindow::heightCont()
{
    return ui->heightControl;
}

QSpinBox * MainWindow::widthCont()
{
    return ui->widthControl;
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
