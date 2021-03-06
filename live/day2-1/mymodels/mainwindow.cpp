#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "numbersmodel.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    NumbersModel *model = new NumbersModel(this);
    ui->listView->setModel(model);
    ui->tableView->setModel(model);
    ui->spinBox->setValue(model->columnCount(QModelIndex()));
    QObject::connect(ui->spinBox,
                     SIGNAL(valueChanged(int)),
                     model,
                     SLOT(setColumnCount(int)));
}

MainWindow::~MainWindow()
{
    delete ui;
}
