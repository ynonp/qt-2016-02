#ifndef COUNTER_H
#define COUNTER_H

#include <QWidget>

namespace Ui {
class Counter;
}

class Counter : public QWidget
{
    Q_OBJECT

public:
    explicit Counter(QWidget *parent = 0);
    ~Counter();

private slots:
    void inc();

    void updateText();
private:
    Ui::Counter *ui;

    int m_count;











};

#endif // COUNTER_H
