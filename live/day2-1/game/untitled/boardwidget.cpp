#include "boardwidget.h"
#include "tictactoegameengine.h"

BoardWidget::BoardWidget(QWidget *parent) :
    QWidget(parent),
    m_engine(NULL)
{

}

void BoardWidget::setGameEngine(TicTacToeGameEngine *engine)
{
    if (m_engine)
    {
        QObject::disconnect(m_engine, SIGNAL(dataChanged(int,int)),
                            this, SLOT(update()));
    }
    m_engine = engine;

    QObject::connect(m_engine, SIGNAL(dataChanged(int,int)),
                     this, SLOT(update()));

    QObject::connect(this, SIGNAL(clicked(int,int)),
                     m_engine, SLOT(play(int,int)));

    update();
}

void BoardWidget::paintEvent(QPaintEvent *)
{
    if (!m_engine) return;

    QPainter p(this);
    qreal height = rect().height();
    qreal width = rect().width();

    p.drawLine(x1, 0, x1, height);
    p.drawLine(x2, 0, x2, height);
    p.drawLine(0, y1, width, y1);
    p.drawLine(0, y2, width, y2);

    for (auto i=0; i<3; i++)
    {
        for (auto j=0; j<3; j++)
        {
            auto val = m_engine->valueAt(i, j);
            if (val != m_engine->blank())
            {
                paintValue(p, val, i, j);
            }
        }
    }
}

void BoardWidget::resizeEvent(QResizeEvent *)
{
    x1 = rect().width() / 3;
    x2 = x1 * 2;

    y1 = rect().height() / 3;
    y2 = y1 * 2;
}

void BoardWidget::mousePressEvent(QMouseEvent *e)
{
    int row=-1, col=-1;

    if (e->pos().x() < x1)
    {
        col = 0;
    }
    else if ( (e->pos().x() > x1) && (e->pos().x() < x2))
    {
        col = 1;
    }
    else if (e->pos().x() > x2)
    {
        col = 2;
    }


    if (e->pos().y() < y1)
    {
        row = 0;
    }
    else if ( (e->pos().y() > y1) && (e->pos().y() < y2))
    {
        row = 1;
    }
    else if (e->pos().y() > y2)
    {
        row = 2;
    }

    if ((row >=0) && (col>=0))
    {
        emit clicked(row, col);
    }

}

void BoardWidget::paintValue(QPainter &painter, QString val, int row, int col)
{
    qreal left = col * x1;
    qreal top = row * y1;

    qreal w = rect().width() / 3;
    qreal h = rect().height() / 3;

    QFontMetrics metrics(painter.font());

    int textWidth = metrics.width(val);

    qreal start_x = left + ((w - textWidth) / 2);
    qreal start_y = top + h/2;

    painter.drawText(start_x, start_y, val);
}

