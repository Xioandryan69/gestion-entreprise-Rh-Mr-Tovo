#pragma once

#include "PropertiesReader.h"
#include "Serveur.h"
#include "Database.h"
#include "StaticFiles.h"
#include "PageRouteur.h"
#include "Routeur.h"
#include "Api.h"
#include "Web.h"

#include <memory>

class Initializer {
    private:
        PropertiesReader properties;
        Serveur serveur;
        Database base;

        std::unique_ptr<PageRouteur> pageRouteur;
        std::unique_ptr<Routeur> apiRouteur;

        std::unique_ptr<StaticFiles> fichiersStatiques;

        std::unique_ptr<Web> routeWeb;
        std::unique_ptr<Api> routeApi;
    public:
        bool init();

        bool initDatabase();
        bool initServeur();
        bool initFichierStatiques();
        bool initPageRouteur();
        bool initRouteur();

        Serveur& getServeur();
        Database& getDatabase();
        PageRouteur& getPageRouteur();
};