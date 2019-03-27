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
    src/CellBase.cpp \
    src/CellComp.cpp \
    src/CellUser.cpp \
    src/Main.cpp \
    src/QmlTranslator.cpp \
    src/TablesCompUser.cpp \
    src/lib_tables/TableComp.cpp \
    src/lib_tables/TableUser.cpp \
    src/lib_tables/TableAny.cpp \
    src/QmlSettings.cpp

DISTFILES += \
    qml/FoxHunting.qml \
    qml/cover/CoverPage.qml \
    qml/pages/*.qml \
    rpm/FoxHunting.changes.in \
    rpm/FoxHunting.changes.run.in \
    rpm/FoxHunting.spec \
    rpm/FoxHunting.yaml \
    image/*.ico \
    image/*.jpg \
    FoxHunting.desktop \
    icons/108x108/FoxHunting.png \
    icons/128x128/FoxHunting.png \
    icons/172x172/FoxHunting.png \
    icons/86x86/FoxHunting.png \
    translations/FoxHunting.ts \
    translations/FoxHunting-en.ts \
    translations/FoxHunting-ru.ts \
    soundeffects/shot.wav \
    js/database/Database.js \

RESOURCES += \
    foxhunting.qrc

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
    src/QmlSettings.h

#SUBDIRS += \
#    FoxHunting.pro
