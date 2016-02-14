#include "onoffswitch.h"
#include <QDebug>

OnOffSwitch::OnOffSwitch(QWidget *parent) :
    QWidget(parent),
    m_topHeight(50),
    m_isOn(false)
{
    setMinimumSize(60, m_topHeight + 30);
}

QSize OnOffSwitch::minimumSizeHint() const
{
    return QSize(60, m_topHeight + 30);
}

void OnOffSwitch::paintEvent(QPaintEvent *)
{
    QPainter p(this);
    QBrush bgColor = palette().background();

    QRect bottom = rect().adjusted(0, m_topHeight, 0, 0);

    QRect top = rect();
    top.setBottom(m_topHeight);

    QRect knob = top;
    knob.setWidth(rect().width() / 2);

    p.fillRect(top, QBrush(Qt::white));

    if (m_isOn)
    {
        knob.translate(rect().width() / 2, 0);
        p.fillRect(bottom, bgColor);
    }
    else
    {
        p.fillRect(bottom, QBrush(Qt::gray));
    }

    p.fillRect(knob, Qt::black);
}

void OnOffSwitch::mousePressEvent(QMouseEvent *e)
{
    if (e->pos().y() < m_topHeight)
    {
        m_isOn = ! m_isOn;
        update();
    }
}

