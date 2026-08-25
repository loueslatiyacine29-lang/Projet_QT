#include "salles.h"

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
