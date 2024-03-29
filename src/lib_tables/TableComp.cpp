#include "TableComp.h"

TableComp::TableComp(QObject *parent) : QObject(parent) {

}

void TableComp::editCellsWhenFox(QList<CellComp *> *list, int index, int numberFoxes, int countFoundFoxes) {
    list->value(index)->setBackgroundURL("qrc:/image/fox.jpg");
    list->value(index)->setText("");
    list->value(index)->setShot(true);
    list->value(index)->setPossibleShot(false);
    editPossibleShotFalseAround(list, index);
    recalculatePossibleShot(list, numberFoxes, countFoundFoxes);
}

void TableComp::recalculatePossibleShot(QList<CellComp *> *list, int numberFoxes, int countFoundFoxes) {
    int countCells = list->count();
    for (int i = 0; i < countCells; i++) {
        int valueCell = list->value(i)->getValue();
        bool shotCell = list->value(i)->getShot();
        if (valueCell != VALUE_FOX && shotCell) {
            int foundFoxesShapeSnowflake = countFoundFoxesShapeSnowflake(list, i);
            if (valueCell == foundFoxesShapeSnowflake) {
                editCellsWhenZero(list, i);
            }
            if (numberFoxes - valueCell == countFoundFoxes - foundFoxesShapeSnowflake) {
                editCellsWhenNumberFoxes(list, i);
            }
        }
    }
}

int TableComp::countFoundFoxesShapeSnowflake(QList<CellComp *> *list, int index) {
    int countCells = list->count();
    QVector<bool> cellsShapeSnowflake = TableAny::calculateIndexesShapeSnowflake(countCells, index);
    int countFoundFoxesAround = 0;
    for (int i = 0; i < countCells; i++) {
        if (cellsShapeSnowflake[i]) {
            int valueCell = list->value(i)->getValue();
            bool shotCell = list->value(i)->getShot();
            if (valueCell == VALUE_FOX && shotCell)
                countFoundFoxesAround += 1;
        }
    }
    return countFoundFoxesAround;
}

void TableComp::editCellsWhenNoFox(QList<CellComp *> *list, int index, int numberFoxes, int countFoundFoxes) {
    int valueCell = list->value(index)->getValue();
    list->value(index)->setText(QString::number(valueCell));
    list->value(index)->setBackgroundURL("qrc:/image/lightYellow.jpg");
    list->value(index)->setShot(true);
    list->value(index)->setPossibleShot(false);
    int foundFoxesShapeSnowflake = countFoundFoxesShapeSnowflake(list, index);
    if (valueCell == foundFoxesShapeSnowflake) {
        editCellsWhenZero(list, index);
    }
    if (valueCell == numberFoxes + foundFoxesShapeSnowflake - countFoundFoxes) {
        editCellsWhenNumberFoxes(list, index);
    }
    editCellsWhenNumber(list, index, numberFoxes);
}

void TableComp::editCellsWhenZero(QList<CellComp *> *list, int index) {
    TableAny::editCellsShapeSnowflake(list, index, editPossibleShotFalse);
}

void TableComp::editCellsWhenNumberFoxes(QList<CellComp *> *list, int index) {
    TableAny::editCellsShapeNoSnowflake(list, index, editPossibleShotFalse);
}

void TableComp::editPossibleShotFalse(QList<CellComp *> *list, int currentIndex) {
    list->value(currentIndex)->setPossibleShot(false);
}

void TableComp::editPossibleShotFalseAround(QList<CellComp *> *list, int currentIndex) {
    int countCells = list->count();
    int indexesCellsAround[8];
    TableAny::calculateIndexesCellsAroundRadius(indexesCellsAround, countCells, currentIndex);
    for (auto indexCell : indexesCellsAround) {
        if(indexCell >= 0) {
            list->value(indexCell)->setPossibleShot(false);
        }
    }
}

void TableComp::editCellsWhenNumber(QList<CellComp *> *list, int currentIndex, int numberFoxes) {
    int countCells = list->count();
    QVector<bool> cellsShapeSnowflake = TableAny::calculateIndexesShapeSnowflake(countCells, currentIndex);
    int countGroupTrue = TableAny::countGroupTrueIndexes(cellsShapeSnowflake);
    int valueCell = list->value(currentIndex)->getValue();
    double chanceGroupTrue = static_cast<double>(valueCell) / (countGroupTrue * numberFoxes);
    double chanceGroupFalse = static_cast<double>(numberFoxes - valueCell) / ((countCells - countGroupTrue) * numberFoxes);
    for (int i = 0; i < countCells; i++) {
        if(cellsShapeSnowflake[i]) {
            editChance(list, i, chanceGroupTrue);
        }
        else {
            editChance(list, i, chanceGroupFalse);
        }
    }
}

void TableComp::editChance(QList<CellComp *> *list, int index, double newChance) {
    double oldChance = list->value(index)->getChance();
    double resultChance = (oldChance + newChance) / 2;
    list->value(index)->setChance(resultChance);
}

int TableComp::generateIndexCellForShot(QList<CellComp *> *list) {
    QVector<int> indexesRandomCells = calculateIndexesCellsMaxChance(list);
    int countCellsRandom = indexesRandomCells.count();
    int randomNumber = rand() % countCellsRandom;
    int randomIndex = indexesRandomCells[randomNumber];
    return randomIndex;
}

int TableComp::countMaxChance(QList<CellComp *> *list) {
    int countCells = list->count();
    double maxChance = -1;
    int countChance = 0;
    for (int i = 0; i < countCells; i++) {
        double chance = list->value(i)->getChance();
        if (list->value(i)->getPossibleShot()) {
            if (chance > maxChance) {
                maxChance = chance;
                countChance = 1;
            }
            else if (chance == maxChance) {
                countChance += 1;
            }
        }
    }
    return countChance;
}

QVector<int> TableComp::calculateIndexesCellsMaxChance(QList<CellComp *> *list) {
    int countCells = list->count();
    double maxChance = -1;
    QVector<int> indexesCellsMax;
    for (int i = 0; i < countCells; i++) {
        double chance = list->value(i)->getChance();
        if (list->value(i)->getPossibleShot()) {
            if (chance > maxChance) {
                maxChance = chance;
                indexesCellsMax.clear();
                indexesCellsMax.append(i);
            }
            else if (chance == maxChance) {
                indexesCellsMax.append(i);
            }
        }
    }
    return indexesCellsMax;
}

int TableComp::generateRandomIndexForShot(QList<CellComp *> *list, int countCells) {
    int randomIndex = rand() % countCells;
    if (list->value(randomIndex)->getShot()){
        randomIndex = generateRandomIndexForShot(list, countCells);
    }
    return randomIndex;
}

