#include "TablesCompUser.h"

TablesCompUser::TablesCompUser(QObject *parent) : QObject(parent) {
    srand( time(0) ); // автоматическая рандомизация
    connect(this, &TablesCompUser::baseTableSizeChanged, this, &TablesCompUser::createData);
    connect(this, &TablesCompUser::numberFoxesChanged, this, &TablesCompUser::initData);
}

void TablesCompUser::createData() {
    int countCells = baseFieldSize * baseFieldSize;
    double chance = (double)1/countCells;
    for(int i = 0; i < countCells; i++) {
        CellComp *elementCellComp = new CellComp(this);
        elementCellComp->setChance(chance);
        dataComp << elementCellComp;

        CellUser *elementCellUser = new CellUser(this);
        dataUser << elementCellUser;
    }
}

void TablesCompUser::initData() {
    TableAny::addRandomFoxes(&dataComp, numberFoxes);
    TableComp::showFoxesOnField(&dataComp);
    TableAny::addRandomFoxes(&dataUser, numberFoxes);
}

QQmlListProperty<CellComp> TablesCompUser::getDataComp() {
    return QQmlListProperty<CellComp>(static_cast<QObject *>(this), static_cast<void *>(&dataComp),
                                     &TablesCompUser::appendDataCells<CellComp>,
                                     &TablesCompUser::countDataCells<CellComp>,
                                     &TablesCompUser::atDataCells<CellComp>,
                                     &TablesCompUser::clearDataCells<CellComp>);
}

QQmlListProperty<CellUser> TablesCompUser::getDataUser() {
    return QQmlListProperty<CellUser>(static_cast<QObject *>(this), static_cast<void *>(&dataUser),
                                     &TablesCompUser::appendDataCells<CellUser>,
                                     &TablesCompUser::countDataCells<CellUser>,
                                     &TablesCompUser::atDataCells<CellUser>,
                                     &TablesCompUser::clearDataCells<CellUser>);
}

int TablesCompUser::getBaseTableSize() {
    return baseFieldSize;
}

int TablesCompUser::getNumberFoxes() {
    return numberFoxes;
}

void TablesCompUser::setBaseTableSize(int newValue) {
    if (newValue <= 0 || baseFieldSize == newValue) {
        return;
    }
    baseFieldSize = newValue;
    emit baseTableSizeChanged();
}

void TablesCompUser::setNumberFoxes(int newValue) {
    if (newValue <= 0 || numberFoxes == newValue) {
        return;
    }
    numberFoxes = newValue;
    emit numberFoxesChanged();
}

// abstract functions (depend on QList<T *>)

template <class T>
void TablesCompUser::appendDataCells(QQmlListProperty<T> *list, T *value) {
    QList<T *> *dataTable = static_cast<QList<T *> *>(list->data);
    dataTable->append(value);
}
template <class T>
int TablesCompUser::countDataCells(QQmlListProperty<T> *list) {
    QList<T *> *dataTable = static_cast<QList<T *> *>(list->data);
    return dataTable->size();
}
template <class T>
T *TablesCompUser::atDataCells(QQmlListProperty<T> *list, int index) {
    QList<T *> *dataTable = static_cast<QList<T *> *>(list->data);
    return dataTable->at(index);
}
template <class T>
void TablesCompUser::clearDataCells(QQmlListProperty<T> *list) {
    QList<T *> *dataTable = static_cast<QList<T *> *>(list->data);
    qDeleteAll(dataTable->begin(), dataTable->end());
    dataTable->clear();
}

void TablesCompUser::shotCellUser(int index) {
    if (dataUser.value(index)->getShot()) {
        return;
    }
    int valueCell = dataUser.value(index)->getValue();
    if (valueCell == VALUE_FOX) {
        TableUser::editCellsWhenFox(&dataUser, index);
        countFoundFoxesUser++;
        if (countFoundFoxesUser == numberFoxes) {
            emit winUser();
        }
    }
    else {
        TableUser::editCellsWhenNoFox(&dataUser, index);
        shotCellComp();
    }
}

void TablesCompUser::shotCellComp() {
    int smartRandomIndex = TableComp::generateIndexCellForShot(&dataComp);
    int valueCell = dataComp.value(smartRandomIndex)->getValue();
    if (valueCell == VALUE_FOX) {
        TableComp::editCellsWhenFox(&dataComp, smartRandomIndex, numberFoxes, countFoundFoxesComp);
        countFoundFoxesComp++;
        if (countFoundFoxesComp == numberFoxes) {
            emit winComp();
            return;
        }
        QTimer::singleShot(500, this, &TablesCompUser::nextStepComp);
    }
    else {
        TableComp::editCellsWhenNoFox(&dataComp, smartRandomIndex, numberFoxes, countFoundFoxesComp);
    }
}

void TablesCompUser::nextStepComp(){
    shotCellComp();
}



