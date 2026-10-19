#pragma once

#include <QHttpServer>
#include <QTcpServer>

class Serveur {
    private:
        quint16     port;
        QHttpServer httpServer;
        QTcpServer  tcpServer;

    public:   
        Serveur();
        ~Serveur();

        QHttpServer& getHttpServer();
        QTcpServer& getTcpServer();

        void initServeur(quint16 p);

        bool lancerServeur();
};