#include "TableComp.h"

TableComp::TableComp(QObject *parent) : QObject(parent) {
    for(int i = 0; i < 81; i++) {
        CellComp *element = new CellComp(this);
        element->setProperty("text", "*");

        dataComp << element;
    }
}
QQmlListProperty<CellComp> TableComp::getDataComp() {
    return QQmlListProperty<CellComp>(static_cast<QObject *>(this), static_cast<void *>(&dataComp),
                                     &TableComp::appendDataComp, &TableComp::countDataComp,
                                     &TableComp::atDataComp, &TableComp::clearDataComp);
}

void TableComp::add() {
    CellComp *cellComp = new CellComp(this);
    cellComp->setProperty("text", "!");
    dataComp.append(cellComp);

    emit dataCompChanged();
}
void TableComp::appendDataComp(QQmlListProperty<CellComp> *list, CellComp *value) {
    QList<CellComp*> *dataComp = static_cast<QList<CellComp*> *>(list->data);
    dataComp->append(value);
}

int TableComp::countDataComp(QQmlListProperty<CellComp> *list) {
    QList<CellComp*> *dataComp = static_cast<QList<CellComp*> *>(list->data);
    return dataComp->size();
}

CellComp *TableComp::atDataComp(QQmlListProperty<CellComp> *list, int index) {
    QList<CellComp*> *dataComp = static_cast<QList<CellComp*> *>(list->data);
    return dataComp->at(index);
}

void TableComp::clearDataComp(QQmlListProperty<CellComp> *list) {
    QList<CellComp*> *dataComp = static_cast<QList<CellComp*> *>(list->data);
    qDeleteAll(dataComp->begin(), dataComp->end());
    dataComp->clear();
}

