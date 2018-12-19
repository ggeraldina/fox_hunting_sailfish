#include "TableUser.h"

TableUser::TableUser(QObject *parent) : QObject(parent) {
    for(int i = 0; i < 56; i++) {
        CellUser *element = new CellUser(this);
        element->setProperty("text", "?");

        data << element;
    }
}
QQmlListProperty<CellUser> TableUser::getData() {
    return QQmlListProperty<CellUser>(static_cast<QObject *>(this), static_cast<void *>(&data),
                                     &TableUser::appendData, &TableUser::countData,
                                     &TableUser::atData, &TableUser::clearData);
}

void TableUser::add() {
    CellUser *cellUser = new CellUser(this);
    cellUser->setProperty("text", "!");
    data.append(cellUser);

    emit dataChanged();
}
void TableUser::appendData(QQmlListProperty<CellUser> *list, CellUser *value) {
    QList<CellUser*> *data = static_cast<QList<CellUser*> *>(list->data);
    data->append(value);
}

int TableUser::countData(QQmlListProperty<CellUser> *list) {
    QList<CellUser*> *data = static_cast<QList<CellUser*> *>(list->data);
    return data->size();
}

CellUser *TableUser::atData(QQmlListProperty<CellUser> *list, int index) {
    QList<CellUser*> *data = static_cast<QList<CellUser*> *>(list->data);
    return data->at(index);
}

void TableUser::clearData(QQmlListProperty<CellUser> *list) {
    QList<CellUser*> *data = static_cast<QList<CellUser*> *>(list->data);
    qDeleteAll(data->begin(), data->end());
    data->clear();
}
