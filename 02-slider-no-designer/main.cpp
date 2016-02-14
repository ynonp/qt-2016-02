#include <QtGui>
#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QWidget w;
    QLCDNumber *lcd = new QLCDNumber(&w);
    QSlider *slider = new QSlider(Qt::Horizontal, &w);

    QVBoxLayout *layout = new QVBoxLayout(&w);
    layout->addWidget(slider);
    layout->addWidget(lcd);

    QObject::connect(slider, SIGNAL(valueChanged(int)),
                     lcd, SLOT(display(int)));
    w.show();

    return app.exec();

}
