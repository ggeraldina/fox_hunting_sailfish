#ifndef QMLSETTINGS_H
#define QMLSETTINGS_H

#include <QObject>
#include <QCoreApplication>
#include <QStandardPaths>
#include <QDir>
#include <QSettings>

class QmlSettings : public QObject {
    Q_OBJECT
    Q_PROPERTY(int settingBaseTableSize READ getBaseTableSize WRITE setBaseTableSize NOTIFY settingBaseTableSizeChanged)
    Q_PROPERTY(int settingNumberFoxes READ getNumberFoxes WRITE setNumberFoxes NOTIFY settingNumberFoxesChanged)
    Q_PROPERTY(int settingSpeedStepComp READ getSpeedStepComp WRITE setSpeedStepComp NOTIFY settingSpeedStepCompChanged)
    Q_PROPERTY(float settingVolumeEffects READ getVolumeEffects WRITE setVolumeEffects NOTIFY settingVolumeEffectsChanged)
    Q_PROPERTY(QString settingLanguage READ getLanguage WRITE setLanguage NOTIFY settingLanguageChanged)
    Q_PROPERTY(int settingLevel READ getLevel WRITE setLevel NOTIFY settingLevelChanged)
    Q_PROPERTY(QString settingSavingGames READ getSavingGames WRITE setSavingGames NOTIFY settingSavingGamesChanged)
    Q_PROPERTY(QString settingSavingStatistics READ getSavingStatistics WRITE setSavingStatistics NOTIFY settingSavingStatisticsChanged)
    Q_PROPERTY(QString settingUserName READ getUserName WRITE setUserName NOTIFY settingUserNameChanged)
    Q_PROPERTY(QString settingUserOpponentName READ getUserOpponentName WRITE setUserOpponentName NOTIFY settingUserOpponentNameChanged)
    Q_PROPERTY(int settingRotationFieldTop READ getRotationFieldTop WRITE setRotationFieldTop NOTIFY settingRotationFieldTopChanged)
    Q_PROPERTY(int settingRotationFieldBottom READ getRotationFieldBottom WRITE setRotationFieldBottom NOTIFY settingRotationFieldBottomChanged)

public:
    explicit QmlSettings(QObject *parent = nullptr);

    int getBaseTableSize();
    int getNumberFoxes();
    int getSpeedStepComp();
    float getVolumeEffects();
    QString getLanguage();
    int getLevel();
    QString getSavingGames();
    QString getSavingStatistics();
    QString getUserName();
    QString getUserOpponentName();
    int getRotationFieldTop();
    int getRotationFieldBottom();

    void setBaseTableSize(int newValue);
    void setNumberFoxes(int newValue);
    void setSpeedStepComp(int newValue);
    void setVolumeEffects(float newValue);
    void setLanguage(QString newValue);
    void setLevel(int newValue);
    void setSavingGames(QString newValue);
    void setSavingStatistics(QString newValue);
    void setUserName(QString newValue);
    void setUserOpponentName(QString newValue);
    void setRotationFieldTop(int newValue);
    void setRotationFieldBottom(int newValue);

    Q_INVOKABLE void updateToDefaultSettings();

private:
    const QString NAME_FILE_SETTINGS = QDir(QStandardPaths::writableLocation(QStandardPaths::ConfigLocation)).filePath(QCoreApplication::applicationName());
    const QString SETTING_BASE_TABLE_SIZE = "settings_game/base_table_size";
    const QString SETTING_NUMBER_FOXES = "settings_game/number_foxes";
    const QString SETTING_SPEED_STEP_COMP = "settings_game/speed_step_comp";
    const QString SETTING_VOLUME_EFFECTS = "settings_app/volume_effects";
    const QString SETTING_LANGUAGE = "settings_app/language";
    const QString SETTING_LEVEL = "settings_game/level";
    const QString SETTING_SAVING_GAMES = "settings_app/saving_games";
    const QString SETTING_SAVING_STATISTICS = "settings_app/saving_statistics";
    const QString SETTING_USER_NAME = "settings_app/user_name";
    const QString SETTING_USER_OPPONENT_NAME = "settings_app/user_opponent_name";
    const QString SETTING_ROTATION_FIELD_TOP = "settings_app/rotation_field_top";
    const QString SETTING_ROTATION_FIELD_BOTTOM = "settings_app/rotation_field_bottom";

signals:
    void settingBaseTableSizeChanged();
    void settingNumberFoxesChanged();
    void settingSpeedStepCompChanged();
    void settingVolumeEffectsChanged();
    void settingLanguageChanged();
    void settingLevelChanged();
    void settingSavingGamesChanged();
    void settingSavingStatisticsChanged();
    void settingUserNameChanged();
    void settingUserOpponentNameChanged();
    void settingRotationFieldTopChanged();
    void settingRotationFieldBottomChanged();
};

#endif // QMLSETTINGS_H
