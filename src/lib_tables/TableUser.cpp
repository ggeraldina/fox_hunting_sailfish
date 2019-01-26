#include "TableUser.h"

TableUser::TableUser(QObject *parent) : QObject(parent) {

}

void TableUser::editCellWithFox(QList<CellUser *> *list, int index) {
    list->value(index)->setBackgroundURL("qrc:/image/fox.jpg");
    list->value(index)->setShot(true);
}

void TableUser::editCellWithoutFox(QList<CellUser *> *list, int index) {
    int valueCell = list->value(index)->getValue();
    list->value(index)->setText(QString::number(valueCell));
    list->value(index)->setShot(true);
}

