#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->btnSelectColor, SIGNAL(clicked()),
                     this, SLOT(selectColor()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::selectColor()
{
    QColor next = QColorDialog::getColor(m_selectedColor);
    if (next.isValid())
    {
        m_selectedColor = next;
        ui->lblValue->setText(m_selectedColor.name());
        ui->lblValue->setStyleSheet(QString("background: %1").arg(m_selectedColor.name()));
    }
}
