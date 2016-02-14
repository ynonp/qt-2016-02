#ifndef COUNTEDTEXTEDIT_H
#define COUNTEDTEXTEDIT_H

#include <QWidget>

namespace Ui {
class CountedTextEdit;
}

class CountedTextEdit : public QWidget
{
    Q_OBJECT

public:
    explicit CountedTextEdit(QWidget *parent = 0);
    ~CountedTextEdit();

    void installEventFilterOnTextedit(QObject *filter);

private slots:
    void handleTextChanged();


private:
    Ui::CountedTextEdit *ui;
};

#endif // COUNTEDTEXTEDIT_H
