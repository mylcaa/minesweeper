QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    field.cpp \
    main.cpp \
    dialog.cpp \
    minesweeper.cpp \
    square.cpp \
    subdialog.cpp \
    warning.cpp

HEADERS += \
    dialog.h \
    field.h \
    minesweeper.h \
    square.h \
    subdialog.h \
    warning.h

FORMS += \
    dialog.ui \
    field.ui \
    minesweeper.ui \
    subdialog.ui \
    warning.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
