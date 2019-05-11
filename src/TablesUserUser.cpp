#include "TablesUserUser.h"

TablesUserUser::TablesUserUser(QObject *parent) : TablesCompUser(parent) {

}

TablesUserUser::~TablesUserUser() {
    // qDeleteAll - вызывает С++ delete для элементов, являющихся указателями,
    // но при этом не удаляет элементы из контейнера QList
    // clear - удаляет элементы из контейнера
    qDeleteAll(dataUser.begin(), dataUser.end());
    dataUser.clear();

    qDeleteAll(dataUserOpponent.begin(), dataUserOpponent.end());
    dataUserOpponent.clear();
}

void TablesUserUser::createData() {
    int countCells = baseFieldSize * baseFieldSize;
    for(int i = 0; i < countCells; i++) {
        CellUser *elementCellUser = new CellUser(this);
        dataUser << elementCellUser;

        CellUser *elementCellUserOpponent = new CellUser(this);
        dataUserOpponent << elementCellUserOpponent;
    }
}

void TablesUserUser::addFoxesUserOpponent(QVariant indexes) {
    TableAny::addFoxes(&dataUserOpponent, indexes);
}

void TablesUserUser::shotCellUserOpponentGameRestore(int index) {
    increaseCountStepsUserOpponent();
    int valueCell = dataUserOpponent.value(index)->getValue();
    if (valueCell == VALUE_FOX) {
        countFoundFoxesUserOpponent++;
        TableUser::editCellsWhenFox(&dataUserOpponent, index);
    }
    else {
        TableUser::editCellsWhenNoFox(&dataUserOpponent, index);
    }
}

QQmlListProperty<CellUser> TablesUserUser::getDataUserOpponent() {
    return QQmlListProperty<CellUser>(static_cast<QObject *>(this), static_cast<void *>(&dataUserOpponent),
                                     &TablesBase::appendDataCells<CellUser>,
                                     &TablesBase::countDataCells<CellUser>,
                                     &TablesBase::atDataCells<CellUser>,
                                     &TablesBase::clearDataCells<CellUser>);
}

int TablesUserUser::getCountStepsUserOpponent() {
    return countStepsUserOpponent;
}

bool TablesUserUser::getFlagLockedTablesOpponent() {
    return flagLockedTablesOpponent;
}

void TablesUserUser::setFlagLockedTablesOpponent(bool newValue) {
    if (flagLockedTablesOpponent == newValue) {
        return;
    }
    flagLockedTablesOpponent = newValue;
    emit flagLockedTablesOpponentChanged();
}

void TablesUserUser::increaseCountStepsUserOpponent(int addedValue) {
    countStepsUserOpponent += addedValue;
    emit countStepsUserOpponentChanged();
}




void TablesUserUser::shotCellUserOpponent(int index) {
    if (flagLockedTablesOpponent || dataUserOpponent.value(index)->getShot()) {
        return;
    }
    flagLockedTablesOpponent = true;
    emit shotUserOpponent(index);
    increaseCountStepsUserOpponent();
    int valueCell = dataUserOpponent.value(index)->getValue();
    if (valueCell == VALUE_FOX) {
        emit shotFoxUserOpponent(countFoundFoxesUserOpponent);
        shotCellUserOpponentWhenFox(index);
    }
    else {
        TableUser::editCellsWhenNoFox(&dataUserOpponent, index);
        flagLockedTables = false;
    }
}

void TablesUserUser::shotCellUserOpponentWhenFox(int index) {
    TableUser::editCellsWhenFox(&dataUserOpponent, index);
    countFoundFoxesUserOpponent++;
    if (countFoundFoxesUserOpponent == numberFoxes) {
        flagLockedTablesOpponent = true;
        QTimer::singleShot(speedTimer, this, &TablesUserUser::signalWinUserOpponent);
        return;
    }
    flagLockedTablesOpponent = false;
}

void TablesUserUser::signalWinUserOpponent() {
    emit winUserOpponent();
}

void TablesUserUser::shotCellUser(int index) {
    if (flagLockedTables || dataUser.value(index)->getShot()) {
        return;
    }
    flagLockedTables = true;
    emit shotUser(index);
    TablesCompUser::increaseCountStepsUser();
    int valueCell = dataUser.value(index)->getValue();
    if (valueCell == VALUE_FOX) {
        TablesCompUser::shotCellUserWhenFox(index);
    }
    else {
        TableUser::editCellsWhenNoFox(&dataUser, index);
        flagLockedTablesOpponent = false;
    }
}

void TablesUserUser::putOrRemoveMarkCellUserOpponent(int index) {
    TableUser::putOrRemoveMarkCell(&dataUserOpponent, index);
}
