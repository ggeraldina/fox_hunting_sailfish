#include "CellBase.h"

CellBase::CellBase(QObject *parent) : QObject(parent) {
    text = "";
    backgroundURL = "qrc:/image/lightGreen.jpg"; // "../../image/fox.jpg"
    value = 0;
}

QString CellBase::getText() {
    return text;
}

QString CellBase::getBackgroundURL() {
    return backgroundURL;
}

int CellBase::getValue() {
    return value;
}

void CellBase::setText(QString newValue) {
    if (text == newValue) {
        return;
    }
    text = newValue;
    emit textChanged();
}

void CellBase::setBackgroundURL(QString newValue) {
    if (backgroundURL == newValue) {
        return;
    }
    backgroundURL = newValue;
    emit backgroundURLChanged();
}

void CellBase::setValue(int newValue) {
    if (value == newValue) {
        return;
    }
    value = newValue;
    emit valueChanged();
}
