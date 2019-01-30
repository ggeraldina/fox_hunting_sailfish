#ifndef TABLEUSER_H
#define TABLEUSER_H

#include <QObject>
#include "../CellUser.h"

class TableUser : public QObject {
     Q_OBJECT

public:
    explicit TableUser(QObject *parent = nullptr);

    static void editCellsWhenFox(QList<CellUser *> *list, int index);
    static void editCellsWhenNoFox(QList<CellUser *> *list, int index);

private:
    static const int VALUE_FOX = -1;
};

#endif // TABLEUSER_H
