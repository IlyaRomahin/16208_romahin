#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "mainwindow.h"
#include "model.h"

class Controller : public QWidget
{
Q_OBJECT
public:
    Controller(QWidget *parent, Model *m, MainWindow *w);

signals:
    void environmentChanged(bool ok);
    void gameEnds(bool ok);

public slots:
    void saveGame();
    void loadGame();
    void startGame(bool);
    void stopGame();
    void clear();
    void selectMasterColor();

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
    void newGeneration();
    void finishGame();
    void lostGame();
    void needUpdate();

private:
    Model *model;
    MainWindow *view;
};

#endif // CONTROLLER_H
