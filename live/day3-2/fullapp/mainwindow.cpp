#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QtGui>
#include <QtWidgets>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    ui->mainToolBar->addAction(ui->actionOpen);
    ui->mainToolBar->addWidget(new QLineEdit(this));
    ui->centralWidget->addAction(ui->actionOpen);
    ui->centralWidget->setContextMenuPolicy(Qt::ActionsContextMenu);

    setWindowModified(true);

    //ui->actionOpen->setEnabled(false);

    QObject::connect(ui->actionOpen,
                     SIGNAL(triggered(bool)),
                     this,
                     SLOT(openFile()));

    QSettings settings;
    QVariant prevName = settings.value("name");
    if (prevName.isValid())
    {
        ui->label->setText(prevName.toString());
    }
    else
    {
        ui->label->setText(tr("Select File"));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openFile()
{
    QString name = QFileDialog::getOpenFileName();
    ui->label->setText(name);

    QSettings settings;
    settings.setValue("name", name);
}




















