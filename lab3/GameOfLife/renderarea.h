#ifndef RENDERAREA_H
#define RENDERAREA_H

#include <QColor>
#include <QWidget>

class RenderArea : public QWidget
{
Q_OBJECT
public:
    explicit RenderArea(QWidget *parent = 0);

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);
    void mouseMoveEvent(QMouseEvent *e);
    void wheelEvent(QWheelEvent *e);

signals:
    void environmentChanged(bool ok);
    void nextGeneration(bool ok);
    void needCheck(bool ok);

public slots:
    void startGame();
    void stopGame();

    std::vector<bool> &getNext();
    std::vector<bool> &getUniverse();

    void setUniverse(std::vector<bool> &u);
    void setNext(std::vector<bool> &n);

    void setHeight(const int h);
    void setWidth(const int w);
    void needUpdate();

    int interval();
    void setInterval(const int msec);

    QColor masterColor();
    void setMasterColor(const QColor &color);

    void returnToNormalZoom();

private slots:
    void paintGrid(QPainter &p);
    void paintUniverse(QPainter &p);
    void newGeneration();
    void check();

private:
    QColor m_masterColor;
    QTimer* timer;
    int generations;
    std::vector<bool> universe;
    std::vector<bool> next;
    int height_;
    int width_;
    double normalHeight;
    double normalWidth;
};

#endif // RENDERAREA_H
