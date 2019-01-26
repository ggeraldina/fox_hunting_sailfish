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
    const QString SETTING_BASE_TABLE_SIZE = "settings_game/base_table_size";
    const QString SETTING_NUMBER_FOXES = "settings_game/number_foxes";

signals:
    void settingBaseTableSizeChanged();
    void settingNumberFoxesChanged();
};

#endif // QMLSETTINGS_H
