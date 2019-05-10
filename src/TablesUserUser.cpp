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
