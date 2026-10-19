#pragma once

#include <QHttpServer>
#include <QString>

class PageRouteur {
    private:
        QHttpServer& serveur;
        QString dossier;
    public:
        PageRouteur(QHttpServer& serve, const QString& dossierFront);

        void page(const QString& url, const QString& fichier);
};