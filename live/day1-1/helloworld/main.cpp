#include <QtWidgets/QApplication>
#include <QtWidgets/QLabel>
#include <QtWidgets>
#include <QtGui>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget w;
    QVBoxLayout *layout = new QVBoxLayout(&w);

    QLabel *l = new QLabel("Hello World");
    QLabel *t = new QLabel("Hello World");

    layout->addWidget(l);
    layout->addWidget(t);

    w.show();

    return app.exec();
}
