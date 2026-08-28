#ifndef CONNECTION_H
#define CONNECTION_H

#include <QtSql/QSqlDatabase>

class Connection
{
public:
    static Connection *instance();
    bool createConnect();
    ~Connection();

private:
    Connection(); //CONSTRUCTEUR
    Connection(const Connection &) = delete;
    Connection &operator=(const Connection &) = delete;

    static Connection *p_instance;
    QSqlDatabase m_database;
};

#endif // CONNECTION_H
