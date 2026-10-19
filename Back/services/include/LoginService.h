#pragma once

#include "LoginRepository.h"

#include <QString>
#include <QJsonObject>

class LoginService {
private:
    LoginRepository& repository;

public:
    explicit LoginService(LoginRepository& repo);

    QJsonObject connecter(
        const QString& login,
        const QString& password
    );
};