#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->widget_3,
                     SIGNAL(valueChanged(QString)),
                     ui->label,
                     SLOT(setText(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
