#ifndef TABLESCOMPUSER_H
#define TABLESCOMPUSER_H

#include <QObject>
#include <QQmlListProperty>
#include <QTime>
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
    Q_INVOKABLE void shotCellUser(int index);

private:
    static void appendDataComp(QQmlListProperty<CellComp> *list, CellComp *value);
    static int countDataComp(QQmlListProperty<CellComp> *list);
    static CellComp *atDataComp(QQmlListProperty<CellComp> *list, int index);
    static void clearDataComp(QQmlListProperty<CellComp> *list);

    static void appendDataUser(QQmlListProperty<CellUser> *list, CellUser *value);
    static int countDataUser(QQmlListProperty<CellUser> *list);
    static CellUser *atDataUser(QQmlListProperty<CellUser> *list, int index);
    static void clearDataUser(QQmlListProperty<CellUser> *list);

    void randomFoxes();
    template <typename T>
    void addFox(T data, int numberCell);
    template <typename T>
    void addRandomFox(T data);
    template <typename T>
    bool checkPossibleAddFox(T data, int randomIndex);
    void showFoxesCompOnField();
    void shotCellComp();

    const int baseFieldSize = 9;
    const int countCells = baseFieldSize * baseFieldSize;
    const int numberFoxes = 4;
    const int valueFox = -1;

    int countFoundFoxesComp = 0;
    int countFoundFoxesUser = 0;

    QList<CellComp*> dataComp;
    QList<CellUser*> dataUser;

signals:
    void dataCompChanged();
    void dataUserChanged();
    void winUser();
    void winComp();

public slots:
};

#endif // TABLESCOMPUSER_H
