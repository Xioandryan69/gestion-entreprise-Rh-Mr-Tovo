#include "Requete.h"

Requete::Requete(const QHttpServerRequest& req) : requete(req) {}

QString Requete::queryString(const QString& nom, const QString& valeurParDefaut) const {
    QUrlQuery params(requete.url());
    if(!params.hasQueryItem(nom)) {
        return valeurParDefaut;
    }
    return params.queryItemValue(nom);
}

int Requete::queryInt(const QString& nom, const int valeurParDefaut) const {
    bool ok = false;
    QString val = queryString(nom);

    if(val.isEmpty()) {
        return valeurParDefaut;
    }
    int resultat = val.toInt(&ok);
    
    if(!ok) {
        return valeurParDefaut;
    }
    return resultat;
}

bool Requete::queryBool(const QString& nom, const bool valeurParDefaut) const {
    QString valeur = queryString(nom).toLower();
    
    if(valeur == "true" || valeur == "1") {
        return true;
    }
    if(valeur == "false" || valeur == "0") {
        return false;
    }

    return valeurParDefaut;
}

QString Requete::header(const QString& nom) const {
    return QString::fromUtf8(
        requete.value(nom.toUtf8())  
    );
}

QByteArray Requete::body() const {
    return requete.body();
}

QJsonObject Requete::json() const {
    QJsonParseError erreur;
    QJsonDocument document = QJsonDocument::fromJson(requete.body(), &erreur);
    if(erreur.error != QJsonParseError::NoError || !document.isObject()) {
        return {};
    }
    return document.object();
}