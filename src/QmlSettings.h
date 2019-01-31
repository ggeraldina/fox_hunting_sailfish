#ifndef QMLSETTINGS_H
#define QMLSETTINGS_H


#include <QDebug>


#include <QObject>
#include <QSettings>

class QmlSettings : public QObject
{
    Q_OBJECT
    Q_PROPERTY(int settingBaseTableSize READ getBaseTableSize WRITE setBaseTableSize NOTIFY settingBaseTableSizeChanged)
    Q_PROPERTY(int settingNumberFoxes READ getNumberFoxes WRITE setNumberFoxes NOTIFY settingNumberFoxesChanged)
    Q_PROPERTY(int settingSpeedStepComp READ getSpeedStepComp WRITE setSpeedStepComp NOTIFY settingSpeedStepCompChanged)
    Q_PROPERTY(float settingVolumeEffects READ getVolumeEffects WRITE setVolumeEffects NOTIFY settingVolumeEffectsChanged)
public:
    explicit QmlSettings(QObject *parent = nullptr);

    int getBaseTableSize();
    int getNumberFoxes();
    int getSpeedStepComp();
    float getVolumeEffects();

    Q_INVOKABLE void setBaseTableSize(int newValue);
    Q_INVOKABLE void setNumberFoxes(int newValue);
    Q_INVOKABLE void setSpeedStepComp(int newValue);
    Q_INVOKABLE void setVolumeEffects(float newValue);

private:
    const QString NAME_FILE_SETTINGS = "settingsFoxHunting.conf";
    const QString SETTING_BASE_TABLE_SIZE = "settings_game/base_table_size";
    const QString SETTING_NUMBER_FOXES = "settings_game/number_foxes";
    const QString SETTING_SPEED_STEP_COMP = "settings_game/speed_step_comp";
    const QString SETTING_VOLUME_EFFECTS = "settings_app/volume_effects";

signals:
    void settingBaseTableSizeChanged();
    void settingNumberFoxesChanged();
    void settingSpeedStepCompChanged();
    void settingVolumeEffectsChanged();
};

#endif // QMLSETTINGS_H
