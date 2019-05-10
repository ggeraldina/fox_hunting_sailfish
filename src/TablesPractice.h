#ifndef TABLESPRACTICE_H
#define TABLESPRACTICE_H

#include <QObject>
#include <QQmlListProperty>
#include "lib_tables/TableUser.h"
#include "CellUser.h"
#include "TablesCompUser.h"

class TablesPractice : public TablesCompUser {
    Q_OBJECT

public:
    TablesPractice(QObject *parent = nullptr);
    ~TablesPractice();

    Q_INVOKABLE void createData();
    Q_INVOKABLE void shotCellUser(int index); // the user made the shot on the cell with index
};

#endif // TABLESPRACTICE_H
