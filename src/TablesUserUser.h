#ifndef TABLESUSERUSER_H
#define TABLESUSERUSER_H

#include <QDebug>
#include <QObject>
#include <QQmlListProperty>
#include "TablesCompUser.h"

class TablesUserUser : public TablesCompUser {
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<CellUser> dataUserOpponent READ getDataUserOpponent NOTIFY dataUserOpponentChanged)
    Q_PROPERTY(int countStepsUserOpponent READ getCountStepsUserOpponent NOTIFY countStepsUserOpponentChanged)
    Q_PROPERTY(int flagLockedTablesOpponent READ getFlagLockedTablesOpponent WRITE setFlagLockedTablesOpponent NOTIFY flagLockedTablesOpponentChanged)

public:
    TablesUserUser(QObject *parent = nullptr);
    ~TablesUserUser();

    QQmlListProperty<CellUser> getDataUserOpponent();
    int getCountStepsUserOpponent();
    bool getFlagLockedTablesOpponent();

    void setFlagLockedTablesOpponent(bool newValue);

    Q_INVOKABLE void createData();
//    Q_INVOKABLE void shotCellUserOpponent(int index);
//    Q_INVOKABLE void putOrRemoveMarkCellUserOpponent(int index);
//    Q_INVOKABLE void initFoxesUserOpponent();
//    Q_INVOKABLE void addFoxesUserOpponent(QVariant indexes);
//    Q_INVOKABLE void shotCellUserOpponentGameRestore(int index);

protected:
    void increaseCountStepsUserOpponent(int addedValue = 1);

    int countFoundFoxesUserOpponent = 0;
    int countStepsUserOpponent = 0;
    bool flagLockedTablesOpponent = false;

    QList<CellUser *> dataUserOpponent;

signals:
    void dataUserOpponentChanged();
    void countStepsUserOpponentChanged();
    void flagLockedTablesOpponentChanged();
    void shotUserOpponent(int index);
    void shotFoxUserOpponent(int beforeCountFoxes);
    void winUserOpponent();
    void addFoxUserOpponent(int index);

protected slots:
//    void signalWinUserOpponent();
};

#endif // TABLESUSERUSER_H
