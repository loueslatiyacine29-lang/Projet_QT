#include "mainwindow.h"
#include "Connexion.h"
#include <QApplication>
#include <QMessageBox>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    Connexion connexion;
    bool test=connexion.createconnexion();
        MainWindow w;
    if (!test) {
        QString err = connexion.getLastError();
        QString msg = "La connexion à la base de données a échoué.";
        if (!err.isEmpty()) {
            msg += "\n\nDétails : " + err;
        }
        QMessageBox::critical(nullptr, "Base de données Echec", msg);
        return -1; // Stop application if database fails
    } else {
        QMessageBox::information(nullptr, "Base de données Succès", "Connexion réussie à la base de données !");
    }


    w.show();
    return a.exec();
}
