# NOTICE:
#
# Application name defined in TARGET has a corresponding QML filename.
# If name defined in TARGET is changed, the following needs to be done
# to match new name:
#   - corresponding QML filename must be changed
#   - desktop icon filename must be changed
#   - desktop filename must be changed
#   - icon definition filename in desktop file must be changed
#   - translation filenames have to be changed

# The name of your application
TARGET = openrepos-fox-hunting

CONFIG += sailfishapp

SOURCES += \
    src/CellBase.cpp \
    src/CellComp.cpp \
    src/CellUser.cpp \
    src/Main.cpp \
    src/QmlTranslator.cpp \
    src/TablesCompUser.cpp \
    src/lib_tables/TableComp.cpp \
    src/lib_tables/TableUser.cpp \
    src/lib_tables/TableAny.cpp \
    src/QmlSettings.cpp \
    src/TablesBase.cpp \
    src/TablesLocationFoxes.cpp \
    src/TablesPractice.cpp \
    src/TablesUserUser.cpp

DISTFILES += \
    qml/FoxHunting.qml \
    qml/cover/CoverPage.qml \
    qml/pages/*.qml \
    image/*.ico \
    image/*.jpg \
    soundeffects/shot.wav \
    js/database/Database.js \
    icons/108x108/openrepos-fox-hunting.png \
    icons/128x128/openrepos-fox-hunting.png \
    icons/172x172/openrepos-fox-hunting.png \
    icons/86x86/openrepos-fox-hunting.png \
    qml/pages/AboutPage.qml \
    qml/pages/LocationFoxesPage.qml \
    qml/pages/GamePracticePage.qml \
    qml/pages/WinGamePracticePage.qml \
    qml/pages/GameUserUserPage.qml \
    qml/pages/components/statistics_page/SectionGameAI.qml \
    qml/pages/components/statistics_page/SectionGamePractice.qml \
    qml/pages/components/statistics_page/SectionGameUserUser.qml \
    qml/pages/WinGameUserUserPage.qml \
    qml/pages/rulesPages/VariantsGamePage.qml \
    qml/pages/rulesPages/OnePlayerPage.qml \
    qml/pages/rulesPages/TwoPlayersPage.qml \
    qml/pages/rulesPages/FeatureGamePage.qml \
    qml/pages/rulesPages/FunctionalityGamePage.qml \
    rpm/openrepos-fox-hunting.changes.in \
    rpm/openrepos-fox-hunting.yaml \
    rpm/openrepos-fox-hunting.spec \
    rpm/openrepos-fox-hunting.changes.run.in \
    translations/openrepos-fox-hunting-en.ts \
    translations/openrepos-fox-hunting.ts \
    translations/openrepos-fox-hunting-ru.ts \
    openrepos-fox-hunting.desktop

RESOURCES += \
    foxhunting.qrc

SAILFISHAPP_ICONS = 86x86 108x108 128x128 172x172

# Translations
CONFIG += \
    translations \
    sailfishapp_i18n \

TRANSLATIONS += \
    translations/openrepos-fox-hunting-ru.ts \
    translations/openrepos-fox-hunting-en.ts \
    translations/openrepos-fox-hunting.ts \

lupdate_only {
    SOURCES += \
    qml/cover/CoverPage.qml \
    qml/*.qml \
    qml/pages/*.qml
}

HEADERS += \
    src/CellBase.h \
    src/CellComp.h \
    src/CellUser.h \
    src/QmlTranslator.h \
    src/TablesCompUser.h \
    src/lib_tables/TableComp.h \
    src/lib_tables/TableUser.h \
    src/lib_tables/TableAny.h \
    src/QmlSettings.h \
    src/TablesBase.h \
    src/TablesLocationFoxes.h \
    src/TablesPractice.h \
    src/TablesUserUser.h

#SUBDIRS += \
#    FoxHunting.pro
