#include "countedtextarea.h"
#include "ui_countedtextarea.h"

CountedTextarea::CountedTextarea(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CountedTextarea),
    m_lengthText("You typed %1 characters")
{
    ui->setupUi(this);
    QObject::connect(ui->textEdit, SIGNAL(textChanged()),
                     this, SLOT(textChanged()));
    textChanged();
}

CountedTextarea::~CountedTextarea()
{
    delete ui;
}

void CountedTextarea::textChanged()
{
    int len = ui->textEdit->toPlainText().length();
    ui->label->setText(m_lengthText.arg(len));
}
