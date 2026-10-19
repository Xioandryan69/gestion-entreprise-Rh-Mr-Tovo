#include "Routeur.h"

QHttpServerResponse Routeur::convertirJSON(const QJsonObject& json) const {
    return QHttpServerResponse(
        "application/json",
        QJsonDocument(json).toJson(QJsonDocument::Compact)
    );
}

Routeur::Routeur(QHttpServer& serve) : serveur(serve) {}

void Routeur::get(const QString& url, std::function<QJsonObject(const Requete&)>action) {
    serveur.route(
        url,
        QHttpServerRequest::Method::Get,
        [this,action](const QHttpServerRequest& request) {
            Requete req(request);
            return convertirJSON(action(req));
        }
    );
}

void Routeur::post(const QString& url, std::function<QJsonObject(const Requete&)>action) {
    serveur.route(
        url,
        QHttpServerRequest::Method::Post,
        [this,action](const QHttpServerRequest& request) {
            Requete req(request);
            return convertirJSON(action(req));
        }
    );
}

void Routeur::put(const QString& url, std::function<QJsonObject(const Requete&)>action) {
    serveur.route(
        url,
        QHttpServerRequest::Method::Put,
        [this,action](const QHttpServerRequest& request) {
            Requete req(request);
            return convertirJSON(action(req));
        }
    );
}

void Routeur::pacth(const QString& url, std::function<QJsonObject(const Requete&)>action) {
    serveur.route(
        url,
        QHttpServerRequest::Method::Patch,
        [this,action](const QHttpServerRequest request) {
            Requete req(request);
            return convertirJSON(action(req));
        }
    );
}

void Routeur::sup(const QString& url, std::function<QJsonObject(const Requete&)>action) {
    serveur.route(
        url,
        QHttpServerRequest::Method::Delete,
        [this,action](const QHttpServerRequest request) {
            Requete req(request);
            return convertirJSON(action(req));
        }
    );
}