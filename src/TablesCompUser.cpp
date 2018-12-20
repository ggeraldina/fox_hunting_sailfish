#include "TablesCompUser.h"

TablesCompUser::TablesCompUser(QObject *parent) : QObject(parent)
{
    tableComp = new TableComp(this);
    tableUser = new TableUser(this);
}


TableComp* TablesCompUser::getTableComp() {
    return tableComp;
}

TableUser* TablesCompUser::getTableUser() {
    return tableUser;
}

void TablesCompUser::setTableComp(TableComp *newValue) {
    tableComp = newValue;
    emit tableCompChanged();
}

void TablesCompUser::setTableUser(TableUser *newValue) {
    tableUser = newValue;
    emit tableUserChanged();
}
