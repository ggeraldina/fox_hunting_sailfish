#include "TablesPractice.h"

TablesPractice::TablesPractice(QObject *parent) : TablesCompUser(parent) {
}

TablesPractice::~TablesPractice() {
    // qDeleteAll - вызывает С++ delete для элементов, являющихся указателями,
    // но при этом не удаляет элементы из контейнера QList
    // clear - удаляет элементы из контейнера
    qDeleteAll(dataUser.begin(), dataUser.end());
    dataUser.clear();
}

void TablesPractice::createData() {
    int countCells = baseFieldSize * baseFieldSize;
    for(int i = 0; i < countCells; i++) {
        CellUser *elementCellUser = new CellUser(this);
        dataUser << elementCellUser;
    }
}

void TablesPractice::shotCellUser(int index) {
    if (flagLockedTables || dataUser.value(index)->getShot()) {
        return;
    }
    emit shotUser(index);
    TablesCompUser::increaseCountStepsUser();
    int valueCell = dataUser.value(index)->getValue();
    if (valueCell == VALUE_FOX) {
        emit shotFoxUser(countFoundFoxesUser);
        TablesCompUser::shotCellUserWhenFox(index);
    }
    else {
        TableUser::editCellsWhenNoFox(&dataUser, index);
    }
}
