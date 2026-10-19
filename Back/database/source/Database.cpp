#include "Database.h"

#include "QSqlError"
#include <QDebug>


Database::Database() {}

Database::~Database() {
    closeConnection();
}

QSqlDatabase Database::getConnection() {
    if(!connection.isOpen()) {
        if(!connection.open()) {
            qCritical() << "Erreur PostgreSQL: " 
                        << connection.lastError().text();
            return QSqlDatabase();
        }
    }
    return connection;
}

bool Database::initDatabase(const QString& driver, const QString& host, const quint16& port, const QString& database,
const QString& user, const QString& password) {
    connection = QSqlDatabase::addDatabase(driver);

    connection.setHostName(host);
    connection.setPort(port);
    connection.setDatabaseName(database);
    connection.setUserName(user);
    connection.setPassword(password);

    return true;
}

void Database::closeConnection() {
    if(connection.isOpen()) {
        connection.close();
    }
}