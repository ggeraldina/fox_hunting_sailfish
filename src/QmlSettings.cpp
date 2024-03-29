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
    return settings.value(SETTING_LEVEL, 5).toInt();
}

QString QmlSettings::getSavingGames() {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    return settings.value(SETTING_SAVING_GAMES, "true").toString();
}

QString QmlSettings::getSavingStatistics() {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    return settings.value(SETTING_SAVING_STATISTICS, "true").toString();
}

QString QmlSettings::getUserName() {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    return settings.value(SETTING_USER_NAME, "Player").toString();
}

QString QmlSettings::getUserOpponentName() {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    return settings.value(SETTING_USER_OPPONENT_NAME, "Player 2").toString();
}

int QmlSettings::getRotationFieldTop() {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    return settings.value(SETTING_ROTATION_FIELD_TOP, 0).toInt();
}

int QmlSettings::getRotationFieldBottom() {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    return settings.value(SETTING_ROTATION_FIELD_BOTTOM, 0).toInt();
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

void QmlSettings::setUserName(QString newValue) {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    settings.setValue(SETTING_USER_NAME, newValue);
    settings.sync();
    emit settingUserNameChanged();
}

void QmlSettings::setUserOpponentName(QString newValue) {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    settings.setValue(SETTING_USER_OPPONENT_NAME, newValue);
    settings.sync();
    emit settingUserOpponentNameChanged();
}

void QmlSettings::setRotationFieldTop(int newValue) {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    settings.setValue(SETTING_ROTATION_FIELD_TOP, newValue);
    settings.sync();
    emit settingRotationFieldTopChanged();
}

void QmlSettings::setRotationFieldBottom(int newValue) {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    settings.setValue(SETTING_ROTATION_FIELD_BOTTOM, newValue);
    settings.sync();
    emit settingRotationFieldBottomChanged();
}

void QmlSettings::updateToDefaultSettings() {
    QSettings settings(NAME_FILE_SETTINGS, QSettings::NativeFormat, this);
    settings.setValue(SETTING_BASE_TABLE_SIZE, 9);
    settings.setValue(SETTING_NUMBER_FOXES, 4);
    settings.setValue(SETTING_SPEED_STEP_COMP, 1000);
    settings.setValue(SETTING_VOLUME_EFFECTS, 0.0);
    settings.setValue(SETTING_LANGUAGE, "-??");
    settings.setValue(SETTING_LEVEL, 5);
    settings.setValue(SETTING_SAVING_GAMES, "true");
    settings.setValue(SETTING_SAVING_STATISTICS, "true");
    settings.setValue(SETTING_USER_NAME, "Player");
    settings.setValue(SETTING_USER_OPPONENT_NAME, "Player 2");
    settings.setValue(SETTING_ROTATION_FIELD_TOP, 0);
    settings.setValue(SETTING_ROTATION_FIELD_BOTTOM, 0);
    emit settingBaseTableSizeChanged();
    emit settingNumberFoxesChanged();
    emit settingSpeedStepCompChanged();
    emit settingVolumeEffectsChanged();
    emit settingLanguageChanged();
    emit settingLevelChanged();
    emit settingSavingGamesChanged();
    emit settingSavingStatisticsChanged();
    emit settingUserNameChanged();
    emit settingUserOpponentNameChanged();
    emit settingRotationFieldTopChanged();
    emit settingRotationFieldBottomChanged();
    settings.sync();
}
