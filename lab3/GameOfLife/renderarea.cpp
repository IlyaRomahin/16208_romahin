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
    rule("Conway`s")
{
    timer->setInterval(300);
    m_masterColor = "#000";
    universe = new bool[(height_ + 2) * (width_ + 2)];
    next = new bool[(height_ + 2) * (width_ + 2)];
    connect(timer, SIGNAL(timeout()), this, SLOT(newGeneration()));
    memset(universe, false, sizeof(bool) * (height_ + 2) * (width_ + 2));
    memset(next, false, sizeof(bool) * (height_ + 2) * (width_ + 2));
}

RenderArea::~RenderArea()
{
    delete [] universe;
    delete [] next;
}

void RenderArea::startGame()
{
    timer->start();
}

void RenderArea::stopGame()
{
    timer->stop();
}

void RenderArea::clear()
{
    update();
}

void RenderArea::setRule()
{
    update();
}

void RenderArea::setHeight()
{
    update();
}

void RenderArea::setWidth()
{
    update();
}

void RenderArea::loadGame()
{
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

int RenderArea::interval()
{
    return timer->interval();
}

void RenderArea::setInterval(const int msec)
{
    timer->setInterval(msec);
}

void RenderArea::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    paintGrid(p);
    paintUniverse(p);
}

void RenderArea::mousePressEvent(QMouseEvent *e)
{
    emit environmentChanged(true);
    double cellWidth = (double)width() / width_;
    double cellHeight = (double)height() / height_;
    int k = floor(e->y() / cellHeight) + 1;
    int j = floor(e->x() / cellWidth) + 1;
    universe[k * width_ + j] = !universe[k * width_ + j];
    update();
}

void RenderArea::mouseMoveEvent(QMouseEvent *e)
{
    double cellWidth = (double)width() / width_;
    double cellHeight = (double)height() / height_;
    int k = floor(e->y() / cellHeight) + 1;
    int j = floor(e->x() / cellWidth) + 1;
    int currentLocation = k * width_ + j;
    if (!universe[currentLocation]) {
        universe [currentLocation] = !universe[currentLocation];
        update();
    }
}

void RenderArea::wheelEvent(QWheelEvent *e)
{
    if (e->delta() > 0) {
        setFixedSize(width()*1.15, height()*1.15);
    }
    if (e->delta() < 0) {
        setFixedSize(width()*0.85, height()*0.85);
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
