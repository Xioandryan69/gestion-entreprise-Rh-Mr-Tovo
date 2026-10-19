#pragma once

#include "Database.h"

#include <QString>

class LoginRepository {
private:
    Database& base;

public:
    explicit LoginRepository(Database& database);

    QString trouverMotDePasse(
        const QString& login,
        bool& trouve
    );
};