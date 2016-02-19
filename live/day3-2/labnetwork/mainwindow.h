#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>

#include "omdbapi.h"
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
    void search();

private:
    Ui::MainWindow *ui;
    OmdbApi api;
};

#endif // MAINWINDOW_H
