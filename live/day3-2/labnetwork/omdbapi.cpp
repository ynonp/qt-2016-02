#include "omdbapi.h"
#include <QtCore>
#include <QJsonArray>
#include <QJsonDocument>

OmdbApi::OmdbApi(QObject *parent) : QObject(parent)
{
    QObject::connect(&m_nam, SIGNAL(finished(QNetworkReply*)),
                     this, SLOT(queryFinished(QNetworkReply*)));
}

QString OmdbApi::title()
{
    return m_title;
}

QString OmdbApi::year()
{
    return m_year;
}

QString OmdbApi::imageUrl()
{
    return m_imageUrl;
}

void OmdbApi::search(QString keyword)
{
    QUrl url(QString("http://omdbapi.com/?s=%1").arg(keyword));
    QNetworkRequest req(url);
    m_nam.get(req);

}

void OmdbApi::queryFinished(QNetworkReply *r)
{
    auto doc = QJsonDocument::fromJson(r->readAll());
    QJsonObject root = doc.object();
    QJsonArray results = root.value("Search").toArray();

    QJsonObject first = results.at(0).toObject();
    setTitle(first.value("Title").toString());
    setYear(first.value("Year").toString());
    setImageUrl(first.value("Poster").toString());
}

void OmdbApi::setTitle(QString val)
{
    m_title = val;
    emit titleChanged(val);
}

void OmdbApi::setYear(QString val)
{
    m_year = val;
    emit yearChanged(val);
}

void OmdbApi::setImageUrl(QString val)
{
    m_imageUrl = val;
    emit imageUrlChanged(val);
}






















