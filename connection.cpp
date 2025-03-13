#include "connection.h"

Connection::Connection()
{
}

bool Connection::createconnect()
{
    bool test = false;
    QSqlDatabase db = QSqlDatabase::addDatabase("QODBC");
    db.setDatabaseName("Source_Projet2A");
    db.setUserName("Mariem");
    db.setPassword("esprit18");

    if (db.open()) {
        test = true;
        qDebug() << "Connexion réussie !";
    } else {
        qDebug() << "Échec de la connexion :" << db.lastError().text();
    }
    return test;
}

bool Connection::createUser(const QString &nom, const QString &prenom, const QString &adresse, const QString &email, const QString &telephone)
{
    QSqlQuery query;
    query.prepare("INSERT INTO Utilisateurs (nom, prenom, adresse, email, telephone) VALUES (:nom, :prenom, :adresse, :email, :telephone)");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);
    query.bindValue(":telephone", telephone);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur lors de la création de l'utilisateur :" << query.lastError().text();
        return false;
    }
}

QList<QSqlRecord> Connection::readUsers()
{
    QSqlQuery query("SELECT * FROM Utilisateurs");
    QList<QSqlRecord> records;

    while (query.next()) {
        records.append(query.record());
    }

    return records;
}

bool Connection::updateUser(int id, const QString &nom, const QString &prenom, const QString &adresse, const QString &email, const QString &telephone)
{
    QSqlQuery query;
    query.prepare("UPDATE Utilisateurs SET nom = :nom, prenom = :prenom, adresse = :adresse, email = :email, telephone = :telephone WHERE id = :id");
    query.bindValue(":nom", nom);
    query.bindValue(":prenom", prenom);
    query.bindValue(":adresse", adresse);
    query.bindValue(":email", email);
    query.bindValue(":telephone", telephone);
    query.bindValue(":id", id);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur lors de la mise à jour de l'utilisateur :" << query.lastError().text();
        return false;
    }
}

bool Connection::deleteUser(int id)
{
    QSqlQuery query;
    query.prepare("DELETE FROM Utilisateurs WHERE id = :id");
    query.bindValue(":id", id);

    if (query.exec()) {
        return true;
    } else {
        qDebug() << "Erreur lors de la suppression de l'utilisateur :" << query.lastError().text();
        return false;
    }
}
