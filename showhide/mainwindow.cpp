#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QPropertyAnimation>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    isHidden(false)
{
    ui->setupUi(this);
    ui->label->setStyleSheet("background:lightblue");
    QObject::connect(ui->pushButton, SIGNAL(clicked()), this, SLOT(handleClick()));
    ui->centralWidget->layout()->setAlignment(Qt::AlignTop);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::handleClick()
{
    QPropertyAnimation *animation =
            new QPropertyAnimation(ui->label, "maximumHeight");

    animation->setDuration(100);

    if (isHidden)
    {
        animation->setEndValue(QVariant(100));
    }
    else
    {
        animation->setEndValue(QVariant(0));
    }


    animation->start(QAbstractAnimation::DeleteWhenStopped);
    isHidden = ! isHidden;
}

















