#ifndef MYFILEWRITER_H
#define MYFILEWRITER_H

#include <QObject>

class MyFileWriter: public QObject
{
    Q_OBJECT

public:    
    MyFileWriter();

signals:
    void done(QString filename);

public slots:
    void writeToFile(QString file);


};

#endif // MYFILEWRITER_H
