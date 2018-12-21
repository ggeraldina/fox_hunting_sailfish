#include "TablesCompUser.h"

TablesCompUser::TablesCompUser(QObject *parent) : QObject(parent)
{
    for(int i = 0; i < countCells; i++) {
        CellComp *elementCellComp = new CellComp(this);
        elementCellComp->setProperty("text", "");
        elementCellComp->setProperty("color", "lightGreen");
        elementCellComp->setProperty("value", 0);
        dataComp << elementCellComp;

        CellUser *elementCellUser = new CellUser(this);
        elementCellUser->setProperty("text", "");
        elementCellUser->setProperty("color", "lightGreen");
        elementCellUser->setProperty("value", 0);
        dataUser << elementCellUser;
    }
    randomFoxes();
}

void TablesCompUser::randomFoxes() {
    srand( time(0) ); // автоматическая рандомизация
    for(int i = 0; i < numberFoxes; i++) {
        addRandomFox(dataComp);
        showFoxesCompOnField();
        addRandomFox(dataUser);
    }
}

void TablesCompUser::showFoxesCompOnField() {
    for(int i = 0; i < countCells; i++) {
        int value = dataComp.value(i)->getValue();
        if (value == valueFox)
            dataComp.value(i)->setProperty("text", "(fox)");
    }
}

template <typename T>
void TablesCompUser::addRandomFox(T data) {
    int randomIndex;
    while(true) {
        randomIndex = rand() % (countCells - 1);
        if (checkPossibleAddFox(data, randomIndex)) {
            addFox(data, randomIndex);
            return;
        }
    }
}

template <typename T>
bool TablesCompUser::checkPossibleAddFox(T data, int currentCell) {
    if (data.value(currentCell)->getValue() == valueFox)
        return false;
    int leftCenterCell = currentCell - 1;
    int leftTopCell = currentCell - baseFieldSize - 1;
    int topCell = currentCell - baseFieldSize;
    int rightTopCell = currentCell - baseFieldSize + 1;
    int rightCenterCell = currentCell + 1;
    int rightBottomCell = currentCell + baseFieldSize + 1;
    int bottomCell = currentCell + baseFieldSize;
    int leftBottomCell = currentCell + baseFieldSize - 1;
    if (leftCenterCell >= 0 && data.value(leftCenterCell)->getValue() == valueFox)
        return false;
    if (leftTopCell >= 0 && data.value(leftTopCell)->getValue() == valueFox)
        return false;
    if (topCell >= 0 && data.value(topCell)->getValue() == valueFox)
        return false;
    if (rightTopCell >= 0 && data.value(rightTopCell)->getValue() == valueFox)
        return false;
    if (rightCenterCell < countCells && data.value(rightCenterCell)->getValue() == valueFox)
        return false;
    if (rightBottomCell < countCells && data.value(rightBottomCell)->getValue() == valueFox)
        return false;
    if (bottomCell < countCells && data.value(bottomCell)->getValue() == valueFox)
        return false;
    if (leftBottomCell < countCells && data.value(leftBottomCell)->getValue() == valueFox)
        return false;
    return true;
}

template <typename T>
void TablesCompUser::addFox(T data, int currentCell) {

    data.value(currentCell)->setProperty("value", valueFox);

    int currentRow = currentCell / baseFieldSize;
    int currentColumn = currentCell % baseFieldSize;

    int leftCenterCell = currentCell - 1;
    int leftTopCell = currentCell - baseFieldSize - 1;
    int topCell = currentCell - baseFieldSize;
    int rightTopCell = currentCell - baseFieldSize + 1;
    int rightCenterCell = currentCell + 1;
    int rightBottomCell = currentCell + baseFieldSize + 1;
    int bottomCell = currentCell + baseFieldSize;
    int leftBottomCell = currentCell + baseFieldSize - 1;

    for(int i = 0; i < baseFieldSize; i++) {
        if (leftCenterCell >= 0 ) {
            int valueCell = data.value(leftCenterCell)->getValue();
            int rowCell = leftCenterCell / baseFieldSize;
            if (valueCell != valueFox && rowCell == currentRow)
                data.value(leftCenterCell)->setProperty("value", valueCell + 1);
        }
        leftCenterCell -= 1;

        if (leftTopCell >= 0 ) {
            int valueCell = data.value(leftTopCell)->getValue();
            int columnCell = leftTopCell % baseFieldSize;
            if (valueCell != valueFox && columnCell < currentColumn)
                data.value(leftTopCell)->setProperty("value", valueCell + 1);
        }
        leftTopCell -= (baseFieldSize + 1);

        if (topCell >= 0 ) {
            int valueCell = data.value(topCell)->getValue();
            if (valueCell != valueFox)
                data.value(topCell)->setProperty("value", valueCell + 1);
        }
        topCell -= baseFieldSize;

        if (rightTopCell >= 0 ) {
            int valueCell = data.value(rightTopCell)->getValue();
            int columnCell = rightTopCell % baseFieldSize;
            if (valueCell != valueFox && columnCell > currentColumn)
                data.value(rightTopCell)->setProperty("value", valueCell + 1);
        }
        rightTopCell -= (baseFieldSize - 1);


        if (rightCenterCell < countCells) {
            int valueCell = data.value(rightCenterCell)->getValue();
            int rowCell = rightCenterCell / baseFieldSize;
            if (valueCell != valueFox && rowCell == currentRow)
                data.value(rightCenterCell)->setProperty("value", valueCell + 1);
        }
        rightCenterCell += 1;

        if (rightBottomCell < countCells) {
            int valueCell = data.value(rightBottomCell)->getValue();
            int columnCell = rightBottomCell % baseFieldSize;
            if (valueCell != valueFox && columnCell > currentColumn)
                data.value(rightBottomCell)->setProperty("value", valueCell + 1);
        }
        rightBottomCell += (baseFieldSize + 1);

        if (bottomCell < countCells) {
            int valueCell = data.value(bottomCell)->getValue();
            if (valueCell != valueFox)
                data.value(bottomCell)->setProperty("value", valueCell + 1);
        }
        bottomCell += baseFieldSize;

        if (leftBottomCell < countCells) {
            int valueCell = data.value(leftBottomCell)->getValue();
            int columnCell = leftBottomCell % baseFieldSize;
            if (valueCell != valueFox && columnCell < currentColumn)
                data.value(leftBottomCell)->setProperty("value", valueCell + 1);
        }
        leftBottomCell += (baseFieldSize - 1);
    }
}

QQmlListProperty<CellComp> TablesCompUser::getDataComp() {
    return QQmlListProperty<CellComp>(static_cast<QObject *>(this), static_cast<void *>(&dataComp),
                                     &TablesCompUser::appendDataComp, &TablesCompUser::countDataComp,
                                     &TablesCompUser::atDataComp, &TablesCompUser::clearDataComp);
}
void TablesCompUser::appendDataComp(QQmlListProperty<CellComp> *list, CellComp *value) {
    QList<CellComp*> *dataComp = static_cast<QList<CellComp*> *>(list->data);
    dataComp->append(value);
}
int TablesCompUser::countDataComp(QQmlListProperty<CellComp> *list) {
    QList<CellComp*> *dataComp = static_cast<QList<CellComp*> *>(list->data);
    return dataComp->size();
}
CellComp *TablesCompUser::atDataComp(QQmlListProperty<CellComp> *list, int index) {
    QList<CellComp*> *dataComp = static_cast<QList<CellComp*> *>(list->data);
    return dataComp->at(index);
}
void TablesCompUser::clearDataComp(QQmlListProperty<CellComp> *list) {
    QList<CellComp*> *dataComp = static_cast<QList<CellComp*> *>(list->data);
    qDeleteAll(dataComp->begin(), dataComp->end());
    dataComp->clear();
}


QQmlListProperty<CellUser> TablesCompUser::getDataUser() {
    return QQmlListProperty<CellUser>(static_cast<QObject *>(this), static_cast<void *>(&dataUser),
                                     &TablesCompUser::appendDataUser, &TablesCompUser::countDataUser,
                                     &TablesCompUser::atDataUser, &TablesCompUser::clearDataUser);
}
void TablesCompUser::appendDataUser(QQmlListProperty<CellUser> *list, CellUser *value) {
    QList<CellUser*> *dataUser = static_cast<QList<CellUser*> *>(list->data);
    dataUser->append(value);
}
int TablesCompUser::countDataUser(QQmlListProperty<CellUser> *list) {
    QList<CellUser*> *dataUser = static_cast<QList<CellUser*> *>(list->data);
    return dataUser->size();
}
CellUser *TablesCompUser::atDataUser(QQmlListProperty<CellUser> *list, int index) {
    QList<CellUser*> *dataUser = static_cast<QList<CellUser*> *>(list->data);
    return dataUser->at(index);
}
void TablesCompUser::clearDataUser(QQmlListProperty<CellUser> *list) {
    QList<CellUser*> *dataUser = static_cast<QList<CellUser*> *>(list->data);
    qDeleteAll(dataUser->begin(), dataUser->end());
    dataUser->clear();
}

void TablesCompUser::shotCellUser(int index) {
    int value = dataUser.value(index)->getValue();
    if (value == valueFox) {
        dataUser.value(index)->setProperty("color", "orange");
        dataUser.value(index)->setProperty("text", "fox");
        countFoundFoxesUser++;
        if (countFoundFoxesUser == numberFoxes)
            emit winUser();
    }
    else {
        dataUser.value(index)->setProperty("text", value);
        shotCellComp();
    }
}

void TablesCompUser::shotCellComp() {
    int randomIndex = rand() % (countCells - 1);
    int value = dataComp.value(randomIndex)->getValue();
    if (value == valueFox) {
        dataComp.value(randomIndex)->setProperty("color", "orange");
        dataComp.value(randomIndex)->setProperty("text", "fox");
        countFoundFoxesComp++;
        if (countFoundFoxesComp == numberFoxes)
            emit winComp();
        shotCellComp();
    }
    else
        dataComp.value(randomIndex)->setProperty("text", value);
}



