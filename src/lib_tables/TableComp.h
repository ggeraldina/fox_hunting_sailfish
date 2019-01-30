#ifndef TABLECOMP_H
#define TABLECOMP_H

#include <QObject>
#include "../CellComp.h"
#include "TableAny.h"

class TableComp : public QObject {
     Q_OBJECT

public:
    explicit TableComp(QObject *parent = nullptr);

    static void showFoxesOnField(QList<CellComp *> *list);
    static void editCellsWhenFox(QList<CellComp *> *list, int index, int numberFoxes, int countFoundFoxes);
    static void recalculatePossibleShot(QList<CellComp *> *list, int numberFoxes, int countFoundFoxes);
    static int countFoundFoxesShapeSnowflake(QList<CellComp *> *list, int index);
    static void editCellsWhenNoFox(QList<CellComp *> *list, int index, int numberFoxes, int countFoundFoxes);
    static void editCellsWhenZero(QList<CellComp *> *list, int index);
    static void editPossibleShotFalse(QList<CellComp *> *list, int index);
    static void editPossibleShotFalseAround(QList<CellComp *> *list, int currentIndex);
    static void editCellsWhenNumberFoxes(QList<CellComp *> *list, int index);
    static void editCellsWhenNumber(QList<CellComp *> *list, int index, int numberFoxes);
    static void editChance(QList<CellComp *> *list, int index, double newChance);
    static int generateIndexCellForShot(QList<CellComp *> *list);
    static int countMaxChance(QList<CellComp *> *list);
    static void calculateIndexesCellsMaxChance(QList<CellComp *> *list, int indexesCells[], int sizeArray);


private:
    static const int VALUE_FOX = -1;
};

#endif // TABLECOMP_H
