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
    field(new RenderArea(this)),
    birth(0),
    life(0)
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

    connect(field, SIGNAL(environmentChanged(bool)), this, SLOT(updateModel(bool)));
    connect(field, SIGNAL(environmentChanged(bool)), ui->heightControl, SLOT(setDisabled(bool)));
    connect(field, SIGNAL(environmentChanged(bool)), ui->widthControl, SLOT(setDisabled(bool)));
    connect(field, SIGNAL(environmentChanged(bool)), ui->colorButton, SLOT(setDisabled(bool)));
    connect(field, &RenderArea::nextGeneration, [this](bool b){newGeneration(b);});
    connect(field, &RenderArea::needCheck, [this](bool b){check(b);});

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
    ui->saveButton->setDisabled(true);
    ui->loadButton->setDisabled(true);
}

void MainWindow::stopGame()
{
    field->stopGame();
    ui->saveButton->setEnabled(true);
    ui->loadButton->setEnabled(true);
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

void MainWindow::setRule(std::string fRule)
{
    QString rule = QString::fromStdString(fRule);
    ui->rulesControl->setCurrentText(rule);
    rulesCont(rule);
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
    ui->colorButton->setEnabled(true);
}

void MainWindow::setEnabledBoxes()
{
    ui->lc1->setEnabled(true);
    ui->lc2->setEnabled(true);
    ui->lc3->setEnabled(true);
    ui->lc4->setEnabled(true);
    ui->lc5->setEnabled(true);
    ui->lc6->setEnabled(true);
    ui->lc7->setEnabled(true);
    ui->lc8->setEnabled(true);
    ui->bc1->setEnabled(true);
    ui->bc2->setEnabled(true);
    ui->bc3->setEnabled(true);
    ui->bc4->setEnabled(true);
    ui->bc5->setEnabled(true);
    ui->bc6->setEnabled(true);
    ui->bc7->setEnabled(true);
    ui->bc8->setEnabled(true);
}

void MainWindow::setDisabledBoxes()
{
    ui->lc1->setDisabled(true);
    ui->lc2->setDisabled(true);
    ui->lc3->setDisabled(true);
    ui->lc4->setDisabled(true);
    ui->lc5->setDisabled(true);
    ui->lc6->setDisabled(true);
    ui->lc7->setDisabled(true);
    ui->lc8->setDisabled(true);
    ui->bc1->setDisabled(true);
    ui->bc2->setDisabled(true);
    ui->bc3->setDisabled(true);
    ui->bc4->setDisabled(true);
    ui->bc5->setDisabled(true);
    ui->bc6->setDisabled(true);
    ui->bc7->setDisabled(true);
    ui->bc8->setDisabled(true);
}

void MainWindow::needUpdate()
{
    field->needUpdate();
}

void MainWindow::updateModel(bool)
{
    emit(environmentChanged(true));
}

void MainWindow::newGeneration(bool)
{
    emit(nextGeneration(true));
}

void MainWindow::check(bool)
{
    birth = 0;
    life = 0;
    if (ui->lc1->isChecked() && ui->lc1->isEnabled())
    {
       life++;
    }
    if (ui->lc2->isChecked() && ui->lc2->isEnabled())
    {
       life++;
    }
    if (ui->lc3->isChecked() && ui->lc3->isEnabled())
    {
       life++;
    }
    if (ui->lc4->isChecked() && ui->lc4->isEnabled())
    {
       life++;
    }
    if (ui->lc5->isChecked() && ui->lc5->isEnabled())
    {
       life++;
    }
    if (ui->lc6->isChecked() && ui->lc6->isEnabled())
    {
       life++;
    }
    if (ui->lc7->isChecked() && ui->lc7->isEnabled())
    {
       life++;
    }
    if (ui->lc8->isChecked() && ui->lc8->isEnabled())
    {
       life++;
    }
    if (ui->bc1->isChecked() && ui->bc1->isEnabled())
    {
       birth++;
    }
    if (ui->bc2->isChecked() && ui->bc2->isEnabled())
    {
       birth++;
    }
    if (ui->bc3->isChecked() && ui->bc3->isEnabled())
    {
       birth++;
    }
    if (ui->bc4->isChecked() && ui->bc4->isEnabled())
    {
       birth++;
    }
    if (ui->bc5->isChecked() && ui->bc5->isEnabled())
    {
       birth++;
    }
    if (ui->bc6->isChecked() && ui->bc6->isEnabled())
    {
       birth++;
    }
    if (ui->bc7->isChecked() && ui->bc7->isEnabled())
    {
       birth++;
    }
    if (ui->bc8->isChecked() && ui->bc8->isEnabled())
    {
       birth++;
    }
    emit(needCheck(birth, life));
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

void MainWindow::setCellsWidth(int cw)
{
    ui->widthControl->setValue(cw);
    emit(widthContValueChanged(cw));
}

void MainWindow::setCellsHeight(int ch)
{
    ui->heightControl->setValue(ch);
    emit(heightContValueChanged(ch));
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
