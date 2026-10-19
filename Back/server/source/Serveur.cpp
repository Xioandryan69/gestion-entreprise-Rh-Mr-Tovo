#include "Serveur.h"

#include "PropertiesReader.h"

Serveur::Serveur() {}

Serveur::~Serveur() {}

QHttpServer& Serveur::getHttpServer() {
    return httpServer;
}

QTcpServer& Serveur::getTcpServer() {
    return tcpServer;
}

bool Serveur::lancerServeur() {
    if(!tcpServer.listen(QHostAddress::Any, port)) {
        qCritical() << tcpServer.errorString();
        return false;
    }
    
    httpServer.bind(&tcpServer);

    qInfo() << "SERVEUR DEMARER SUR LE PORT:"
            << tcpServer.serverPort();

    return true;
}

void Serveur::initServeur(quint16 p) {
    port = p;
}