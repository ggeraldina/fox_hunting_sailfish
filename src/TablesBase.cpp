#include "TablesBase.h"

TablesBase::TablesBase(QObject *parent) : QObject(parent){

}

TablesBase::~TablesBase() {

}


int TablesBase::getBaseTableSize() {
    return baseFieldSize;
}

int TablesBase::getNumberFoxes() {
    return numberFoxes;
}

void TablesBase::setBaseTableSize(int newValue) {
    if (newValue <= 0 || baseFieldSize == newValue) {
        return;
    }
    baseFieldSize = newValue;
    emit baseTableSizeChanged();
}

void TablesBase::setNumberFoxes(int newValue) {
    if (newValue <= 0 || numberFoxes == newValue) {
        return;
    }
    numberFoxes = newValue;
    emit numberFoxesChanged();
}


