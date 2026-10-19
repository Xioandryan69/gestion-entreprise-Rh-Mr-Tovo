#include "LoginController.h"

LoginController::LoginController(LoginService& loginService)
    : service(loginService) {
}

QJsonObject LoginController::login(const Requete& requete) {
    QJsonObject donnees = requete.json();

    QString login = donnees.value("utilisateur").toString();
    QString password = donnees.value("password").toString();

    return service.connecter(login, password);
}