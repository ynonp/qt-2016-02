#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QtCore>

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();    

private slots:
    void onClick();
    void handleProcFinished();



private:
    Ui::MainWindow *ui;
    QProcess m_proc;

};

#endif // MAINWINDOW_H
