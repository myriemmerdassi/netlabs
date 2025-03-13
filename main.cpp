#include <QCoreApplication>
#include <QDebug>
#include "connection.h"

int main(int argc, char *argv[])
{
    QCoreApplication a(argc, argv);

    Connection conn;
    if (conn.createconnect()) {
        qDebug() << "Connexion à la base de données établie !";
    } else {
        qDebug() << "Échec de la connexion à la base de données !";
    }

    return a.exec();
}
