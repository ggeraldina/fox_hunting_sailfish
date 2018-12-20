#ifndef TABLESCOMPUSER_H
#define TABLESCOMPUSER_H

#include <QObject>
#include <QQmlListProperty>
#include "CellComp.h"
#include "CellUser.h"


class TablesCompUser : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<CellComp> dataComp READ getDataComp NOTIFY dataCompChanged)
    Q_PROPERTY(QQmlListProperty<CellUser> dataUser READ getDataUser NOTIFY dataUserChanged)
    Q_CLASSINFO("DefaultProperty", "dataComp")
    Q_CLASSINFO("DefaultProperty", "dataUser")
public:
    explicit TablesCompUser(QObject *parent = 0);

    QQmlListProperty<CellComp> getDataComp();
    QQmlListProperty<CellUser> getDataUser();

    Q_INVOKABLE void clickCellComp(int index);
private:
    static void appendDataComp(QQmlListProperty<CellComp> *list, CellComp *value);
    static int countDataComp(QQmlListProperty<CellComp> *list);
    static CellComp *atDataComp(QQmlListProperty<CellComp> *list, int index);
    static void clearDataComp(QQmlListProperty<CellComp> *list);

    static void appendDataUser(QQmlListProperty<CellUser> *list, CellUser *value);
    static int countDataUser(QQmlListProperty<CellUser> *list);
    static CellUser *atDataUser(QQmlListProperty<CellUser> *list, int index);
    static void clearDataUser(QQmlListProperty<CellUser> *list);

    QList<CellComp*> dataComp;
    QList<CellUser*> dataUser;

signals:
    void dataCompChanged();
    void dataUserChanged();
    void clickComp(int index);

public slots:
    void printUser(int index);
};

#endif // TABLESCOMPUSER_H
