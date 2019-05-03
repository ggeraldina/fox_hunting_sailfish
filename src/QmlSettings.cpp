#include "QmlSettings.h"

QmlSettings::QmlSettings(QObject *parent) : QObject(parent) {

}

int QmlSettings::getBaseTableSize() {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    return settings.value(SETTING_BASE_TABLE_SIZE, 9).toInt();
}

int QmlSettings::getNumberFoxes() {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    return settings.value(SETTING_NUMBER_FOXES, 4).toInt();
}

int QmlSettings::getSpeedStepComp() {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    return settings.value(SETTING_SPEED_STEP_COMP, 500).toInt();
}

float QmlSettings::getVolumeEffects() {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    return settings.value(SETTING_VOLUME_EFFECTS, 0.0).toFloat();
}

QString QmlSettings::getLanguage() {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    return settings.value(SETTING_LANGUAGE, "-??").toString();
}

int QmlSettings::getLevel() {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    return settings.value(SETTING_LEVEL, 1).toInt();
}

QString QmlSettings::getSavingGames() {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    return settings.value(SETTING_SAVING_GAMES, "true").toString();
}

QString QmlSettings::getSavingStatistics() {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    return settings.value(SETTING_SAVING_STATISTICS, "true").toString();
}

void QmlSettings::setBaseTableSize(int newValue) {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    settings.setValue(SETTING_BASE_TABLE_SIZE, newValue);
    settings.sync();
    emit settingBaseTableSizeChanged();
}

void QmlSettings::setNumberFoxes(int newValue) {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    settings.setValue(SETTING_NUMBER_FOXES, newValue);
    settings.sync();
    emit settingNumberFoxesChanged();
}

void QmlSettings::setSpeedStepComp(int newValue) {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    settings.setValue(SETTING_SPEED_STEP_COMP, newValue);
    settings.sync();
    emit settingSpeedStepCompChanged();
}

void QmlSettings::setVolumeEffects(float newValue) {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    settings.setValue(SETTING_VOLUME_EFFECTS, newValue);
    settings.sync();
    emit settingVolumeEffectsChanged();
}

void QmlSettings::setLanguage(QString newValue) {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    settings.setValue(SETTING_LANGUAGE, newValue);
    settings.sync();
    emit settingLanguageChanged();
}

void QmlSettings::setLevel(int newValue) {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    settings.setValue(SETTING_LEVEL, newValue);
    settings.sync();
    emit settingLevelChanged();
}

void QmlSettings::setSavingGames(QString newValue) {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    settings.setValue(SETTING_SAVING_GAMES, newValue);
    settings.sync();
    emit settingSavingGamesChanged();
}

void QmlSettings::setSavingStatistics(QString newValue) {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    settings.setValue(SETTING_SAVING_STATISTICS, newValue);
    settings.sync();
    emit settingSavingStatisticsChanged();
}

void QmlSettings::updateToDefaultSettings() {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    settings.setValue(SETTING_BASE_TABLE_SIZE, 9);
    settings.setValue(SETTING_NUMBER_FOXES, 4);
    settings.setValue(SETTING_SPEED_STEP_COMP, 1000);
    settings.setValue(SETTING_VOLUME_EFFECTS, 0.0);
    settings.setValue(SETTING_LANGUAGE, "-??");
    settings.setValue(SETTING_LEVEL, 1);
    settings.setValue(SETTING_SAVING_GAMES, "true");
    settings.setValue(SETTING_SAVING_STATISTICS, "true");
    emit settingBaseTableSizeChanged();
    emit settingNumberFoxesChanged();
    emit settingSpeedStepCompChanged();
    emit settingVolumeEffectsChanged();
    emit settingLanguageChanged();
    emit settingLevelChanged();
    emit settingSavingGamesChanged();
    emit settingSavingStatisticsChanged();
    settings.sync();
}
