#ifndef OMDBAPI_H
#define OMDBAPI_H

#include <QObject>
#include <QtNetwork>

class OmdbApi : public QObject
{
    Q_OBJECT
public:
    explicit OmdbApi(QObject *parent = 0);

signals:

public slots:
    void gotResponse(QNetworkReply *r);
};

#endif // OMDBAPI_H
