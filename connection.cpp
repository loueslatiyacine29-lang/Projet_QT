#include "connection.h"

#include <QString>
#include <QtSql/QSqlDatabase>
#include <QSqlError>
#include <QDebug>

Connection *Connection::p_instance = nullptr;

Connection::Connection() = default;

Connection::~Connection()
{
    if (m_database.isValid()) {
        // Ensure the singleton releases the connection before application shutdown.
        const QString connectionName = m_database.connectionName();
        if (m_database.isOpen()) {
            m_database.close();
        }
        m_database = QSqlDatabase();
        if (!connectionName.isEmpty()) {
            QSqlDatabase::removeDatabase(connectionName);
        }
    }
}

Connection *Connection::instance()
{
    if (p_instance == nullptr) {
        p_instance = new Connection();
    }
    return p_instance;
}

bool Connection::createConnect()
{
    if (!m_database.isValid()) {
        // Configure the unique default connection the first time it is requested.
        m_database = QSqlDatabase::addDatabase("QODBC");
        m_database.setDatabaseName("wes");
        m_database.setUserName("SYSTEM");
        m_database.setPassword("wes");
    }

    if (!m_database.isOpen()) {
        bool ok = m_database.open();
        if (ok) {
            qDebug() << "Connection::createConnect() - database opened successfully.";
        }

        return true;
    }

    return true;
}
