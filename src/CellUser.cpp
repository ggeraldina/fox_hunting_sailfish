#include "CellUser.h"

CellUser::CellUser(QObject *parent) : QObject(parent) {
//    this->text = 'fox';
}

QString CellUser::getText() {
    return text;
}

void CellUser::setText(QString newValue) {
    if (text == newValue) {
        return;
    }
    text = newValue;
    emit textChanged(text);
}
