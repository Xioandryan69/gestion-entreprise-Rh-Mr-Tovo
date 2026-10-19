#pragma once

#include <QSqlDatabase>

class Database {
    private:
        QSqlDatabase connection;
    
    public:
        Database();
        ~Database();

        QSqlDatabase getConnection();

        bool initDatabase(const QString& driver, const QString& host, 
                            const quint16& port, const QString& database,
                                const QString& user, const QString& password);
        void closeConnection();
};