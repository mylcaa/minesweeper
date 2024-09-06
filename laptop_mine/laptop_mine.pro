QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

LIBS += -L/usr/local/lib -lwiringPi

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    field.cpp \
    main.cpp \
    dialog.cpp \
    mainwindow.cpp \
    minecounter.cpp \
    minetimer.cpp \
    square.cpp \
    subdialog.cpp \
    warning.cpp

HEADERS += \
    dialog.h \
    field.h \
    mainwindow.h \
    minecounter.h \
    minetimer.h \
    square.h \
    subdialog.h \
    warning.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

FORMS += \
    dialog.ui \
    subdialog.ui \
    warning.ui
