#ifndef COURS_H
#define COURS_H

#include <QString>
#include <QDate>

class COURS
{
public:
    COURS();
    COURS(int ID_COUR, QString NOM, QString DESCRIPTION, QDate DATE_DEBUT, QDate DATE_FIN, int PRIX, QString NIVEAU, int ID_SALLE);

    void SET_ID_COUR(int ID);
    int GET_ID_COUR();

    void SET_NOM(QString NOM);
    QString GET_NOM();

    void SET_DESCRIPTION(QString DESCRIPTION);
    QString GET_DESCRIPTION();

    void SET_DATE_DEBUT(QDate DATE_DEBUT);
    QDate GET_DATE_DEBUT();

    void SET_DATE_FIN(QDate DATE_FIN);
    QDate GET_DATE_FIN();

    void SET_PRIX(int PRIX);
    int GET_PRIX();

    void SET_NIVEAU(QString NIVEAU);
    QString GET_NIVEAU();

    void SET_ID_SALLE(int ID_SALLE);
    int GET_ID_SALLE();

private:
    int ID_COUR;
    QString NOM;
    QString DESCRIPTION;
    QDate DATE_DEBUT;
    QDate DATE_FIN;
    int PRIX;
    QString NIVEAU;
    int ID_SALLE;
};

#endif // COURS_H
