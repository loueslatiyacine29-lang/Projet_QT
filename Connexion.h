#ifndef CONNEXION_H
#define CONNEXION_H

#include <QSqlDatabase>
#include <QString>

class Connexion
{
public:
    Connexion();
    bool createconnexion();
    void fermerConnexion();
    QString getLastError() const;

private:
    QString lastError;
};

#endif // CONNEXION_H
