#include "omdbapi.h"
#include <QDebug>
#include <QJsonDocument>
#include <QJsonObject>
#include <QJsonArray>

OmdbApi::OmdbApi(QObject *parent) : QObject(parent)
{

}

void OmdbApi::gotResponse(QNetworkReply *r)
{
    auto doc = QJsonDocument::fromJson(r->readAll());
    QJsonObject root = doc.object();
    QJsonArray results = root.value("Search").toArray();

    QJsonObject first = results.at(0).toObject();
    qDebug() << first.value("Title").toString();

}

