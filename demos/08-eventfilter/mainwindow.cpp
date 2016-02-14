#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "keysfilter.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    KeysFilter *filter = new KeysFilter(this);
    ui->widget->installEventFilterOnTextedit(filter);
}

MainWindow::~MainWindow()
{
    delete ui;
}
