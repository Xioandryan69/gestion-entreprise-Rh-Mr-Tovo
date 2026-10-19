#pragma once

#include <QHttpServer>
#include <QString>

class StaticFiles {
    private:
        QString dossier;
    public:
        explicit StaticFiles(const QString& chemin);

        void enregistrer(QHttpServer& serveur);
};