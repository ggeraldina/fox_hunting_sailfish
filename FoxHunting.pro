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
TARGET = FoxHunting

CONFIG += sailfishapp

SOURCES += \
    src/CellUser.cpp \
    src/CellComp.cpp \
    src/Main.cpp \
    src/TablesCompUser.cpp \
    src/QmlTranslator.cpp \

DISTFILES += \
    qml/FoxHunting.qml \
    qml/cover/CoverPage.qml \
    qml/pages/GamePage.qml \
    qml/pages/WinGamePage.qml \
    qml/pages/LoseGamePage.qml \
    qml/pages/RulesPage.qml \
    qml/pages/LittersCell.qml \
    qml/pages/FieldTableLitters.qml \
    qml/pages/FieldTableDigits.qml \
    qml/pages/SelectLanguagePage.qml \
    qml/pages/MenuPage.qml \
    rpm/FoxHunting.changes.in \
    rpm/FoxHunting.changes.run.in \
    rpm/FoxHunting.spec \
    rpm/FoxHunting.yaml \
    image/fox.ico \
    image/fox.jpg \
    FoxHunting.desktop \
    icons/108x108/FoxHunting.png \
    icons/128x128/FoxHunting.png \
    icons/172x172/FoxHunting.png \
    icons/86x86/FoxHunting.png \
    translations/FoxHunting.ts \
    translations/FoxHunting-en.ts \
    translations/FoxHunting-ru.ts \

SAILFISHAPP_ICONS = 86x86 108x108 128x128 172x172

# Translations
CONFIG += \
    translations \
    sailfishapp_i18n \

TRANSLATIONS += \
    translations/FoxHunting-ru.ts \
    translations/FoxHunting-en.ts \
    translations/FoxHunting.ts \

lupdate_only {
    SOURCES += \
    qml/FoxHunting.qml \
    qml/cover/CoverPage.qml \
    qml/pages/GamePage.qml \
    qml/pages/WinGamePage.qml \
    qml/pages/LoseGamePage.qml \
    qml/pages/RulesPage.qml \
    qml/pages/LittersCell.qml \
    qml/pages/FieldTableLitters.qml \
    qml/pages/FieldTableDigits.qml \
    qml/pages/SelectLanguagePage.qml \
    qml/pages/MenuPage.qml \
}

HEADERS += \
    src/CellUser.h \
    src/CellComp.h \
    src/TablesCompUser.h \
    src/QmlTranslator.h \

SUBDIRS += \
    FoxHunting.pro
