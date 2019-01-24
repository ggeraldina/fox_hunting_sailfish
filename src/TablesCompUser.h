#ifndef TABLESCOMPUSER_H
#define TABLESCOMPUSER_H

#include <QObject>
#include <QQmlListProperty>
#include "CellComp.h"
#include "CellUser.h"
#include "lib_tables/TableAny.h"
#include "lib_tables/TableComp.h"


class TablesCompUser : public QObject {
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<CellComp> dataComp READ getDataComp NOTIFY dataCompChanged)
    Q_PROPERTY(QQmlListProperty<CellUser> dataUser READ getDataUser NOTIFY dataUserChanged)
    Q_PROPERTY(int baseTableSize READ getBaseTableSize WRITE setBaseTableSize NOTIFY baseTableSizeChanged)
    Q_PROPERTY(int numberFoxes READ getNumberFoxes WRITE setNumberFoxes NOTIFY numberFoxesChanged)


public:
    explicit TablesCompUser(QObject *parent = 0);

    QQmlListProperty<CellComp> getDataComp();
    QQmlListProperty<CellUser> getDataUser();
    int getBaseTableSize();
    int getNumberFoxes();

    void setBaseTableSize(int newValue);
    void setNumberFoxes(int newValue);

    Q_INVOKABLE void shotCellUser(int index); // the user made the shot on the cell with index

private:
    template <class T>
    static void appendDataCells(QQmlListProperty<T> *list, T *value);
    template <class T>
    static int countDataCells(QQmlListProperty<T> *list);
    template <class T>
    static T *atDataCells(QQmlListProperty<T> *list, int index);
    template <class T>
    static void clearDataCells(QQmlListProperty<T> *list);

    void shotCellComp();

    int baseFieldSize;
    int numberFoxes;
    const int VALUE_FOX = -1;

    int countFoundFoxesComp = 0;
    int countFoundFoxesUser = 0;

    QList<CellComp *> dataComp;
    QList<CellUser *> dataUser;

signals:
    void dataCompChanged();
    void dataUserChanged();
    void baseTableSizeChanged();
    void numberFoxesChanged();
    void winUser();
    void winComp();

public slots:
    void initData();
    void createData();
};

#endif // TABLESCOMPUSER_H
