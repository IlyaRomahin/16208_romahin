/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.1
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSpinBox>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralWidget;
    QHBoxLayout *horizontalLayout;
    QHBoxLayout *mainLayout;
    QVBoxLayout *gameLayout;
    QVBoxLayout *setLayout;
    QHBoxLayout *controlLayout;
    QPushButton *startButton;
    QPushButton *stopButton;
    QPushButton *clearButton;
    QLabel *label3;
    QComboBox *rulesControl;
    QLabel *label_4;
    QHBoxLayout *aliveCells1;
    QCheckBox *ac1;
    QCheckBox *ac2;
    QCheckBox *ac3;
    QCheckBox *ac4;
    QHBoxLayout *aliveCells2;
    QCheckBox *ac5;
    QCheckBox *ac6;
    QCheckBox *ac7;
    QCheckBox *ac8;
    QLabel *label_5;
    QHBoxLayout *deadCells1;
    QCheckBox *dc1;
    QCheckBox *dc2;
    QCheckBox *dc3;
    QCheckBox *dc4;
    QHBoxLayout *deadCells2;
    QCheckBox *dc5;
    QCheckBox *dc6;
    QCheckBox *dc7;
    QCheckBox *dc8;
    QHBoxLayout *LabelLayout;
    QLabel *label_3;
    QLabel *label_2;
    QHBoxLayout *cellLayout;
    QSpinBox *heightControl;
    QSpinBox *widthControl;
    QLabel *label2;
    QSpinBox *iterInterval;
    QHBoxLayout *fileLayout;
    QPushButton *loadButton;
    QPushButton *saveButton;
    QPushButton *colorButton;
    QSpacerItem *verticalSpacer;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(700, 500);
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        horizontalLayout = new QHBoxLayout(centralWidget);
        horizontalLayout->setSpacing(6);
        horizontalLayout->setContentsMargins(11, 11, 11, 11);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        mainLayout = new QHBoxLayout();
        mainLayout->setSpacing(6);
        mainLayout->setObjectName(QStringLiteral("mainLayout"));
        gameLayout = new QVBoxLayout();
        gameLayout->setSpacing(6);
        gameLayout->setObjectName(QStringLiteral("gameLayout"));

        mainLayout->addLayout(gameLayout);

        setLayout = new QVBoxLayout();
        setLayout->setSpacing(6);
        setLayout->setObjectName(QStringLiteral("setLayout"));
        controlLayout = new QHBoxLayout();
        controlLayout->setSpacing(6);
        controlLayout->setObjectName(QStringLiteral("controlLayout"));
        startButton = new QPushButton(centralWidget);
        startButton->setObjectName(QStringLiteral("startButton"));

        controlLayout->addWidget(startButton);

        stopButton = new QPushButton(centralWidget);
        stopButton->setObjectName(QStringLiteral("stopButton"));

        controlLayout->addWidget(stopButton);

        clearButton = new QPushButton(centralWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));

        controlLayout->addWidget(clearButton);


        setLayout->addLayout(controlLayout);

        label3 = new QLabel(centralWidget);
        label3->setObjectName(QStringLiteral("label3"));

        setLayout->addWidget(label3);

        rulesControl = new QComboBox(centralWidget);
        rulesControl->setObjectName(QStringLiteral("rulesControl"));
        rulesControl->setEditable(false);

        setLayout->addWidget(rulesControl);

        label_4 = new QLabel(centralWidget);
        label_4->setObjectName(QStringLiteral("label_4"));

        setLayout->addWidget(label_4);

        aliveCells1 = new QHBoxLayout();
        aliveCells1->setSpacing(6);
        aliveCells1->setObjectName(QStringLiteral("aliveCells1"));
        ac1 = new QCheckBox(centralWidget);
        ac1->setObjectName(QStringLiteral("ac1"));

        aliveCells1->addWidget(ac1);

        ac2 = new QCheckBox(centralWidget);
        ac2->setObjectName(QStringLiteral("ac2"));

        aliveCells1->addWidget(ac2);

        ac3 = new QCheckBox(centralWidget);
        ac3->setObjectName(QStringLiteral("ac3"));

        aliveCells1->addWidget(ac3);

        ac4 = new QCheckBox(centralWidget);
        ac4->setObjectName(QStringLiteral("ac4"));

        aliveCells1->addWidget(ac4);


        setLayout->addLayout(aliveCells1);

        aliveCells2 = new QHBoxLayout();
        aliveCells2->setSpacing(6);
        aliveCells2->setObjectName(QStringLiteral("aliveCells2"));
        ac5 = new QCheckBox(centralWidget);
        ac5->setObjectName(QStringLiteral("ac5"));

        aliveCells2->addWidget(ac5);

        ac6 = new QCheckBox(centralWidget);
        ac6->setObjectName(QStringLiteral("ac6"));

        aliveCells2->addWidget(ac6);

        ac7 = new QCheckBox(centralWidget);
        ac7->setObjectName(QStringLiteral("ac7"));

        aliveCells2->addWidget(ac7);

        ac8 = new QCheckBox(centralWidget);
        ac8->setObjectName(QStringLiteral("ac8"));

        aliveCells2->addWidget(ac8);


        setLayout->addLayout(aliveCells2);

        label_5 = new QLabel(centralWidget);
        label_5->setObjectName(QStringLiteral("label_5"));

        setLayout->addWidget(label_5);

        deadCells1 = new QHBoxLayout();
        deadCells1->setSpacing(6);
        deadCells1->setObjectName(QStringLiteral("deadCells1"));
        dc1 = new QCheckBox(centralWidget);
        dc1->setObjectName(QStringLiteral("dc1"));

        deadCells1->addWidget(dc1);

        dc2 = new QCheckBox(centralWidget);
        dc2->setObjectName(QStringLiteral("dc2"));

        deadCells1->addWidget(dc2);

        dc3 = new QCheckBox(centralWidget);
        dc3->setObjectName(QStringLiteral("dc3"));

        deadCells1->addWidget(dc3);

        dc4 = new QCheckBox(centralWidget);
        dc4->setObjectName(QStringLiteral("dc4"));

        deadCells1->addWidget(dc4);


        setLayout->addLayout(deadCells1);

        deadCells2 = new QHBoxLayout();
        deadCells2->setSpacing(6);
        deadCells2->setObjectName(QStringLiteral("deadCells2"));
        dc5 = new QCheckBox(centralWidget);
        dc5->setObjectName(QStringLiteral("dc5"));

        deadCells2->addWidget(dc5);

        dc6 = new QCheckBox(centralWidget);
        dc6->setObjectName(QStringLiteral("dc6"));

        deadCells2->addWidget(dc6);

        dc7 = new QCheckBox(centralWidget);
        dc7->setObjectName(QStringLiteral("dc7"));

        deadCells2->addWidget(dc7);

        dc8 = new QCheckBox(centralWidget);
        dc8->setObjectName(QStringLiteral("dc8"));

        deadCells2->addWidget(dc8);


        setLayout->addLayout(deadCells2);

        LabelLayout = new QHBoxLayout();
        LabelLayout->setSpacing(6);
        LabelLayout->setObjectName(QStringLiteral("LabelLayout"));
        label_3 = new QLabel(centralWidget);
        label_3->setObjectName(QStringLiteral("label_3"));

        LabelLayout->addWidget(label_3);

        label_2 = new QLabel(centralWidget);
        label_2->setObjectName(QStringLiteral("label_2"));

        LabelLayout->addWidget(label_2);


        setLayout->addLayout(LabelLayout);

        cellLayout = new QHBoxLayout();
        cellLayout->setSpacing(6);
        cellLayout->setObjectName(QStringLiteral("cellLayout"));
        heightControl = new QSpinBox(centralWidget);
        heightControl->setObjectName(QStringLiteral("heightControl"));
        heightControl->setMinimum(2);
        heightControl->setMaximum(3000);
        heightControl->setValue(50);

        cellLayout->addWidget(heightControl);

        widthControl = new QSpinBox(centralWidget);
        widthControl->setObjectName(QStringLiteral("widthControl"));
        widthControl->setMinimum(2);
        widthControl->setMaximum(3000);
        widthControl->setValue(50);

        cellLayout->addWidget(widthControl);


        setLayout->addLayout(cellLayout);

        label2 = new QLabel(centralWidget);
        label2->setObjectName(QStringLiteral("label2"));

        setLayout->addWidget(label2);

        iterInterval = new QSpinBox(centralWidget);
        iterInterval->setObjectName(QStringLiteral("iterInterval"));
        iterInterval->setMinimum(50);
        iterInterval->setMaximum(100000);
        iterInterval->setSingleStep(10);
        iterInterval->setValue(100);

        setLayout->addWidget(iterInterval);

        fileLayout = new QHBoxLayout();
        fileLayout->setSpacing(6);
        fileLayout->setObjectName(QStringLiteral("fileLayout"));
        loadButton = new QPushButton(centralWidget);
        loadButton->setObjectName(QStringLiteral("loadButton"));

        fileLayout->addWidget(loadButton);

        saveButton = new QPushButton(centralWidget);
        saveButton->setObjectName(QStringLiteral("saveButton"));

        fileLayout->addWidget(saveButton);


        setLayout->addLayout(fileLayout);

        colorButton = new QPushButton(centralWidget);
        colorButton->setObjectName(QStringLiteral("colorButton"));

        setLayout->addWidget(colorButton);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        setLayout->addItem(verticalSpacer);


        mainLayout->addLayout(setLayout);


        horizontalLayout->addLayout(mainLayout);

        MainWindow->setCentralWidget(centralWidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "Game of Life", Q_NULLPTR));
        startButton->setText(QApplication::translate("MainWindow", "Start", Q_NULLPTR));
        stopButton->setText(QApplication::translate("MainWindow", "Stop", Q_NULLPTR));
        clearButton->setText(QApplication::translate("MainWindow", "Clear", Q_NULLPTR));
        label3->setText(QApplication::translate("MainWindow", "Rules of Game", Q_NULLPTR));
        rulesControl->setCurrentText(QString());
        label_4->setText(QApplication::translate("MainWindow", "AliveCells", Q_NULLPTR));
        ac1->setText(QApplication::translate("MainWindow", "ac1", Q_NULLPTR));
        ac2->setText(QApplication::translate("MainWindow", "ac2", Q_NULLPTR));
        ac3->setText(QApplication::translate("MainWindow", "ac3", Q_NULLPTR));
        ac4->setText(QApplication::translate("MainWindow", "ac4", Q_NULLPTR));
        ac5->setText(QApplication::translate("MainWindow", "ac5", Q_NULLPTR));
        ac6->setText(QApplication::translate("MainWindow", "ac6", Q_NULLPTR));
        ac7->setText(QApplication::translate("MainWindow", "ac7", Q_NULLPTR));
        ac8->setText(QApplication::translate("MainWindow", "ac8", Q_NULLPTR));
        label_5->setText(QApplication::translate("MainWindow", "DeadCells", Q_NULLPTR));
        dc1->setText(QApplication::translate("MainWindow", "dc1", Q_NULLPTR));
        dc2->setText(QApplication::translate("MainWindow", "dc2", Q_NULLPTR));
        dc3->setText(QApplication::translate("MainWindow", "dc3", Q_NULLPTR));
        dc4->setText(QApplication::translate("MainWindow", "dc4", Q_NULLPTR));
        dc5->setText(QApplication::translate("MainWindow", "dc5", Q_NULLPTR));
        dc6->setText(QApplication::translate("MainWindow", "dc6", Q_NULLPTR));
        dc7->setText(QApplication::translate("MainWindow", "dc7", Q_NULLPTR));
        dc8->setText(QApplication::translate("MainWindow", "dc8", Q_NULLPTR));
        label_3->setText(QApplication::translate("MainWindow", "Height", Q_NULLPTR));
        label_2->setText(QApplication::translate("MainWindow", "Width", Q_NULLPTR));
        heightControl->setSuffix(QApplication::translate("MainWindow", " cells", Q_NULLPTR));
        widthControl->setSuffix(QApplication::translate("MainWindow", " cells", Q_NULLPTR));
        label2->setText(QApplication::translate("MainWindow", "Generation interval (in msec)", Q_NULLPTR));
        iterInterval->setSuffix(QApplication::translate("MainWindow", " ms", Q_NULLPTR));
        loadButton->setText(QApplication::translate("MainWindow", "Load", Q_NULLPTR));
        saveButton->setText(QApplication::translate("MainWindow", "Save", Q_NULLPTR));
        colorButton->setText(QApplication::translate("MainWindow", "Select color for cells", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
