#ifndef BOARDWIDGET_H
#define BOARDWIDGET_H

#include <QWidget>
class TicTacToeGameEngine;
#include <QtGui>

class BoardWidget : public QWidget
{
    Q_OBJECT
public:
    explicit BoardWidget(QWidget *parent = 0);

    void setGameEngine(TicTacToeGameEngine *engine);

protected:
    void paintEvent(QPaintEvent *);
    void resizeEvent(QResizeEvent *);
    void mousePressEvent(QMouseEvent *e);

signals:
    void clicked(int row, int col);

public slots:

private:
    void paintValue(QPainter &painter, QString val, int row, int col);

private:
    TicTacToeGameEngine *m_engine;

    qreal x1, x2, y1, y2;
};

#endif // BOARDWIDGET_H
