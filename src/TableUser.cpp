#include "TableUser.h"

TableUser::TableUser(QObject *parent) : QObject(parent) {
    for(int i = 0; i < 81; i++) {
        CellUser *element = new CellUser(this);
        element->setProperty("text", "+");

        dataUser << element;
    }
}
QQmlListProperty<CellUser> TableUser::getDataUser() {
    return QQmlListProperty<CellUser>(static_cast<QObject *>(this), static_cast<void *>(&dataUser),
                                     &TableUser::appendDataUser, &TableUser::countDataUser,
                                     &TableUser::atDataUser, &TableUser::clearDataUser);
}

void TableUser::add() {
    CellUser *cellUser = new CellUser(this);
    cellUser->setProperty("text", "!");
    dataUser.append(cellUser);

    emit dataUserChanged();
}
void TableUser::appendDataUser(QQmlListProperty<CellUser> *list, CellUser *value) {
    QList<CellUser*> *dataUser = static_cast<QList<CellUser*> *>(list->data);
    dataUser->append(value);
}

int TableUser::countDataUser(QQmlListProperty<CellUser> *list) {
    QList<CellUser*> *data = static_cast<QList<CellUser*> *>(list->data);
    return data->size();
}

CellUser *TableUser::atDataUser(QQmlListProperty<CellUser> *list, int index) {
    QList<CellUser*> *dataUser = static_cast<QList<CellUser*> *>(list->data);
    return dataUser->at(index);
}

void TableUser::clearDataUser(QQmlListProperty<CellUser> *list) {
    QList<CellUser*> *dataUser = static_cast<QList<CellUser*> *>(list->data);
    qDeleteAll(dataUser->begin(), dataUser->end());
    dataUser->clear();
}
