#include "renderarea.h"
#include "window.h"

#include <QtWidgets>

Window::Window()
{
    renderArea = new RenderArea;

    QGridLayout *mainLayout = new QGridLayout;
    mainLayout->addWidget(renderArea, 0, 0, 1, 1);
    setLayout(mainLayout);

    setWindowTitle(tr("Game of Life"));
}
