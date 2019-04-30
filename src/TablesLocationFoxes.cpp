#include "TablesLocationFoxes.h"

TablesLocationFoxes::TablesLocationFoxes(QObject *parent) : TablesBase(parent) {
    srand( time(0) ); // автоматическая рандомизация
    connect(this, &TablesBase::baseTableSizeChanged, this, &TablesLocationFoxes::createData);
    connect(this, &TablesBase::numberFoxesChanged, this, &TablesLocationFoxes::initData);
    currentCountFoxes = 0;
}

TablesLocationFoxes::~TablesLocationFoxes() {
    // qDeleteAll - вызывает С++ delete для элементов, являющихся указателями,
    // но при этом не удаляет элементы из контейнера QList
    // clear - удаляет элементы из контейнера
    qDeleteAll(dataFoxes.begin(), dataFoxes.end());
    dataFoxes.clear();
}

void TablesLocationFoxes::createData() {
    int countCells = baseFieldSize * baseFieldSize;
    for(int i = 0; i < countCells; i++) {
        CellBase *elementCell = new CellBase(this);
        dataFoxes << elementCell;
    }
}

void TablesLocationFoxes::initData() {
    generateRandomLocationFoxes();
    currentCountFoxes = numberFoxes;
}

QQmlListProperty<CellBase> TablesLocationFoxes::getDataFoxes() {
    return QQmlListProperty<CellBase>(static_cast<QObject *>(this), static_cast<void *>(&dataFoxes),
                                     &TablesBase::appendDataCells<CellBase>,
                                     &TablesBase::countDataCells<CellBase>,
                                     &TablesBase::atDataCells<CellBase>,
                                     &TablesBase::clearDataCells<CellBase>);
}

void TablesLocationFoxes::cleanLocationFoxes() {
    currentCountFoxes = 0;
    for (auto cell : dataFoxes) {
        cell->setValue(0);
        cell->setText("");
    }
    emit removeAllFox();
}

void TablesLocationFoxes::generateRandomLocationFoxes() {
    cleanLocationFoxes();
    currentCountFoxes = numberFoxes;
    for(int i = 0; i < numberFoxes; i++) {
        int countCells = dataFoxes.count();
        int randomIndex;
        while(true) {
            randomIndex = rand() % countCells;
            if (TableAny::checkPossibleAddFox(&dataFoxes, randomIndex)) {
                dataFoxes.value(randomIndex)->setValue(VALUE_FOX);
                dataFoxes.value(randomIndex)->setText("x");
                emit addFox(randomIndex);
                break;
            }
        }
    }
}

QString TablesLocationFoxes::putOrRemoveFox(int index) {
    if (dataFoxes.value(index)->getValue() == VALUE_FOX) {
        dataFoxes.value(index)->setValue(0);
        dataFoxes.value(index)->setText("");
        emit removeFox(index);
        currentCountFoxes--;
        return tr("Foxes less than need");
    }
    if (currentCountFoxes < numberFoxes) {
        if (TableAny::checkPossibleAddFox(&dataFoxes, index)) {
            dataFoxes.value(index)->setValue(VALUE_FOX);
            dataFoxes.value(index)->setText("x");
            emit addFox(index);
            currentCountFoxes++;
            if (currentCountFoxes != numberFoxes) {
                return tr("Foxes less than need");
            }
            return "";
        }
        return tr("There are nearby foxes");
    }
    return tr("A lot of foxes");
}

bool TablesLocationFoxes::equalNumberAndCountFoxes() {
    if (currentCountFoxes != numberFoxes) {
        return false;
    }
    return true;
}
