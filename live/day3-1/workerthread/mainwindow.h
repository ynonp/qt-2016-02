#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "myfilewriter.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(MyFileWriter &writer, QWidget *parent = 0);
    ~MainWindow();

signals:
    void askWorkerToStartWriting(QString fileName);

private slots:
    void startWrite();
    void writeDone(QString fileName);

private:
    Ui::MainWindow *ui;
    MyFileWriter &m_writer;
};

#endif // MAINWINDOW_H








