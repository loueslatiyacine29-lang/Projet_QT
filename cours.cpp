#include "cours.h"
#include "qsqlquery.h"

// =========================
// Constructeurs
// =========================

COURS::COURS()
{
}

COURS::COURS(int ID_COUR,
             QString NOM,
             QString DESCRIPTION,
             QDate DATE_DEBUT,
             QDate DATE_FIN,
             int PRIX,
             QString NIVEAU,
             int ID_SALLE)
{
    this->ID_COUR = ID_COUR;
    this->NOM = NOM;
    this->DESCRIPTION = DESCRIPTION;
    this->DATE_DEBUT = DATE_DEBUT;
    this->DATE_FIN = DATE_FIN;
    this->PRIX = PRIX;
    this->NIVEAU = NIVEAU;
    this->ID_SALLE = ID_SALLE;
}


// =========================
// ID_COUR
// =========================

void COURS::SET_ID_COUR(int ID)
{
    ID_COUR = ID;
}

int COURS::GET_ID_COUR()
{
    return ID_COUR;
}


// =========================
// NOM
// =========================

void COURS::SET_NOM(QString NOM)
{
    this->NOM = NOM;
}

QString COURS::GET_NOM()
{
    return NOM;
}


// =========================
// DESCRIPTION
// =========================

void COURS::SET_DESCRIPTION(QString DESCRIPTION)
{
    this->DESCRIPTION = DESCRIPTION;
}

QString COURS::GET_DESCRIPTION()
{
    return DESCRIPTION;
}


// =========================
// DATE_DEBUT
// =========================

void COURS::SET_DATE_DEBUT(QDate DATE_DEBUT)
{
    this->DATE_DEBUT = DATE_DEBUT;
}

QDate COURS::GET_DATE_DEBUT()
{
    return DATE_DEBUT;
}


// =========================
// DATE_FIN
// =========================

void COURS::SET_DATE_FIN(QDate DATE_FIN)
{
    this->DATE_FIN = DATE_FIN;
}

QDate COURS::GET_DATE_FIN()
{
    return DATE_FIN;
}


// =========================
// PRIX
// =========================

void COURS::SET_PRIX(int PRIX)
{
    this->PRIX = PRIX;
}

int COURS::GET_PRIX()
{
    return PRIX;
}


// =========================
// NIVEAU
// =========================

void COURS::SET_NIVEAU(QString NIVEAU)
{
    this->NIVEAU = NIVEAU;
}

QString COURS::GET_NIVEAU()
{
    return NIVEAU;
}


// =========================
// ID_SALLE
// =========================

void COURS::SET_ID_SALLE(int ID_SALLE)
{
    this->ID_SALLE = ID_SALLE;
}

int COURS::GET_ID_SALLE()
{
    return ID_SALLE;
}


// =========================
// AJOUTER
// =========================

bool COURS::ajouter()
{
    QSqlQuery query;

    query.prepare(
        "INSERT INTO COURS "
        "(ID_COUR, NOM, DESCRIPTION, DATE_DEBUT, DATE_FIN, PRIX, NIVEAU, ID_SALLE) "
        "VALUES "
        "(:id, :nom, :description, :date_debut, :date_fin, :prix, :niveau, :id_salle)"
        );

    query.bindValue(":id", ID_COUR);
    query.bindValue(":nom", NOM);
    query.bindValue(":description", DESCRIPTION);
    query.bindValue(":date_debut", DATE_DEBUT);
    query.bindValue(":date_fin", DATE_FIN);
    query.bindValue(":prix", PRIX);
    query.bindValue(":niveau", NIVEAU);
    query.bindValue(":id_salle", ID_SALLE);

    bool test = query.exec();

    if (test == true)
        return true;
    else
        return false;
}


// =========================
// ID EXISTS
// =========================

bool COURS::idExists(int id)
{
    QSqlQuery query;

    query.prepare(
        "SELECT COUNT(*) "
        "FROM COURS "
        "WHERE ID_COUR = :id"
        );

    query.bindValue(":id", id);

    if (query.exec() && query.next())
    {
        int count = query.value(0).toInt();

        return count > 0;
    }

    return false;
}


// =========================
// MODIFIER
// =========================

bool COURS::modifier()
{
    QSqlQuery query;

    query.prepare(
        "UPDATE COURS SET "
        "NOM = :nom, "
        "DESCRIPTION = :description, "
        "DATE_DEBUT = :date_debut, "
        "DATE_FIN = :date_fin, "
        "PRIX = :prix, "
        "NIVEAU = :niveau, "
        "ID_SALLE = :id_salle "
        "WHERE ID_COUR = :id"
        );

    query.bindValue(":id", ID_COUR);
    query.bindValue(":nom", NOM);
    query.bindValue(":description", DESCRIPTION);
    query.bindValue(":date_debut", DATE_DEBUT);
    query.bindValue(":date_fin", DATE_FIN);
    query.bindValue(":prix", PRIX);
    query.bindValue(":niveau", NIVEAU);
    query.bindValue(":id_salle", ID_SALLE);

    return query.exec();
}


// =========================
// SUPPRIMER
// =========================

bool COURS::supprimer(int id)
{
    QSqlQuery query;

    query.prepare(
        "DELETE FROM COURS "
        "WHERE ID_COUR = :id"
        );

    query.bindValue(":id", id);

    return query.exec();
}


// =========================
// AFFICHER
// =========================

QSqlQueryModel* COURS::afficher()
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery(
        "SELECT * FROM COURS"
        );

    return model;
}


// =========================
// CHERCHER
// =========================

QSqlQueryModel* COURS::chercher(QString column, QString text)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery(
        "SELECT * FROM COURS "
        "WHERE " + column + " LIKE '%" + text + "%'"
        );

    return model;
}


// =========================
// TRI
// =========================

QSqlQueryModel* COURS::tri(QString column, QString choix)
{
    QSqlQueryModel* model = new QSqlQueryModel();

    model->setQuery(
        "SELECT * FROM COURS "
        "ORDER BY " + column + " " + choix
        );

    return model;
}


// =========================
// LISTE DES ID SALLES
// =========================

QList<int> COURS::ListIdSalle()
{
    QList<int> list;

    QSqlQuery query;

    query.prepare(
        "SELECT ID_SALLE "
        "FROM SALLES"
        );

    if (query.exec())
    {
        while (query.next())
        {
            list.append(query.value(0).toInt());
        }
    }

    return list;
}

// =========================
// STAT
// =========================

QMap<QString, int> COURS::statistiquesParNiveau() {
    QMap<QString, int> NiveauStats;

    QSqlQuery query;
    query.prepare("SELECT NIVEAU, COUNT(*) as count FROM COURS GROUP BY NIVEAU");

    if (query.exec()) {
        while (query.next()) {
            QString Niveau = query.value(0).toString();
            int count = query.value(1).toInt();
            NiveauStats[Niveau] = count;
        }
    }

    return NiveauStats;
}
