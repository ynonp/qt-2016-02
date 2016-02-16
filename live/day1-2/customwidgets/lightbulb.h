#ifndef LIGHTBULB_H
#define LIGHTBULB_H

#include <QWidget>

class LightBulb : public QWidget
{
    Q_OBJECT
public:
    explicit LightBulb(QWidget *parent = 0);

signals:

public slots:

    // QWidget interface
public:
    virtual QSize sizeHint() const;

protected:
    virtual void paintEvent(QPaintEvent *);
    virtual void mousePressEvent(QMouseEvent *);


private:
    bool m_isOn;

};

#endif // LIGHTBULB_H




