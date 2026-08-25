#include "cours.h"

COURS::COURS() {}

COURS::COURS(int ID_COUR, QString NOM, QString DESCRIPTION, QDate DATE_DEBUT, QDate DATE_FIN, int PRIX, QString NIVEAU, int ID_SALLE)
{
    this->ID_COUR=ID_COUR;
    this->NOM=NOM;
    this->DESCRIPTION=DESCRIPTION;
    this->DATE_DEBUT=DATE_DEBUT;
    this->DATE_FIN=DATE_FIN;
    this->PRIX=PRIX;
    this->NIVEAU=NIVEAU;
    this->ID_SALLE=ID_SALLE;
}

void COURS::SET_ID_COUR(int ID)
{
    ID_COUR=ID;
}

int COURS::GET_ID_COUR()
{
    return ID_COUR;
}

void COURS::SET_NOM(QString NOM)
{
    this->NOM=NOM;
}

QString COURS::GET_NOM()
{
    return NOM;
}

void COURS::SET_DESCRIPTION(QString DESCRIPTION)
{
    this->DESCRIPTION=DESCRIPTION;
}

QString COURS::GET_DESCRIPTION()
{
    return DESCRIPTION;
}

void COURS::SET_DATE_DEBUT(QDate DATE_DEBUT)
{
    this->DATE_DEBUT=DATE_DEBUT;
}

QDate COURS::GET_DATE_DEBUT()
{
    return DATE_DEBUT;
}

void COURS::SET_DATE_FIN(QDate DATE_FIN)
{
    this->DATE_FIN=DATE_FIN;
}

QDate COURS::GET_DATE_FIN()
{
    return DATE_FIN;
}

void COURS::SET_PRIX(int PRIX)
{
    this->PRIX=PRIX;
}

int COURS::GET_PRIX()
{
    return PRIX;
}

void COURS::SET_NIVEAU(QString NIVEAU)
{
    this->NIVEAU=NIVEAU;
}

QString COURS::GET_NIVEAU()
{
    return NIVEAU;
}

void COURS::SET_ID_SALLE(int ID_SALLE)
{
    this->ID_SALLE=ID_SALLE;
}

int COURS::GET_ID_SALLE()
{
    return ID_SALLE;
}
