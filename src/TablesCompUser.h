#ifndef TABLESCOMPUSER_H
#define TABLESCOMPUSER_H

#include <QObject>
#include <QQmlListProperty>
#include <QTimer>
#include <QTime>
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
    Q_PROPERTY(int countStepsComp READ getCountStepsComp NOTIFY countStepsCompChanged)
    Q_PROPERTY(int countStepsUser READ getCountStepsUser NOTIFY countStepsUserChanged)
    Q_PROPERTY(QString timeGameComp READ getTimeGameComp NOTIFY timeGameCompChanged)
    Q_PROPERTY(QString timeGameUser READ getTimeGameUser NOTIFY timeGameUserChanged)
    Q_PROPERTY(int levelGame READ getLevelGame WRITE setLevelGame NOTIFY levelGameChanged)


public:
    explicit TablesCompUser(QObject *parent = 0);
    ~TablesCompUser();

    QQmlListProperty<CellComp> getDataComp();
    QQmlListProperty<CellUser> getDataUser();
    int getBaseTableSize();
    int getNumberFoxes();
    int getSpeedStepComp();
    int getCountStepsComp();
    int getCountStepsUser();
    QString getTimeGameComp();
    QString getTimeGameUser();
    int getLevelGame();


    void setBaseTableSize(int newValue);
    void setNumberFoxes(int newValue);
    void setSpeedStepComp(int newValue);
    void setLevelGame(int newValue);

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

    void increaseCountStepsComp(int addedValue = 1);
    void increaseCountStepsUser(int addedValue = 1);

    void shotCellUserWhenFox(int index);
    void shotCellUserWhenNoFox(int index);
    void shotCellComp();
    void shotCellCompWhenFox(int index);
    void shotCellCompWhenNoFox(int index);
    int generateIndexByLevel();

    int baseFieldSize;
    int numberFoxes;
    int speedStepComp; // msec
    int levelGame; // 1 - minimum level
    const int VALUE_FOX = -1;
    const QString MARK_USER = "?";

    int countFoundFoxesComp = 0;
    int countFoundFoxesUser = 0;
    int countStepsComp = 0;
    int countStepsUser = 0;
    QTime timeGameComp;
    QTime timeGameUser;
    QTimer timerGameComp;
    QTimer timerGameUser;
    bool flagLockedTables = false;

    QList<CellComp *> dataComp;
    QList<CellUser *> dataUser;

signals:
    void dataCompChanged();
    void dataUserChanged();
    void baseTableSizeChanged();
    void numberFoxesChanged();
    void speedStepCompChanged();
    void countStepsCompChanged();
    void countStepsUserChanged();
    void timeGameCompChanged();
    void timeGameUserChanged();
    void levelGameChanged();
    void shotUser();
    void shotComp();
    void winUser();
    void winComp();

public slots:

private slots:
    void initData();
    void createData();
    void startTimerGameUser();
    void updateTimeGameComp();
    void updateTimeGameUser();
};

#endif // TABLESCOMPUSER_H
