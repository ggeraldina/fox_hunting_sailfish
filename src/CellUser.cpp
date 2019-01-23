#include "CellUser.h"

CellUser::CellUser(QObject *parent) : CellBase(parent) {
    shot = false;
}

bool CellUser::getShot() {
    return shot;
}

void CellUser::setShot(bool newValue) {
    if (shot == newValue) {
        return;
    }
    shot = newValue;
    emit shotChanged();
}

