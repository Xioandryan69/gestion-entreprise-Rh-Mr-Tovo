#include "StaticFiles.h"

#include <QFile>
#include <QFileInfo>
#include <QMimeDatabase>
#include <QHttpServerResponder>
#include <QDir>

StaticFiles::StaticFiles(const QString& chemin)
    : dossier(QDir(chemin).absolutePath()) {
}

void StaticFiles::enregistrer(QHttpServer& serveur) {
    serveur.setMissingHandler(
        &serveur,
        [this](const QHttpServerRequest& requete, QHttpServerResponder& reponse) {
            QString chemin = requete.url().path();

            if(chemin == "/") {
                chemin = "/index.html";
            }

            QString fichier = QDir(dossier).filePath(chemin.mid(1));
            QFileInfo info(fichier);

            if(!info.exists() || !info.isFile()) {
                reponse.write(
                    "Fichier Introuvable",
                    "text/plain",
                    QHttpServerResponder::StatusCode::NotFound
                );
                return;
            }

            QFile f(fichier);

            if(!f.open(QIODevice::ReadOnly)) {
                reponse.write(
                    "Impossible de lire le fichier",
                    "text/plain",
                    QHttpServerResponder::StatusCode::NotFound
                );
                return;
            }

            QByteArray contenu = f.readAll();

            QMimeDatabase mime;
            QByteArray type = mime.mimeTypeForFile(info).name().toUtf8();

            reponse.write(
                contenu,
                type,
                QHttpServerResponder::StatusCode::Ok
            );
        }
    );
}