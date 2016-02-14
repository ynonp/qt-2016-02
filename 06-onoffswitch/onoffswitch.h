#ifndef ONOFFSWITCH_H
#define ONOFFSWITCH_H

#include <QWidget>
#include <QtGUi>

class OnOffSwitch : public QWidget
{
    Q_OBJECT
public:
    explicit OnOffSwitch(QWidget *parent = 0);

    QSize minimumSizeHint() const;

protected:
    void paintEvent(QPaintEvent *);
    void mousePressEvent(QMouseEvent *e);

signals:

public slots:

private:
    int m_topHeight;
    bool m_isOn;
};

#endif // ONOFFSWITCH_H
