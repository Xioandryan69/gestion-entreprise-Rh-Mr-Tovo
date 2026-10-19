#pragma once

#include <functional>

#include <QHttpServer>
#include <QHttpServerResponse>
#include <QJsonDocument>
#include <QJsonObject>

#include "Requete.h"

class Routeur {
    private:
        QHttpServer& serveur;

        QHttpServerResponse convertirJSON(const QJsonObject& json) const;

    public:
        explicit Routeur(QHttpServer& serveur);

        void get(const QString& url,std::function<QJsonObject(const Requete&)>action);
        void post(const QString& url,std::function<QJsonObject(const Requete&)>action);
        void put(const QString& url,std::function<QJsonObject(const Requete&)>action);
        void pacth(const QString& url,std::function<QJsonObject(const Requete&)>action);
        void sup(const QString& url,std::function<QJsonObject(const Requete&)>action);
};