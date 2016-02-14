#ifndef COUNTEDTEXTAREA_H
#define COUNTEDTEXTAREA_H

#include <QWidget>

namespace Ui {
class CountedTextarea;
}

class CountedTextarea : public QWidget
{
    Q_OBJECT

public:
    explicit CountedTextarea(QWidget *parent = 0);
    ~CountedTextarea();

    QString getText();

private slots:
    void textChanged();

private:    
    Ui::CountedTextarea *ui;
    QString m_lengthText;
};

#endif // COUNTEDTEXTAREA_H
