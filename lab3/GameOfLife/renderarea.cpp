#include "renderarea.h"

#include <QPainter>
#include <QMouseEvent>

RenderArea::RenderArea(QWidget *parent)
    : QWidget(parent)
{


    connect(&timer,SIGNAL (timeout()),this,SLOT(tick()));
    timer.start(1000);
    setBackgroundRole(QPalette::Base);
    setAutoFillBackground(true);

}

void RenderArea::tick() {
    flag=!flag;
    repaint();
}

QSize RenderArea::minimumSizeHint() const
{
    return QSize(100, 100);
}

QSize RenderArea::sizeHint() const
{
    return QSize(400, 200);
}

void RenderArea::paintEvent(QPaintEvent * /* event */)
{
    QColor c = flag ? Qt::red : Qt::green;
    QColor col = flag ? Qt::green : Qt::red;
    QPainter p(this);
    p.setPen(Qt::black);

    for (int i = 0; i <= 700; i+=5){
        p.drawLine(0,i,700,i);
        p.drawLine(i,0,i,700);
    }
    for (int i = 0; i <= 350; i+=5){
        for (int j = 0; j <= 350; j+=5){
            if (i % 10 == 0 && j % 10 == 0){
               p.fillRect(i,j,i+5,j+5,col);
            }
            else{
               p.fillRect(i,j,i+5,j+5,c);
            }
        }
    }

}

void RenderArea::mousePressEvent(QMouseEvent *event) {
    if (event->x() > 50 && event->x() < 250) {
        if(event->y() > 50 && event->y() < 250) {
            flag=!flag;
            repaint();
        }
    }
}
