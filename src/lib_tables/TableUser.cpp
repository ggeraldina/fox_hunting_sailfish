#include "TableUser.h"

TableUser::TableUser(QObject *parent) : QObject(parent) {

}

void TableUser::editCellsWhenFox(QList<CellUser *> *list, int index) {
    list->value(index)->setBackgroundURL("qrc:/image/fox.jpg");
    list->value(index)->setShot(true);
}

void TableUser::editCellsWhenNoFox(QList<CellUser *> *list, int index) {
    int valueCell = list->value(index)->getValue();
    list->value(index)->setText(QString::number(valueCell));
    list->value(index)->setBackgroundURL("qrc:/image/lightYellow.jpg");
    list->value(index)->setShot(true);
}

void TableUser::putOrRemoveMarkCell(QList<CellUser *> *list, int index) {
    if (list->value(index)->getShot()) {
        return;
    }
    QString textCell = list->value(index)->getText();
    if (textCell == "") {
        list->value(index)->setText("?");
    }
    else {
        list->value(index)->setText("");
    }
}

