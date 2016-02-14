#include "countedtextedit.h"
#include "ui_countedtextedit.h"
#include "keysfilter.h"
#include <QDebug>

CountedTextEdit::CountedTextEdit(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::CountedTextEdit)
{
    ui->setupUi(this);
    handleTextChanged();

    QObject::connect(ui->textEdit,
                     SIGNAL(textChanged()),
                     this,
                     SLOT(handleTextChanged()));
}

CountedTextEdit::~CountedTextEdit()
{
    delete ui;
}

void CountedTextEdit::installEventFilterOnTextedit(QObject *filter)
{
    ui->textEdit->installEventFilter(filter);
}

void CountedTextEdit::handleTextChanged()
{
    int sz = ui->textEdit->toPlainText().size();
    ui->label->setText(QString("Total Characters: %1").arg(sz));
}








