#include "clicker.h"
#include "ui_clicker.h"

Clicker::Clicker(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Clicker),
    m_clicks(0),
    m_displayText("You Clicked: %1 times")
{
    ui->setupUi(this);    
    QObject::connect(ui->pushButton, SIGNAL(clicked()),
                     this, SLOT(handleClick()));

    ui->label->setText(m_displayText.arg(m_clicks));
}

Clicker::~Clicker()
{
    delete ui;
}

void Clicker::handleClick()
{
    m_clicks++;
    ui->label->setText(m_displayText.arg(m_clicks));
}
