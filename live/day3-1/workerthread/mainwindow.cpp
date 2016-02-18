#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(MyFileWriter &writer, QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow),
    m_writer(writer)
{
    ui->setupUi(this);    

    QObject::connect(ui->pushButton, SIGNAL(clicked()),
                     this, SLOT(startWrite()));

    QObject::connect(this, SIGNAL(askWorkerToStartWriting(QString)),
                     &m_writer, SLOT(writeToFile(QString)));

    QObject::connect(&m_writer, SIGNAL(done(QString)),
                     this, SLOT(writeDone(QString)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::startWrite()
{
    emit askWorkerToStartWriting(ui->lineEdit->text());
}

void MainWindow::writeDone(QString fileName)
{
    ui->label->setText("Finished Writing: " + fileName);
}














