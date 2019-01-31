#ifndef TABLESCOMPUSER_H
#define TABLESCOMPUSER_H

#include <QObject>
#include <QQmlListProperty>
#include <QTimer>
#include "CellComp.h"
#include "CellUser.h"
#include "lib_tables/TableAny.h"
#include "lib_tables/TableComp.h"
#include "lib_tables/TableUser.h"


class TablesCompUser : public QObject {
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<CellComp> dataComp READ getDataComp NOTIFY dataCompChanged)
    Q_PROPERTY(QQmlListProperty<CellUser> dataUser READ getDataUser NOTIFY dataUserChanged)
    Q_PROPERTY(int baseTableSize READ getBaseTableSize WRITE setBaseTableSize NOTIFY baseTableSizeChanged)
    Q_PROPERTY(int numberFoxes READ getNumberFoxes WRITE setNumberFoxes NOTIFY numberFoxesChanged)
    Q_PROPERTY(int speedStepComp READ getSpeedStepComp WRITE setSpeedStepComp NOTIFY speedStepCompChanged)


public:
    explicit TablesCompUser(QObject *parent = 0);

    QQmlListProperty<CellComp> getDataComp();
    QQmlListProperty<CellUser> getDataUser();
    int getBaseTableSize();
    int getNumberFoxes();
    int getSpeedStepComp();

    void setBaseTableSize(int newValue);
    void setNumberFoxes(int newValue);
    void setSpeedStepComp(int newValue);

    Q_INVOKABLE void shotCellUser(int index); // the user made the shot on the cell with index
    Q_INVOKABLE void putOrRemoveMarkCellUser(int index);

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
    int speedStepComp;
    const int VALUE_FOX = -1;
    const QString MARK_USER = "?";

    int countFoundFoxesComp = 0;
    int countFoundFoxesUser = 0;
    bool flagStepComp = false;

    QList<CellComp *> dataComp;
    QList<CellUser *> dataUser;

signals:
    void dataCompChanged();
    void dataUserChanged();
    void baseTableSizeChanged();
    void numberFoxesChanged();
    void speedStepCompChanged();
    void shotUser();
    void shotComp();
    void winUser();
    void winComp();

public slots:
    void initData();
    void createData();

private slots:
    void nextStepComp();
};

#endif // TABLESCOMPUSER_H
