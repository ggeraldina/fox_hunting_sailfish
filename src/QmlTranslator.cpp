#include "QmlTranslator.h"

QmlTranslator::QmlTranslator(QObject *parent) : QObject(parent)
{
    translator = new QTranslator(this);
}

void QmlTranslator::setTranslation(QString language)
{
    QDir dir = QDir(qApp->applicationDirPath());
    if (!translator->load(
                // for example, in case of "ru" language the file would be
                // FoxHunting-ru.qm
                // extension is set automatically
                QString("FoxHunting-%1").arg(language),
                // look for the file in folder within working directory
                QString("%1/translations").arg(dir.path())
                )
            )
    {
        qDebug() << "Failed to load translation file, falling back to English";
    }
    // it's a global thing, we can use it anywhere (after #including <QGuiApplication>)
    qApp->installTranslator(translator);
    emit languageChanged(); // Signaling a change in the current translation
}
