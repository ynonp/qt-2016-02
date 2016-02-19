#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()),
                     this, SLOT(search()));
    QObject::connect(&api, SIGNAL(titleChanged(QString)),
                     ui->title, SLOT(setText(QString)));

    QObject::connect(&api, SIGNAL(yearChanged(QString)),
                     ui->year, SLOT(setText(QString)));

    QObject::connect(&api, SIGNAL(imageUrlChanged(QString)),
                     ui->img, SLOT(setText(QString)));


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::search()
{
    api.search(ui->lineEdit->text());
}










