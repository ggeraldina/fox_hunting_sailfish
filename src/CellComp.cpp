#include "CellComp.h"

CellComp::CellComp(QObject *parent) : QObject(parent) {
//    this->text = 'fox';
}

QString CellComp::getText() {
    return text;
}

void CellComp::setText(QString newValue) {
    if (text == newValue) {
        return;
    }
    text = newValue;
    emit textChanged(text);
}
