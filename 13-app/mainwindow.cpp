#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets/QColorDialog>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->actionChange_Color, &QAction::triggered,
                     this, &MainWindow::selectBackgroundColor);

    ui->mainToolBar->addWidget(new QLineEdit(this));
    ui->statusBar->addWidget(new QLabel("demo widget"));
    ui->statusBar->addPermanentWidget(new QLabel("permanent widget"));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectBackgroundColor()
{
    ui->statusBar->showMessage("Select color");
    QColor color = QColorDialog::getColor(Qt::white, this);

    setStyleSheet(QString("background-color: %1").arg(color.name()));
    ui->statusBar->clearMessage();
}

