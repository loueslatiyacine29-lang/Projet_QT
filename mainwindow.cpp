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



    QRegularExpression charRegex("[a-zA-Z]*");
    QRegularExpressionValidator* charValidator = new QRegularExpressionValidator(charRegex, this);
    ui->nom_salle->setValidator(charValidator);

  //.  ui->tableView_salle->setModel(s.afficher());

    remplir_comboBox_SALLE();
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
                //etape3: appel du fonction ajout
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
            if(ordre=="ASECENDANT")
            {
                ordre="ASC";
            }
            else
                ordre="DESC";

            QString choix_salle=ui->choix_salle->currentText();

            ui->tableView_salle->setModel(s.tri(choix_salle,ordre));
        }


        void MainWindow::on_bt_chercher_salle_clicked()
        {
            QString chercher_text_salle=ui->chercher_text_salle->text();
            QString choix_salle=ui->choix_salle->currentText();
            ui->tableView_salle->setModel(s.chercher(choix_salle,choix_salle));

        }


        void MainWindow::on_tableView_cour_clicked(const QModelIndex &index)
        {

        }

