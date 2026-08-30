#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QPieSeries>
#include <QChart>
#include <QChartView>
#include <QVBoxLayout>

#include <QFileDialog>
#include <QFileInfo>
#include <QPrinter>
#include <QTextDocument>
#include <QTextStream>
#include "Qrcode.hpp"
// Generate QR code
using namespace qrcodegen;
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


        // Enregistrer l'ajout dans l'historique
        addToHistory("Ajout du salle", QString::number(id_salle));
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

                    // Enregistrer l'opération d'update dans l'historique
                    addToHistory("Mise à jour du salle", QString::number(id_salle));
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

                addToHistory("Suppression du salle", QString::number(id_salle));

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


        void MainWindow::on_bt_stat_salle_clicked()
        {
            QMap<QString, int> stats = s.statistiquesParType();

            QPieSeries *series = new QPieSeries();

            // Calcul du nombre total de Salle
            int total = 0;
            for (auto it = stats.begin(); it != stats.end(); ++it) {
                total += it.value();
            }

            // Ajouter les données au graphique
            for (auto it = stats.begin(); it != stats.end(); ++it) {

                double pourcentage = (total > 0)
                ? (it.value() * 100.0 / total)
                : 0;

                QPieSlice *slice = series->append(
                    QString("%1 : %2 Salles (%3%)")
                        .arg(it.key())
                        .arg(it.value())
                        .arg(QString::number(pourcentage, 'f', 1)),
                    it.value()
                    );

                // Afficher le pourcentage sur la part
                slice->setLabelVisible(true);

                // Mettre légèrement en évidence la part
                slice->setExploded(true);
                slice->setExplodeDistanceFactor(0.05);
            }

            // Création du graphique
            QChart *chart = new QChart();
            chart->addSeries(series);

            chart->setTitle(
                QString("Statistiques des salles par type — Total : %1 type")
                    .arg(total)
                );

            chart->setAnimationOptions(QChart::SeriesAnimations);

            // Légende
            chart->legend()->setVisible(true);
            chart->legend()->setAlignment(Qt::AlignRight);

            // Police du titre
            QFont titleFont;
            titleFont.setPointSize(14);
            titleFont.setBold(true);
            chart->setTitleFont(titleFont);

            // Vue du graphique
            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);

            // Dialogue
            QDialog *chartDialog = new QDialog(this);
            chartDialog->setWindowTitle("Statistiques des Salles");
            chartDialog->resize(750, 550);

            QVBoxLayout *layout = new QVBoxLayout(chartDialog);
            layout->setContentsMargins(15, 15, 15, 15);
            layout->addWidget(chartView);

            chartDialog->exec();
        }

        void MainWindow::on_bt_stat_cour_clicked()
        {
            QMap<QString, int> stats = c.statistiquesParNiveau();

            QPieSeries *series = new QPieSeries();

            // Calcul du nombre total de cours
            int total = 0;
            for (auto it = stats.begin(); it != stats.end(); ++it) {
                total += it.value();
            }

            // Ajouter les données au graphique
            for (auto it = stats.begin(); it != stats.end(); ++it) {

                double pourcentage = (total > 0)
                ? (it.value() * 100.0 / total)
                : 0;

                QPieSlice *slice = series->append(
                    QString("%1 : %2 cours (%3%)")
                        .arg(it.key())
                        .arg(it.value())
                        .arg(QString::number(pourcentage, 'f', 1)),
                    it.value()
                    );

                // Afficher le pourcentage sur la part
                slice->setLabelVisible(true);

                // Mettre légèrement en évidence la part
                slice->setExploded(true);
                slice->setExplodeDistanceFactor(0.05);
            }

            // Création du graphique
            QChart *chart = new QChart();
            chart->addSeries(series);

            chart->setTitle(
                QString("Statistiques des cours par niveau — Total : %1 cours")
                    .arg(total)
                );

            chart->setAnimationOptions(QChart::SeriesAnimations);

            // Légende
            chart->legend()->setVisible(true);
            chart->legend()->setAlignment(Qt::AlignRight);

            // Police du titre
            QFont titleFont;
            titleFont.setPointSize(14);
            titleFont.setBold(true);
            chart->setTitleFont(titleFont);

            // Vue du graphique
            QChartView *chartView = new QChartView(chart);
            chartView->setRenderHint(QPainter::Antialiasing);

            // Dialogue
            QDialog *chartDialog = new QDialog(this);
            chartDialog->setWindowTitle("Statistiques des Cours");
            chartDialog->resize(750, 550);

            QVBoxLayout *layout = new QVBoxLayout(chartDialog);
            layout->setContentsMargins(15, 15, 15, 15);
            layout->addWidget(chartView);

            chartDialog->exec();
        }

        void MainWindow::on_bt_pdf_cour_clicked()
        {
            QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tableView_cour->model()->rowCount();
            const int columnCount = ui->tableView_cour->model()->columnCount();

            out << "<html>\n"
                   "<head>\n"
                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                   "<title>%1</title>\n"
                   "<style>\n"
                   "table {\n"
                   "    width: 100%;\n"
                   "    border-collapse: collapse;\n"
                   "}\n"
                   "th, td {\n"
                   "    padding: 8px;\n"
                   "    text-align: left;\n"
                   "    border-bottom: 1px solid #ddd;\n"
                   "}\n"
                   "tr:nth-child(even) {\n"
                   "    background-color: #f2f2f2;\n"
                   "}\n"
                   "</style>\n"
                   "</head>\n"
                   "<body bgcolor=#ffffff link=#5000A0>\n"
                   "<center> <H1>Liste des Cours</H1></center><br/><br/>\n"
                   "<table>\n";

            // headers
            out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
            for (int column = 0; column < columnCount; column++)
            {
                if (!ui->tableView_cour->isColumnHidden(column))
                {
                    out << QString("<th>%1</th>").arg(ui->tableView_cour->model()->headerData(column, Qt::Horizontal).toString());
                }
            }
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++)
            {
                out << "<tr> <td>" << row + 1 << "</td>";
                for (int column = 0; column < columnCount; column++)
                {
                    if (!ui->tableView_cour->isColumnHidden(column))
                    {
                        QString data = ui->tableView_cour->model()->data(ui->tableView_cour->model()->index(row, column)).toString().simplified();
                        out << QString("<td>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }



            QString fileName = QFileDialog::getSaveFileName((QWidget *)0, "Sauvegarder en PDF", QString(), "*.pdf");
            if (QFileInfo(fileName).suffix().isEmpty())
            {
                fileName.append(".pdf");
            }

            QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPageSize(QPageSize::A4);
            printer.setOutputFileName(fileName);

            QTextDocument doc;
            doc.setHtml(strStream);
            doc.print(&printer);

        }


        void MainWindow::on_bt_pdf_salle_clicked()
        {
            QString strStream;
            QTextStream out(&strStream);

            const int rowCount = ui->tableView_salle->model()->rowCount();
            const int columnCount = ui->tableView_salle->model()->columnCount();

            out << "<html>\n"
                   "<head>\n"
                   "<meta Content=\"Text/html; charset=Windows-1251\">\n"
                   "<title>%1</title>\n"
                   "<style>\n"
                   "table {\n"
                   "    width: 100%;\n"
                   "    border-collapse: collapse;\n"
                   "}\n"
                   "th, td {\n"
                   "    padding: 8px;\n"
                   "    text-align: left;\n"
                   "    border-bottom: 1px solid #ddd;\n"
                   "}\n"
                   "tr:nth-child(even) {\n"
                   "    background-color: #f2f2f2;\n"
                   "}\n"
                   "</style>\n"
                   "</head>\n"
                   "<body bgcolor=#ffffff link=#5000A0>\n"
                   "<center> <H1>Liste des Salles</H1></center><br/><br/>\n"
                   "<table>\n";

            // headers
            out << "<thead><tr bgcolor=#f0f0f0> <th>Numero</th>";
            for (int column = 0; column < columnCount; column++)
            {
                if (!ui->tableView_salle->isColumnHidden(column))
                {
                    out << QString("<th>%1</th>").arg(ui->tableView_salle->model()->headerData(column, Qt::Horizontal).toString());
                }
            }
            out << "</tr></thead>\n";

            // data table
            for (int row = 0; row < rowCount; row++)
            {
                out << "<tr> <td>" << row + 1 << "</td>";
                for (int column = 0; column < columnCount; column++)
                {
                    if (!ui->tableView_salle->isColumnHidden(column))
                    {
                        QString data = ui->tableView_salle->model()->data(ui->tableView_salle->model()->index(row, column)).toString().simplified();
                        out << QString("<td>%1</td>").arg((!data.isEmpty()) ? data : QString("&nbsp;"));
                    }
                }
                out << "</tr>\n";
            }



            QString fileName = QFileDialog::getSaveFileName((QWidget *)0, "Sauvegarder en PDF", QString(), "*.pdf");
            if (QFileInfo(fileName).suffix().isEmpty())
            {
                fileName.append(".pdf");
            }

            QPrinter printer(QPrinter::PrinterResolution);
            printer.setOutputFormat(QPrinter::PdfFormat);
            printer.setPageSize(QPageSize::A4);
            printer.setOutputFileName(fileName);

            QTextDocument doc;
            doc.setHtml(strStream);
            doc.print(&printer);

        }


        void MainWindow::on_bt_historique_clicked()
        {
            QString filePath = "/Users/MSI/Documents/Projet_QT/historique_salles.txt";
            QFile file(filePath);

            // Vérifier si le fichier peut être ouvert en mode lecture
            if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
                QMessageBox::critical(this, "Erreur", "Impossible d'ouvrir le fichier d'historique.");
                return;
            }

            // Lire tout le contenu du fichier historique
            QTextStream in(&file);
            QString historyContent = in.readAll();

            // Afficher le contenu dans une boîte de dialogue ou une zone de texte
            QMessageBox::information(this, "Historique des salles", historyContent);

            // Fermer le fichier
            file.close();
        }

        void MainWindow::addToHistory(const QString &action, const QString &SalleNom)
        {
            // Chemin du fichier historique
            QString filePath = "/Users/MSI/Documents/Projet_QT/historique_salles.txt";
            QFile file(filePath);

            // Ouvrir le fichier en mode ajout
            if (!file.open(QIODevice::Append | QIODevice::Text)) {
                qDebug() << "Erreur lors de l'ouverture du fichier historique.";
                return;
            }

            // Créer un flux texte pour écrire dans le fichier
            QTextStream out(&file);

            // Obtenir la date et l'heure actuelles
            QDateTime currentDateTime = QDateTime::currentDateTime();

            // Écrire l'action dans le fichier historique avec la date et l'heure
            out << currentDateTime.toString("yyyy-MM-dd hh:mm:ss") << " - " << action;
            if (!SalleNom.isEmpty()) {
                out << " pour le salle : " << SalleNom;
            }
            out << "\n";

            // Fermer le fichier
            file.close();
        }

        void MainWindow::on_bt_qrcode_clicked()
        {
            // Vérifier qu'une ligne est sélectionnée
            QModelIndex index = ui->tableView_cour->currentIndex();

            if (!index.isValid())
            {
                QMessageBox::warning(
                    this,
                    "QR Code",
                    "Veuillez sélectionner un cours dans la table."
                    );
                return;
            }

            // Récupérer le modèle
            QAbstractItemModel *model = ui->tableView_cour->model();

            int row = index.row();

            // ==========================================
            // Récupération de toutes les informations
            // ==========================================

            QString id_cour =
                model->data(model->index(row, 0)).toString();

            QString nom =
                model->data(model->index(row, 1)).toString();

            QString description =
                model->data(model->index(row, 2)).toString();

            QDate debut =
                model->data(model->index(row, 3)).toDate();

            QDate fin =
                model->data(model->index(row, 4)).toDate();

            QString prix =
                model->data(model->index(row, 5)).toString();

            QString niveau =
                model->data(model->index(row, 6)).toString();

            QString id_salle =
                model->data(model->index(row, 7)).toString();


            // ==========================================
            // Texte qui sera contenu dans le QR Code
            // ==========================================

            QString text =
                "===== COURS =====\n"
                "ID COUR : " + id_cour + "\n"
                            "NOM : " + nom + "\n"
                        "DESCRIPTION : " + description + "\n"
                                "DATE DEBUT : " + debut.toString("dd/MM/yyyy") + "\n"
                                                 "DATE FIN : " + fin.toString("dd/MM/yyyy") + "\n"
                                               "PRIX : " + prix + "\n"
                         "NIVEAU : " + niveau + "\n"
                           "ID SALLE : " + id_salle + "\n"
                             "=================";


            // ==========================================
            // Génération du QR Code
            // ==========================================

            using namespace qrcodegen;

            QByteArray qrData = text.toUtf8();

            QrCode qr = QrCode::encodeText(
                qrData.constData(),
                QrCode::Ecc::MEDIUM
                );

            int sz = qr.getSize();

            QImage image(
                sz,
                sz,
                QImage::Format_RGB32
                );

            QRgb black = qRgb(0, 0, 0);
            QRgb white = qRgb(255, 255, 255);

            // Dessiner le QR Code
            for (int y = 0; y < sz; y++)
            {
                for (int x = 0; x < sz; x++)
                {
                    image.setPixel(
                        x,
                        y,
                        qr.getModule(x, y)
                            ? black
                            : white
                        );
                }
            }


            // ==========================================
            // Agrandir le QR Code
            // ==========================================

            QPixmap qrPixmap =
                QPixmap::fromImage(image).scaled(
                    350,
                    350,
                    Qt::KeepAspectRatio,
                    Qt::FastTransformation
                    );


            // ==========================================
            // Création du Dialog
            // ==========================================

            QDialog *dialog = new QDialog(this);

            dialog->setWindowTitle(
                "QR Code - Informations du cours"
                );

            dialog->resize(450, 600);


            // ==========================================
            // Création du VBoxLayout
            // ==========================================

            QVBoxLayout *vbox =
                new QVBoxLayout(dialog);


            // ==========================================
            // Titre
            // ==========================================

            QLabel *titleLabel =
                new QLabel("QR CODE DU COURS");

            titleLabel->setAlignment(
                Qt::AlignCenter
                );

            QFont titleFont;
            titleFont.setBold(true);
            titleFont.setPointSize(16);

            titleLabel->setFont(titleFont);


            // ==========================================
            // QLabel pour le QR Code
            // ==========================================

            QLabel *qrLabel =
                new QLabel();

            qrLabel->setPixmap(qrPixmap);

            qrLabel->setAlignment(
                Qt::AlignCenter
                );


            // ==========================================
            // Informations affichées sous le QR
            // ==========================================

            QString info =
                "<b>ID COUR :</b> " + id_cour + "<br>"
                                                "<b>NOM :</b> " + nom + "<br>"
                        "<b>DESCRIPTION :</b> " + description + "<br>"
                                "<b>DATE DEBUT :</b> " +
                debut.toString("dd/MM/yyyy") + "<br>"
                                               "<b>DATE FIN :</b> " +
                fin.toString("dd/MM/yyyy") + "<br>"
                                             "<b>PRIX :</b> " + prix + "<br>"
                         "<b>NIVEAU :</b> " + niveau + "<br>"
                           "<b>ID SALLE :</b> " + id_salle;


            QLabel *infoLabel =
                new QLabel(info);

            infoLabel->setAlignment(
                Qt::AlignCenter
                );

            infoLabel->setWordWrap(true);


            // ==========================================
            // Bouton Fermer
            // ==========================================

            QPushButton *closeButton =
                new QPushButton("Fermer");


            // ==========================================
            // Ajouter dans le VBoxLayout
            // ==========================================

            vbox->addWidget(titleLabel);
            vbox->addWidget(qrLabel);
            vbox->addWidget(infoLabel);
            vbox->addWidget(closeButton);


            // ==========================================
            // Fermer le dialog
            // ==========================================

            connect(
                closeButton,
                &QPushButton::clicked,
                dialog,
                &QDialog::accept
                );


            // ==========================================
            // Afficher le Dialog
            // ==========================================

            dialog->exec();

            delete dialog;
        }


