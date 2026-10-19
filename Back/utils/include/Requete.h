#pragma once

#include <QHttpServerRequest>
#include <QUrlQuery>
#include <QJsonDocument>
#include <QJsonObject>
#include <QString>

class Requete {
    private:
        QHttpServerRequest requete;

    public:
        explicit Requete(const QHttpServerRequest& requete);

        int queryInt(const QString& nom, const int valeurParDefaut = 0) const;

        bool queryBool(const QString& nom, const bool valeurParDefaut = false) const;

        QString queryString(const QString& nom, const QString& valeurParDefaut = "") const;

        QString header(const QString& nom) const;

        QByteArray body() const;
        QJsonObject json() const;
};