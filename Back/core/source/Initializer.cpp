#include "Initializer.h"

#include <QDir>
#include <QCoreApplication>

bool Initializer::init() {
    QString chemin = "config/application.properties";

    if(!properties.load(chemin)) {
        return false;
    }
    if(!initDatabase()) {
        return false;
    }
    if(!initServeur()) {
        return false;
    }
    if(!initFichierStatiques()) {
        return false;
    }
    if(!initPageRouteur()) {
        return false;
    }   
    if(!initRouteur()) {
        return false;
    }

    routeWeb = std::make_unique<Web>(*pageRouteur);
    routeWeb->declarationDesRoutesWeb();

    routeApi = std::make_unique<Api>(*apiRouteur, base);
    routeApi->declarationDesRoutesApi();

    if (!serveur.lancerServeur()) {
        qCritical() << "Erreur lors du lancement du serveur";
        return false;
    }

return true;


}   

bool Initializer::initDatabase() {
    if(!base.initDatabase(
        properties.get("database.driver"),
        properties.get("database.host"),
        properties.get("database.port").toUShort(),
        properties.get("database.name"),
        properties.get("database.user"),
        properties.get("database.password")   
    )) {
        return false;
    }
    return true;
}

bool Initializer::initServeur() {
    serveur.initServeur(
        properties.get("server.port").toUShort()
    );
    return true;
}

bool Initializer::initFichierStatiques() {
    // Récupérer le dossier Front depuis la configuration
    QString dossier = QDir(
        QCoreApplication::applicationDirPath()
    ).filePath(properties.get("server.static_dir"));

    fichiersStatiques = std::make_unique<StaticFiles>(dossier);

    // Enregistrer le moteur de fichiers sur le serveur HTTP
    fichiersStatiques->enregistrer(serveur.getHttpServer());
    return true;
}

bool Initializer::initPageRouteur() {
    pageRouteur = std::make_unique<PageRouteur>(
        serveur.getHttpServer(),properties.get("server.static_dir")
    );
    return true;
}

bool Initializer::initRouteur() {
    apiRouteur = std::make_unique<Routeur>(serveur.getHttpServer());
    return true;
}

Database& Initializer::getDatabase() {
    return base;
}

Serveur& Initializer::getServeur() {
    return serveur;
}

PageRouteur& Initializer::getPageRouteur() {
    return *pageRouteur;
}