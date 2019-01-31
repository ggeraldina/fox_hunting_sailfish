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
    return settings.value(SETTING_VOLUME_EFFECTS, 0.5).toFloat();
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
