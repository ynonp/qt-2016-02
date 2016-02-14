#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimer>

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
    void start();
    void stop();

    void showQueueCount();

private:
    Ui::MainWindow *ui;    

    QStringList m_queue;
    QMutex m_mutex;
    bool m_running;
    QTimer m_timer;
};

#endif // MAINWINDOW_H
