#include "filechooser.h"
#include "ui_filechooser.h"
#include <QFileDialog>

FileChooser::FileChooser(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::FileChooser)
{
    ui->setupUi(this);
    QObject::connect(ui->pushButton,
                     &QPushButton::clicked,
                     this,
                     &FileChooser::showFileDialog);
}

FileChooser::~FileChooser()
{
    delete ui;
}

void FileChooser::showFileDialog()
{
    QString name = QFileDialog::getOpenFileName();
    if (!name.isNull())
    {
        ui->lineEdit->setText(name);
        emit valueChanged(name);
    }

}
















