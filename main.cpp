#include "mainwindow.h"

#include <QApplication>
#include <QMessageBox>
#include "connection.h"
#include <QPointer>
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    // Try to create/open the database connection and show a debug popup
    Connection *cnx = Connection::instance();
    bool test = false;
    if (cnx) {
        test = cnx->createConnect();
    }

    // Show a French debug popup indicating connection success/failure
    if (test) {
        QMessageBox::information(nullptr, QStringLiteral("Base de données"), QStringLiteral("Connexion réussie"));
    } else {
        QMessageBox::warning(nullptr, QStringLiteral("Base de données"), QStringLiteral("Échec de la connexion"));
    }



    MainWindow w;
    if(test)
    {w.show();

        QMessageBox::information(nullptr, QObject::tr("database is  open"),
                                 QObject::tr("connection succefull.\n"
                                             "Click Cancel to exit."), QMessageBox::Cancel);



    }
    else
        QMessageBox::critical(nullptr, QObject::tr("database is not open"),
                              QObject::tr("connection failed.\n"
                                          "Click Cancel to exit."), QMessageBox::Cancel);


    w.show();
    return a.exec();
}
