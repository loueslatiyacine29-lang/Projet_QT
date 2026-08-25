#ifndef CONNEXION_H
#define CONNEXION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>

class Connexion
{
public:
    Connexion();
    bool createconnexion();
    void fermerConnexion();
    QSqlDatabase db;

};

#endif // CONNECTION_H
