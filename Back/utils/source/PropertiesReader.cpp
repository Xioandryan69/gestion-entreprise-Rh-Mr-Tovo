#include "PropertiesReader.h"

#include <QFile>
#include <QDebug>
#include <QDir>
#include <QTextStream>

bool PropertiesReader::load(const QString& chemin) {
    QFile fichier(chemin);

    if(!fichier.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qCritical() << "Impossible d'ouvrire le fichier";
        return false;
    }

    QTextStream flux(&fichier);

    while(!flux.atEnd()) {
        QString ligne = flux.readLine().trimmed();
        if(ligne.isEmpty() || ligne.startsWith("#") || ligne.startsWith("!")) {
            continue;
        }
        int separateur = ligne.indexOf("=");
        if(separateur == -1) {
            continue;
        }
        QString clee = ligne.left(separateur).trimmed();
        QString valeur = ligne.mid(separateur+1).trimmed();
        properties.insert(clee,valeur);
    }
    return true;
}

QString PropertiesReader::get(const QString& clee, const QString& valeurParDefaut) const {
    return properties.value(clee,valeurParDefaut);
}