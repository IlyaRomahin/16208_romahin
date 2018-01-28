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
    void startButclicked(bool ok);
    void stopButclicked(bool ok);
    void clearButclicked(bool ok);
    void saveButclicked(bool ok);
    void loadButclicked(bool ok);
    void colorButclicked(bool ok);
    void scrollButclicked(bool ok);
    void rulesContValueChanged(QString);
    void iterInterValueChanged(int);
    void heightContValueChanged(int);
    void widthContValueChanged(int);

public slots:
    void newGeneration(bool);
    void selectMasterColor();
    void startGame();
    void stopGame();
    std::vector<bool> &getNext();
    std::vector<bool> &getUniverse();
    void setHeight(const int h);
    void setWidth(const int w);
    int interval();
    void setInterval(const int msec);
    QColor masterColor();
    void setMasterColor(const QColor &color);
    void setNext(std::vector<bool> &n);
    void setUniverse(std::vector<bool> &u);
    void setEnabledSpinBoxes();
    void setEnabledBoxes();
    void setDisabledBoxes();
    void needUpdate();
    void startBut();
    void stopBut();
    void clearBut();
    void scrollBut();
    void saveBut();
    void loadBut();
    void colorBut();
    void rulesCont(QString r);
    void iterInter(int it);
    void heightCont(int h);
    void widthCont(int w);

    
private:
    Ui::MainWindow *ui;
    QColor currentColor;
    RenderArea *field;
};

#endif // MAINWINDOW_H
