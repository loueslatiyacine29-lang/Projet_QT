
#include <QApplication>
#include <QMessageBox>
#include <QDebug>
#include "connexion.h"
#include <QObject>


Connexion::Connexion()
{

}

bool Connexion::createconnexion()
{bool test=false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("wes");
    db.setUserName("SYSTEM");
    db.setPassword("wes");

    if (db.open())
        test=true;
    return  test;
}

void Connexion::fermerConnexion()
{
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.close();
}

