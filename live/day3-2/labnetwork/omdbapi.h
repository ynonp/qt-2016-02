#ifndef OMDBAPI_H
#define OMDBAPI_H

#include <QObject>
#include <QtNetwork>

class OmdbApi : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString title READ title WRITE setTitle NOTIFY titleChanged)
    Q_PROPERTY(QString year READ year WRITE setYear NOTIFY yearChanged)
    Q_PROPERTY(QString imageUrl READ imageUrl WRITE setImageUrl NOTIFY imageUrlChanged)

public:
    explicit OmdbApi(QObject *parent = 0);

    QString title();
    QString year();
    QString imageUrl();

signals:
    void titleChanged(QString title);
    void yearChanged(QString year);
    void imageUrlChanged(QString imageUrl);

public slots:
    void search(QString keyword);
    void queryFinished(QNetworkReply *r);

    void setTitle(QString val);
    void setYear(QString val);
    void setImageUrl(QString val);

private:
    QNetworkAccessManager m_nam;
    QString m_title;
    QString m_year;
    QString m_imageUrl;
};

#endif // OMDBAPI_H
















