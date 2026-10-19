#include "LoginService.h"

LoginService::LoginService(LoginRepository& repo)
    : repository(repo) {
}

QJsonObject LoginService::connecter(
    const QString& login,
    const QString& password
) {
    if (login.trimmed().isEmpty() || password.isEmpty()) {
        return {
            {"success", false},
            {"message", "Login et mot de passe obligatoires"}
        };
    }

    bool trouve = false;

    QString motDePasseEnregistre =
        repository.trouverMotDePasse(login.trimmed(), trouve);

    if (!trouve || motDePasseEnregistre != password) {
        return {
            {"success", false},
            {"message", "Identifiants incorrects"}
        };
    }

    return {
        {"success", true},
        {"message", "Connexion réussie"},
        {"login", login.trimmed()}
    };
}