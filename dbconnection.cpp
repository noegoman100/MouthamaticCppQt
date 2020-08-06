#include "dbconnection.h"
#include "global.h"
#include <QFileDialog>
#include <QDebug>


DBConnection::DBConnection() //default construct definition
{

}

bool DBConnection::connect()
{
    //For SQLite connection.
    g_db = QSqlDatabase::addDatabase("QSQLITE");
    g_db.setDatabaseName(QDir::currentPath() + "/SQLiteDB.sqlite");

    qDebug() << QDir::currentPath();
    return g_db.open();

}
