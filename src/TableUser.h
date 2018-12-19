#ifndef TABLEUSER_H
#define TABLEUSER_H

#include <QObject>
#include <QQmlListProperty>
#include "CellUser.h"

class TableUser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<CellUser> data READ getData NOTIFY dataChanged)
    Q_CLASSINFO("DefaultProperty", "data")
public:
    explicit TableUser(QObject *parent = 0);

    QQmlListProperty<CellUser> getData();

    Q_INVOKABLE void add();
private:
    static void appendData(QQmlListProperty<CellUser> *list, CellUser *value);
    static int countData(QQmlListProperty<CellUser> *list);
    static CellUser *atData(QQmlListProperty<CellUser> *list, int index);
    static void clearData(QQmlListProperty<CellUser> *list);

    QList<CellUser*> data;

signals:
    void dataChanged();

public slots:
};

#endif // TABLEUSER_H
