#include "PageRouteur.h"

#include <QFile>
#include <QDir>
#include <QHttpServerResponse>

PageRouteur::PageRouteur(QHttpServer& serve, const QString& doc) : serveur(serve), dossier(doc) {}

void PageRouteur::page(const QString& url, const QString& fichier) {
    QString chemin = QDir(dossier).filePath(fichier);

    serveur.route(
        url,
        QHttpServerRequest::Method::Get,
        [chemin]() -> QHttpServerResponse {
            QFile f(chemin);

            if(!f.open(QIODevice::ReadOnly)) {
                return QHttpServerResponse(
                    QHttpServerResponder::StatusCode::NotFound
                );
            }

            return QHttpServerResponse(
                "text/html; charset=utf-8",
                f.readAll()
            );
        }
    );
}
