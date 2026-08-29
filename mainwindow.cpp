#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    QIntValidator *intValidator = new QIntValidator(0, 100000000, this); // Only allows integers from 0 to 100000
    ui->id_cour->setValidator(intValidator);
    ui->id_salle->setValidator(intValidator);
    ui->numero_salle->setValidator(intValidator);
    ui->capacite_salle->setValidator(intValidator);
    ui->prix_cour->setValidator(intValidator);



    QRegularExpression charRegex("[a-zA-Z]*");
    QRegularExpressionValidator* charValidator = new QRegularExpressionValidator(charRegex, this);
    ui->nom_salle->setValidator(charValidator);

    ui->tableView_salle->setModel(s.afficher());
    ui->tableView_cour->setModel(c.afficher());

    remplir_comboBox_SALLE();


    ui->debut_cour->setDate(QDate::currentDate());
    ui->fin_cour->setDate(QDate::currentDate());


}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_bt_ajouter_salle_clicked()
{
//etape1: récupération d'apres ui
    int id_salle=ui->id_salle->text().toInt();
    QString nom=ui->nom_salle->text();
    int numero=ui->numero_salle->text().toInt();
    int capacite=ui->capacite_salle->text().toInt();
    QString type_salle=ui->type_salle->currentText();

//etape2: controle de saisie
    if(nom==""||id_salle==0 || numero==0 || capacite==0 )
    {
        QMessageBox::critical(nullptr, QStringLiteral(""), QStringLiteral("Tu dois remplir tous les champs"));

      return;
    }
    if(s.idExists(id_salle)==true)
    {
        QMessageBox::critical(nullptr, QStringLiteral(""), QStringLiteral("Le id déja existe"));
        return;
    }
//etape3: appel du fonction ajout
    SALLES s(id_salle,nom,capacite,numero,type_salle);
    bool test=s.ajouter();
//etape4: affichage du message
    if(test==true)
    {
        QMessageBox::information(nullptr, QStringLiteral(""), QStringLiteral("ajout avec succées"));
        ui->id_salle->clear();
        ui->nom_salle->clear();
        ui->capacite_salle->clear();
        ui->numero_salle->clear();
        ui->tableView_salle->setModel(s.afficher());
        remplir_comboBox_SALLE();
    }
    else
    {
        QMessageBox::critical(nullptr, QStringLiteral(""), QStringLiteral("ajout échoué"));

    }
}



void MainWindow::remplir_comboBox_SALLE()
{
    ui->id_salle_cour->clear();

    QList<int> liste=c.ListIdSalle();

    for(int i=0 ;i<liste.length();i++)
    {
        ui->id_salle_cour->addItem(QString::number(liste[i]));
    }


}









        void MainWindow::on_tableView_salle_clicked(const QModelIndex &index)
        {
            //etape1: numero du ligne ! clicked !
            QAbstractItemModel* model = ui->tableView_salle->model();

            int row = index.row();
            //etape2:  table du format matrice , recuperation du donne
            QString id_salle = model->data(model->index(row, 0)).toString();
            QString nom = model->data(model->index(row, 1)).toString();
            QString numero = model->data(model->index(row, 2)).toString();
            QString capacite = model->data(model->index(row, 3)).toString();
            QString type_salle = model->data(model->index(row, 4)).toString();

            //etape3: insertion dans ui  ( lineEdit , comboBox)

            ui->id_salle->setText(id_salle);
            ui->nom_salle->setText(nom);
            ui->numero_salle->setText(numero);
            ui->capacite_salle->setText(capacite);
            ui->type_salle->setCurrentText(type_salle);

            ui->tableView_salle->setModel(s.afficher());


        }








        void MainWindow::on_bt_modifier_salle_clicked()
        {
            {
                //etape1: récupération d'apres ui
                int id_salle=ui->id_salle->text().toInt();
                QString nom=ui->nom_salle->text();
                int numero=ui->numero_salle->text().toInt();
                int capacite=ui->capacite_salle->text().toInt();
                QString type_salle=ui->type_salle->currentText();

                //etape2: controle de saisie
                if(nom==""||id_salle==0 || numero==0 || capacite==0 )
                {
                    QMessageBox::critical(nullptr, QStringLiteral(""), QStringLiteral("Tu dois remplir tous les champs"));

                    return;
                }
                if(s.idExists(id_salle)==false)
                {
                    QMessageBox::critical(nullptr, QStringLiteral(""), QStringLiteral("Le id n'existe pas "));
                    return;
                }
                //etape3: appel du fonction modifier
                SALLES s(id_salle,nom,capacite,numero,type_salle);
                bool test=s.modifier();
                //etape4: affichage du message
                if(test==true)
                {
                    QMessageBox::information(nullptr, QStringLiteral(""), QStringLiteral("modification avec succées"));
                    ui->id_salle->clear();
                    ui->nom_salle->clear();
                    ui->capacite_salle->clear();
                    ui->numero_salle->clear();
                    ui->tableView_salle->setModel(s.afficher());
                    remplir_comboBox_SALLE();
                }
                else
                {
                    QMessageBox::information(nullptr, QStringLiteral(""), QStringLiteral("modification échoué"));

                }
            }
        }


        void MainWindow::on_bt_supprimer_salle_clicked()
        {
            int id_salle=ui->id_salle->text().toInt();
            if(s.idExists(id_salle)==false)
            {
                QMessageBox::critical(nullptr, QStringLiteral(""), QStringLiteral("Le id n'existe pas "));
                return;
            }
            bool test=s.supprimer(id_salle);
            if(test)
            {

                QMessageBox::information(nullptr, QStringLiteral(""), QStringLiteral("suppression avec succées"));
                ui->id_salle->clear();
                ui->nom_salle->clear();
                ui->capacite_salle->clear();
                ui->numero_salle->clear();
                ui->tableView_salle->setModel(s.afficher());
                remplir_comboBox_SALLE();

            }

            else
            {
                QMessageBox::critical(nullptr, QStringLiteral(""), QStringLiteral("suppression échoué"));

            }
        }


        void MainWindow::on_bt_tri_salle_clicked()
        {
            QString ordre= ui->ordre_tri_salle->currentText();
            QString choix_salle=ui->choix_salle->currentText();

            if(ordre=="ASCENDANT")
            {
                ordre="ASC";
            }
            else
                ordre="DESC";


            ui->tableView_salle->setModel(s.tri(choix_salle,ordre));
        }


        void MainWindow::on_bt_chercher_salle_clicked()
        {
            QString chercher_text_salle=ui->chercher_text_salle->text();
            QString choix_salle=ui->choix_salle->currentText();
            ui->tableView_salle->setModel(s.chercher(choix_salle,chercher_text_salle));

        }




        void MainWindow::on_bt_refresh_clicked()
        {
            ui->tableView_salle->setModel(s.afficher());

        }


        void MainWindow::on_tableView_cour_clicked(const QModelIndex &index)
        {
            //etape1: numero du ligne ! clicked !
            QAbstractItemModel* model = ui->tableView_cour->model();

            int row = index.row();
            //etape2:  table du format matrice , recuperation du donne
            QString id_cour = model->data(model->index(row, 0)).toString();
            QString nom = model->data(model->index(row, 1)).toString();
            QString description = model->data(model->index(row, 2)).toString();
            QDate debut = model->data(model->index(row, 3)).toDate();
            QDate fin = model->data(model->index(row, 4)).toDate();
            QString prix = model->data(model->index(row, 5)).toString();
            QString niveau = model->data(model->index(row, 6)).toString();
            QString id_salle = model->data(model->index(row, 7)).toString();

            //etape3: insertion dans ui  ( lineEdit , comboBox)

            ui->id_cour->setText(id_cour);
            ui->nom_cour->setText(nom);
            ui->description_cour->setText(description);
            ui->debut_cour->setDate(debut);
            ui->fin_cour->setDate(fin);
            ui->prix_cour->setText(prix);
            ui->niveau_cour->setCurrentText(niveau);
            ui->id_salle_cour->setCurrentText(id_cour);

            ui->tableView_salle->setModel(s.afficher());
        }

        void MainWindow::on_bt_ajouter_cour_clicked()
        {
          int id_cour=  ui->id_cour->text().toInt();
          QString nom=  ui->nom_cour->text();
          QString description =  ui->description_cour->text();
           QDate debut= ui->debut_cour->date();
           QDate fin= ui->fin_cour->date();
           int prix = ui->prix_cour->text().toInt();
           QString niveau= ui->niveau_cour->currentText();
           int id_salle_cour = ui->id_salle_cour->currentText().toInt();

           //etape2: controle de saisie
           if(nom==""||id_cour==0 || prix==0 || description=="" )
           {
               QMessageBox::critical(nullptr, QStringLiteral(""), QStringLiteral("Tu dois remplir tous les champs"));

               return;
           }
           if(c.idExists(id_cour)==true)
           {
               QMessageBox::critical(nullptr, QStringLiteral(""), QStringLiteral("Le id déja existe"));
               return;
           }
           if(debut>fin)
           {
               QMessageBox::critical(nullptr, QStringLiteral(""), QStringLiteral("La date de debut ne doit pas passer la date de fin"));
               return;
           }

           //etape3:
           COURS c(id_cour,nom,description,debut,fin,prix,niveau,id_salle_cour);
           bool test=c.ajouter();

           //etape4
           if(test==true)
           {
               QMessageBox::information(nullptr, QStringLiteral(""), QStringLiteral("ajout avec succées"));
                ui->id_cour->clear();
                ui->nom_cour->clear();
                ui->description_cour->clear();
                ui->debut_cour->setDate(QDate::currentDate());
                ui->fin_cour->setDate(QDate::currentDate());
                ui->prix_cour->clear();
                ui->niveau_cour->currentText();
                ui->id_salle_cour->currentText().toInt();

               ui->tableView_cour->setModel(c.afficher());

           }
           else
           {
               QMessageBox::critical(nullptr, QStringLiteral(""), QStringLiteral("ajout échoué"));

           }




        }


        void MainWindow::on_bt_modifier_cour_clicked()
        {
            int id_cour=  ui->id_cour->text().toInt();
            QString nom=  ui->nom_cour->text();
            QString description =  ui->description_cour->text();
            QDate debut= ui->debut_cour->date();
            QDate fin= ui->fin_cour->date();
            int prix = ui->prix_cour->text().toInt();
            QString niveau= ui->niveau_cour->currentText();
            int id_salle_cour = ui->id_salle_cour->currentText().toInt();

            //etape2: controle de saisie
            if(nom==""||id_cour==0 || prix==0 || description=="" )
            {
                QMessageBox::critical(nullptr, QStringLiteral(""), QStringLiteral("Tu dois remplir tous les champs"));

                return;
            }
            if(c.idExists(id_cour)==false)
            {
                QMessageBox::critical(nullptr, QStringLiteral(""), QStringLiteral("Le id n'existe pas"));
                return;
            }
            if(debut>fin)
            {
                QMessageBox::critical(nullptr, QStringLiteral(""), QStringLiteral("La date de debut ne doit pas passer la date de fin"));
                return;
            }

            //etape3:
            COURS c(id_cour,nom,description,debut,fin,prix,niveau,id_salle_cour);
            bool test=c.modifier();

            //etape4
            if(test==true)
            {
                QMessageBox::information(nullptr, QStringLiteral(""), QStringLiteral("Modification avec succées"));
                ui->id_cour->clear();
                ui->nom_cour->clear();
                ui->description_cour->clear();
                ui->debut_cour->setDate(QDate::currentDate());
                ui->fin_cour->setDate(QDate::currentDate());
                ui->prix_cour->clear();
                ui->niveau_cour->currentText();
                ui->id_salle_cour->currentText().toInt();

                ui->tableView_cour->setModel(c.afficher());

            }
            else
            {
                QMessageBox::critical(nullptr, QStringLiteral(""), QStringLiteral("Modification échoué"));

            }
        }

        void MainWindow::on_bt_supprimer_cour_clicked()
        {
            int id_cour=ui->id_cour->text().toInt();
            if(c.idExists(id_cour)==false)
            {
                QMessageBox::critical(nullptr, QStringLiteral(""), QStringLiteral("Le id n'existe pas "));
                return;
            }
            bool test=c.supprimer(id_cour);
            if(test)
            {

                QMessageBox::information(nullptr, QStringLiteral(""), QStringLiteral("suppression avec succées"));
                ui->id_cour->clear();
                ui->nom_cour->clear();
                ui->description_cour->clear();
                ui->debut_cour->setDate(QDate::currentDate());
                ui->fin_cour->setDate(QDate::currentDate());
                ui->prix_cour->clear();
                ui->niveau_cour->currentText();
                ui->id_salle_cour->currentText().toInt();

                ui->tableView_cour->setModel(c.afficher());

            }

            else
            {
                QMessageBox::critical(nullptr, QStringLiteral(""), QStringLiteral("suppression échoué"));

            }
        }

        void MainWindow::on_bt_tri_cour_clicked()
        {
            QString ordre= ui->ordre_tri_cour->currentText();
            QString choix_cour=ui->choix_cour->currentText();

            if(ordre=="ASCENDANT")
            {
                ordre="ASC";
            }
            else
                ordre="DESC";


            ui->tableView_cour->setModel(c.tri(choix_cour,ordre));
        }


        void MainWindow::on_bt_chercher_cour_clicked()
        {
            QString chercher_text_cour=ui->chercher_text_cour->text();
            QString choix_cour=ui->choix_cour->currentText();
            ui->tableView_cour->setModel(c.chercher(choix_cour,chercher_text_cour));
        }


        void MainWindow::on_bt_refresh_cour_clicked()
        {
            ui->tableView_cour->setModel(c.afficher());

        }

