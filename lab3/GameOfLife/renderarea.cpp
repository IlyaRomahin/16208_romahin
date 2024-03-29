#include <QMessageBox>
#include <QTimer>
#include <QMouseEvent>
#include <QDebug>
#include <QRectF>
#include <QPainter>
#include <qmath.h>
#include "renderarea.h"

RenderArea::RenderArea(QWidget *parent) :
    QWidget(parent),
    timer(new QTimer(this)),
    generations(-1),
    height_(50),
    width_(50),
    normalHeight(0),
    normalWidth(0)
{
    timer->setInterval(100);
    m_masterColor = "#000";
    connect(timer, SIGNAL(timeout()), this, SLOT(check()));
    connect(timer, SIGNAL(timeout()), this, SLOT(newGeneration()));
    universe.resize(((height_ + 2) * (width_ + 2)), bool());
    next.resize(((height_ + 2) * (width_ + 2)), bool());
}

void RenderArea::startGame()
{
    timer->start();
}

void RenderArea::stopGame()
{
    timer->stop();
}

std::vector<bool> &RenderArea::getUniverse()
{
    return universe;
}

std::vector<bool> &RenderArea::getNext()
{
    return next;
}

void RenderArea::setNext(std::vector<bool> &n)
{
    next = n;
}

void RenderArea::setUniverse(std::vector<bool> &u)
{
    universe = u;
}

void RenderArea::setHeight(const int h)
{
    height_ = h;
    universe.resize(((height_ + 2) * (width_ + 2)), bool());
    next.resize(((height_ + 2) * (width_ + 2)), bool());
    update();
}

void RenderArea::setWidth(const int w)
{
    width_ = w;
    universe.resize(((height_ + 2) * (width_ + 2)), bool());
    next.resize(((height_ + 2) * (width_ + 2)), bool());
    update();
}

void RenderArea::needUpdate()
{
    update();
}

void RenderArea::newGeneration()
{
    emit(nextGeneration(true));
}

void RenderArea::check()
{
    emit(needCheck(true));
}

int RenderArea::interval()
{
    return timer->interval();
}

void RenderArea::setInterval(const int msec)
{
    timer->setInterval(msec);
}

void RenderArea::returnToNormalZoom()
{
    if (normalWidth != 0 && normalHeight != 0){
        setFixedSize(normalWidth, normalHeight);
    }
}

void RenderArea::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    paintGrid(p);
    paintUniverse(p);
}

void RenderArea::mousePressEvent(QMouseEvent *e)
{
    double cellWidth = (double)width() / width_;
    double cellHeight = (double)height() / height_;
    int k = 0;
    int j = 0;
    if (0 < e->y() && e->y() < height())
    {
        k = floor(e->y() / cellHeight) + 1;
    }
    if (0 < e->x() && e->x() < width())
    {
        j = floor(e->x() / cellWidth) + 1;
    }
    if (k != 0 && j != 0)
    {
        universe[k * width_ + j] = !universe[k * width_ + j];
    }
    emit(environmentChanged(true));
    update();
}

void RenderArea::mouseMoveEvent(QMouseEvent *e)
{
    double cellWidth = (double)width() / width_;
    double cellHeight = (double)height() / height_;
    int k = 0;
    int j = 0;
    if (0 < e->y() && e->y() < height())
    {
        k = floor(e->y() / cellHeight) + 1;
    }
    if (0 < e->x() && e->x() < width())
    {
        j = floor(e->x() / cellWidth) + 1;
    }
    if (k != 0 && j != 0){
        int currentLocation = k * width_ + j;
        if (!universe[currentLocation]) {
            universe [currentLocation] = !universe[currentLocation];
            update();
        }
    }
}

void RenderArea::wheelEvent(QWheelEvent *e)
{
    if (normalHeight == 0 && normalWidth == 0)
    {
        normalHeight = height();
        normalWidth = width();
    }
    if (e->delta() > 0) {
        setFixedSize(width()*1.15, height()*1.15);
    }
    if (e->delta() < 0) {
        setFixedSize(width()/1.15, height()/1.15);
    }
}

void RenderArea::paintGrid(QPainter &p)
{
    QColor gridColor = "#555";
    p.setPen(gridColor);
    double cellWidth = (double)width() / width_;
    QRect rec(0, 0, width(), height());
    p.fillRect(rec, "#ccc");
    for(double k = cellWidth; k <= width(); k += cellWidth)
    {
        p.drawLine(k, 0, k, height());
    }
    double cellHeight = (double)height() / height_;
    for(double k = cellHeight; k <= height(); k += cellHeight)
    {
        p.drawLine(0, k, width(), k);
    }
    QPen pen(Qt::black);
    pen.setWidth(3);

    QPoint p1;
    p1.setX(0);
    p1.setY(0);

    QPoint p2;
    p2.setX(width() - 1);
    p2.setY(0);

    QPoint p3;
    p3.setX(0);
    p3.setY(height() - 1);

    QPoint p4;
    p4.setX(width() - 1);
    p4.setY(height() - 1);

    p.setPen(pen);
    p.drawLine(p1, p2);
    p.drawLine(p2, p4);
    p.drawLine(p1, p3);
    p.drawLine(p3, p4);
}

void RenderArea::paintUniverse(QPainter &p)
{
    double cellWidth = (double)width() / width_;
    double cellHeight = (double)height() / height_;
    for(int k = 1; k <= height_; k++) {
        for(int j = 1; j <= width_; j++) {
            if(universe[k * width_ + j] == true) {
                qreal left = (qreal)(cellWidth * j - cellWidth);
                qreal top  = (qreal)(cellHeight * k - cellHeight);
                QRectF r(left, top, (qreal)cellWidth, (qreal)cellHeight);
                p.fillRect(r, QBrush(m_masterColor));
            }
        }
    }
}

QColor RenderArea::masterColor()
{
    return m_masterColor;
}

void RenderArea::setMasterColor(const QColor &color)
{
    m_masterColor = color;
    update();
}
