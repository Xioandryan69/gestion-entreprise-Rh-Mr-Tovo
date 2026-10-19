#pragma once

#include "LoginService.h"
#include "Routeur.h"

class LoginController {
private:
    LoginService& service;

public:
    explicit LoginController(LoginService& loginService);

    QJsonObject login(const Requete& requete);
};