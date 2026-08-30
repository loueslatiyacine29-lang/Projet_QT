/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 6.9.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateEdit>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QTabWidget *tabWidget;
    QWidget *SALLE;
    QLabel *label;
    QLineEdit *id_salle;
    QLabel *label_2;
    QLineEdit *nom_salle;
    QLabel *label_3;
    QLineEdit *numero_salle;
    QLabel *label_4;
    QLineEdit *capacite_salle;
    QComboBox *type_salle;
    QLabel *label_5;
    QTableView *tableView_salle;
    QPushButton *bt_ajouter_salle;
    QPushButton *bt_modifier_salle;
    QPushButton *bt_supprimer_salle;
    QPushButton *bt_pdf_salle;
    QPushButton *bt_stat_salle;
    QPushButton *bt_tri_salle;
    QComboBox *ordre_tri_salle;
    QComboBox *choix_salle;
    QPushButton *bt_chercher_salle;
    QLineEdit *chercher_text_salle;
    QPushButton *bt_refresh;
    QPushButton *bt_historique;
    QWidget *COUR;
    QPushButton *bt_modifier_cour;
    QLabel *label_6;
    QLineEdit *chercher_text_cour;
    QComboBox *ordre_tri_cour;
    QPushButton *bt_supprimer_cour;
    QPushButton *bt_ajouter_cour;
    QLabel *label_7;
    QComboBox *niveau_cour;
    QTableView *tableView_cour;
    QLineEdit *description_cour;
    QComboBox *choix_cour;
    QLabel *label_8;
    QPushButton *bt_chercher_cour;
    QLabel *label_9;
    QLineEdit *nom_cour;
    QLineEdit *id_cour;
    QPushButton *bt_pdf_cour;
    QLabel *label_10;
    QPushButton *bt_tri_cour;
    QPushButton *bt_stat_cour;
    QLabel *label_11;
    QLineEdit *prix_cour;
    QLabel *label_12;
    QDateEdit *debut_cour;
    QDateEdit *fin_cour;
    QLabel *label_13;
    QComboBox *id_salle_cour;
    QPushButton *bt_refresh_cour;
    QPushButton *bt_qrcode;
    QMenuBar *menubar;
    QStatusBar *statusbar;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1920, 1080);
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        tabWidget = new QTabWidget(centralwidget);
        tabWidget->setObjectName("tabWidget");
        tabWidget->setGeometry(QRect(0, 0, 1920, 1080));
        tabWidget->setStyleSheet(QString::fromUtf8("background-color:#D3D3D3"));
        SALLE = new QWidget();
        SALLE->setObjectName("SALLE");
        label = new QLabel(SALLE);
        label->setObjectName("label");
        label->setGeometry(QRect(70, 20, 171, 71));
        id_salle = new QLineEdit(SALLE);
        id_salle->setObjectName("id_salle");
        id_salle->setGeometry(QRect(260, 20, 231, 61));
        label_2 = new QLabel(SALLE);
        label_2->setObjectName("label_2");
        label_2->setGeometry(QRect(80, 110, 171, 71));
        nom_salle = new QLineEdit(SALLE);
        nom_salle->setObjectName("nom_salle");
        nom_salle->setGeometry(QRect(260, 110, 231, 61));
        label_3 = new QLabel(SALLE);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(70, 190, 171, 71));
        numero_salle = new QLineEdit(SALLE);
        numero_salle->setObjectName("numero_salle");
        numero_salle->setGeometry(QRect(260, 200, 231, 61));
        label_4 = new QLabel(SALLE);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(70, 290, 171, 71));
        capacite_salle = new QLineEdit(SALLE);
        capacite_salle->setObjectName("capacite_salle");
        capacite_salle->setGeometry(QRect(260, 300, 231, 61));
        type_salle = new QComboBox(SALLE);
        type_salle->addItem(QString());
        type_salle->addItem(QString());
        type_salle->addItem(QString());
        type_salle->addItem(QString());
        type_salle->addItem(QString());
        type_salle->addItem(QString());
        type_salle->setObjectName("type_salle");
        type_salle->setGeometry(QRect(260, 390, 221, 71));
        label_5 = new QLabel(SALLE);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(70, 390, 171, 71));
        tableView_salle = new QTableView(SALLE);
        tableView_salle->setObjectName("tableView_salle");
        tableView_salle->setGeometry(QRect(570, 170, 900, 471));
        bt_ajouter_salle = new QPushButton(SALLE);
        bt_ajouter_salle->setObjectName("bt_ajouter_salle");
        bt_ajouter_salle->setGeometry(QRect(30, 510, 161, 61));
        bt_modifier_salle = new QPushButton(SALLE);
        bt_modifier_salle->setObjectName("bt_modifier_salle");
        bt_modifier_salle->setGeometry(QRect(210, 510, 121, 61));
        bt_supprimer_salle = new QPushButton(SALLE);
        bt_supprimer_salle->setObjectName("bt_supprimer_salle");
        bt_supprimer_salle->setGeometry(QRect(360, 510, 191, 61));
        bt_pdf_salle = new QPushButton(SALLE);
        bt_pdf_salle->setObjectName("bt_pdf_salle");
        bt_pdf_salle->setGeometry(QRect(600, 670, 191, 61));
        bt_stat_salle = new QPushButton(SALLE);
        bt_stat_salle->setObjectName("bt_stat_salle");
        bt_stat_salle->setGeometry(QRect(910, 670, 191, 61));
        bt_tri_salle = new QPushButton(SALLE);
        bt_tri_salle->setObjectName("bt_tri_salle");
        bt_tri_salle->setGeometry(QRect(600, 90, 191, 61));
        ordre_tri_salle = new QComboBox(SALLE);
        ordre_tri_salle->addItem(QString());
        ordre_tri_salle->addItem(QString());
        ordre_tri_salle->setObjectName("ordre_tri_salle");
        ordre_tri_salle->setGeometry(QRect(830, 90, 171, 61));
        choix_salle = new QComboBox(SALLE);
        choix_salle->addItem(QString());
        choix_salle->addItem(QString());
        choix_salle->addItem(QString());
        choix_salle->addItem(QString());
        choix_salle->addItem(QString());
        choix_salle->setObjectName("choix_salle");
        choix_salle->setGeometry(QRect(1030, 90, 171, 61));
        bt_chercher_salle = new QPushButton(SALLE);
        bt_chercher_salle->setObjectName("bt_chercher_salle");
        bt_chercher_salle->setGeometry(QRect(1240, 90, 191, 61));
        chercher_text_salle = new QLineEdit(SALLE);
        chercher_text_salle->setObjectName("chercher_text_salle");
        chercher_text_salle->setGeometry(QRect(1240, 30, 181, 51));
        bt_refresh = new QPushButton(SALLE);
        bt_refresh->setObjectName("bt_refresh");
        bt_refresh->setGeometry(QRect(620, 20, 161, 51));
        bt_historique = new QPushButton(SALLE);
        bt_historique->setObjectName("bt_historique");
        bt_historique->setGeometry(QRect(1180, 670, 191, 61));
        tabWidget->addTab(SALLE, QString());
        COUR = new QWidget();
        COUR->setObjectName("COUR");
        bt_modifier_cour = new QPushButton(COUR);
        bt_modifier_cour->setObjectName("bt_modifier_cour");
        bt_modifier_cour->setGeometry(QRect(690, 650, 191, 61));
        label_6 = new QLabel(COUR);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(40, 380, 171, 71));
        chercher_text_cour = new QLineEdit(COUR);
        chercher_text_cour->setObjectName("chercher_text_cour");
        chercher_text_cour->setGeometry(QRect(1020, 10, 181, 51));
        ordre_tri_cour = new QComboBox(COUR);
        ordre_tri_cour->addItem(QString());
        ordre_tri_cour->addItem(QString());
        ordre_tri_cour->setObjectName("ordre_tri_cour");
        ordre_tri_cour->setGeometry(QRect(800, 80, 171, 61));
        bt_supprimer_cour = new QPushButton(COUR);
        bt_supprimer_cour->setObjectName("bt_supprimer_cour");
        bt_supprimer_cour->setGeometry(QRect(910, 650, 191, 61));
        bt_ajouter_cour = new QPushButton(COUR);
        bt_ajouter_cour->setObjectName("bt_ajouter_cour");
        bt_ajouter_cour->setGeometry(QRect(510, 650, 161, 61));
        label_7 = new QLabel(COUR);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(50, 100, 171, 71));
        niveau_cour = new QComboBox(COUR);
        niveau_cour->addItem(QString());
        niveau_cour->addItem(QString());
        niveau_cour->addItem(QString());
        niveau_cour->addItem(QString());
        niveau_cour->setObjectName("niveau_cour");
        niveau_cour->setGeometry(QRect(230, 560, 221, 71));
        tableView_cour = new QTableView(COUR);
        tableView_cour->setObjectName("tableView_cour");
        tableView_cour->setGeometry(QRect(540, 160, 900, 471));
        description_cour = new QLineEdit(COUR);
        description_cour->setObjectName("description_cour");
        description_cour->setGeometry(QRect(230, 190, 231, 61));
        choix_cour = new QComboBox(COUR);
        choix_cour->addItem(QString());
        choix_cour->addItem(QString());
        choix_cour->addItem(QString());
        choix_cour->addItem(QString());
        choix_cour->addItem(QString());
        choix_cour->addItem(QString());
        choix_cour->addItem(QString());
        choix_cour->addItem(QString());
        choix_cour->setObjectName("choix_cour");
        choix_cour->setGeometry(QRect(800, 10, 171, 61));
        label_8 = new QLabel(COUR);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(40, 280, 171, 71));
        bt_chercher_cour = new QPushButton(COUR);
        bt_chercher_cour->setObjectName("bt_chercher_cour");
        bt_chercher_cour->setGeometry(QRect(1020, 80, 191, 61));
        label_9 = new QLabel(COUR);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(40, 10, 171, 71));
        nom_cour = new QLineEdit(COUR);
        nom_cour->setObjectName("nom_cour");
        nom_cour->setGeometry(QRect(230, 100, 231, 61));
        id_cour = new QLineEdit(COUR);
        id_cour->setObjectName("id_cour");
        id_cour->setGeometry(QRect(230, 10, 231, 61));
        bt_pdf_cour = new QPushButton(COUR);
        bt_pdf_cour->setObjectName("bt_pdf_cour");
        bt_pdf_cour->setGeometry(QRect(1110, 650, 191, 61));
        label_10 = new QLabel(COUR);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(40, 180, 171, 71));
        bt_tri_cour = new QPushButton(COUR);
        bt_tri_cour->setObjectName("bt_tri_cour");
        bt_tri_cour->setGeometry(QRect(570, 80, 191, 61));
        bt_stat_cour = new QPushButton(COUR);
        bt_stat_cour->setObjectName("bt_stat_cour");
        bt_stat_cour->setGeometry(QRect(1320, 650, 191, 61));
        label_11 = new QLabel(COUR);
        label_11->setObjectName("label_11");
        label_11->setGeometry(QRect(40, 470, 171, 71));
        prix_cour = new QLineEdit(COUR);
        prix_cour->setObjectName("prix_cour");
        prix_cour->setGeometry(QRect(230, 480, 231, 61));
        label_12 = new QLabel(COUR);
        label_12->setObjectName("label_12");
        label_12->setGeometry(QRect(40, 560, 171, 71));
        debut_cour = new QDateEdit(COUR);
        debut_cour->setObjectName("debut_cour");
        debut_cour->setGeometry(QRect(230, 290, 221, 61));
        fin_cour = new QDateEdit(COUR);
        fin_cour->setObjectName("fin_cour");
        fin_cour->setGeometry(QRect(230, 390, 221, 61));
        label_13 = new QLabel(COUR);
        label_13->setObjectName("label_13");
        label_13->setGeometry(QRect(40, 660, 171, 71));
        id_salle_cour = new QComboBox(COUR);
        id_salle_cour->setObjectName("id_salle_cour");
        id_salle_cour->setGeometry(QRect(230, 660, 221, 71));
        bt_refresh_cour = new QPushButton(COUR);
        bt_refresh_cour->setObjectName("bt_refresh_cour");
        bt_refresh_cour->setGeometry(QRect(600, 10, 161, 51));
        bt_qrcode = new QPushButton(COUR);
        bt_qrcode->setObjectName("bt_qrcode");
        bt_qrcode->setGeometry(QRect(1270, 50, 191, 61));
        tabWidget->addTab(COUR, QString());
        MainWindow->setCentralWidget(centralwidget);
        menubar = new QMenuBar(MainWindow);
        menubar->setObjectName("menubar");
        menubar->setGeometry(QRect(0, 0, 1920, 26));
        MainWindow->setMenuBar(menubar);
        statusbar = new QStatusBar(MainWindow);
        statusbar->setObjectName("statusbar");
        MainWindow->setStatusBar(statusbar);

        retranslateUi(MainWindow);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        label->setText(QCoreApplication::translate("MainWindow", "ID SALLE", nullptr));
        label_2->setText(QCoreApplication::translate("MainWindow", "NOM", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "NUMERO", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "CAPACITE", nullptr));
        type_salle->setItemText(0, QCoreApplication::translate("MainWindow", "CLASSIQUE", nullptr));
        type_salle->setItemText(1, QCoreApplication::translate("MainWindow", "INFORMATIQUE", nullptr));
        type_salle->setItemText(2, QCoreApplication::translate("MainWindow", "LABORATOIRE", nullptr));
        type_salle->setItemText(3, QCoreApplication::translate("MainWindow", "REUNION", nullptr));
        type_salle->setItemText(4, QCoreApplication::translate("MainWindow", "AMPHITHEATRE", nullptr));
        type_salle->setItemText(5, QCoreApplication::translate("MainWindow", "ATELIER", nullptr));

        label_5->setText(QCoreApplication::translate("MainWindow", "TYPE DE SALLE", nullptr));
        bt_ajouter_salle->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        bt_modifier_salle->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        bt_supprimer_salle->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        bt_pdf_salle->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        bt_stat_salle->setText(QCoreApplication::translate("MainWindow", "STATISTIQUE", nullptr));
        bt_tri_salle->setText(QCoreApplication::translate("MainWindow", "TRI", nullptr));
        ordre_tri_salle->setItemText(0, QCoreApplication::translate("MainWindow", "ASCENDANT", nullptr));
        ordre_tri_salle->setItemText(1, QCoreApplication::translate("MainWindow", "DESCENDANT", nullptr));

        choix_salle->setItemText(0, QCoreApplication::translate("MainWindow", "ID_SALLE", nullptr));
        choix_salle->setItemText(1, QCoreApplication::translate("MainWindow", "NOM", nullptr));
        choix_salle->setItemText(2, QCoreApplication::translate("MainWindow", "NUMERO", nullptr));
        choix_salle->setItemText(3, QCoreApplication::translate("MainWindow", "CAPACITE", nullptr));
        choix_salle->setItemText(4, QCoreApplication::translate("MainWindow", "TYPE_SALLE", nullptr));

        bt_chercher_salle->setText(QCoreApplication::translate("MainWindow", "CHERCHER", nullptr));
        bt_refresh->setText(QCoreApplication::translate("MainWindow", "REFRESH", nullptr));
        bt_historique->setText(QCoreApplication::translate("MainWindow", "HISTORIQUE", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(SALLE), QCoreApplication::translate("MainWindow", "GESTION SALLE", nullptr));
        bt_modifier_cour->setText(QCoreApplication::translate("MainWindow", "Modifier", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "DATE DE FIN", nullptr));
        ordre_tri_cour->setItemText(0, QCoreApplication::translate("MainWindow", "ASCENDANT", nullptr));
        ordre_tri_cour->setItemText(1, QCoreApplication::translate("MainWindow", "DESCENDANT", nullptr));

        bt_supprimer_cour->setText(QCoreApplication::translate("MainWindow", "Supprimer", nullptr));
        bt_ajouter_cour->setText(QCoreApplication::translate("MainWindow", "Ajouter", nullptr));
        label_7->setText(QCoreApplication::translate("MainWindow", "NOM", nullptr));
        niveau_cour->setItemText(0, QCoreApplication::translate("MainWindow", "DEBUTANT", nullptr));
        niveau_cour->setItemText(1, QCoreApplication::translate("MainWindow", "INTERMEDIAIRE", nullptr));
        niveau_cour->setItemText(2, QCoreApplication::translate("MainWindow", "AVANCE", nullptr));
        niveau_cour->setItemText(3, QCoreApplication::translate("MainWindow", "EXPERT", nullptr));

        choix_cour->setItemText(0, QCoreApplication::translate("MainWindow", "ID_COUR", nullptr));
        choix_cour->setItemText(1, QCoreApplication::translate("MainWindow", "NOM", nullptr));
        choix_cour->setItemText(2, QCoreApplication::translate("MainWindow", "DESCRIPTION", nullptr));
        choix_cour->setItemText(3, QCoreApplication::translate("MainWindow", "DATE_DEBUT", nullptr));
        choix_cour->setItemText(4, QCoreApplication::translate("MainWindow", "DATE_FIN", nullptr));
        choix_cour->setItemText(5, QCoreApplication::translate("MainWindow", "PRIX", nullptr));
        choix_cour->setItemText(6, QCoreApplication::translate("MainWindow", "NIVEAU", nullptr));
        choix_cour->setItemText(7, QCoreApplication::translate("MainWindow", "ID_SALLE", nullptr));

        label_8->setText(QCoreApplication::translate("MainWindow", "DATE DE DEBUT", nullptr));
        bt_chercher_cour->setText(QCoreApplication::translate("MainWindow", "CHERCHER", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "ID COUR", nullptr));
        bt_pdf_cour->setText(QCoreApplication::translate("MainWindow", "PDF", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "DESCRIPTION", nullptr));
        bt_tri_cour->setText(QCoreApplication::translate("MainWindow", "TRI", nullptr));
        bt_stat_cour->setText(QCoreApplication::translate("MainWindow", "STATISTIQUE", nullptr));
        label_11->setText(QCoreApplication::translate("MainWindow", "PRIX", nullptr));
        label_12->setText(QCoreApplication::translate("MainWindow", "NIVEAU", nullptr));
        label_13->setText(QCoreApplication::translate("MainWindow", "ID SALLE", nullptr));
        bt_refresh_cour->setText(QCoreApplication::translate("MainWindow", "REFRESH", nullptr));
        bt_qrcode->setText(QCoreApplication::translate("MainWindow", "QRCODE", nullptr));
        tabWidget->setTabText(tabWidget->indexOf(COUR), QCoreApplication::translate("MainWindow", "GESTION COUR", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
