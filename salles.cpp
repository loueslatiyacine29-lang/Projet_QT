#include "salles.h"
#include "qsqlquery.h"

SALLES::SALLES() {}

SALLES::SALLES(int id_salle, QString nom, int capacite, int numero, QString type_salle)
{
    ID_SALLE=id_salle;
    NOM=nom;
    CAPACITE=capacite;
    NUMERO=numero;
    TYPE_SALLE=type_salle;
}

void SALLES::setIdSalle(int id)
{
    ID_SALLE=id;
}

int SALLES::getIdSalle()
{
    return ID_SALLE;
}

void SALLES::setNom(QString nom)
{
    NOM=nom;
}

QString SALLES::getNom()
{
    return NOM;
}

void SALLES::setCapacite(int capacite)
{
    CAPACITE=capacite;
}

int SALLES::getCapacite()
{
    return CAPACITE;
}

void SALLES::setNumero(int numero)
{
    NUMERO=numero;
}

int SALLES::getNumero()
{
    return NUMERO;
}

void SALLES::setTypeSalle(QString type_salle)
{
    TYPE_SALLE=type_salle;
}

QString SALLES::getTypeSalle()
{
    return TYPE_SALLE;
}

bool SALLES::ajouter()
{

    QSqlQuery query;

    query.prepare("INSERT INTO SALLES (ID_SALLE,NOM,CAPACITE,NUMERO,TYPE_SALLE) "
                  "VALUES (:id,:nom,:capacite,:numero,:type_salle)");

    query.bindValue(":id",ID_SALLE);
    query.bindValue(":nom",NOM);
    query.bindValue(":capacite",CAPACITE);
    query.bindValue(":numero",NUMERO);
    query.bindValue(":type_salle",TYPE_SALLE);

    bool test=query.exec();
    if(test==true)
        return true;
    else
        return false;

}


bool SALLES::idExists(int id)
{
    QSqlQuery query;
    query.prepare("SELECT COUNT(*) FROM SALLES WHERE ID_SALLE = :id");
    query.bindValue(":id", id);

    if (query.exec() && query.next()) {
        int count = query.value(0).toInt();
        return count > 0;
    }

    return false;
}


bool SALLES::modifier()
{

    QSqlQuery query;

    query.prepare("UPDATE SALLES SET NOM = :nom, CAPACITE = :capacite, NUMERO = :numero, TYPE_SALLE = :type_salle "
                  " WHERE ID_SALLE = :id");
    query.bindValue(":id",ID_SALLE);
    query.bindValue(":nom",NOM);
    query.bindValue(":capacite",CAPACITE);
    query.bindValue(":numero",NUMERO);
    query.bindValue(":type_salle",TYPE_SALLE);

    return query.exec();

}


bool SALLES::supprimer(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM SALLES WHERE ID_SALLE=:id");
    query.bindValue(":id",id);
    return query.exec();
}

QSqlQueryModel* SALLES::afficher()
{
    QSqlQueryModel* model=new QSqlQueryModel();
    model->setQuery("SELECT * FROM SALLES");
    return model;



}

QSqlQueryModel* SALLES::chercher(QString column, QString text)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM SALLES WHERE " + column + " LIKE '%" + text + "%'");
    return model;
}

QSqlQueryModel* SALLES::tri(QString column, QString choix)//(SALLES ASC)
{
    QSqlQueryModel* model = new QSqlQueryModel();
    model->setQuery("SELECT * FROM SALLES ORDER BY " + column + " " + choix);
    return model;
}


// =========================
// STAT
// =========================

QMap<QString, int> SALLES::statistiquesParType() {
    QMap<QString, int> TypeStats;

    QSqlQuery query;
    query.prepare("SELECT TYPE_SALLE, COUNT(*) as count FROM SALLES GROUP BY TYPE_SALLE");

    if (query.exec()) {
        while (query.next()) {
            QString Type = query.value(0).toString();
            int count = query.value(1).toInt();
            TypeStats[Type] = count;
        }
    }

    return TypeStats;
}
