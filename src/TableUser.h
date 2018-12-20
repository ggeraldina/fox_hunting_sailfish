#ifndef TABLEUSER_H
#define TABLEUSER_H

#include <QObject>
#include <QQmlListProperty>
#include "CellUser.h"

class TableUser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<CellUser> dataUser READ getDataUser NOTIFY dataUserChanged)
public:
    explicit TableUser(QObject *parent = 0);

    QQmlListProperty<CellUser> getDataUser();

    Q_INVOKABLE void addDataUser();
private:
    static void appendDataUser(QQmlListProperty<CellUser> *list, CellUser *value);
    static int countDataUser(QQmlListProperty<CellUser> *list);
    static CellUser *atDataUser(QQmlListProperty<CellUser> *list, int index);
    static void clearDataUser(QQmlListProperty<CellUser> *list);

    QList<CellUser*> dataUser;

signals:
    void dataUserChanged();

public slots:
};

#endif // TABLEUSER_H
