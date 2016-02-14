#include <QtGui>
#include <QtWidgets>

int main(int argc, char **argv)
{
    QApplication app(argc, argv);

    QColor color;

    QWidget w;
    QVBoxLayout *lv = new QVBoxLayout();
    QHBoxLayout *lh = new QHBoxLayout();
    w.setLayout(lv);
    lv->addLayout(lh);

    QPushButton *btn = new QPushButton("Select Color", &w);
    lv->addWidget(btn);

    QLabel *header = new QLabel("Color Is: ", &w);
    lh->addWidget(header);

    QLabel *value = new QLabel(color.name());
    lh->addWidget(value);
    lh->addStretch();

    QObject::connect(btn, &QPushButton::clicked,
                     [&] () {
        QColor newColor = QColorDialog::getColor(color);
        if (newColor.isValid())
        {
            color = newColor;
            value->setText(color.name());
            value->setStyleSheet(QString("background: %1").arg(color.name()));
        }
    });

    w.show();

    return app.exec();
}
