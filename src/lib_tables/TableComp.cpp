#include "TableComp.h"

TableComp::TableComp(QObject *parent) : QObject(parent) {

}

void TableComp::showFoxesOnField(QList<CellComp *> *list) {
    int countCells = list->count();
    for(int i = 0; i < countCells; i++) {
        int valueCell = list->value(i)->getValue();
        if (valueCell == VALUE_FOX)
            list->value(i)->setText("x");
    }
}

void TableComp::editCellWithFox(QList<CellComp *> *list, int index) {
    list->value(index)->setBackgroundURL("qrc:/image/fox.jpg");
    list->value(index)->setText("");
    list->value(index)->setShot(true);
}

void TableComp::editCellWithoutFox(QList<CellComp *> *list, int index) {
    int valueCell = list->value(index)->getValue();
    list->value(index)->setText(QString::number(valueCell));
    list->value(index)->setShot(true);
}

int TableComp::generateIndexCellForShot(QList<CellComp *> *list, int countCells) {
    int randomIndex = rand() % (countCells - 1);
    if (list->value(randomIndex)->getShot()){
        randomIndex = generateIndexCellForShot(list, countCells);
    }
    return randomIndex;
}



