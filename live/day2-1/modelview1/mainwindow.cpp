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

    for (auto i=1; i < 5; i++)
    {
        QList<QStandardItem *>row;
        for (auto j=1; j<5; j++)
        {
            auto val = i * j;
            auto item = new QStandardItem(QString::number(val));
            item->setEditable(false);

            if (val % 3 == 0)
            {
                QVariant yellow;
                yellow.setValue<QColor>(Qt::yellow);
                item->setData(yellow, Qt::BackgroundRole);
            }
            row << item;
        }
        model->appendRow(row);
    }

    QVariant v;
    v.setValue<QColor>(Qt::yellow);
    model->setData(model->index(0, 0),
                   v,
                   Qt::UserRole + 1);

    QVariant res = model->data(model->index(0,0), Qt::UserRole+1);
    qDebug() << res.value<QColor>();


    ui->tableView->setModel(model);
}

MainWindow::~MainWindow()
{
    delete ui;   
}







