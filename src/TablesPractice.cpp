#include "TablesPractice.h"

TablesPractice::TablesPractice(QObject *parent) : TablesCompUser(parent) {
}

TablesPractice::~TablesPractice() {
}

void TablesPractice::shotCellUser(int index) {
    if (dataUser.value(index)->getShot()) {
        return;
    }
    emit shotUser(index);
    TablesCompUser::increaseCountStepsUser();
    int valueCell = dataUser.value(index)->getValue();
    if (valueCell == VALUE_FOX) {
        TablesCompUser::shotCellUserWhenFox(index);
    }
    else {
        TableUser::editCellsWhenNoFox(&dataUser, index);
    }
}
