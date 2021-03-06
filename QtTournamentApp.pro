QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addplayerdialog.cpp \
    editinfoaboutdialog.cpp \
    gallery.cpp \
    galleryphotoviewer.cpp \
    gallerythumbnail.cpp \
    main.cpp \
    mainwindow.cpp \
    modifyplayerdialog.cpp \
    player.cpp \
    playerbase.cpp \
    tabwidgetroundrobin.cpp \
    tournamentinfo.cpp

HEADERS += \
    addplayerdialog.h \
    editinfoaboutdialog.h \
    gallery.h \
    galleryphotoviewer.h \
    gallerythumbnail.h \
    mainwindow.h \
    modifyplayerdialog.h \
    player.h \
    playerbase.h \
    tabwidgetroundrobin.h \
    tournamentinfo.h

FORMS += \
    addplayerdialog.ui \
    editinfoaboutdialog.ui \
    galleryphotoviewer.ui \
    mainwindow.ui \
    modifyplayerdialog.ui \
    tabwidgetroundrobin.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    Resources.qrc
