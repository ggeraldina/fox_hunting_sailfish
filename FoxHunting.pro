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
    src/TableUser.cpp \
    src/TableComp.cpp \
    src/Main.cpp \
    src/FoxHunting.cpp

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
    qml/pages/FoxCell.qml \
    qml/pages/SecondPage.qml \
    qml/pages/PlanetItem.qml

SAILFISHAPP_ICONS = 86x86 108x108 128x128 172x172

# to disable building translations every time, comment out the
# following CONFIG line
CONFIG += sailfishapp_i18n

# German translation is enabled as an example. If you aren't
# planning to localize your app, remember to comment out the
# following TRANSLATIONS line. And also do not forget to
# modify the localized app name in the the .desktop file.
TRANSLATIONS += translations/FoxHunting-de.ts

HEADERS += \
    src/CellUser.h \
    src/CellComp.h \
    src/TableUser.h \
    src/TableComp.h
