#ifndef CELLCOMP_H
#define CELLCOMP_H

#include "CellBase.h"

class CellComp : public CellBase {
    Q_OBJECT
    Q_PROPERTY(bool shot READ getShot WRITE setShot NOTIFY shotChanged)
    Q_PROPERTY(bool possibleShot READ getPossibleShot WRITE setPossibleShot NOTIFY possibleShotChanged)
    Q_PROPERTY(int chance READ getChance WRITE setChance NOTIFY chanceChanged)

public:
    explicit CellComp(QObject *parent = 0);

    bool getShot();
    bool getPossibleShot();
    int getChance();

    void setShot(bool shot);
    void setPossibleShot(bool possibleShot);
    void setChance(int chance);

private:
    bool shot;
    bool possibleShot;
    int chance;

signals:
    void shotChanged();
    void possibleShotChanged();
    void chanceChanged();
};


#endif // CELLCOMP_H
