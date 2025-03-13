#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QMessageBox>
#include <QDebug>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    conn.createconnect();
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_ajouterButton_clicked()
{
    QString nom = ui->nomLineEdit->text();
    QString prenom = ui->prenomLineEdit->text();
    QString adresse = ui->adresseLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString telephone = ui->telephoneLineEdit->text();

    if (conn.createUser(nom, prenom, adresse, email, telephone)) {
        QMessageBox::information(this, "Succès", "Utilisateur ajouté avec succès !");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de l'ajout de l'utilisateur.");
    }
}

void MainWindow::on_modifierButton_clicked()
{
    int id = ui->idLineEdit->text().toInt();
    QString nom = ui->nomLineEdit->text();
    QString prenom = ui->prenomLineEdit->text();
    QString adresse = ui->adresseLineEdit->text();
    QString email = ui->emailLineEdit->text();
    QString telephone = ui->telephoneLineEdit->text();

    if (conn.updateUser(id, nom, prenom, adresse, email, telephone)) {
        QMessageBox::information(this, "Succès", "Utilisateur modifié avec succès !");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la modification de l'utilisateur.");
    }
}

void MainWindow::on_supprimerButton_clicked()
{
    int id = ui->idLineEdit->text().toInt();

    if (conn.deleteUser(id)) {
        QMessageBox::information(this, "Succès", "Utilisateur supprimé avec succès !");
    } else {
        QMessageBox::warning(this, "Erreur", "Échec de la suppression de l'utilisateur.");
    }
}

void MainWindow::on_rechercherButton_clicked()
{
    QString nom = ui->nomLineEdit->text();
    QList<QSqlRecord> users = conn.readUsers();

    for (const QSqlRecord &record : users) {
        if (record.value("nom").toString() == nom) {
            ui->prenomLineEdit->setText(record.value("prenom").toString());
            ui->adresseLineEdit->setText(record.value("adresse").toString());
            ui->emailLineEdit->setText(record.value("email").toString());
            ui->telephoneLineEdit->setText(record.value("telephone").toString());
            ui->idLineEdit->setText(record.value("id").toString());
            break;
        }
    }
}
