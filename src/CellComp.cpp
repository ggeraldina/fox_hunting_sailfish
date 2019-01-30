#include "CellComp.h"

CellComp::CellComp(QObject *parent) : CellBase(parent) {
    shot = false;
    possibleShot = true;
    chance = 0;
}

bool CellComp::getShot() {
    return shot;
}

bool CellComp::getPossibleShot() {
    return possibleShot;
}

double CellComp::getChance() {
    return chance;
}

void CellComp::setShot(bool newValue) {
    if (shot == newValue) {
        return;
    }
    shot = newValue;
    emit shotChanged();
}

void CellComp::setPossibleShot(bool newValue) {
    if (possibleShot == newValue) {
        return;
    }
    possibleShot = newValue;
    emit possibleShotChanged();
}

void CellComp::setChance(double newValue) {
    if (chance == newValue) {
        return;
    }
    chance = newValue;
    emit chanceChanged();
}

