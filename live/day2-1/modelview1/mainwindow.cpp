#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QStandardItemModel *model = new QStandardItemModel(this);
    QStandardItem *a = new QStandardItem("1");
    QStandardItem *b = new QStandardItem("2");
    QStandardItem *c = new QStandardItem("3");
    QList<QStandardItem *>row;
    row << a << b << c;

    model->appendRow(row);

    QVariant v;
    v.setValue<QColor>(Qt::yellow);
    model->setData(model->index(0, 0),
                   v,
                   Qt::UserRole + 1);

    QVariant res = model->data(model->index(0,0), Qt::UserRole+1);
    qDebug() << res.value<QColor>();


    ui->listView->setModel(model);
    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;   
}







