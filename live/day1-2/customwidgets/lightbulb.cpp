#include "lightbulb.h"
#include <QtGui>

LightBulb::LightBulb(QWidget *parent) :
    QWidget(parent),
    m_isOn(false)
{

}


QSize LightBulb::sizeHint() const
{
    return QSize(50, 150);
}

void LightBulb::paintEvent(QPaintEvent *)
{
    QPainter painter(this);
    painter.setRenderHint(QPainter::Antialiasing);

    painter.rotate(10);
    QPalette pal = palette();
    QBrush offColor = pal.window();
    QBrush onColor = pal.alternateBase();

    QRect top = rect();
    top.setBottom(top.top() + 30);

    QRect bottom = rect();
    bottom.setTop(top.bottom());

    QRect knob = top;
    knob.setWidth(top.width()/2);

    if (m_isOn)
    {
        knob.moveLeft(knob.width());
        painter.fillRect(bottom, onColor);
    }
    else
    {
        painter.fillRect(bottom, offColor);
    }

    painter.fillRect(top, Qt::gray);
    painter.fillRect(knob, Qt::black);
}











void LightBulb::mousePressEvent(QMouseEvent *)
{
    m_isOn = !m_isOn;
    update();
}















