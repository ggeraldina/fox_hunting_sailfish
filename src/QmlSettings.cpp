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
