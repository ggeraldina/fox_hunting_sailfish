#ifndef QMLSETTINGS_H
#define QMLSETTINGS_H

#include <QObject>
#include <QSettings>

class QmlSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int settingBaseTableSize READ getBaseTableSize WRITE setBaseTableSize NOTIFY settingBaseTableSizeChanged)
    Q_PROPERTY(int settingNumberFoxes READ getNumberFoxes WRITE setNumberFoxes NOTIFY settingNumberFoxesChanged)

public:
    explicit QmlSettings(QObject *parent = nullptr);

    int getBaseTableSize();
    int getNumberFoxes();

    Q_INVOKABLE void setBaseTableSize(int newValue);
    Q_INVOKABLE void setNumberFoxes(int newValue);

private:
    const QString NAME_FILE_SETTINGS = "settingsFoxHunting.conf";

signals:
    void settingBaseTableSizeChanged();
    void settingNumberFoxesChanged();
};

#endif // QMLSETTINGS_H
