#include "TablesCompUser.h"

TablesCompUser::TablesCompUser(QObject *parent) : QObject(parent) {
    srand( time(0) ); // автоматическая рандомизация
    timeGameComp.setHMS(0, 0, 0, 0);
    timeGameUser.setHMS(0, 0, 0, 0);
    connect(&timerGameComp, &QTimer::timeout, this, &TablesCompUser::updateTimeGameComp);
    connect(&timerGameUser, &QTimer::timeout, this, &TablesCompUser::updateTimeGameUser);
    connect(this, &TablesCompUser::baseTableSizeChanged, this, &TablesCompUser::createData);
    connect(this, &TablesCompUser::numberFoxesChanged, this, &TablesCompUser::initData);
    connect(this, &TablesCompUser::speedStepCompChanged, this, &TablesCompUser::startTimerGameUser);
}

TablesCompUser::~TablesCompUser() {
    // qDeleteAll - вызывает С++ delete для элементов, являющихся указателями,
    // но при этом не удаляет элементы из контейнера QList
    // clear - удаляет элементы из контейнера
    qDeleteAll(dataComp.begin(), dataComp.end());
    dataComp.clear();
    qDeleteAll(dataUser.begin(), dataUser.end());
    dataUser.clear();
}

void TablesCompUser::createData() {
    int countCells = baseFieldSize * baseFieldSize;
    double chance = static_cast<double>(1)/countCells;
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

void TablesCompUser::startTimerGameUser(){
    timerGameUser.start(speedStepComp);
}

void TablesCompUser::updateTimeGameComp() {
    timeGameComp = timeGameComp.addMSecs(speedStepComp);
    emit timeGameCompChanged();
    shotCellComp();
}

void TablesCompUser::updateTimeGameUser() {
    timeGameUser = timeGameUser.addMSecs(speedStepComp);
    emit timeGameUserChanged();
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

QString TablesCompUser::getTimeGameComp() {
    return timeGameComp.toString("mm:ss");
}

QString TablesCompUser::getTimeGameUser() {
    return timeGameUser.toString("mm:ss");
}

int TablesCompUser::getLevelGame() {
    return levelGame;
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

void TablesCompUser::setLevelGame(int newValue) {
    if (newValue <= 0 || levelGame == newValue) {
        return;
    }
    levelGame = newValue;
    emit levelGameChanged();
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
    if (flagLockedTables || dataUser.value(index)->getShot()) {
        return;
    }
    flagLockedTables = true;
    emit shotUser();
    increaseCountStepsUser();
    int valueCell = dataUser.value(index)->getValue();
    if (valueCell == VALUE_FOX) {
        shotCellUserWhenFox(index);
    }
    else {
        shotCellUserWhenNoFox(index);
    }
}

void TablesCompUser::shotCellUserWhenFox(int index) {
    TableUser::editCellsWhenFox(&dataUser, index);
    countFoundFoxesUser++;
    if (countFoundFoxesUser == numberFoxes) {
        timerGameComp.stop();
        timerGameUser.stop();
        emit winUser();
    }
    flagLockedTables = false;
}

void TablesCompUser::shotCellUserWhenNoFox(int index) {
    timerGameUser.stop();
    TableUser::editCellsWhenNoFox(&dataUser, index);
    timerGameComp.start(speedStepComp);
}


void TablesCompUser::shotCellComp() {
    emit shotComp();
    increaseCountStepsComp();
    int smartRandomIndex = generateIndexByLevel();
    int valueCell = dataComp.value(smartRandomIndex)->getValue();
    if (valueCell == VALUE_FOX) {
        shotCellCompWhenFox(smartRandomIndex);
    }
    else {
        shotCellCompWhenNoFox(smartRandomIndex);
    }
}

void TablesCompUser::shotCellCompWhenFox(int index) {
    TableComp::editCellsWhenFox(&dataComp, index, numberFoxes, countFoundFoxesComp);
    countFoundFoxesComp++;
    if (countFoundFoxesComp == numberFoxes) {
        timerGameComp.stop();
        timerGameUser.stop();
        emit winComp();
        return;
    }
}

void TablesCompUser::shotCellCompWhenNoFox(int index) {
    timerGameComp.stop();
    TableComp::editCellsWhenNoFox(&dataComp, index, numberFoxes, countFoundFoxesComp);
    timerGameUser.start(speedStepComp);
    flagLockedTables = false;
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

int TablesCompUser::generateIndexByLevel() {
    int randNumber= rand() % 100; // 0..99
    int chanseSmartShot = 0;
    switch (levelGame) {
    case 1:
        //  probability smart shot = 0%
        break;
    case 2:
        chanseSmartShot = 15;
        break;
    case 3:
        chanseSmartShot = 40;
        break;
    case 4:
        chanseSmartShot = 70;
        break;
    case 5:
        //  probability smart shot = 100%
        chanseSmartShot = 100;
        break;
    default:
        break;
    }
    if (randNumber < chanseSmartShot) {
        // smart shot
        return TableComp::generateIndexCellForShot(&dataComp);
    }
    else {
        return TableComp::generateRandomIndexForShot(&dataComp, dataComp.count());
    }
}



