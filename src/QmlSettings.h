#ifndef QMLSETTINGS_H
#define QMLSETTINGS_H

#include <QObject>
#include <QSettings>

class QmlSettings : public QObject {
    Q_OBJECT
    Q_PROPERTY(int settingBaseTableSize READ getBaseTableSize WRITE setBaseTableSize NOTIFY settingBaseTableSizeChanged)
    Q_PROPERTY(int settingNumberFoxes READ getNumberFoxes WRITE setNumberFoxes NOTIFY settingNumberFoxesChanged)
    Q_PROPERTY(int settingSpeedStepComp READ getSpeedStepComp WRITE setSpeedStepComp NOTIFY settingSpeedStepCompChanged)
    Q_PROPERTY(float settingVolumeEffects READ getVolumeEffects WRITE setVolumeEffects NOTIFY settingVolumeEffectsChanged)
    Q_PROPERTY(QString settingLanguage READ getLanguage WRITE setLanguage NOTIFY settingLanguageChanged)
    Q_PROPERTY(int settingLevel READ getLevel WRITE setLevel NOTIFY settingLevelChanged)

public:
    explicit QmlSettings(QObject *parent = nullptr);

    int getBaseTableSize();
    int getNumberFoxes();
    int getSpeedStepComp();
    float getVolumeEffects();
    QString getLanguage();
    int getLevel();

    void setBaseTableSize(int newValue);
    void setNumberFoxes(int newValue);
    void setSpeedStepComp(int newValue);
    void setVolumeEffects(float newValue);
    void setLanguage(QString newValue);
    void setLevel(int newValue);
    Q_INVOKABLE void updateToDefaultSettings();

private:
    const QString NAME_FILE_SETTINGS = "settingsFoxHunting.conf";
    const QString SETTING_BASE_TABLE_SIZE = "settings_game/base_table_size";
    const QString SETTING_NUMBER_FOXES = "settings_game/number_foxes";
    const QString SETTING_SPEED_STEP_COMP = "settings_game/speed_step_comp";
    const QString SETTING_VOLUME_EFFECTS = "settings_app/volume_effects";
    const QString SETTING_LANGUAGE = "settings_app/language";
    const QString SETTING_LEVEL = "settings_game/level";

signals:
    void settingBaseTableSizeChanged();
    void settingNumberFoxesChanged();
    void settingSpeedStepCompChanged();
    void settingVolumeEffectsChanged();
    void settingLanguageChanged();
    void settingLevelChanged();
};

#endif // QMLSETTINGS_H
