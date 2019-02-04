#include "TablesCompUser.h"

TablesCompUser::TablesCompUser(QObject *parent) : QObject(parent) {
    srand( time(0) ); // автоматическая рандомизация
    connect(this, &TablesCompUser::baseTableSizeChanged, this, &TablesCompUser::createData);
    connect(this, &TablesCompUser::numberFoxesChanged, this, &TablesCompUser::initData);
    timeGame = new QTime(0, 0);
    timerGame = new QTimer(this);
    connect(timerGame, SIGNAL(timeout()), this, SLOT(updateTimeGame()));
    timerGame->start(1000);
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

void TablesCompUser::updateTimeGame() {
    *timeGame = timeGame->addSecs(1);
    emit timeGameChanged();
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

int TablesCompUser::getSpeedStepComp() {
    return speedStepComp;
}

int TablesCompUser::getCountStepsComp() {
    return countStepsComp;
}

int TablesCompUser::getCountStepsUser() {
    return countStepsUser;
}

QString TablesCompUser::getTimeGame() {
    return timeGame->toString("hh:mm:ss");
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

void TablesCompUser::setSpeedStepComp(int newValue) {
    if (newValue <= 0 || speedStepComp == newValue) {
        return;
    }
    speedStepComp = newValue;
    emit speedStepCompChanged();
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

void TablesCompUser::increaseCountStepsComp(int addedValue) {
    countStepsComp += addedValue;
    emit countStepsCompChanged();
}

void TablesCompUser::increaseCountStepsUser(int addedValue) {
    countStepsUser += addedValue;
    emit countStepsUserChanged();
}

void TablesCompUser::shotCellUser(int index) {
    if (flagStepComp || dataUser.value(index)->getShot()) {
        return;
    }
    flagStepComp = true;
    emit shotUser();
    increaseCountStepsUser();
    int valueCell = dataUser.value(index)->getValue();
    if (valueCell == VALUE_FOX) {
        TableUser::editCellsWhenFox(&dataUser, index);
        countFoundFoxesUser++;
        if (countFoundFoxesUser == numberFoxes) {
            emit winUser();
        }
        flagStepComp = false;
    }
    else {
        TableUser::editCellsWhenNoFox(&dataUser, index);
        QTimer::singleShot(speedStepComp, this, &TablesCompUser::nextStepComp);
    }
}

void TablesCompUser::shotCellComp() {
    emit shotComp();
    increaseCountStepsComp();
    int smartRandomIndex = TableComp::generateIndexCellForShot(&dataComp);
    int valueCell = dataComp.value(smartRandomIndex)->getValue();
    if (valueCell == VALUE_FOX) {
        TableComp::editCellsWhenFox(&dataComp, smartRandomIndex, numberFoxes, countFoundFoxesComp);
        countFoundFoxesComp++;
        if (countFoundFoxesComp == numberFoxes) {
            emit winComp();
            return;
        }
        QTimer::singleShot(speedStepComp, this, &TablesCompUser::nextStepComp);
    }
    else {
        TableComp::editCellsWhenNoFox(&dataComp, smartRandomIndex, numberFoxes, countFoundFoxesComp);
        flagStepComp = false;
    }
}

void TablesCompUser::nextStepComp(){
    shotCellComp();
}

void TablesCompUser::putOrRemoveMarkCellUser(int index) {
    if (dataUser.value(index)->getShot()) {
        return;
    }
    QString textCell = dataUser.value(index)->getText();
    if (textCell == "") {
        dataUser.value(index)->setText(MARK_USER);
    }
    else {
        dataUser.value(index)->setText("");
    }
}



