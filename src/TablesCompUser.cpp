#include "TablesCompUser.h"

TablesCompUser::TablesCompUser(QObject *parent) : QObject(parent) {
    srand( time(0) ); // автоматическая рандомизация
    connect(this, &TablesCompUser::baseTableSizeChanged, this, &TablesCompUser::createData);
    connect(this, &TablesCompUser::numberFoxesChanged, this, &TablesCompUser::initData);
}

void TablesCompUser::createData() {
    int countCells = baseFieldSize * baseFieldSize;
    for(int i = 0; i < countCells; i++) {
        CellComp *elementCellComp = new CellComp(this);
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
    QList<T *> *dataUser = static_cast<QList<T *> *>(list->data);
    dataUser->append(value);
}
template <class T>
int TablesCompUser::countDataCells(QQmlListProperty<T> *list) {
    QList<T *> *dataUser = static_cast<QList<T *> *>(list->data);
    return dataUser->size();
}
template <class T>
T *TablesCompUser::atDataCells(QQmlListProperty<T> *list, int index) {
    QList<T *> *dataUser = static_cast<QList<T *> *>(list->data);
    return dataUser->at(index);
}
template <class T>
void TablesCompUser::clearDataCells(QQmlListProperty<T> *list) {
    QList<T *> *dataUser = static_cast<QList<T *> *>(list->data);
    qDeleteAll(dataUser->begin(), dataUser->end());
    dataUser->clear();
}

void TablesCompUser::shotCellUser(int index) {
    if (dataUser.value(index)->getShot())
        return;
    int value = dataUser.value(index)->getValue();
    if (value == VALUE_FOX) {
        dataUser.value(index)->setProperty("backgroundURL", "qrc:/image/fox.jpg");
        countFoundFoxesUser++;
        if (countFoundFoxesUser == numberFoxes)
            emit winUser();
    }
    else {
        dataUser.value(index)->setProperty("text", value);
        shotCellComp();
    }
    dataUser.value(index)->setProperty("shot", true);
}

void TablesCompUser::shotCellComp() {
    int countCells = baseFieldSize * baseFieldSize;
    int randomIndex = rand() % (countCells - 1);
    if (dataComp.value(randomIndex)->getShot()){
        shotCellComp();
        return;
    }
    int value = dataComp.value(randomIndex)->getValue();
    if (value == VALUE_FOX) {
        dataComp.value(randomIndex)->setProperty("backgroundURL", "qrc:/image/fox.jpg");
        dataComp.value(randomIndex)->setProperty("text", "");
        countFoundFoxesComp++;
        if (countFoundFoxesComp == numberFoxes)
            emit winComp();
        shotCellComp();
    }
    else
        dataComp.value(randomIndex)->setProperty("text", value);
    dataComp.value(randomIndex)->setProperty("shot", true);
}



