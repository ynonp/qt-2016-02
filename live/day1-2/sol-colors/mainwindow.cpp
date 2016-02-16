#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->btnSetColor,
                     SIGNAL(clicked()),
                     this,
                     SLOT(showColorDialog()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::showColorDialog()
{
    QColor clr = QColorDialog::getColor();

    if (clr.isValid())
    {
        ui->lblValue->setText(clr.name());
    }
}












