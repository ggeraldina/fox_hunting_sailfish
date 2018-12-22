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

DISTFILES += qml/FoxHunting.qml \
    qml/cover/CoverPage.qml \
    qml/pages/FirstPage.qml \
    rpm/FoxHunting.changes.in \
    rpm/FoxHunting.changes.run.in \
    rpm/FoxHunting.spec \
    rpm/FoxHunting.yaml \
    translations/*.ts \
    FoxHunting.desktop \
    qml/pages/LittersCell.qml \
    qml/pages/FieldTableLitters.qml \
    qml/pages/FieldTableDigits.qml \
    image/fox.ico \
    image/fox.jpg \
    qml/pages/GamePage.qml \
    qml/pages/WinGamePage.qml \
    qml/pages/LoseGamePage.qml \
    qml/pages/RulesPage.qml \
    translations/FoxHunting-ru.ts \
    FoxHunting.desktop \
    rpm/FoxHunting.changes.run.in \
    rpm/FoxHunting.yaml \
    image/fox.jpg \
    icons/108x108/FoxHunting.png \
    icons/128x128/FoxHunting.png \
    icons/172x172/FoxHunting.png \
    icons/86x86/FoxHunting.png \
    image/fox.ico \
    rpm/FoxHunting.changes.in \
    translations/FoxHunting-ru.ts \
    translations/FoxHunting.ts \
    qml/cover/CoverPage.qml \
    qml/FoxHunting.qml \
    rpm/FoxHunting.spec

SAILFISHAPP_ICONS = 86x86 108x108 128x128 172x172

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# Russian translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/FoxHunting-ru.ts

HEADERS += \
    src/CellUser.h \
    src/CellComp.h \
    src/TablesCompUser.h \
    src/QmlTranslator.h \

SUBDIRS += \
    FoxHunting.pro
