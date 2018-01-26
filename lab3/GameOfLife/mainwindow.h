#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QColor>
#include <QPushButton>
#include <QComboBox>
#include <QSpinBox>
#include "renderarea.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT
    
public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

signals:
    void nextGeneration(bool ok);

public slots:
    void newGeneration();
    void selectMasterColor();
    void startGame();
    void stopGame();
    void clear();
    void setRule();
    void setHeight();
    void setWidth();
    int interval();
    void setInterval(const int msec);
    QColor masterColor();
    void setMasterColor(const QColor &color);
    void loadGame();
    void needUpdate();
    QPushButton * startBut();
    QPushButton * stopBut();
    QPushButton * clearBut();
    QPushButton * saveBut();
    QPushButton * loadBut();
    QPushButton * colorBut();
    QComboBox * rulesCont();
    QSpinBox * iterInter();
    QSpinBox * heightCont();
    QSpinBox * widthCont();

    
private:
    Ui::MainWindow *ui;
    QColor currentColor;
    RenderArea *field;
};

#endif // MAINWINDOW_H
