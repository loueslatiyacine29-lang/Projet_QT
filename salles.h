#ifndef SALLES_H
#define SALLES_H

#include <QString>
#include <QDate>

class SALLES
{
public:
    SALLES();
    SALLES(int id_salle, QString nom, int capacite, int numero, QString type_salle);

    void setIdSalle(int id);
    int getIdSalle();

    void setNom(QString nom);
    QString getNom();

    void setCapacite(int capacite);
    int getCapacite();

    void setNumero(int numero);
    int getNumero();

    void setTypeSalle(QString type_salle);
    QString getTypeSalle();

private:
    int ID_SALLE;
    QString NOM;
    int CAPACITE;
    int NUMERO;
    QString TYPE_SALLE;
};

#endif // SALLES_H
