#include "TablesCompUser.h"

TablesCompUser::TablesCompUser(QObject *parent) : TablesBase(parent) {
    connect(this, &TablesBase::baseTableSizeChanged, this, &TablesCompUser::createData);
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

void TablesCompUser::addFoxesComp(QVariant indexes) {
    QList<QVariant> list = indexes.toList();
    for(auto index : list) {
        int indexInt = index.toInt();
        TableAny::addOneFox(&dataComp, indexInt);
    }
    TableAny::showFoxesOnField(&dataComp);
}

void TablesCompUser::initFoxesUser() {
    QVector<int> indexesUserFoxes = TableAny::addRandomFoxes(&dataUser, numberFoxes);
    for(auto index : indexesUserFoxes) {
        emit addFoxUser(index);
    }
}

void TablesCompUser::addFoxesUser(QVariant indexes) {
    QList<QVariant> list = indexes.toList();
    for(auto index : list) {
        int indexInt = index.toInt();
        TableAny::addOneFox(&dataUser, indexInt);
    }
}

void TablesCompUser::shotCellCompGameSave(int index) {
    increaseCountStepsComp();
    int valueCell = dataComp.value(index)->getValue();
    if (valueCell == VALUE_FOX) {
        countFoundFoxesComp++;
        TableComp::editCellsWhenFox(&dataComp, index, numberFoxes, countFoundFoxesComp);
    }
    else {
        TableComp::editCellsWhenNoFox(&dataComp, index, numberFoxes, countFoundFoxesComp);
    }

//    for (int i = 0; i < dataComp.count(); i++) {
//        qDebug() << i << " Comp with:";
//        qDebug() << "value " << dataComp.value(i)->getValue();
//        qDebug() << "shot " << dataComp.value(i)->getShot();
//        qDebug() << "possible shot " << dataComp.value(i)->getPossibleShot();
//        qDebug() << "chance " << dataComp.value(i)->getChance();
//    }
}

void TablesCompUser::shotCellUserGameSave(int index) {
    increaseCountStepsUser();
    int valueCell = dataUser.value(index)->getValue();
    if (valueCell == VALUE_FOX) {
        countFoundFoxesUser++;
        TableUser::editCellsWhenFox(&dataUser, index);
    }
    else {
        TableUser::editCellsWhenNoFox(&dataUser, index);
    }

//    for (int i = 0; i < dataUser.count(); i++) {
//        qDebug() << i << " User with:";
//        qDebug() << "value " << dataUser.value(i)->getValue();
//        qDebug() << "shot " << dataUser.value(i)->getShot();
//    }
}

QQmlListProperty<CellComp> TablesCompUser::getDataComp() {
    return QQmlListProperty<CellComp>(static_cast<QObject *>(this), static_cast<void *>(&dataComp),
                                     &TablesBase::appendDataCells<CellComp>,
                                     &TablesBase::countDataCells<CellComp>,
                                     &TablesBase::atDataCells<CellComp>,
                                     &TablesBase::clearDataCells<CellComp>);
}

QQmlListProperty<CellUser> TablesCompUser::getDataUser() {
    return QQmlListProperty<CellUser>(static_cast<QObject *>(this), static_cast<void *>(&dataUser),
                                     &TablesBase::appendDataCells<CellUser>,
                                     &TablesBase::countDataCells<CellUser>,
                                     &TablesBase::atDataCells<CellUser>,
                                     &TablesBase::clearDataCells<CellUser>);
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

int TablesCompUser::getLevelGame() {
    return levelGame;
}

bool TablesCompUser::getFlagLockedTables() {
    return flagLockedTables;
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

void TablesCompUser::setFlagLockedTables(bool newValue) {
    if (flagLockedTables == newValue) {
        return;
    }
    flagLockedTables = newValue;
    emit flagLockedTablesChanged();
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
    emit shotUser(index);
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
        emit winUser();
    }
    flagLockedTables = false;
}

void TablesCompUser::shotCellUserWhenNoFox(int index) {
    TableUser::editCellsWhenNoFox(&dataUser, index);
    QTimer::singleShot(speedStepComp, this, &TablesCompUser::nextStepComp);
}

void TablesCompUser::nextStepComp(){
    shotCellComp();
}

void TablesCompUser::shotCellComp() {
    increaseCountStepsComp();
    int smartRandomIndex = generateIndexByLevel();
    emit shotComp(smartRandomIndex);
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
        emit winComp();
        return;
    }
    QTimer::singleShot(speedStepComp, this, &TablesCompUser::nextStepComp);
}

void TablesCompUser::shotCellCompWhenNoFox(int index) {
    TableComp::editCellsWhenNoFox(&dataComp, index, numberFoxes, countFoundFoxesComp);
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



