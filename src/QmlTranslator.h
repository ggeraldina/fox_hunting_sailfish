#ifndef TRANSLATION_H
#define TRANSLATION_H

#include <QObject>
#include <QTranslator>
#include <QCoreApplication>
#include <QGuiApplication>
#include <QDebug>
#include <QDir>

class QmlTranslator : public QObject
{
    Q_OBJECT

public:
    explicit QmlTranslator(QObject *parent = 0);

signals:
    // The signal of change the current language to change the interface translation
    void languageChanged();

public:
    // Translation installation method, which will be available in QML
    Q_INVOKABLE void setTranslation(QString translation);

private:
    QTranslator *translator;
};

#endif // TRANSLATION_H
