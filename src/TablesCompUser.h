#ifndef TABLESCOMPUSER_H
#define TABLESCOMPUSER_H

#include <QDebug>
#include <QVariant>
#include <QObject>
#include <QQmlListProperty>
#include <QTimer>
#include <QTime>
#include "CellComp.h"
#include "CellUser.h"
#include "TablesBase.h"
#include "lib_tables/TableAny.h"
#include "lib_tables/TableComp.h"
#include "lib_tables/TableUser.h"


class TablesCompUser : public TablesBase {
    Q_OBJECT
    Q_PROPERTY(QQmlListProperty<CellComp> dataComp READ getDataComp NOTIFY dataCompChanged)
    Q_PROPERTY(QQmlListProperty<CellUser> dataUser READ getDataUser NOTIFY dataUserChanged)
    Q_PROPERTY(int speedStepComp READ getSpeedStepComp WRITE setSpeedStepComp NOTIFY speedStepCompChanged)
    Q_PROPERTY(int countStepsComp READ getCountStepsComp NOTIFY countStepsCompChanged)
    Q_PROPERTY(int countStepsUser READ getCountStepsUser NOTIFY countStepsUserChanged)
    Q_PROPERTY(int levelGame READ getLevelGame WRITE setLevelGame NOTIFY levelGameChanged)
    Q_PROPERTY(int flagLockedTables READ getFlagLockedTables WRITE setFlagLockedTables NOTIFY flagLockedTablesChanged)

public:
    explicit TablesCompUser(QObject *parent = nullptr);
    ~TablesCompUser();

    QQmlListProperty<CellComp> getDataComp();
    QQmlListProperty<CellUser> getDataUser();
    int getSpeedStepComp();
    int getCountStepsComp();
    int getCountStepsUser();
    int getLevelGame();
    bool getFlagLockedTables();

    void setSpeedStepComp(int newValue);
    void setLevelGame(int newValue);
    void setFlagLockedTables(bool newValue);

    Q_INVOKABLE void shotCellUser(int index); // the user made the shot on the cell with index
    Q_INVOKABLE void shotCellComp();
    Q_INVOKABLE void putOrRemoveMarkCellUser(int index);
    Q_INVOKABLE void addFoxesComp(QVariant indexes);
    Q_INVOKABLE void initFoxesUser();
    Q_INVOKABLE void addFoxesUser(QVariant indexes);
    Q_INVOKABLE void shotCellCompGameSave(int index);
    Q_INVOKABLE void shotCellUserGameSave(int index);


private:
    void increaseCountStepsComp(int addedValue = 1);
    void increaseCountStepsUser(int addedValue = 1);

    void shotCellUserWhenFox(int index);
    void shotCellUserWhenNoFox(int index);
    void shotCellCompWhenFox(int index);
    void shotCellCompWhenNoFox(int index);
    int generateIndexByLevel();

    int speedStepComp; // msec
    int levelGame; // 1 - minimum level
    const QString MARK_USER = "?";

    int countFoundFoxesComp = 0;
    int countFoundFoxesUser = 0;
    int countStepsComp = 0;
    int countStepsUser = 0;
    bool flagLockedTables = false;

    QList<CellComp *> dataComp;
    QList<CellUser *> dataUser;

signals:
    void dataCompChanged();
    void dataUserChanged();
    void speedStepCompChanged();
    void countStepsCompChanged();
    void countStepsUserChanged();
    void levelGameChanged();
    void flagLockedTablesChanged();
    void shotUser(int index);
    void shotComp(int index);
    void winUser();
    void winComp();
    void addFoxUser(int index);

public slots:

private slots:
    void createData();
    void nextStepComp();
};

#endif // TABLESCOMPUSER_H
