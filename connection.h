#ifndef CONNECTION_H
#define CONNECTION_H

#include <QSqlDatabase>
#include <QSqlError>
#include <QDebug>
#include <QSqlQuery>
#include <QSqlRecord>

class Connection
{
public:
    Connection();
    bool createconnect();

    // CRUD Operations
    bool createUser(const QString &nom, const QString &prenom, const QString &adresse, const QString &email, const QString &telephone);
    QList<QSqlRecord> readUsers();
    bool updateUser(int id, const QString &nom, const QString &prenom, const QString &adresse, const QString &email, const QString &telephone);
    bool deleteUser(int id);
};

#endif // CONNECTION_H
