#include "CellComp.h"

CellComp::CellComp(QObject *parent) : QObject(parent) {
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

QString CellComp::getColor() {
    return color;
}

void CellComp::setColor(QString newValue) {
    if (color == newValue) {
        return;
    }
    color = newValue;
    emit colorChanged(color);
}

int CellComp::getValue() {
    return value;
}

void CellComp::setValue(int newValue) {
    if (value == newValue) {
        return;
    }
    value = newValue;
    emit valueChanged(value);
}

