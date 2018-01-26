#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QColor>
#include <QWidget>

class RenderArea : public QWidget
{
Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = 0);
    ~RenderArea();

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void wheelEvent(QWheelEvent *e);

signals:
    void environmentChanged(bool ok);
    void gameEnds(bool ok);
    void nextGeneration(bool ok);

public slots:
    void startGame();
    void stopGame();

    void clear();
    void setRule();
    void setHeight();
    void setWidth();
    void loadGame();
    void needUpdate();

    int interval();
    void setInterval(const int msec);

    QColor masterColor();
    void setMasterColor(const QColor &color);

private slots:
    void paintGrid(QPainter &p);
    void paintUniverse(QPainter &p);
    void newGeneration();

private:
    QColor m_masterColor;
    QTimer* timer;
    int generations;
    bool* universe;
    bool* next;
    int height_;
    int width_;
    QString rule;
};

#endif // RENDERAREA_H
