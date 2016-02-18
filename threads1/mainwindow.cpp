#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtCore>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton, SIGNAL(clicked()),
                     this, SLOT(onClick()));
//    QTimer t;
//    t.setInterval(10);
//    t.start();

    QObject::connect(&m_proc, SIGNAL(finished(int)),
                     this, SLOT(handleProcFinished()));

}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::onClick()
{
    ui->label->setText("Calculating");
    ui->pushButton->setEnabled(false);
    m_proc.start("/bin/ls -l /private/etc");

    /*
    ui->pushButton->setEnabled(false);
    unsigned long long i = 1;
    unsigned long long x = 1;
    for (i=1; i<10000000000; i++)
    {
        x +=  i;
        qApp->processEvents();
    }

    ui->label->setText(QString::number(x));
    ui->pushButton->setEnabled(true);
    */
}

void MainWindow::handleProcFinished()
{
    QByteArray stdout = m_proc.readAllStandardOutput();

    ui->label->setText(stdout);
    ui->pushButton->setEnabled(true);
}





































