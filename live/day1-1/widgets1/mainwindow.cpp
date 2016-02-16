#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    ui->label->setText("Hello From Code");

    QObject::connect(ui->horizontalSlider,
                     SIGNAL(valueChanged(int)),
                     ui->spinBox,
                     SLOT(setValue(int)));

    QObject::connect(ui->btnCount,
                    SIGNAL(clicked()),
                     this,
                     SLOT(inc()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::inc()
{
    m_count++;
    QString s = QString("You clicked %1 times")
            .arg(m_count);

    ui->label->setText(s);
}










