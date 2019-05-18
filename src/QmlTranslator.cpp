#include "QmlTranslator.h"

QmlTranslator::QmlTranslator(QObject *parent) : QObject(parent) {
    // new необходимо; иначе язык применяется только для текущей страницы, а не для всего приложения
    translator = new QTranslator(this);
}

QmlTranslator::~QmlTranslator() {
    delete translator;
}

void QmlTranslator::setTranslation(QString language) {
    QString translationPath(SailfishApp::pathTo("translations").toLocalFile());
    if (!translator->load(QString("harbour-fox-hunting%1").arg(language), translationPath)) {
        qDebug() << "Failed to load translation file, falling back to English";
    }
    // it's a global thing, we can use it anywhere (after #including <QGuiApplication>)
    qApp->installTranslator(translator);
    emit languageChanged(); // Signaling a change in the current translation
}
