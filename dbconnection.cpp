#include "dbconnection.h"
#include "global.h"


DBConnection::DBConnection() //default construct definition
{

}

bool DBConnection::connect()
{
    /*
     *  This required that the qsqlmysql.dll  + qsqlmysqld.dll (plugins + sqldrivers folders),
     *  and libmysql.dll (lib and bin folders) drivers be downloaded from codemonkey89 on github.
     *  This was done for both MSCV2019_64, and mingw81_64
     *  What a wild goose chase that was!
     */
    g_db = QSqlDatabase::addDatabase("QMYSQL");
    g_db.setHostName("phoneme-db.crm7fj6xpwpv.us-west-1.rds.amazonaws.com");
    g_db.setUserName("appuser");
    g_db.setPassword("testPassword123");
    g_db.setDatabaseName("word-to-phoneme");

    return g_db.open();

}
