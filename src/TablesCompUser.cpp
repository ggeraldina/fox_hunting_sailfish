#include "TablesCompUser.h"

TablesCompUser::TablesCompUser(QObject *parent) : QObject(parent)
{
    for(int i = 0; i < 81; i++) {
        CellComp *element = new CellComp(this);
        element->setProperty("text", "*");

        dataComp << element;
    }
    for(int i = 0; i < 81; i++) {
        CellUser *element = new CellUser(this);
        element->setProperty("text", "+");

        dataUser << element;
    }
//    QObject::connect(&dataComp, SIGNAL(valueChanged(int)), &dataUser, SLOT(setValue(int)));
}

QQmlListProperty<CellComp> TablesCompUser::getDataComp() {
    return QQmlListProperty<CellComp>(static_cast<QObject *>(this), static_cast<void *>(&dataComp),
                                     &TablesCompUser::appendDataComp, &TablesCompUser::countDataComp,
                                     &TablesCompUser::atDataComp, &TablesCompUser::clearDataComp);
}

QQmlListProperty<CellUser> TablesCompUser::getDataUser() {
    return QQmlListProperty<CellUser>(static_cast<QObject *>(this), static_cast<void *>(&dataUser),
                                     &TablesCompUser::appendDataUser, &TablesCompUser::countDataUser,
                                     &TablesCompUser::atDataUser, &TablesCompUser::clearDataUser);
}

void TablesCompUser::clickCellComp(int index) {
    emit clickComp(index);
}

void TablesCompUser::printUser(int index) {
    qDebug(index);
}

void TablesCompUser::appendDataComp(QQmlListProperty<CellComp> *list, CellComp *value) {
    QList<CellComp*> *dataComp = static_cast<QList<CellComp*> *>(list->data);
    dataComp->append(value);
}

void TablesCompUser::appendDataUser(QQmlListProperty<CellUser> *list, CellUser *value) {
    QList<CellUser*> *dataUser = static_cast<QList<CellUser*> *>(list->data);
    dataUser->append(value);
}

int TablesCompUser::countDataComp(QQmlListProperty<CellComp> *list) {
    QList<CellComp*> *dataComp = static_cast<QList<CellComp*> *>(list->data);
    return dataComp->size();
}

int TablesCompUser::countDataUser(QQmlListProperty<CellUser> *list) {
    QList<CellUser*> *dataUser = static_cast<QList<CellUser*> *>(list->data);
    return dataUser->size();
}

CellComp *TablesCompUser::atDataComp(QQmlListProperty<CellComp> *list, int index) {
    QList<CellComp*> *dataComp = static_cast<QList<CellComp*> *>(list->data);
    return dataComp->at(index);
}

CellUser *TablesCompUser::atDataUser(QQmlListProperty<CellUser> *list, int index) {
    QList<CellUser*> *dataUser = static_cast<QList<CellUser*> *>(list->data);
    return dataUser->at(index);
}

void TablesCompUser::clearDataComp(QQmlListProperty<CellComp> *list) {
    QList<CellComp*> *dataComp = static_cast<QList<CellComp*> *>(list->data);
    qDeleteAll(dataComp->begin(), dataComp->end());
    dataComp->clear();
}

void TablesCompUser::clearDataUser(QQmlListProperty<CellUser> *list) {
    QList<CellUser*> *dataUser = static_cast<QList<CellUser*> *>(list->data);
    qDeleteAll(dataUser->begin(), dataUser->end());
    dataUser->clear();
}


