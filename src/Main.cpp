
#include <QtQuick>
#include <sailfishapp.h>
#include <QtQml>
#include "CellUser.h"
#include "CellComp.h"
#include "TablesCompUser.h"
#include "QmlSettings.h"
#include "QmlTranslator.h"

int main(int argc, char *argv[])
{
    QGuiApplication *app = (SailfishApp::application(argc, argv));
    QStringList args = app->arguments();
    bool daemonized = args.contains("-daemon");

    qmlRegisterType<CellUser>("CellUser", 1, 0, "CellUser");
    qmlRegisterType<CellComp>("CellComp", 1, 0, "CellComp");
    qmlRegisterType<TablesCompUser>("TablesCompUser", 1, 0, "TablesCompUser");
    qmlRegisterType<QmlSettings>("QmlSettings", 1, 0, "QmlSettings");
    qmlRegisterType<QmlTranslator>("QmlTranslator", 1, 0, "QmlTranslator");

    QScopedPointer<QQuickView> view(SailfishApp::createView());
    view->setSource(SailfishApp::pathTo("qml/FoxHunting.qml"));
    if(daemonized)
        app->setQuitOnLastWindowClosed(false);
    else
        view->show();
    return app->exec();
}
