#include "LoginRepository.h"

#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <QDebug>

LoginRepository::LoginRepository(Database& database)
    : base(database) {
}

QString LoginRepository::trouverMotDePasse(
    const QString& login,
    bool& trouve
) {
    trouve = false;

    QSqlQuery query(base.getConnection());

    query.prepare(
        "SELECT password FROM Logins WHERE login = :login"
    );

    query.bindValue(":login", login);

    if (!query.exec()) {
        qWarning() << "Erreur SQL :" << query.lastError().text();
        return {};
    }

    if (!query.next()) {
        return {};
    }

    trouve = true;
    return query.value(0).toString();
}