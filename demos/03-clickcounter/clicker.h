#ifndef CLICKER_H
#define CLICKER_H

#include <QWidget>

namespace Ui {
class Clicker;
}

class Clicker : public QWidget
{
    Q_OBJECT

public:
    explicit Clicker(QWidget *parent = 0);
    ~Clicker();

private slots:
    void handleClick();

private:
    Ui::Clicker *ui;
    int m_clicks;
    QString m_displayText;
};

#endif // CLICKER_H
