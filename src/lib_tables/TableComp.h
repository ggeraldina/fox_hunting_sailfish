#ifndef TABLECOMP_H
#define TABLECOMP_H

#include <QObject>
#include "../CellComp.h"

class TableComp : public QObject {
     Q_OBJECT

public:
    explicit TableComp(QObject *parent = nullptr);

    static void showFoxesOnField(QList<CellComp *> *list);

private:
    static const int VALUE_FOX = -1;
};

#endif // TABLECOMP_H
