#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QThreadPool>
#include "producer.h"
#include "consumer.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    QObject::connect(ui->btnStart, &QPushButton::clicked,
                     this, &MainWindow::start);

    QObject::connect(ui->btnStop, &QPushButton::clicked,
                     this, &MainWindow::stop);

    QObject::connect(&m_timer, &QTimer::timeout,
                     this, &MainWindow::showQueueCount);

    m_running = false;
    m_timer.setInterval(500);
}

MainWindow::~MainWindow()
{
    m_running = false;
    QThreadPool::globalInstance()->waitForDone();
    delete ui;
}

void MainWindow::start()
{
    ui->boxConsumers->setEnabled(false);
    ui->boxProducers->setEnabled(false);
    ui->btnStart->setEnabled(false);
    ui->btnStop->setEnabled(true);

    int consumers = ui->boxConsumers->value();
    int producers = ui->boxProducers->value();

    qDebug() << "Starting " << consumers << " and " << producers;
    m_queue.clear();

    QThreadPool *pool = QThreadPool::globalInstance();
    m_running = true;

    for (int i=0; i < producers; i++)
    {
        pool->start(new Producer(m_queue, m_mutex, i, &m_running));
    }

    for (int i=0; i < consumers; i++)
    {
        pool->start(new Consumer(m_queue, m_mutex, &m_running));
    }

    pool->setMaxThreadCount(consumers + producers);

    m_timer.start();
}

void MainWindow::stop()
{
    ui->boxConsumers->setEnabled(true);
    ui->boxProducers->setEnabled(true);
    ui->btnStart->setEnabled(true);
    ui->btnStop->setEnabled(false);

    m_timer.stop();
    m_running = false;
}

void MainWindow::showQueueCount()
{
    m_mutex.lock();
    int sz = m_queue.size();
    m_mutex.unlock();

    qDebug() << "Count = " << sz;
    ui->value->display(sz);
}
