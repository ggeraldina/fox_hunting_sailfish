#ifndef QMLTRANSLATOR_H
#define QMLTRANSLATOR_H

#include <QObject>
#include <sailfishapp.h>
#include <QTranslator>
#include <QCoreApplication>
#include <QGuiApplication>
#include <QDir>

class QmlTranslator : public QObject {
    Q_OBJECT

public:
    explicit QmlTranslator(QObject *parent = nullptr);
    ~QmlTranslator();

    Q_INVOKABLE void setTranslation(QString translation);

private:
    QTranslator *translator;

signals:
    void languageChanged();

};

#endif // QMLTRANSLATOR_H
