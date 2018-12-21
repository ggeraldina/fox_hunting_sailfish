#include "CellUser.h"

CellUser::CellUser(QObject *parent) : QObject(parent) {
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

QString CellUser::getColor() {
    return color;
}

void CellUser::setColor(QString newValue) {
    if (color == newValue) {
        return;
    }
    color = newValue;
    emit colorChanged(color);
}

int CellUser::getValue() {
    return value;
}

void CellUser::setValue(int newValue) {
    if (value == newValue) {
        return;
    }
    value = newValue;
    emit valueChanged(value);
}
