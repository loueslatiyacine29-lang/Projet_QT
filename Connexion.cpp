#include "connexion.h"
#include <QSqlError>

Connexion::Connexion() : lastError("")
{
}
bool Connexion::createconnexion()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");

    // Connects directly to Oracle without relying on Windows DSN setup:
    db.setDatabaseName("DRIVER={Oracle in XE};DBQ=localhost:1521/XE;Uid=admin;Pwd=admin123;");

    bool opened = db.open();
    if (!opened) {
        lastError = db.lastError().text();
    }
    return opened;
}

void Connexion::fermerConnexion()
{
    QSqlDatabase::database().close();
}

QString Connexion::getLastError() const
{
    return lastError;
}

