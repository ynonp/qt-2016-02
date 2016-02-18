#include <QCoreApplication>
#include <QtNetwork>
#include <QDebug>
#include "omdbapi.h"
int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    QNetworkAccessManager nam;
    QUrl url("http://omdbapi.com/?s=fargo");
    QNetworkRequest req(url);
    nam.get(req);
    OmdbApi api;


    QObject::connect(&nam, SIGNAL(finished(QNetworkReply*)),
                     &api, SLOT(gotResponse(QNetworkReply*)));


    return a.exec();
}

