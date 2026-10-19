#include <QCoreApplication>

#include <QSqlQuery>

#include "Initializer.h"
#include "Routeur.h"

#include "LoginController.h"

int main(int argc, char* argv[]) {
    QCoreApplication app(argc,argv);

    Initializer initializer;

    if(!initializer.init()) {
        qInfo() << "Erreur d'initialisation";
        return 1;
    }

    return app.exec();
}