#include "counter.h"
#include "ui_counter.h"

Counter::Counter(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Counter),
    m_count(0)
{
    ui->setupUi(this);
    updateText();

    QLabel l;

    QObject::connect(ui->pushButton,
                     SIGNAL(clicked()),
                     this,
                     SLOT(inc()));
}

Counter::~Counter()
{
    delete ui;
}

void Counter::inc()
{
    m_count++;
    updateText();
}

void Counter::updateText()
{
    ui->label->setText(
                QString("You clicked %1 times")
                .arg(m_count));
}









