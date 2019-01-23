#include "TableComp.h"

TableComp::TableComp(QObject *parent) : QObject(parent) {

}

void TableComp::showFoxesOnField(QList<CellComp *> *list) {
    int countCells = list->count();
    for(int i = 0; i < countCells; i++) {
        int value = list->value(i)->getValue();
        if (value == VALUE_FOX)
            list->value(i)->setText("x");
    }
}




