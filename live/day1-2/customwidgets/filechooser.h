#ifndef FILECHOOSER_H
#define FILECHOOSER_H

#include <QWidget>

namespace Ui {
class FileChooser;
}

class FileChooser : public QWidget
{
    Q_OBJECT

public:
    explicit FileChooser(QWidget *parent = 0);
    ~FileChooser();

signals:
    void valueChanged(QString);

private slots:
    void showFileDialog();

private:
    Ui::FileChooser *ui;
};

#endif // FILECHOOSER_H













