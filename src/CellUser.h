#ifndef CELLUSER_H
#define CELLUSER_H

#include "CellBase.h"

class CellUser : public CellBase {
    Q_OBJECT
    Q_PROPERTY(bool shot READ getShot WRITE setShot NOTIFY shotChanged)

public:
    explicit CellUser(QObject *parent = nullptr);

    bool getShot();
    void setShot(bool shot);

private:
    bool shot;

signals:    
    void shotChanged();
};

#endif // CELLUSER_H
