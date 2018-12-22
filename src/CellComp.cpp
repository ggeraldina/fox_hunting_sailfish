#include "CellComp.h"

CellComp::CellComp(QObject *parent) : QObject(parent) {
    text = "";
    color = "lightGreen";
    value = 0;
    shot = false;
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

bool CellComp::getShot() {
    return shot;
}

void CellComp::setShot(bool newValue) {
    if (shot == newValue) {
        return;
    }
    shot = newValue;
    emit shotChanged(shot);
}

bool CellComp::getPossibleShot() {
    return shot;
}

void CellComp::setPossibleShot(bool newValue) {
    if (possibleShot == newValue) {
        return;
    }
    possibleShot = newValue;
    emit possibleShotChanged(possibleShot);
}

int CellComp::getChance() {
    return chance;
}

void CellComp::setChance(int newValue) {
    if (chance == newValue) {
        return;
    }
    chance = newValue;
    emit chanceChanged(chance);
}

