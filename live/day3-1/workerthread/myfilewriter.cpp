#include "myfilewriter.h"
#include <QtCore>

MyFileWriter::MyFileWriter()
{

}

void MyFileWriter::writeToFile(QString file)
{
    QFile f(file);
    f.open(QIODevice::WriteOnly);
    for(int i=0; i <100000000; i++)
    {
        f.write("I'll never throw candies at people again\n");
    }
    f.close();
    emit done(file);
}










