#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "mainwindow.h"
#include "model.h"

class Controller : public QWidget
{
Q_OBJECT
public:
    Controller(QWidget *parent, Model *m, MainWindow *w);

public slots:
    void saveGame(bool);
    void loadGame(bool);
    void startGame(bool);
    void stopGame(bool);
    void clear(bool);
    void selectMasterColor(bool);
    void myRule(bool);
    void notMyRule(bool);

    QString gameRule();
    void setRule(const QString &r);

    int cellsHeight();
    void setHeight(const int h);

    int cellsWidth();
    void setWidth(const int w);

    int interval();
    void setInterval(const int msec);

    QColor masterColor();
    void setMasterColor(const QColor &color);

private slots:
    void newGeneration(bool);
    void check(std::vector<bool>, std::vector<bool>);
    void finishGame(bool);
    void lostGame(bool);
    void needUpdate(bool);
    void updateModel(bool);

private:
    Model *model;
    MainWindow *view;
};

#endif // CONTROLLER_H
