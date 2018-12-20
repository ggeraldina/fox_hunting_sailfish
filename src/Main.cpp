#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include "CellUser.h"
#include "TableUser.h"
#include "CellComp.h"
#include "TableComp.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<CellUser>("CellUser", 1, 0, "CellUser");
    qmlRegisterType<TableUser>("TableUser", 1, 0, "TableUser");
    qmlRegisterType<CellComp>("CellComp", 1, 0, "CellComp");
    qmlRegisterType<TableComp>("TableComp", 1, 0, "TableComp");
    qmlRegisterType<TableComp>("TablesCompUser", 1, 0, "TablesCompUser");
    return SailfishApp::main(argc, argv);    
}
