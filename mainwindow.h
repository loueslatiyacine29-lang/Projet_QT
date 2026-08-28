#ifndef MAINWINDOW_H
#define MAINWINDOW_H
#include "cours.h"
#include "salles.h"
#include <QMainWindow>

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void on_bt_ajouter_salle_clicked();
    void remplir_comboBox_SALLE();

    void on_tableView_cour_clicked(const QModelIndex &index);

    void on_tableView_salle_clicked(const QModelIndex &index);

    void on_bt_modifier_salle_clicked();

    void on_bt_supprimer_salle_clicked();

    void on_bt_tri_salle_clicked();

    void on_bt_chercher_salle_clicked();

private:
    Ui::MainWindow *ui;
    SALLES s;
    COURS c;
};
#endif // MAINWINDOW_H
