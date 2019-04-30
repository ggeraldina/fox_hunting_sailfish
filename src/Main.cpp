
#include <QtQuick>
#include <sailfishapp.h>
#include <QtQml>
#include "CellBase.h"
#include "CellUser.h"
#include "CellComp.h"
#include "TablesCompUser.h"
#include "TablesLocationFoxes.h"
#include "QmlSettings.h"
#include "QmlTranslator.h"

int main(int argc, char *argv[])
{
    srand( time(0) ); // автоматическая рандомизация

    QGuiApplication *app = (SailfishApp::application(argc, argv));
    QStringList args = app->arguments();
    bool daemonized = args.contains("-daemon");

    qmlRegisterType<CellBase>("CellBase", 1, 0, "CellBase");
    qmlRegisterType<CellUser>("CellUser", 1, 0, "CellUser");
    qmlRegisterType<CellComp>("CellComp", 1, 0, "CellComp");
    qmlRegisterType<TablesCompUser>("TablesCompUser", 1, 0, "TablesCompUser");
    qmlRegisterType<TablesLocationFoxes>("TablesLocationFoxes", 1, 0, "TablesLocationFoxes");
    qmlRegisterType<QmlSettings>("QmlSettings", 1, 0, "QmlSettings");
    qmlRegisterType<QmlTranslator>("QmlTranslator", 1, 0, "QmlTranslator");    

    QScopedPointer<QQuickView> view(SailfishApp::createView());

    QQmlContext *context = view->rootContext();
    QmlTranslator translator;
    context->setContextProperty("translator", &translator);
    QmlSettings settings;
    context->setContextProperty("settings", &settings);

    view->setSource(SailfishApp::pathTo("qml/FoxHunting.qml"));
    if(daemonized)
        app->setQuitOnLastWindowClosed(false);
    else
        view->show();

   return app->exec();
}
