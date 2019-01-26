#include "QmlTranslator.h"

QmlTranslator::QmlTranslator(QObject *parent) : QObject(parent) {
    translator = new QTranslator(this);
}

void QmlTranslator::setTranslation(QString language) {
    QString translationPath(SailfishApp::pathTo("translations").toLocalFile());
    if (!translator->load(QString("FoxHunting%1").arg(language), translationPath)) {
        qDebug() << "Failed to load translation file, falling back to English";
    }
    // it's a global thing, we can use it anywhere (after #including <QGuiApplication>)
    qApp->installTranslator(translator);
    emit languageChanged(); // Signaling a change in the current translation
}
