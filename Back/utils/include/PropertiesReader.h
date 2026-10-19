#pragma once

#include <QMap>

class PropertiesReader {
    private:
        QMap<QString,QString> properties;
    public:
        bool load(const QString& chemin);

        QString get(const QString& clee, const QString& valeurParDefaut = "") const;
};