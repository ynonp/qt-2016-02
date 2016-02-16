
#include <QtGui>
#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc,argv);

    QWidget w;
    QHBoxLayout *layout = new QHBoxLayout(&w);

    QSlider *slider = new QSlider(Qt::Horizontal);
    layout->addWidget(slider);

    QSpinBox *box = new QSpinBox();
    layout->addWidget(box);

    QObject::connect(slider, SIGNAL(valueChanged(int)),
                     box, SLOT(setValue(int)));




    w.show();

    return app.exec();
}
