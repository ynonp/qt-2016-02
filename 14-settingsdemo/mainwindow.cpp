#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore/QSettings>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QSettings settings;
    QVariant lastPosition = settings.value("pos");
    if (lastPosition.isValid())
    {
        setGeometry(lastPosition.toRect());
    }
}

MainWindow::~MainWindow()
{
    QSettings settings;
    settings.setValue("pos", geometry());
    delete ui;
}
