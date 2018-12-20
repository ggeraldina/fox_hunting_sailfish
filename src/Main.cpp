#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include "CellUser.h"
#include "CellComp.h"
#include "TablesCompUser.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<CellUser>("CellUser", 1, 0, "CellUser");
    qmlRegisterType<CellComp>("CellComp", 1, 0, "CellComp");;
    qmlRegisterType<TablesCompUser>("TablesCompUser", 1, 0, "TablesCompUser");
    return SailfishApp::main(argc, argv);    
}
