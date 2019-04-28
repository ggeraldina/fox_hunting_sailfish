#ifndef TABLESCOMPUSER_H
#define TABLESCOMPUSER_H

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

public:
    explicit TablesCompUser(QObject *parent = nullptr);
    ~TablesCompUser();

    QQmlListProperty<CellComp> getDataComp();
    QQmlListProperty<CellUser> getDataUser();
    int getSpeedStepComp();
    int getCountStepsComp();
    int getCountStepsUser();
    int getLevelGame();

    void setSpeedStepComp(int newValue);
    void setLevelGame(int newValue);

    Q_INVOKABLE void shotCellUser(int index); // the user made the shot on the cell with index
    Q_INVOKABLE void putOrRemoveMarkCellUser(int index);

private:
    void increaseCountStepsComp(int addedValue = 1);
    void increaseCountStepsUser(int addedValue = 1);

    void shotCellUserWhenFox(int index);
    void shotCellUserWhenNoFox(int index);
    void shotCellComp();
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
    void shotUser();
    void shotComp();
    void winUser();
    void winComp();

public slots:

private slots:
    void initData();
    void createData();
    void nextStepComp();
};

#endif // TABLESCOMPUSER_H
