#ifdef QT_QML_DEBUG
#include <QtQuick>
#endif

#include <sailfishapp.h>
#include "CellUser.h"
#include "TableUser.h"

int main(int argc, char *argv[])
{
    qmlRegisterType<CellUser>("CellUser", 1, 0, "CellUser");
    qmlRegisterType<TableUser>("TableUser", 1, 0, "TableUser");
    return SailfishApp::main(argc, argv);    
}
